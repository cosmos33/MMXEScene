/******************************************************************************

@File         XEImg2DScreenSequenceFrameActor.h

@Version       1.0

@Created      2019, 3, 15

@Description  代表基于屏幕的2D序列帧；

@HISTORY:

******************************************************************************/
#ifndef XE_2D_SCREEN_SEQUENCE_FRAME_ACTOR_H
#define XE_2D_SCREEN_SEQUENCE_FRAME_ACTOR_H

#include "XEMagicCoreActorBase.h"
/*
序列帧Actor点选优先级采用默认值，即启用点选优先级
*/
class XEImgSequenceFrameActorBase : public XEMagicCoreActorBase
{
public:
	XEImgSequenceFrameActorBase(){ m_szActorShortName = "SeqFrameBase"; }
	virtual ~XEImgSequenceFrameActorBase(){}
	X_EES_LINE virtual void         PostInitialized() override;//you may do something else later in this function. Elements in Array were ready.
	virtual xfloat32                GetRenderOrderFactor()const override;
public:
	XE_ACTOR_CAST(XEImgSequenceFrameActorBase)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)

public:
	void							SetRotateScreen(const xfloat32& fRotateDegree);
	xfloat32						GetRotateScreen() const;//角度
	void							SetScaleScreen(const XVECTOR2& vScale);
	XVECTOR2						GetScaleScreen() const;
	void							SetLocationScreen(const XVECTOR2& vLoc);
	XVECTOR2						GetLocationScreen()const;
	xbool                           IsSegmentationEnable() const;//check in its components
	xbool                           IsObjectDetectEnable() const;//check in its components
public:
	static const XString ACTOR_TYPENAME;
};

class XEImg2DScreenSequenceFrameActor : public XEImgSequenceFrameActorBase
{
public:
								XEImg2DScreenSequenceFrameActor();
	virtual						~XEImg2DScreenSequenceFrameActor();
public:
	XE_ACTOR_CAST(XEImg2DScreenSequenceFrameActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEImg2DScreenSequenceFrameActor)
	   
	virtual void                Initialize(XEWorld* pWorld)override;
public:
	static const XString ACTOR_TYPENAME;
};


#endif

