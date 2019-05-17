/******************************************************************************

@File         XEAnimController.h

@Version       1.0

@Created      2017,12, 22

@HISTORY:

******************************************************************************/
#ifndef XE_ANIM_CONTROLLER_H
#define XE_ANIM_CONTROLLER_H
#include "XEAnimControllerBase.h"

class XEModelComponent;
class XEAnimMontage;
class XESequencer;
class XEAnimComponentPlayList;
class XSkelAnimController;
class XEPrimitiveComponent;
class XAnimMultiLayer;

class XEAnimController : public XEAnimControllerBase
{
public:
	class Listener
	{
	public:
		virtual			            ~Listener() {}
		virtual	void	             Ls_StepMove(xfloat32 fTime){}
		virtual void                 Ls_PlayStateChange(XEAnimControllerBase::EPlayControlState state){}
		virtual void                 Ls_PlayOneTimeFinished(xbool bReversePlaying){}
	};
	typedef XArray<Listener*>        StepperListenerList;
public:
	XEAnimController();
	virtual ~XEAnimController();
public:
	xbool                            AddListener(Listener* pListener);
	xbool                            RemoveListener(Listener* pListener);
	void							 NavigateToHead();
	void							 NavigateToTail();
	void                             BroadcastStepMove();
	void                             BroadcastPlayState(XEAnimControllerBase::EPlayControlState state);
	virtual void                     BroadcastPlayOneTimeFinished(xbool bReversePlaying);
 	X_FORCEINLINE xint32             GetCurTime(){ return m_nCurTime; }
	X_FORCEINLINE void               SetManaulStartTime(xint32 nTime){ m_nManualStartTime = nTime; }
	X_FORCEINLINE xint32             GetManualStartTime() const{ return m_nManualStartTime; }
	X_FORCEINLINE void               SetManualEndTime(xint32 nTime){ m_nManualEndTime = nTime; }
	X_FORCEINLINE xint32             GetManualEndTime() const{ return m_nManualEndTime; }
	X_FORCEINLINE void               SetManualTimeMode(xbool bManual){ m_bManualTimeMode = bManual; }
	X_FORCEINLINE xbool              IsManualTimeMode() const{ return m_bManualTimeMode; }
	/** 
	*
	*	@attention forbidden to delete this in callback, if it is true!
	*/
	X_FORCEINLINE xbool              IsCallbackSafeLocked()const{ return m_bAnimCallbackSafeLock; }
	X_CLASS_DEF(XEAnimController)
public:
	virtual void                     Tick(xfloat32 fInterval);//in milliseconds
	virtual xint32                   GetTimeLength() const;
public:
	static  XEAnimController*        AssginAnimControllerForModelComponent(XEModelComponent* pComponent);
	static  XEAnimComponentPlayList* AssginAnimListForModelComponent(XEModelComponent* pComponent);
	static  xbool                    LoadAnimation(const xchar* pAssetName, XEModelComponent* pComponent);//could be .seq or .montage
	static  xbool                    UnloadAnimation(XEModelComponent* pComponent);//unload any animations(removed them as well.)
	static  xbool					 LoadLayerAnimations(const xchar* pLayerName, const XArray<XString>& arrAreaNames, const XArray<XString>& arrAssetNames, XEModelComponent* pComponent, xbool bReload = xfalse);
	static  xbool					 UnloadLayerAnimations(const xchar* pLayerName, XEModelComponent* pComponent);
	static  xbool                    LoadVideo(const xchar* pAssetName, XEPrimitiveComponent* pComponent);
	static  xbool                    UnloadVideo(XEPrimitiveComponent* pComponent);
	static  void					 SetCurPlayLayerName(const XString& strLayerName){ m_strCurPlayLayer = strLayerName; }
	static  const XString&			 GetCurPlayLayerName(){ return m_strCurPlayLayer; }
protected:
	static  xbool					 UpdateLayerAnimations(const xchar* pLayerName, const XArray<XString>& arrAreaNames, const XArray<XString>& arrAssetNames, XEModelComponent* pComponent);
	static  XAnimMultiLayer*         AddLayerAnimSequence(const xchar* pLayerName, const char* pAreaName, const char* pAssetPath, XEModelComponent* pComponent);//add anim asset to an exist layer.
	static  xbool					 IsLayerHasAreas(const xchar* pLayerName, const XArray<XString>& arrAreaNames, XEModelComponent* pComponent);
protected:
	xbool                            m_bSetTimeInTickTicked;//dirty in tick of set-time?
	StepperListenerList              m_Listeners;
	static XString					 m_strCurPlayLayer;
protected:
	xint32                           m_nManualStartTime;
	xint32                           m_nManualEndTime;
	xbool                            m_bManualTimeMode;
private:
	xbool                            m_bAnimCallbackSafeLock;//forbidden to delete this in callback, if it is true!
	xbool                            m_bTicked;

};

#endif // XE_ANIM_CONTROLLER_H
