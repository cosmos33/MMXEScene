/******************************************************************************

@File         XEImgSegmentationActor.h

@Version       1.0

@Created     2019,3,21

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE_IMG_SEGMENTATION_ACTOR_H
#define XE_IMG_SEGMENTATION_ACTOR_H
#include "XEMagicCoreActorBase.h"

class XEViewport;
class XEImgSegmentationActor 
	:public XEMagicCoreActorBase
{
public:
	XEImgSegmentationActor();
	~XEImgSegmentationActor(){};
public:
	virtual void			Initialize(XEWorld* pWorld) override;
	X_EES_LINE virtual void PostInitialized() override;//you may do something else later in this function. Elements in Array were ready.
	virtual xfloat32        GetRenderOrderFactor()const override;
public:
	XE_ACTOR_CAST(XEImgSegmentationActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEImgSegmentationActor)
	   
	static const XString	ACTOR_TYPENAME;
};

#endif // XE_IMG_SEGMENTATION_ACTOR_H
