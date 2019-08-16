/******************************************************************************

@File         XETexFlexiblePrimitive.h

@Version       1.0

@Created      2019, 5, 6

@Description  ARGB-texture primitive .

@HISTORY:

******************************************************************************/
#ifndef _XE_TEX_FLEXIBLE_PRIMITIVE_H
#define _XE_TEX_FLEXIBLE_PRIMITIVE_H
#include "XGlobalFuncs.h"
#include "XETexCustomPrimitive.h"

class XETexFlexiblePrimitive 
	: public XETexCustomPrimitive
{
public:
	XETexFlexiblePrimitive(XTexFormat dataType);
	virtual ~XETexFlexiblePrimitive();
public:
	xbool		                     RebuildFlexibleTexture(const xuint8* pTexBuff, xint32 nImageWidth, xint32 nImageHeight);
	xbool		                     ClearFlexibleTextureData();
	xbool		                     UpdateFlexibleTexture2DWithData(const xuint8* pTexBuff, xint32 nImageWidth, xint32 nImageHeight, xbool bStretchImage = xfalse);
	X_FORCEINLINE XTexFormat         GetFlexibleTextureFormat()const{ return m_eTexFormat; }
	xint32                           GetChannelCount() const;
	virtual IXTexture2D*             ProvideTexture2D() override= 0;
	virtual XMATRIX4                 ProvideWVPMatrix() override = 0;
	virtual xint32                   ProvideRenderPrimitiveNum() override = 0;//usually is the triangle num.
	virtual IXVertexDesc*            ProvideVertexDesc() override = 0;
	virtual IXVertexBuffer*          GetVB() override = 0;
	virtual IXIndexBuffer*			 GetIB() override = 0;
protected:
	IXTexture2D*                     m_pFlexibleTexture2D;
	XTexFormat						 m_eTexFormat;
	static XString                   s_strTexName;
	static xint32                    s_nTexID;
};


#endif//_XE_TEX_FLEXIBLE_PRIMITIVE_H