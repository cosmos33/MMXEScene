/******************************************************************************

@File         XETexSegmentationMask.h

@Version       1.0

@Created      2019, 3, 20

@Description  segmentation mask base class.

@HISTORY:

******************************************************************************/
#ifndef _XE_TEX_SEGMENTATION_MASK_H
#define _XE_TEX_SEGMENTATION_MASK_H
#include "XETexFlexiblePrimitive.h"
#include "XEMagicCore.h"
#include "XBase3DTypes.h"

class IXTexture2D;
class XETexSegmentationMask 
	: public XEMagicCore::FxListener
	, public XETexFlexiblePrimitive
{
public:
	XETexSegmentationMask();
	virtual ~XETexSegmentationMask();
	enum eBlendMaskOption
	{ 
		BMO_NOT_SET		=				 0,
		BMO_BLEND_COLOR =				 1 << 0,
		BMO_BLEND_DIFFUSE_TEXTURE =		 1 << 1,//enable blend diffuse texture
		BMO_BLEND_MASK_TEXTURE_INVERSE = 1 << 2,//inverse mask-texture
		BMO_BLEND_MASK_TEXTURE_ENABLE =	 1 << 3,
		BMO_BLEND_MASK_TEXTURE_U_FLIP =	 1 << 4,//flip u for mask-texture.
		BMO_BLEND_MASK_TEXTURE_V_FLIP =	 1 << 5,//flip v for mask-texture.
		BMO_BLEND_MASK_IN_TEXTURE_SPACE= 1 << 6 //indicate whether the mask texture is in the same texture space with the diffuse one.
	};
public:	
	void						  SetBlendColorEnable(xbool bEnable);
	void						  SetBlendDiffuseTextureEnable(xbool bEnable);
	void						  SetBlendMaskTextureVFlip(xbool bSet); 
	void						  SetBlendMaskInTextureSpace(xbool bSet);
	void				          SetBlendMaskTextureInverse(xbool bInverse);
	void                          SetBlendMaskTextureEnable(xbool bEnable);
	void						  SetBlendMaskTextureUFlip(xbool bSet);
	virtual IXTexture2D*          ProvideTexture2D() override = 0;
	virtual XMATRIX4              ProvideWVPMatrix() override = 0;
	virtual xint32                ProvideRenderPrimitiveNum() override = 0;//usually is the triangle num.
	virtual IXVertexDesc*         ProvideVertexDesc() override = 0;
	virtual IXVertexBuffer*       GetVB() override = 0;
	virtual IXIndexBuffer*		  GetIB() override = 0;
	X_FORCEINLINE xuint8          GetBlendOptions()const{ return m_nBlendMaskOption; }
	X_FORCEINLINE xbool           IsBlendColorEnable()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_COLOR); }
	X_FORCEINLINE xbool           IsBlendDiffuseTextureEnable()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_DIFFUSE_TEXTURE); }
	X_FORCEINLINE xbool           IsBlendMaskTextureInverse()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_MASK_TEXTURE_INVERSE); }
	X_FORCEINLINE xbool           IsBlendMaskTextureEnable()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_MASK_TEXTURE_ENABLE); }
	X_FORCEINLINE xbool           IsBlendMaskTextureUFlip()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_MASK_TEXTURE_U_FLIP); }
	X_FORCEINLINE xbool           IsBlendMaskTextureVFlip()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_MASK_TEXTURE_V_FLIP); }
	X_FORCEINLINE xbool           IsBlendMaskInTextureSpace()const{ return 0 != (m_nBlendMaskOption&BMO_BLEND_MASK_IN_TEXTURE_SPACE); }
	X_FORCEINLINE void            SetBlendMaskTextureRect(const XVECTOR4& vMaskRect){ m_vMaskTextureRect = vMaskRect; }
	X_FORCEINLINE const XVECTOR4& GetBlendMaskTextureRect()const { return m_vMaskTextureRect; }
protected:
	virtual void		          OnSegmentationProcessed(XEDecorationEnvBridgeBase* pEnvBridge) override;
	virtual xbool                 SetupMaterialParameter() override;
public:
	xbool		                  RebuildMaskTexture(XEDecorationEnvBridgeBase* pEnvBridge);//mask data(alpha channel only)
protected:
	xuint8                        m_nBlendMaskOption;
	XVECTOR4                      m_vMaskTextureRect;
	static XString                s_strMaskShadeMacroName;
	static XString                s_strReverseMacroName;
};


#endif//_XE_TEX_SEGMENTATION_MASK_H