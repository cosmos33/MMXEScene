/******************************************************************************

@File         XEFaceKeyPointInstance.h

@Version       1.0

@Created      2019, 6, 4

@Description  FaceKeyPoint Info.

@HISTORY:

******************************************************************************/
#ifndef _XE_FACE_KEY_POINT_INFO_H
#define _XE_FACE_KEY_POINT_INFO_H

#include "XEMagicTrackingBaseInstance.h"

class XEFaceKeyPointInstance : public XEMagicTrackingBaseInstance
{
public:
	XEFaceKeyPointInstance(XEActorComponent* pComponent);
	virtual ~XEFaceKeyPointInstance();
public:
	virtual void                            RenderPivotPoint() const override;
	virtual XMLElement*                     Serialize(XMLElement* pEleParent) override;
	virtual void                            Deserialize(const XMLElement* pEleComponent, XETreeNode::Manager* pNodeMgr = NULL) override;
public:
	//获取当前添加关键点的像素中心
	virtual XVECTOR2                        GetPivotPoint() const;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet             GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif	
	//获取当前关键点的缩放因子（脸远近）
	XVECTOR3                                GetFaceScaleFactor() const;

	virtual XMATRIX4						GetWorldTransform() const override;
protected:
	virtual xbool							IsHasLandmarks() const override;
	XEFaceTrackerActor*						GetFaceTrackActor() const;
public:
	XE_USER_NODE_CAST(XEFaceKeyPointInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};


#endif//_XE_FACE_KEY_POINT_INFO_H