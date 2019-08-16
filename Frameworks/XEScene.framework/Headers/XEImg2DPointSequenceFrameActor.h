/******************************************************************************

@File         XEImg2DPointSequenceFrameActor.h

@Version       1.0

@Created      2019, 3, 15

@Description  代表基于2D点序列帧（人脸关键点/身体关节点）；

@HISTORY:

******************************************************************************/
#ifndef XE_2D_POINT_SEQUENCE_FRAME_ACTOR_H
#define XE_2D_POINT_SEQUENCE_FRAME_ACTOR_H

#include "XEImg2DScreenSequenceFrameActor.h"
/*
* Note:此类Actor只能Attach到XEFaceKeyPointSocketActor和XEBodyJointSocketActor上，
* 不支持附加到其他类型Actor.
*/
class XEImg2DPointSequenceFrameActor : public XEImgSequenceFrameActorBase
{
public:
								XEImg2DPointSequenceFrameActor();
	virtual						~XEImg2DPointSequenceFrameActor();
public:
	XE_ACTOR_CAST(XEImg2DPointSequenceFrameActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEImg2DPointSequenceFrameActor)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)
	   
	virtual void                Initialize(XEWorld* pWorld)override;
//	virtual const XArray<XString>&GetParentActorTypeFilterList()const override;
public:
	static const XString ACTOR_TYPENAME;
	static const XString ACTOR_SHORT_NAME;
protected:
	static XArray<XString>		s_aFilterParentActorType;
};


#endif

