/******************************************************************************

@File         XEImg2DFaceKeyPointSequenceFrameComponent.h

@Version       1.0

@Created      2019, 3, 15

@Description  基于人脸关键点的序列帧

@HISTORY:

******************************************************************************/
#ifndef _XE_IMG_2D_FACE_KEY_POINT_SEQUENCE_FRAME_COMPONENT_H_
#define _XE_IMG_2D_FACE_KEY_POINT_SEQUENCE_FRAME_COMPONENT_H_

#include "XEImgSequenceFrameComponent.h"
#include "XEFaceKeyPointInstance.h"

class XEImg2DFaceKeyPointSequenceFrameComponent : public XEImgSequenceFrameComponent
{
public:
	XE_COMPONENT_CAST(XEImg2DFaceKeyPointSequenceFrameComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEImg2DFaceKeyPointSequenceFrameComponent)
											XEImg2DFaceKeyPointSequenceFrameComponent();
	virtual									~XEImg2DFaceKeyPointSequenceFrameComponent();
public:
	virtual void							Initialize(XEActor* pActor) override;
	virtual void                            Empty() override;
	virtual XMLElement*						Serialize(XMLElement* pEleParent) override;
	virtual void							Deserialize(const XMLElement* pEleComponent) override;
	virtual void							Tick(xfloat32 fDel, xbool bForceTick = xtrue) override;
	virtual void							Render(XEViewport* pViewport) override;
	virtual void                            UpdateDeviceWidthHeight(xfloat32 fWidth, xfloat32 fHeight)override;
public:
	//获取所依赖的所有人脸关键点索引
	const XArray<xint32>&					GetAllKeyPointIndex();
	//添加一个关键点索引，nFaceKeyPointIndex表示人脸关键点索引
	void									AddKeyPointIndex(xint32 nFaceKeyPointIndex);
	//更新索引列表中的索引
	void									SetKeyPointIndex(xint32 nIndex,xint32 nFaceKeyPointIndex);
	//nIndex表示人脸关键点索引在m_aIndex列表中的index
	xbool									RemoveKeyPointIndex(xint32 nIndex);
	//获取当前添加关键点的像素中心
	virtual XVECTOR2                        GetPivotPoint() const;
	//获取当前关键点的缩放因子（脸远近）
	XVECTOR3                                GetFaceScaleFactor() const;
	void									SetShowPivotPoint(xbool bShow);
	xbool									IsShowPivotPoint()const;
	virtual void                            UpdateScreenShape() override;
	XEFaceKeyPointInstance*					GetFaceKeyPointInfo(){ return m_pKeyPointInfo; }
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void                            GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
	XVECTOR2								GetPixelLocation();
	void									SetPixelLocation(const XVECTOR2& vPixelLoc);
#endif
protected:
	//Override this method for custom behavior.
	virtual xbool                           ApplyWorldTransformImpl(const XMATRIX4& mat) override;
	virtual xbool                           MoveComponentImpl(const XVECTOR3& vNewWorldLocation, const XQUATERNION& qNewWorldQuaternion) override;
	virtual XMATRIX4						GetRawWorldTransformImpl() const override;
	virtual void							UpdateSizeWithScaleMode(const XVECTOR2& vRefDeviceSize, const XVECTOR2& vNewDeviceSize, XVECTOR2& vPixelCenter, XVECTOR2& vDesignSize);
	XMATRIX4								GetRotateFaceWorld() const;
private:
	void									UpdateHiddenStatus();
	void                                    UpdateTransform();
	XEFaceTrackerActor*						GetFaceTrackActor() const;
public:
	static const XString					COMPONENT_TYPENAME;
private:
	xbool                                   m_nAutoPlayCount;
	XMATRIX4								m_matRealWorldTransform;
	XEFaceKeyPointInstance*					m_pKeyPointInfo;
};

#endif//_XE_IMG_2D_FACE_KEY_POINT_SEQUENCE_FRAME_COMPONENT_H_

