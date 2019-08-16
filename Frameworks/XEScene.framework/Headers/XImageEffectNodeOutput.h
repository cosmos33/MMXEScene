#ifndef _X_IMAGE_EFFECT_NODE_OUTPUT_H_
#define _X_IMAGE_EFFECT_NODE_OUTPUT_H_

#include "XImageEffectNode.h"

#define NODE_OUTPUT_TYPE_NAME "Output"

class XImageEffectNodeOutput : public XImageEffectNodeBase<1, 1>
{
public:
	static const XString			TYPE_NAME;

public:
	virtual XRenderTargetDesc		ComputeOutputDesc(ENodeOutputId eOutputId) const override;
	virtual IXMaterialInstance*		GetParameterSet() { return NULL; }

	void							SetOutput(xint32 nFrameBufferId, xint32 nWidth, xint32 nHeight);

protected:
	XImageEffectNodeOutput() : m_nFrameBufferId(-1), m_nWidth(0), m_nHeight(0) {}
	virtual ~XImageEffectNodeOutput() {}

protected:
	xint32							m_nFrameBufferId;
	xint32							m_nWidth;
	xint32							m_nHeight;
};

#endif
