/******************************************************************************

@File         XEImg2DPointSequenceFrameComponent.h

@Version       1.0

@Created      2019, 3, 15

@Description  代表基于2D点序列帧（人脸关键点/身体关节点）；

@HISTORY:

******************************************************************************/
#ifndef _XE_IMG_2D_POINT_SEQUENCE_FRAME_COMPONENT_H_
#define _XE_IMG_2D_POINT_SEQUENCE_FRAME_COMPONENT_H_

#include "XEImgSequenceFrameComponent.h"
#include "XEMagicTrackingBaseInstance.h"

class XEImg2DPointSequenceFrameComponent : public XEImgSequenceFrameComponent
{
public:
	XE_COMPONENT_CAST(XEImg2DPointSequenceFrameComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEImg2DPointSequenceFrameComponent)
											XEImg2DPointSequenceFrameComponent();
	virtual									~XEImg2DPointSequenceFrameComponent();
public:
	virtual void							Initialize(XEActor* pActor) override;
	virtual void                            Empty() override;
	virtual XMLElement*						Serialize(XMLElement* pEleParent) override;
	virtual void							Deserialize(const XMLElement* pEleComponent) override;
	virtual void							Tick(xfloat32 fDel, xbool bForceTick = xtrue) override;
	virtual void							Render(XEViewport* pViewport) override;
	virtual void                            UpdateScreenShape() override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void                            GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
	XVECTOR2								GetPixelLocation();
	void									SetPixelLocation(const XVECTOR2& vPixelLoc);
#endif
protected:
	//Override this method for custom behavior.
 	virtual xbool                           ApplyWorldTransformImpl(const XMATRIX4& mat) override;
 	virtual xbool                           MoveComponentImpl(const XVECTOR3& vNewWorldLocation, const XQUATERNION& qNewWorldQuaternion) override;
	virtual void							UpdateSizeWithScaleMode(const XVECTOR2& vRefDeviceSize, const XVECTOR2& vNewDeviceSize, XVECTOR2& vPixelCenter, XVECTOR2& vDesignSize);
 	virtual void							UpdateWorldShapeVers(xint32 nPixelCenterX, xint32 nPixelCenterY, xint32 nPixelWidth, xint32 nPixelHeight);
protected:
	virtual void						    UpdateHiddenStatus();
	XMATRIX4								EliminateTranslateFromParentActor();
public:
	static const XString					COMPONENT_TYPENAME;
private:
	xbool                                   m_nAutoPlayCount;
	XMATRIX4								m_matRealWorldTransform;
};

#endif//_XE_IMG_2D_POINT_SEQUENCE_FRAME_COMPONENT_H_

