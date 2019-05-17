/******************************************************************************

@File         XEAnimControllerBase.h

@Version       1.0

@Created      2019,3, 21

@HISTORY:

******************************************************************************/
#ifndef XE_ANIM_CONTROLLER_BASE_H
#define XE_ANIM_CONTROLLER_BASE_H
#include "XMath3D.h"
#include "XArray.h"
#include "XClassReflector.h"

class XEAnimControllerBase
	: public XMemBase
	, public XClass
{
public:
	enum EPlayControlState
	{
		PS_UNKNOWN = 0,
		PS_PLAY,
		PS_PAUSE,
		PS_STOP
	};
	enum EAnimationMode
	{
		AM_RUN = 1,
		AM_EDIT
	};
public:
	XEAnimControllerBase();
	virtual ~XEAnimControllerBase();
	typedef XEAnimControllerBase     Super;
public:
	X_FORCEINLINE EAnimationMode     GetAnimRunMode(){ return m_eAnimMode; }
	X_FORCEINLINE void               SetAnimRunMode(EAnimationMode em){ m_eAnimMode = em; }
	X_FORCEINLINE EPlayControlState  GetAnimPlayState(){ return m_ePlayState; }
	X_FORCEINLINE void	             SetAnimPlayState(EPlayControlState ps){ m_ePlayState = ps; }
	X_FORCEINLINE xbool              IsLoop() const{ return m_bLoop; }
	X_FORCEINLINE xbool              IsReverse() const{ return m_bReverse; }
	X_FORCEINLINE xbool              IsPlaying() const{ return PS_PLAY == m_ePlayState; }
	X_FORCEINLINE xbool              IsAutoPlay() const{ return m_bAutoPlay; }
	X_FORCEINLINE void               SetAutoPlay(xbool bAuto){ m_bAutoPlay = bAuto; }
	X_FORCEINLINE xfloat32           GetPlayRate(){ return m_fRate; }
	X_FORCEINLINE xbool				 IsAnimRunMode(){ return AM_RUN == m_eAnimMode; }
	X_FORCEINLINE xint32             GetCurTime(){ return m_nCurTime; }
	X_CLASS_DEF(XEAnimControllerBase)
public:
	virtual void                     Tick(xfloat32 fInterval){}//in milliseconds
	virtual void                     Play();
	virtual void                     Resume();
	virtual void                     Stop();
	virtual void                     Pause();
	virtual void                     SetLoop(xbool bLoop);
	virtual void                     SetReverse(xbool bReverse);
	virtual void                     SetPlayRate(xfloat32 fRate);
	virtual void                     SetTime(xint32 nTime);//in micro seconds.
protected:
	EPlayControlState                m_ePlayState;
	EAnimationMode                   m_eAnimMode;
	xbool                            m_bLoop;
	xbool                            m_bReverse;//reverse playing...
	xfloat32                         m_fRate;
	xbool                            m_bAutoPlay;//load then play, if it is auto.
	xint32							m_nCurTime;
};

#endif // 
