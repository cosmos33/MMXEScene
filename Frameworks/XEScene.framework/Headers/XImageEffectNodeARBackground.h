#ifndef _X_IMAGE_EFFECT_NODE_AR_BACKGROUND_H_
#define _X_IMAGE_EFFECT_NODE_AR_BACKGROUND_H_

#include "XImageEffectNode.h"
#include "XInternalResource.h"
#include "XImageEffectParamSet.h"

//-------------------------------------------------------------
//
//	Parameter set
//
//-------------------------------------------------------------
class XEffectARBackgroundParamSet : public XImageEffectParamSet
{
public:
	XEffectARBackgroundParamSet();

	void		SetHueAdjustment(xfloat32 fValue);
	void		SetSaturationAdjustment(xfloat32 fValue);
	void		SetLuminanceAdjustment(xfloat32 fValue);
	xfloat32	GetHueAdjustment() const;
	xfloat32	GetSaturationAdjustment() const;
	xfloat32	GetLuminanceAdjustment() const;
};


//-------------------------------------------------------------
//
//	XImageEffectNodeARBackground
//
//-------------------------------------------------------------
#define NODE_AR_BACKGROUND_TYPE_NAME "ARBackground"

class XImageEffectNodeARBackground : public XImageEffectNodeBase<1, 1>
{
public:
	static const XString					TYPE_NAME;

	struct PositionOnlyVertex
	{
		XVECTOR2 pos;
	};

public:
	// From XImageEffectNode
	virtual XRenderTargetDesc				ComputeOutputDesc(ENodeOutputId eOutputId) const override;
	virtual const xchar*					GetTypeName() { return TYPE_NAME; }
	virtual IXMaterialInstance*				GetParameterSet() override { return &m_paramSet; }
	XTypeVertexBuffer<PositionOnlyVertex>*	GetVertexBuffer() { return m_pVB; }

protected:
	XImageEffectNodeARBackground();
	virtual ~XImageEffectNodeARBackground();

protected:
	// VB, IB and vertex desc
	XTypeVertexBuffer<PositionOnlyVertex>*	m_pVB;
	XIndexBuffer16*							m_pIB;
	XVertexDesc*							m_pVertDef;

	// Parameters
	XEffectARBackgroundParamSet				m_paramSet;
};

#endif
