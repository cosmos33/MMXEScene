#ifndef _X_IMAGE_EFFECT_GRAPH_BUILDER_H_
#define _X_IMAGE_EFFECT_GRAPH_BUILDER_H_

#include "XImageEffectGraph.h"

class IXImageEffectGraphBuilder
{
public:
	virtual			~IXImageEffectGraphBuilder() {}
	virtual	void	BuildImageEffectGraph(XImageEffectGraph& Graph) = 0;
};

class XDefaultPreprocessGraphBuilder : public IXImageEffectGraphBuilder
{
public:
	virtual	void	BuildImageEffectGraph(XImageEffectGraph& Graph) override;
};

class XDefaultPostprocessGraphBuilder : public IXImageEffectGraphBuilder
{
public:
	virtual	void	BuildImageEffectGraph(XImageEffectGraph& Graph) override;
};

#endif