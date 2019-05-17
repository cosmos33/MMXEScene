/******************************************************************************

@File         XEImgSequenceFrameComponent.h

@Version       1.0

@Created      2019, 3, 15

@Description  序列帧动画

@HISTORY:

******************************************************************************/

#ifndef _XE_IMG_SEQUENCE_FRAME_COMPONENT_H_
#define _XE_IMG_SEQUENCE_FRAME_COMPONENT_H_

#include "XEImgSegmentationComponent.h"
#include "XEMagicCoreUtility.h"
#include "XTexture.h"

#define USE_FLEXIBILITY 0

class XViewport;
class XE2DSeqFramePlayListController;
class XE2DSequenceFrameAnimController;
class XEImgSequenceFrameComponent : public XEImgSegmentationComponent
{
public:
	XE_COMPONENT_CAST(XEImgSequenceFrameComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
											XEImgSequenceFrameComponent();
	virtual									~XEImgSequenceFrameComponent();
public:
	virtual void							Initialize(XEActor* pActor) override;
	virtual void                            Empty() override;
	virtual XMLElement*						Serialize(XMLElement* pEleParent) override;
	virtual void							Deserialize(const XMLElement* pEleComponent) override;
	virtual void							Tick(xfloat32 fDel, xbool bForceTick = xtrue) override;
	virtual void							Render(XEViewport* pViewport) override;
	virtual xbool                           RayPick(XEHitResult& hr) override;
public:
	XE2DSeqFramePlayListController*			Assign2DSequenceFrameAnimPlayListController();////to assign an animation, if it was not exist yet.
	XE2DSeqFramePlayListController*			Get2DSequenceFrameAnimPlayListController() const{ return m_p2DSequenceFrameAnimPlayList; }
	void									Remove2DSequenceFrameAnimPlayListController();
	void								    SetTime(xint32 nTime);//in micro seconds. Play calling or manually calling...
	IXTexture*								GetCurrentRenderTexture(){ return m_pCurRenderTex; }
	XVECTOR2                                GetVertexScreenPos(xint32 nVertexIndex);

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void                            GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif

#if USE_FLEXIBILITY
		//序列帧拉伸方式：横向拉伸、纵向拉伸
	enum EFlexibilityType
	{
		EFT_NONE = 1 << 0,
		EFT_HORIZONTAL = 1 << 1,
		EFT_VERTICAL = 1 << 2,
		EFT_NUM = 1 << 3
	};
	void									SetFlexibilityType(EFlexibilityType eType){ m_eFlexibilityType = eType; }
	EFlexibilityType						GetFlexibilityType() const{ return m_eFlexibilityType; }
	xbool									IsHorizontalFlexiblity() const;
	xbool									IsVerticalFlexiblity() const;
#else
	//缩放模式
	enum EScaleMode
	{
		EFM_FIXED_SIZE,//固定序列帧尺寸不变
		EFM_FIXED_SIZE_RATIO_FIT,//锁定序列帧的宽高比，边界留边
		EFM_STRETCH,//保持序列帧尺寸与父窗口的尺寸的比值不变，即序列帧的宽（高）与父窗口的宽（高）比值固定
		EFM_NUM
	};

	void								    SetScaleMode(EScaleMode eScaleMode);
	EScaleMode								GetScaleMode(){ return m_eScaleMode; }
	const XArray<XString>&					GetAllScaleModeName();
	EScaleMode								GetScaleModeByName(const XString& strScaleModeName);
#endif
public:
	virtual  void							SetRotateScreen(const xfloat32& fRotate);
	virtual  xfloat32						GetRotateScreen() const;//角度
	virtual  void							SetScaleScreen(const XVECTOR2& vScale);
	virtual  XVECTOR2						GetScaleScreen() const;
	virtual  void						    SetLocationScreen(const XVECTOR2& vLoc);
	virtual  XVECTOR2					    GetLocationScreen() const{ return m_vPixelCenter; }
	virtual  void                           SetDesignSize(const XVECTOR2& vSize){ m_vDesignSize = vSize; }
	virtual  XVECTOR2                       GetDesignSize() const{return m_vDesignSize; }
	virtual void                            UpdateScreenShape();
	virtual void                            UpdateDeviceWidthHeight(xfloat32 fWidth, xfloat32 fHeight);

protected:
	void									AutoPlay();//根据设置自动播放
#if USE_FLEXIBILITY
#else
	virtual void							UpdateSizeWithScaleMode(const XVECTOR2& vRefDeviceSize,const XVECTOR2& vNewDeviceSize, XVECTOR2& vPixelCenter, XVECTOR2& vDesignSize);
#endif
protected:
	virtual IXTexture2D*					ProvideTexture2D() override;
	virtual IXVertexDesc*                   ProvideVertexDesc() override;
	virtual IXVertexBuffer*                 GetVB() override;
	virtual	void							SerializeTransform(XMLElement* pEleComponent)override;
	virtual void							DeserializeTransform(const XMLElement* pEleComponent)override;
private:
	xbool									LoadAsset(const xchar* pTexPath);
	void									Serialize2DSequenceFrameAnimList(XMLElement* pEleParent);
	void									Deserialize2DSequenceFrameAnimList(const XMLElement* pEleParent);
	void									UpdateTexture();
	
protected:
	void									UpdateWorldShapeVers(xint32 nPixelCenterX, xint32 nPixelCenterY, xint32 nPixelWidth, xint32 nPixelHeight);//更新世界坐标系下的矩形四个顶点坐标，根据当前一个中心点屏幕坐标和指定屏幕宽高，主动调用 
	virtual XMATRIX4						GetShapeTransform() const ;
public:
	static const XString					COMPONENT_TYPENAME;
protected:
	XVECTOR3*								m_pVertLocation;
	XE2DSeqFramePlayListController*			m_p2DSequenceFrameAnimPlayList;
	XVECTOR2                                m_vDesignSize;
	XVECTOR2                                m_vPixelCenter;
	XVECTOR2                                m_vRefDeviceWidthHeight;//参照设备宽高

#if USE_FLEXIBILITY
	EFlexibilityType						m_eFlexibilityType;//影响尺寸和中心点
#else
	EScaleMode								m_eScaleMode;//缩放模式
#endif	
private:
	IXTexture2D*							m_pCurRenderTex;
	XVECTOR2*								m_pTexcoord;
	XString									m_strCurRenderTexturePath;
};

#endif//_XE_IMG_SEQUENCE_FRAME_COMPONENT_H_
