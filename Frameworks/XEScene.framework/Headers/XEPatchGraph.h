/******************************************************************************

@File         XEPatchGraph.h

@Version       1.0

@Created      2019.5.27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_PATCH_GRAPH_H_
#define _XE_PATCH_GRAPH_H_
#include "XTypes.h"
#include "XArray.h"
#include "XMath3D.h"
#include "tinyxml2_XEngine.h"
#include "XClass.h"
X_EEH_FILE//don't export to lua
class XEPatchGraphStateMachine;
class XEPatchGraphNode;
class XEPGraphSchema;

class XEPatchGraph
{
public:
	enum Type
	{
		Graph,
		Subgraph,
		Function,
		Interface,
		Macro,
		MAX
	};

	XEPatchGraph();
	virtual ~XEPatchGraph();
	/**
	 * If true, graph can be deleted from the whatever container it is in. For
	 * FunctionGraphs this flag is reset to false on load (unless the function is the
	 * construction script or AnimGraph)
	 */
	xbool m_bAllowDeletion;
	/**
	 * If true, graph can be renamed; Note: Graph can also be renamed if
	 * bAllowDeletion is true currently
	 */
	xbool m_bAllowRenaming;
	/**
	 * If true, graph can be edited by the user
	 */
	xbool m_bEditable;
	/**
	 * snow flake id for this graph
	 */
	xint64 m_nGraphid;
	/**
	 * Set of all nodes in this graph
	 */
	XArray<XEPatchGraphNode*> m_aNodes;
	/**
	 * The schema that this graph obeys
	 */
	XEPGraphSchema* m_pSchema;

	/**
	 * Child graphs that are a part of this graph; the separation is purely visual
	 */
	XArray<XEPatchGraph*> m_aSubGraphs;

	/**
	 * State machine for patch graph.
	 */
	XEPatchGraphStateMachine* m_pPatchGraphStateMachine;
public:
	virtual void		  Serialize(tinyxml2_XEngine::XMLElement* pEleParent);
	void                  AddNode(XEPatchGraphNode* pNodeToAdd, xbool bUserAction = xfalse, xbool bSelectNewNode = xtrue);
	void                  GetAllChildrenGraphs(XArray<XEPatchGraph*>& aGraphs) const;
	const XEPGraphSchema* GetSchema() const;
	bool				  RemoveNode(XEPatchGraphNode* pNodeToRemove);
	XVECTOR2			  GetGoodPlaceForNewNode();
	
};
#endif // _XE_PATCH_GRAPH_H_
