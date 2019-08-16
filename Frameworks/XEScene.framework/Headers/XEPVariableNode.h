/******************************************************************************

@File         XEPVariableNode.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 12:36:57

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_P_VARIABLE_NODE_H_
#define _XE_P_VARIABLE_NODE_H_
#include "XEPatchNode.h"
X_EEH_FILE//don't export for lua
class XEPVariableNode : public XEPatchNode
{

public:
	XEPVariableNode();
	virtual ~XEPVariableNode();
};
#endif // !defined(_XE_P_VARIABLE_NODE_H_)
