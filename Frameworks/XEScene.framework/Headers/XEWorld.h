﻿/******************************************************************************

@File         XEWorld.h

@Version      1.0

@Created      2017, 6, 2

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_WORLD_H_
#define _XE_WORLD_H_
#include <set>

#include "XMemBase.h"
#include "XArray.h"
#include "XString.h"
#include "XModelInstance.h"
#include "XEViewport.h"
#include "XEActor.h"
#include "IXPhysicsScene.h"
#include "XEUtility.h"
#include <functional>
#include "XEEngine.h"
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
#include "XEMessageLog.h"
#endif

X_EMG_BEGIN
typedef std::function<void(XEActor*, xfloat32)>    OnActorTick;
typedef std::function<void(XEActor*, XEViewport*)> OnActorRender;
typedef std::function<void(XEWorld*)>              OnDeserializeFinished;
typedef std::function<bool(XEWorld*)>              OnFrameSizeChangedFunc;
typedef std::function<void(XMLElement*)>           OnFlushSceneData;//deserialize/serialize...

X_ECB_AUTO(OnActorTick, void, XEActor*, xfloat32)
X_ECB_AUTO(OnActorRender, void, XEActor*, XEViewport*)

class XFileBase;
class XEWorldParam;

enum EWorldMode
{
	WM_EDITTING, 
	WM_RUNTIME 
};

class XEWorld 
	: public XMemBase,public XEEngine::XEFrameListener
{
	friend class XEGame;
public:
	typedef XArray<XEActor*> XEActorList;
	typedef XHashTable<XString, XEActor*> XEActorListFastR;//fast retrieving...

	//////////////////////////////////////////////////////////////////////////
	// version
	X_EEB_BEGIN
	static const xchar*              c_SupportPhysicsSkeletonSceneMinVersion;
	static const xchar*				 c_SupportFaceTrackerActorSceneMinVersion;
	static const xchar*				 c_CurrentSceneVersion;
	X_EEB_END

	//////////////////////////////////////////////////////////////////////////
	enum ESceneType
	{
		ST_DEFAULT = 0,//default scene
		ST_FACE_TRACKER /*= 0*/,
		ST_MOBILE_AR,
		ST_ARADS,
		ST_NUM
	};

	static const XString&				GetSceneNameByType(ESceneType eType);
	static ESceneType					GetSceneTypeByName(const XString &str);
	static const XArray<XString>&		GetAllSceneType();

	struct XESceneData
	{
		ESceneType				eSceneType;//such as face tracker, mobile ar ...
		XString					strSceneVersion;//version
		XESceneData() :eSceneType(ST_DEFAULT) //change to default. yanglj.
			, strSceneVersion(c_CurrentSceneVersion){}
		XESceneData(ESceneType eType, XString strVersion) :eSceneType(eType), strSceneVersion(strVersion){}
		xbool operator == (const XESceneData& sd)const{ return eSceneType == sd.eSceneType && strSceneVersion == sd.strSceneVersion; }
	};


protected:
	XEWorld();//only for XEGame creating.
public:
	virtual					                    ~XEWorld();
	virtual void		                        Init();
	void					                    Release();
	virtual	void			                    ReleaseActor(XEActor* pActor);
	virtual void			                    Tick(xfloat32 fDelSecond);//in seconds.

	virtual void			                    Render(XEViewport *pViewport);

	virtual void                                Deserialize(XFileBase* pFile);

	virtual void		                        Serialize(XFileBase *pFile);

	virtual xbool                               LoadScene(const xchar* pRelativePath, xbool bUseRelPathAsHome = xtrue);//in the format of "xx.xscene", if you don't want to use the relative as home path, set it to xfalse.
	
	virtual xbool                               SaveScene(const xchar* pPathToSave);//save all in the world.

	virtual xbool                               ExportScene(const xchar* pPathToSave);//save all as default.

	virtual XEActor*	                        CreateActor(const XString &strActorType);//With the type of Actor.

	virtual XEActor*                            CreateActor(const XString &strActorType, const XString& strActorName);

	virtual void		                        DeleteActor(XEActor *pActor);

	virtual XEActor*                            UpdateNameOfActor(const XString& strActorOldName, const XString& strActorNewName);

	virtual void								MergeActorHiddenStatus(const XEActor* pCurSelectActor = NULL){}//merge request.
	
	inline xbool			                    IsTickable() { return m_bTickable; }
	inline void                                 SetTickable(xbool bEnable){ m_bTickable = bEnable; }
	inline xbool								IsTickPhysics() { return m_bTickPhysicsable; }
	inline void									SetTickPhysicsable(xbool bEnable) { m_bTickPhysicsable = bEnable; }
	inline xbool								IsRenderPhysics() { return m_bRenderPhysicsable; }
	inline void									SetRenderPhysicsable(xbool bEnable) { m_bRenderPhysicsable = bEnable; }
	inline void		                            ClearTickState() { m_bTickState = xfalse; }

	inline void                                 SetWorldMode(EWorldMode mode){ m_eWorldMode = mode; }
	inline const EWorldMode                     GetWorldMode()const{ return m_eWorldMode; }
	inline void                                 SetWorldName(const XString& szName){ m_strName = szName; }
	inline const XString&                       GetWorldName()const{ return m_strName; }


	inline xbool                                IsAssetRelativeToPackage()const{ return m_bRelPathToScene; }

	inline void                                 SetPreviewRenderMode(xbool bSet){ m_bRenderAsMobilePreviewMode = bSet; }
	inline xbool                                IsInPreviewRenderMode(){ return m_bRenderAsMobilePreviewMode; }

	inline XEScriptContainerInstance*           GetScriptContainerInstance(){ return m_pScriptContainerInstance; }

	//the path to the "xscene", purely.
	inline const XString&                       GetSceneAssetPath()const{ return m_strSceneAssetPath; }
	inline void                                 SetSceneAssetPath(const xchar* pAssetPath){ m_strSceneAssetPath = pAssetPath; }

	XString                                     GetAssetPackage()const;///calculating the correct asset package.
	void										SetAssetPackage(const xchar* pPackagePath);//xxxxx.what?

	inline void                                 SetOnActorTickCallback(OnActorTick func){ m_pOnActorTick = func; }

	inline void                                 SetOnActorRenderCallback(OnActorRender func){ m_pOnActorRender = func; }
X_EEB_BEGIN
	inline OnActorTick                          GetOnActorTickCallback(){ return m_pOnActorTick; }
	inline OnActorRender                        GetOnActorRenderCallback(){ return m_pOnActorRender; }
X_EEB_END

	XEActor*                                    FindActor(const XString& strActorName);
	X_EES_LINE const XEActor*                   FindActor(const XString& strActorName) const;

	xbool                                       HasActor(const XEActor* pActor, xbool bIgnoreDeleted = xtrue) const;
	xint32                                      GetActorCount(const XString& strActorType = "") const;

	void                                        GetActorsOfType(const XString& strActorType, XArray<XEActor*>& actorList) const;
	XString                                     GetActorValidName(const XString& strActorType);
	xint32                                      GetActorValidOrder();
	XEActorList&		                        GetAllActors() { return m_aActor; }
	const XEActorList&		                    GetAllActors() const { return m_aActor; }
	XEActorListFastR&                           GetActorFastMap(){ return m_mActorFastR; }
	const XEActorListFastR&                     GetActorFastMap() const{ return m_mActorFastR; }
	
	void                                        AddTemporalObject(XEUtility::XETemporalObject* pDestroyer);//will be delay destroyed.
	xbool                                       AddActorToRenderOrder(XEActor* pActor);//for semi-transparent-rendering...
	xbool                                       RemoveActorFromRenderOrder(XEActor* pActor);
	void                                        MakeActorInRenderOrderSafe();
	X_EES_LINE void                             SortActorInRenderOrder();
	xbool                                       RestoreActiveCamera(XEViewport *pViewport);//restore the active camera in this world.

	const xchar*			                    GetPhysicsSceneName();//physics scene name

	void					                    CreatePhysicsScene(const XString& szSceneName);//create physics scene by name

	IXPhysicsScene*			                    GetPhysicsScene(){ return m_pPhysicsScene; }//get current physics scene by name

	void					                    ReleasePhysicsScene();//release physics scene

	void					                    CreateWorldProperty(XEWorld* pWorld);

	void					                    ReleaseWorldProperty();

	XEWorldParam*	     	                    GetWorldParam(){ return m_pWorldParam; }

	void					                    SetWorldPropertyModified(xbool bIsModified);

	xbool					                    IsWorldPropertyModified();
			
	/** （default/facetracker/mobile_ar/arads） */
	void				                        SetSceneType(ESceneType eSceneType){ m_SceneData.eSceneType = eSceneType; }
	ESceneType									GetSceneType()const { return m_SceneData.eSceneType; }

	xint32										GetSceneVersionValue();
	X_FORCEINLINE  XString						GetSceneVersion() { return m_SceneData.strSceneVersion; }
	void								        SetSceneVersion(XString strVersion){ m_SceneData.strSceneVersion = strVersion; }
	xbool                                       AttachBindingScriptAsset(const xchar* pAssetPath);//path will be fixed.

	void                                        DetachBindingScriptInstance();

	/** RayCollisionChannel came from XECollisionChannelMeta(located in XEHitResult), indicating that the collision channel(s) that the ray can go through and do the hit-tests.
	*	Objects of the world in the indicating channel will be took part in the calculating with the Ray.
	*	@param vScreenPosition [In]
	*	@param pRayCollisionChannel [In]
	*	@param pActorsExclude [In]
	*	@param HitResult [In/Out]
	*	@param pHitResultList [In/Out]
	*/
	xbool                                       RayPick(const XVECTOR2& vScreenPosition, XEHitResult& HitResult,XArray<XEHitResult>* pHitResultList = NULL, XArray<xint32>* pRayCollisionChannel = NULL, XArray<XEActor*>* pActorsExclude = NULL);

protected:					                    
	XEActorList                                 m_aActor;
	XEActorList                                 m_aActorWithRenderOrder;//come from m_aActor
	XEActorListFastR		                    m_mActorFastR;
	XEUtility::TemporalObjectList               m_aTemporalObj;//temporal objects that can be rendered/ticked in the world.
	xbool					                    m_bTickState;
	xbool                                       m_bTickable;
	xbool										m_bTickPhysicsable;
	xbool										m_bRenderPhysicsable;
	xbool                                       m_bRenderAsMobilePreviewMode;
	EWorldMode                                  m_eWorldMode;
	XString                                     m_strName;
	IXPhysicsScene*			                    m_pPhysicsScene;// physical scene pointer
	XCOLOR                                      m_uVpClearColor;
	XEWorldParam*			                    m_pWorldParam;//world property setting
	XEWorld::XESceneData						m_SceneData;
	tinyxml2_XEngine::XMLDocument				m_CopyOrPasteDoc;//used to copy/paste selected actors
	XHashTable<XString, XString>				m_aOriginNameInXMLToActorName;//clone actor
	XEActorList									m_aSortActorListInClone;//clone actor
	XEScriptContainerInstance*                  m_pScriptContainerInstance;//script holder for this world.
private:
	XString                                     m_strSceneAssetPath;//the package path of the world(scene).(equal to the lib-source-related-engine-path if empty. Runtime. )
	xbool                                       m_bRelPathToScene;//indicated that whether the path is relative to the xscene-path.
protected:
	virtual void     		                    Serialize(tinyxml2_XEngine::XMLDocument& doc, xbool bIsModified = xtrue);
	xbool										GetActorChildNameInActorList(XEActor* pActor, const XEActorList& aActors,XArray<XString>& childActorNamesInActorList);
	virtual void								OnPreFrame();
	virtual void								OnPostFrame();
	virtual void								OnFrameSizeChanged();
private:
	void										SetParentActorForActor(XEActor* pActor, XEActorList& aSerlizeActors);//zsx:fix filterPath
	void										InitActorsFromTempXml(XMLElement* pEleScene, XEActorList& aAddActors);
	void										DeserializeActorsFromTempXml(XMLElement* pEleScene);
	void										ResetActorPropertySerializeFlag(const XEActorList& aActors);
public:
	virtual void                                SerializeForPreview(tinyxml2_XEngine::XMLDocument& doc);
	virtual void			                    Deserialize(tinyxml2_XEngine::XMLDocument& doc);
public:
 	virtual void								CopySelectedActors(const XEActorList& aActors,xbool bIsChangeCopyName = xtrue,xbool bIsResetActorProperty = xtrue);
 	virtual XEActorList							PasteSelectedActors();
	void										ReAttachToActor(XEActor* pSourceActor, XEActor* pParentActor, void* pBindUesrNode);
	XEViewport*                                 GetAttachedViewport() const;//to find the viewport where the world located.[in XEViewportManager]
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void                                GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po);
	xbool										SetMessageLogListener(MessageLogListener* pListener);
	xbool										ClearMessageLogListener();
	MessageLogListener*							GetMessageLogListener(){ return m_pMessageLogListener; }
	MessageLogListener*							m_pMessageLogListener;
#endif
X_EEB_BEGIN
	static xint32                               SortActors(XEActor*const* pLhs, XEActor*const* pRhs);
	static xint32                               SortActorsWithRenderOrder(XEActor*const* pLhs, XEActor*const* pRhs);
	OnActorTick                                 m_pOnActorTick;
	OnActorRender                               m_pOnActorRender;
	static OnDeserializeFinished				s_pOnDeserializeFinished;
	static OnDeserializeFinished				s_pGetWinSizeDeserializeFinished;//序列化完成后，向外部的actor通知窗口尺寸
	static OnFrameSizeChangedFunc				s_pOnFrameSizeChangedFunc;
	static OnFlushSceneData                     s_pOnSceneDeserializeData;
	static OnFlushSceneData                     s_pOnSceneSerializeData;
X_EEB_END
public:
	static const XString						PHY_SCENE_SUFFIX;
};

#endif



