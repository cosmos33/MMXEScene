/******************************************************************************

@File         XETexCustomPrimitive.h

@Version       1.0

@Created      2019, 3, 20

@Description  custom primitive .

@HISTORY:

******************************************************************************/
#ifndef _XE_TEX_CUSTOM_PRIMITIVE_H
#define _XE_TEX_CUSTOM_PRIMITIVE_H
#include "XETexMaterialRenderable.h"
#include "XGlobalFuncs.h"

class XETexCustomPrimitive : public XETexMaterialRenderable
{
public:
	XETexCustomPrimitive();
	virtual ~XETexCustomPrimitive();
public:
	X_FORCEINLINE xfloat32 GetZDelta() const{ return m_fZDelta; }
	X_FORCEINLINE void	   SetZDelta(xfloat32 fDelta){ m_fZDelta = fDelta; }
	virtual IXTexture2D*   ProvideTexture2D() override = 0;
	virtual XMATRIX4       ProvideWVPMatrix() override = 0;
	virtual xint32         ProvideRenderPrimitiveNum() override = 0;//usually is the triangle num.
	virtual IXVertexDesc*  ProvideVertexDesc() override = 0;
	virtual IXVertexBuffer*GetVB() override = 0;
	virtual IXIndexBuffer* GetIB() override = 0;
protected:
	struct Vertex
	{
		Vertex() : pos(0.0f), uv(0.0f){}
		XVECTOR3	pos;
		XVECTOR2	uv;
		void Set(xfloat32 x, xfloat32 y, xfloat32 z, xfloat32 u, xfloat32 v)
		{
			pos.Set(x, y, z);
			uv.Set(u, v);
		}
	};
	xfloat32			 m_fZDelta;//[0,1]
protected:
	static XString       s_strMaterailName;
};


#endif//_XE_TEX_CUSTOM_PRIMITIVE_H