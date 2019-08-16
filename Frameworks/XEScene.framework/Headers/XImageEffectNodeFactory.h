#ifndef _X_IMAGE_EFFECT_NODE_FACTORY_H_
#define _X_IMAGE_EFFECT_NODE_FACTORY_H_

#include "XTypes.h"

class XImageEffectNode;
class IXImageEffectNodeFactory
{
public:
	virtual ~IXImageEffectNodeFactory() {}

	virtual XImageEffectNode*	CreateImageEffectGraphNode(const xchar* szEffectName) = 0;
};

extern IXImageEffectNodeFactory* g_pIXImageEffectNodeFactory;

#endif