/******************************************************************************

@File         XEFaceTrackerActor.h

@Version       1.0

@Created      2019, 3, 11

@Description  代表FaceTracker的Actor，包含跟随人脸和不跟随人脸的两类Actor；

@HISTORY:

******************************************************************************/
#ifndef XE_FACE_TRACKER_ACTOR_H
#define XE_FACE_TRACKER_ACTOR_H

#include "XEActor.h"
#include "XEStaticMeshActor.h"
#include "XEDecorationEnvBridgeBase.h"
#include "XETriggerOption.h"
#include <mutex>

/**
* This class represents a Face Track actor and contains sub-actors that follow faces and do not follow faces.
* The actors that follow faces are attached actors.These actors can be gotten by GetChildActors.
* The position actors only be showed or hidden by face detection status.These actors can be gotten by GetPositionActors.
* 此Actor不能Attach 到任何类型Actor（包括XEFaceTrackerActor）
*/

class FaceTracking;
class XEFaceTrackListenerBridge;
class XEFaceTrackerActor 
	: public XEActor
	, public XEMagicCore::FxListener
{
public:
	XEFaceTrackerActor();
	virtual ~XEFaceTrackerActor();
	enum XEFilterPathType
	{
		EFP_CUSTOM,
		EEP_POSITION,
		EEP_TRACKING
	};
	enum ETrackType
	{
		ETT_NONE,
		ETT_POSITION,
		ETT_ATTACH
	};
	enum ERenderFacePointNumType
	{
		ERFPN_96,
		ERFPN_137,
		ERPN_NUM
	};
public:
	XE_ACTOR_CAST(XEFaceTrackerActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEFaceTrackerActor)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)
	   
	virtual void				                          Tick(xfloat32 fDels, xbool bForceTick = xtrue) override;
	virtual void				                          Initialize(XEWorld* pWorld) override;
	virtual void                                          Release() override;
	virtual void                                          Deserialize(const XMLElement* pEleActor) override;
	virtual XMLElement*                                   Serialize(XMLElement* pEleParent) override;
	virtual void                                          SetDeleted(xbool bDelete) override;
	virtual void                                          SetHidden(xbool bHide) override;
	virtual void                                          Render(XEViewport* pViewport) override;
	virtual const XArray<XString>&						  GetParentActorTypeFilterList()const override;

protected:									              
	virtual void					                      OnMMCVDetectEnableChange(xbool bEnable) override;
	virtual void                                          OnFaceEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, XEMagicCore::eEntityDetectStatus status, const XEMagicCore::XEFaceEntity& entity) override;
	virtual void					                      OnFaceEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const XEMagicCore::FaceEntityList& entities);
	virtual void					                      OnObjectEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, XEMagicCore::eEntityDetectStatus status, const XEMagicCore::XEObjectEntity& entity);
	virtual void					                      OnObjectEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const XEMagicCore::ObjectEntityList& entities);
	virtual void		                                  OnBodyEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, XEMagicCore::eEntityDetectStatus status, const XEMagicCore::XEBodyEntity& entity)override;
	virtual void		                                  OnBodyEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const XEMagicCore::BodyEntityList& entities)override;
public:							   	       	            
	/************************************************************************/
	/*@Deprecated 当世界的版本号大于1.5时，此函数弃用*/
	/*Please call AttachToActor for child actor(2019.6.12)*/
	/************************************************************************/
	void									              Attach(XEActor* pActor,xbool* bResult = NULL);

	/************************************************************************/
	/*@Deprecated 当世界的版本号大于1.5时，此函数弃用*/
	/*Please call DetachFromActor for child actor(2019.6.12)*/
	/************************************************************************/
	void									              Detach(XEActor* pActor, xbool* bResult = NULL);
	/**
	* Get position actors attaching to this actor
	* @return  position actors
	*/
	XArray<XEActor*>&			                          GetPositionActors(){ return m_aPositionActors; }
	const XArray<XEActor*>&		                          GetPositionActors() const{ return m_aPositionActors; }
	/**
	* Get actors that track faces and do not track faces.
	* @param aAttachedActors An out param.Represents actors that track faces and do not track faces
	* @return  whether is successful
	*/
	xbool						                          GetAllActorsInFaceTracker(XArray<XEActor*>& aAttachedActors);

	/**
	* Whether the face mask actor exists
	* @return  whether is successful
	*/
	xbool						                          HasFaceMaskActor();
	XEActor*					                          GetFaceMaskActor();
	xbool						                          HasActor();
	xbool						                          HasActor(XEActor *pActor);
									                      
	void						                          SetEnableMMCVCore(xbool bEnable){ m_bEnableMMCVCore = bEnable; }
	xbool						                          IsEnableMMCVCore(){ return m_bEnableMMCVCore; }
	void						                          SetHideActorsInGame(xbool bHide);
	void						                          SetFaceMaskMdlPath(const XString& strPath){ m_strFaceMaskMdlPath = strPath; }
									                      
	void						                          SetAttachFaceIndex(xint32 nIndex){ m_nAttachFaceIndex = nIndex; }
	xint32						                          GetAttachFaceIndex(){ return m_nAttachFaceIndex; }
									                      
	XString						                          GetFilterPath(XEFilterPathType eFilterPath);
									                      
	X_FORCEINLINE void                                    SetRenderLandmarksEnable(xbool bEnable){ m_bRenderLandmarks = bEnable; }
	X_FORCEINLINE xbool                                   IsRenderLandmarksEnable()const{ return m_bRenderLandmarks; }
	X_FORCEINLINE void                                    SetLandmarkColor(const XCOLORBASE& color){ m_clLandmark = color; }
	X_FORCEINLINE const XCOLORBASE&                       GetLandmarkColor()const{ return m_clLandmark; }
	X_FORCEINLINE void                                    SetRenderFaceRectEnable(xbool bEnable){ m_bRenderFaceRect = bEnable; }
	X_FORCEINLINE xbool				                      IsRenderFaceRectEnable()const{ return m_bRenderFaceRect; }
	X_FORCEINLINE const XVECTOR4&                         GetFaceRect()const{ return m_vFaceRect; }
	X_FORCEINLINE void                                    SetFaceRectColor(const XCOLORBASE& color){ m_clFaceRectMark = color; }
	X_FORCEINLINE const XCOLORBASE&                       GetFaceRectColor()const{ return m_clFaceRectMark; }
	X_FORCEINLINE XETriggerOption::GestureType			  GetGestureType()const{ return m_eGestureType; }
	X_FORCEINLINE XETriggerOption::EmotionalAnimationType GetEmotionAnimationType()const{ return m_eEmotionType; }

	ERenderFacePointNumType								  GetRenderFacePointNumType();
	//NOTE：如果修改了全局参数video.face_alignment_version，需要同步调用SetRenderFacePointNumType更新
	void												  SetRenderFacePointNumType(ERenderFacePointNumType eType);

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                           GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy);
#endif			
	static const XArray<XString>&						  GetAllRenderFacePointNumTypeList();
	static const XString&								  GetRenderFacePointNumTypeNameForType(ERenderFacePointNumType eType);
	static ERenderFacePointNumType						  GetRenderFacePointNumTypeForName(const XString &str);

public:								                      
	const XArray<xfloat32>&			                      GetLandMark(xbool bCopyReshape = xtrue) const;
	const XArray<xfloat32>&                               GetLandMark137(xbool bCopyReshape = xtrue) const;
	void                                                  CopyLandMark(XArray<xfloat32>& arrLandmark, xbool bCopyReshape = xtrue) const;
	void                                                  CopyLandMark137(XArray<xfloat32>& arrLandmark, xbool bCopyReshape = xtrue) const;
	XVECTOR2                                              GetLandMarkPoint(xint32 nPointIndex, xbool bCopyReshape = xtrue) const;
	XVECTOR2                                              GetLandMarkPoint137(xint32 nPointIndex, xbool bCopyReshape = xtrue) const;
	xbool							                      GetFaceMatrixOnWorldSpace(XMATRIX4& matWorld) const;                       
protected:
	virtual xbool				                          PreAttachActorForParentActor(XEActor* pChildActor) override;
	virtual xbool										  PostAttachActorForParentActor(XEActor* pChildActor)override;
	virtual xbool				                          PreDetachForParentActor(XEActor* pChildActor)override;
	virtual xbool				                          PostDetachForParentActor(XEActor* pChildActor)override;
	virtual xbool										  EnableUpdateChildActorMergeMode(XEActor* pChildActor)override;
protected:
	void												  UpdateChildActorMergeStatus(XEActor* pChildActor,xbool bMerge);
	void                                                  ZoomKeypoint();
public:
	static void                                           ReverseZoomKeypoint(XArray<xfloat32>& zoomPoints, XEFilterUtility::XEZoomKeypoint* pZkp);
private:							                      
	xbool						                          AddFaceMaskActor();
	xbool						                          RemoveFaceMaskActor();
	XString						                          GetValidFaceMaskActorName();
	void						                          RestoreActorTransform();/** All actors restore to world transform */
	xbool						                          UpdateFaceMaskState(XEActor* pActor);//为了兼容1.2版本的scene
	void						                          AttachActorByParamExtendConfig(XEActor* pActor);
private:
	void												  SetMobileParamExtendConfig(XEActor* pActor, ETrackType& eType);
public:
	static const XString ACTOR_TYPENAME;
	static const XString ACTOR_SHORT_NAME;
	//注册可以挂载到当前Actor的子Socket Actor
	static void											  RegisterChildSocketActorType(const XString& strChildSocketActorType);
	static XArray<XString>&								  GetChildSocketActorTypeList(){ return s_aChildSocketActorType; }

	//注册不受脸部状态改变影响的子Socket Actor类型
	static void											  RegisterDisableFaceCtrlChildSocketActorType(const XString& strChildSocketActorType);
	static XArray<XString>&								  GetDisableFaceCtrlChildSocketActorTypeList(){ return s_aDisableFaceCtrlChildActorType; }
protected:
	static XArray<XString>								  s_aFilterParentActorType;
	//Track Socket Actor 类型
	static XArray<XString>								  s_aChildSocketActorType;
	//不受脸部状态改变影响的子Socket Actor类型，如XEBodyJointSocketActor
	static XArray<XString>								  s_aDisableFaceCtrlChildActorType;

	//延迟初始化依赖于全局参数的成员变量，如video.face_alignment_version
	class DelayInitDependencyParams :public XEUtility::XETemporalObject
	{
	public:
		DelayInitDependencyParams() :m_pActor(NULL){}
		virtual ~DelayInitDependencyParams(){}
		//functions that should be override.
		virtual xbool ShouldBeDeleted()override;
		virtual void  Release()override{}
	public:
		XEFaceTrackerActor*	  m_pActor;
	};
private:
	/** just control to show or hide actor whether detects face. */
	XArray<XEActor*>			                          m_aPositionActors;/**< position group's actors */
	XString						                          m_strFaceMaskMdlPath;
	xbool						                          m_bEnableMMCVCore;
	xint32						                          m_nAttachFaceIndex;/**< face index,start from 1 */
	XString						                          m_strFaceMaskName;
private:
	//face attribute						              
	xbool									              m_bRenderLandmarks;
	xbool									              m_bRenderFaceRect;
	XCOLORBASE								              m_clLandmark;
	XCOLORBASE								              m_clFaceRectMark;

	//cache for data in thread.				              
	XArray<xfloat32>						              m_aLandmarkCache;
	XArray<xfloat32>						              m_aLandmarkCache_137;//137 points for makeup
	//original points.
	XArray<xfloat32>                                      m_aLandmarkCacheOrigin;
	XArray<xfloat32>                                      m_aLandmarkCacheOrigin_137;
	mutable std::mutex								      m_mutexLandMark;
	XVECTOR4								              m_vFaceRect;
	//indicate that the matrix for the face, need to update every frame.
	XMATRIX4								              m_matFace;
	xbool									              m_bDetectFace;//是否检测到人脸

	XETriggerOption::GestureType			              m_eGestureType;//fast check
	XETriggerOption::EmotionalAnimationType               m_eEmotionType;//fast check
	XEFaceTrackListenerBridge*							  m_pTrackListenerBridge;
	ERenderFacePointNumType								  m_eRenderFacePointNumType;
};


#endif

