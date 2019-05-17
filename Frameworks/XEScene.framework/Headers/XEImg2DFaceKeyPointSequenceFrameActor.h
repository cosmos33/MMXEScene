/******************************************************************************

@File         XEImg2DFaceKeyPointSequenceFrameActor.h

@Version       1.0

@Created      2019, 3, 15

@Description  代表基于人脸关键点的2D序列帧；

@HISTORY:

******************************************************************************/
#ifndef XE_2D_FACE_KEY_POINT_SEQUENCE_FRAME_ACTOR_H
#define XE_2D_FACE_KEY_POINT_SEQUENCE_FRAME_ACTOR_H

#include "XEImg2DScreenSequenceFrameActor.h"

class XEImg2DFaceKeyPointSequenceFrameActor : public XEImgSequenceFrameActorBase
{
public:
								XEImg2DFaceKeyPointSequenceFrameActor();
	virtual						~XEImg2DFaceKeyPointSequenceFrameActor();
public:
	XE_ACTOR_CAST(XEImg2DFaceKeyPointSequenceFrameActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEImg2DFaceKeyPointSequenceFrameActor)
	   
	virtual void                Initialize(XEWorld* pWorld)override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual xbool               IsTransformMergeEditMode()const override{ return xfalse; }
#endif
public:
	static const XString ACTOR_TYPENAME;
};


#endif

