/******************************************************************************

@File         XEGraphBuilderSelector.h

@Version       1.0

@Created      2019, 6, 19

@Description  A selector which take effect from the filter-double-link-list instance.

@HISTORY:

******************************************************************************/
#ifndef _XE_SELECTOR_GRAPH_BUILDER_H
#define _XE_SELECTOR_GRAPH_BUILDER_H
#include "XEFilterUtility.h"
#include "XImageEffectGraphBuilder.h"

class XEFilterContainerInstance;
class XEFilterInstance;
class XEGraphBuilderProcess
	: public IXImageEffectGraphBuilder
{
public:
	XEGraphBuilderProcess();
	virtual ~XEGraphBuilderProcess();
public:
	virtual	void	                         BuildImageEffectGraph(XImageEffectGraph& Graph) override;
	virtual void			                 Tick(xfloat32 fTickTime);
	virtual void			                 Release();
	virtual void                             Init();
	void                                     ClearGraph();
	void                                     RebuildGraph();
	xbool                                    IsCleared()const{ return m_bCleared; }
	void                                     AcceptInstanceListFilterNode(XEFilterUtility::InstanceListFilterNode* pListFilterNode);
	XEFilterUtility::InstanceListFilterNode* GetInstanceListFilterNode() const{ return m_pInstanceListFilterNode; }
	
private:
	XImageEffectGraph*                        m_pGraph;
	xbool                                     m_bCleared;
	XEFilterUtility::InstanceListFilterNode*  m_pInstanceListFilterNode;
};


class XEFilterContainerInstance;
class XEFilterInstance;
class XEGraphBuilderSelector 
{
public:
	XEGraphBuilderSelector();
	virtual ~XEGraphBuilderSelector();
	class XEListener
	{
	public:
		XEListener(){}
		virtual ~XEListener(){}
		virtual void			   Ls_OnGraphChanged(XEFilterContainerInstance* pContainerIns){}
	};
public:
	static XEGraphBuilderSelector* GetInstance();
	xbool						   ReBuildGraphNodeFromFilterContainerIns(XEFilterContainerInstance* pContainerIns, XEFilterUtility::FilterNodeType eFilterNodeType = XEFilterUtility::FILTER_DONTCARE);//including pre-process and post-process nodes
	xbool                          ReBuildGraphNodeFromFilterIns(XEFilterInstance* pFilterIns);//single node-for update material ins.
	void                           ClearGraphNodeForFilterContainerIns(XEFilterContainerInstance* pContainerIns = NULL, XEFilterUtility::FilterNodeType eFilterNodeType = XEFilterUtility::FILTER_DONTCARE);
	void                           SetGraphBuilderRefListNode(XEFilterUtility::InstanceListFilterNode* pPreListNode, XEFilterUtility::InstanceListFilterNode* pPostListNode);//update and set

	void						   AddListener(XEListener* pListener);
	void						   RemoveListener(XEListener* pListener);

protected:
	void						   GraphChanged(XEFilterContainerInstance* pContainerIns);
protected:
	XArray<XEListener*>			   m_aListeners;
};

#endif//_XE_SELECTOR_GRAPH_BUILDER_H