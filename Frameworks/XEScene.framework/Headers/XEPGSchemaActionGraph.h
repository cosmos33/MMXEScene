/******************************************************************************

@File         XEPGSchemaActionGraph.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:53:25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_P_SCHEMA_ACTION_GRAPH_H_
#define _XE_P_SCHEMA_ACTION_GRAPH_H_

#include "XEPatchGraph.h"
#include "XEPGraphSchema.h"

X_EEH_FILE//don't export for lua

/**
 * Reference to a function, macro, event graph, or timeline (only used in 'docked'
 * palette)
 */
struct XEPGSchemaActionGraph
{

public:
	/**
	 * The associated editor graph for this schema
	 */
	XEPatchGraph* m_pPatchGraph;
	/**
	 * Name of function or class
	 */
	XString m_strFuncName;
	/**
	 * The type of graph that action is
	 */
	XEPatchGraph::Type m_eGraphType;

	XEPGSchemaActionGraph()
	{

	}
};
#endif // !defined(_XE_P_SCHEMA_ACTION_GRAPH_H_)
