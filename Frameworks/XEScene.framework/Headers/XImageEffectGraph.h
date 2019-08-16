#ifndef _X_IMAGE_EFFECT_GRAPH_H_
#define _X_IMAGE_EFFECT_GRAPH_H_

#include "XArray.h"
#include "XImageEffectNode.h"

class XImageEffectNodeInput;
class XImageEffectNodeOutput;
class XImageEffectGraph
{
public:
	XImageEffectGraph();
	~XImageEffectGraph();

	XImageEffectNode*			RegisterNode(XImageEffectNode* pNode);

	void						SetFinalOutput(const XImageEffectOutputRef& finalOutput) { m_FinalOutput = finalOutput; }

	void						Process();

	void						Clear();

private:
	void						RecursivelyGatherDependencies(XImageEffectNode* pNode);
	void						RecursivelyProcess(XImageEffectNode* pNode);

	XArray<XImageEffectNode*>	m_aNodes;
	XImageEffectOutputRef		m_FinalOutput;

	XImageEffectNodeInput*		m_pNodeInput;
	XImageEffectNodeOutput*		m_pNodeOutput;

	friend class XImageEffectProcessor;
};

#endif
