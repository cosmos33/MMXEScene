/******************************************************************************

@File         XEFaceKeyPointSocketComponent.h

@Version       1.0

@Created      2019, 6,4

@Description  基于人脸关键点挂点Actor的组件

@HISTORY:

******************************************************************************/
#ifndef XE_FACE_KEY_POINT_SOCKET_COMPONENT_H
#define XE_FACE_KEY_POINT_SOCKET_COMPONENT_H
#include "XETrackSocketComponentBase.h"

class XEFaceKeyPointSocketComponent
	: public XETrackSocketComponentBase
{
public:
	XEFaceKeyPointSocketComponent();
	virtual ~XEFaceKeyPointSocketComponent();
public:
	virtual void							Initialize(XEActor* pActor) override;
public:
	void									UpdateFaceWorldTransform(const XMATRIX4& matTran){ m_matFaceWorldTransform = matTran; }
protected:
	virtual void							UpdateTransform();
public:
	XE_COMPONENT_CAST(XEFaceKeyPointSocketComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEFaceKeyPointSocketComponent)
	static const XString COMPONENT_TYPENAME;
private:
	XMATRIX4								m_matFaceWorldTransform;
};

#endif // XE_IMG_SEGMENTATION_COMPONENT_H