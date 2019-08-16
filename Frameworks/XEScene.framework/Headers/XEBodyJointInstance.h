/******************************************************************************

@File         XEBodyJointInstance.h

@Version       1.0

@Created      2019, 6, 4

@Description  FaceKeyPoint Info.

@HISTORY:

******************************************************************************/
#ifndef _XE_BODY_JOINT_INFO_H
#define _XE_BODY_JOINT_INFO_H

#include "XEMagicTrackingBaseInstance.h"

class XEBodyJointSocketActor;
class XEBodyJointInstance : public XEMagicTrackingBaseInstance
{
public:
	XEBodyJointInstance(XEActorComponent* pComponent);
	virtual ~XEBodyJointInstance();
public:
	virtual void                            RenderPivotPoint() const override;
	virtual XMLElement*                     Serialize(XMLElement* pEleParent) override;
	virtual void                            Deserialize(const XMLElement* pEleComponent, XETreeNode::Manager* pNodeMgr = NULL) override;
public:
	virtual XVECTOR2                        GetPivotPoint() const;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet             GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif	
	XVECTOR3                                GetBodyScaleFactor() const;
private:
	virtual xbool							IsHasLandmarks() const override;
	XEBodyJointSocketActor*					GetBodyJointSocketActor() const;
public:
	XE_USER_NODE_CAST(XEBodyJointInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};


#endif//_XE_FACE_KEY_POINT_INFO_H