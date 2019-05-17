/******************************************************************************

@File         XEImg2DScreenSequenceFrameComponent.h

@Version       1.0

@Created      2019, 3, 15

@Description  基于屏幕的序列帧

@HISTORY:

******************************************************************************/

#ifndef _XE_IMG_2D_SCREEN_SEQUENCE_FRAME_COMPONENT_H_
#define _XE_IMG_2D_SCREEN_SEQUENCE_FRAME_COMPONENT_H_

#include "XEImgSequenceFrameComponent.h"
#include "XEMagicCoreUtility.h"

class XEImg2DScreenSequenceFrameComponent : public XEImgSequenceFrameComponent
{
public:
	XE_COMPONENT_CAST(XEImg2DScreenSequenceFrameComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEImg2DScreenSequenceFrameComponent)
											XEImg2DScreenSequenceFrameComponent();
	virtual									~XEImg2DScreenSequenceFrameComponent();
public:								
	virtual void							Initialize(XEActor* pWorld) override;
	virtual XMLElement*						Serialize(XMLElement* pEleParent) override;
	virtual void							Deserialize(const XMLElement* pEleComponent) override;
	virtual void							Tick(xfloat32 fDel, xbool bForceTick = xtrue) override;
	virtual void							Render(XEViewport* pViewport) override;
	virtual void                            Empty() override;
	virtual void							SetLocationScreen(const XVECTOR2& vLoc) override;
	virtual void                            UpdateScreenShape() override;
public:
	//屏幕序列帧的横向布局方式：左中右
	enum EHorizontalAlignmentType
	{
		EHAT_NONE,
		EHAT_LEFT,
		EHAT_CENTER,
		EHAT_RIGHT,
		EHAT_NUM
	};
	//屏幕序列帧的纵向布局方式：上中下
	enum EVerticalAlignmentType
	{
		EVAT_NONE,
		EVAT_TOP,
		EVAT_CENTER,
		EVAT_BOTTOM,
		EVAT_NUM
	};

	//pinning
	enum EPinningType
	{
		EPT_NONE = 1 << 0,
		EPT_LEFT = 1 << 1,
		EPT_RIGHT = 1 << 2,
		EPT_TOP = 1 << 3,
		EPT_BOTTOM = 1 << 4,
		EPT_NUM = 1 << 5
	};

	//设置对齐类型
	void									SetHorizontalAlignmentType(EHorizontalAlignmentType eType);
	void									SetVerticalAlignmentType(EVerticalAlignmentType eType);
	void                                    StrechToParent();

	void									SetPinningType(EPinningType eType);
	EPinningType							GetPinningType(){ return m_ePinningType; }
	xbool									IsPinningLeft();
	xbool									IsPinningRight();
	xbool									IsPinningTop();
	xbool									IsPinningBottom();
	xfloat32								GetDisToLeftEdge(){ return m_vDisToEdge.x; }
	xfloat32								GetDisToRightEdge(){ return m_vDisToEdge.y; }
	xfloat32								GetDisToTopEdge(){ return m_vDisToEdge.z; }
	xfloat32								GetDisToBottomEdge(){ return m_vDisToEdge.w; }

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void							GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif
protected:
	virtual xbool                           MoveComponentImpl(const XVECTOR3& vNewWorldLocation, const XQUATERNION& qNewWorldQuaternion) override;
	virtual xbool                           ApplyWorldTransformImpl(const XMATRIX4& mat) override;
private:
	void									UpdateDisToEdge();
public:
	static const XString					COMPONENT_TYPENAME;
protected:
	//delay loading...
	class DelayLoadTemproalObject :public XEUtility::XETemporalObject
	{
	public:
		DelayLoadTemproalObject() :m_pComponent(NULL){}
		virtual ~DelayLoadTemproalObject(){}
		//functions that should be override.
		virtual xbool ShouldBeDeleted()override;
		virtual void  Release()override{}
	public:
		XEImg2DScreenSequenceFrameComponent* m_pComponent;
	};
private:
	EPinningType							m_ePinningType;//影响边界距离
	XVECTOR4								m_vDisToEdge;//到边界的距离(xyzw分别代表左右上下)
};

#endif//_XE_IMG_2D_SCREEN_SEQUENCE_FRAME_COMPONENT_H_

