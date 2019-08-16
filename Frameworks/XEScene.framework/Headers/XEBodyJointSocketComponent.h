/******************************************************************************

@File         XEBodyJointSocketComponent.h

@Version       1.0

@Created      2019, 6,4

@Description  基于身体关节点挂点Actor的组件

@HISTORY:

******************************************************************************/
#ifndef XE_BODY_KEY_POINT_SOCKET_COMPONENT_H
#define XE_BODY_KEY_POINT_SOCKET_COMPONENT_H
#include "XETrackSocketComponentBase.h"

class XEBodyJointSocketComponent
	: public XETrackSocketComponentBase
{
public:
	XEBodyJointSocketComponent();
	virtual ~XEBodyJointSocketComponent();
public:
	virtual void							Initialize(XEActor* pActor) override;
protected:
	virtual void							UpdateTransform();
public:
	XE_COMPONENT_CAST(XEBodyJointSocketComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEBodyJointSocketComponent)
	static const XString COMPONENT_TYPENAME;
};

#endif // XE_IMG_SEGMENTATION_COMPONENT_H