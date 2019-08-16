#ifndef _X_IMAGE_EFFECT_NODE_SKIN_BEAUTY_H_
#define _X_IMAGE_EFFECT_NODE_SKIN_BEAUTY_H_

#include "XImageEffectNode.h"
#include "XInternalResource.h"
#include "XImageEffectParamSet.h"

//-------------------------------------------------------------
//
//	Parameter set
//
//-------------------------------------------------------------
class XEffectSkinBeautyParamSet : public XImageEffectParamSet
{
public:
	XEffectSkinBeautyParamSet();
public:
	void SetWorldMatrix(const XMATRIX4& matWorld);
	void SetTexelWidthOffset(xfloat32 fW);
	void SetTexelHeightOffset(xfloat32 fH);
	void SetToneLevel(xfloat32 fToneLevel);
	void SetBeautyLevel(xfloat32 fBeautyLevel);
	void SetBrightLevel(xfloat32 fBrightLevel);
	const XMATRIX4& GetWorldMatrix()const;
	xfloat32 GetTexelWidthOffset() const;
	xfloat32 GetTexelHeightOffset()const;
	xfloat32 GetToneLevel()const;
	xfloat32 GetBeautyLevel()const;
	xfloat32 GetBrightLevel()const;
};


//-------------------------------------------------------------
//
//	XImageEffectNodeSkinBeauty
//
//-------------------------------------------------------------
#define NODE_SKIN_BEAUTY_TYPE_NAME "SkinBeauty"

class XImageEffectNodeSkinBeauty : public XImageEffectNodeBase<1, 1>
{
public:
	static const XString TYPE_NAME;

	struct Vertex
	{
		Vertex() : pos(0.0f), uv(0.0f){}
		Vertex(xfloat32 x, xfloat32 y, xfloat32 z, xfloat32 u, xfloat32 v){ Set(x,y,z,u,v); }
		XVECTOR3   pos;
		XVECTOR2   uv;
		void Set(xfloat32 x, xfloat32 y, xfloat32 z, xfloat32 u, xfloat32 v)
		{
			pos.Set(x, y, z);
			uv.Set(u, v);
		}
	};

public:
	// From XImageEffectNode
	virtual XRenderTargetDesc				ComputeOutputDesc(ENodeOutputId eOutputId) const override;
	virtual const xchar*					GetTypeName() { return TYPE_NAME; }
	virtual IXMaterialInstance*				GetParameterSet() override { return &m_paramSet; }
	XTypeVertexBuffer<Vertex>*				GetVertexBuffer() { return m_pVB; }

protected:
	XImageEffectNodeSkinBeauty();
	virtual ~XImageEffectNodeSkinBeauty();

protected:
	// VB, IB and vertex desc
	XTypeVertexBuffer<Vertex>*				m_pVB;
	XIndexBuffer16*							m_pIB;
	XVertexDesc*							m_pVertDef;

	// Parameters
	XEffectSkinBeautyParamSet			m_paramSet;
};

#endif
