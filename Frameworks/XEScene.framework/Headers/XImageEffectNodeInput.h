#ifndef _X_IMAGE_EFFECT_NODE_INPUT_H_
#define _X_IMAGE_EFFECT_NODE_INPUT_H_

#include "XImageEffectNode.h"
#include "IXImageEffectProcessor.h"

#define NODE_INPUT_TYPE_NAME "Input"

class XImageEffectNodeInput : public XImageEffectNodeBase<0, 1>
{
public:
	static const XString						TYPE_NAME;

public:
	virtual XRenderTargetDesc					ComputeOutputDesc(ENodeOutputId eOutputId) const override;
	virtual IXMaterialInstance*					GetParameterSet() override { return NULL; }

	void										SetInput(const IXImageEffectProcessor::ImageEffectSource& source) { m_Source = source; }

protected:
	XImageEffectNodeInput() : m_Source() {}
	virtual ~XImageEffectNodeInput() {}

protected:
	IXImageEffectProcessor::ImageEffectSource	m_Source;
};

#endif
