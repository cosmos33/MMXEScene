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

/*
* Note:此类Actor只能Attach到XEFaceTrackerActor上，不支持附加到其他类型Actor.
*/
class XEImg2DFaceKeyPointSequenceFrameActor : public XEImgSequenceFrameActorBase
{
public:
								XEImg2DFaceKeyPointSequenceFrameActor();
	virtual						~XEImg2DFaceKeyPointSequenceFrameActor();
public:
	XE_ACTOR_CAST(XEImg2DFaceKeyPointSequenceFrameActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEImg2DFaceKeyPointSequenceFrameActor)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)
	   
	virtual void                Initialize(XEWorld* pWorld)override;
	virtual const XArray<XString>&GetParentActorTypeFilterList()const override;

public:
	static const XString ACTOR_TYPENAME;
	static const XString ACTOR_SHORT_NAME;
protected:
	static XArray<XString>		s_aFilterParentActorType;
};


#endif

