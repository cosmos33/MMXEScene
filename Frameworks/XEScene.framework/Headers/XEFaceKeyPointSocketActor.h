/******************************************************************************

@File         XEFaceKeyPointSocketActor.h

@Version       1.0

@Created      2019, 6, 4

@Description  此类Actor是基于人脸关键点、并且可以挂载3D Actor的容器.

@HISTORY:

******************************************************************************/
#ifndef XE_MAGIC_FACE_KEY_POINTSOCKET_ACTOR_H
#define XE_MAGIC_FACE_KEY_POINTSOCKET_ACTOR_H

#include "XEMagicCoreTrackingActorBase.h"
/*
* Note:此类Actor只能Attach到XEFaceTrackerActor，不支持附加到其他类型Actor.
*/

class XEViewport;
class XEFaceKeyPointSocketActor
	:public XEMagicCoreTrackingActorBase
{
public:
	XEFaceKeyPointSocketActor();
	virtual ~XEFaceKeyPointSocketActor(){};
public:
	virtual void					Initialize(XEWorld* pWorld) override;
	virtual const XArray<XString>&	GetParentActorTypeFilterList()const override;
	virtual void                    Render(XEViewport* pViewport) override;

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet		GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
public:
	XE_ACTOR_CAST(XEFaceKeyPointSocketActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEFaceKeyPointSocketActor)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)

	static const XString	       ACTOR_TYPENAME;
	static const XString	       ACTOR_SHORT_NAME;
protected:					       
	static XArray<XString>	       s_aFilterParentActorType;
};

#endif