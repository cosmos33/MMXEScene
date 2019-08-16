/******************************************************************************

@File         XEPCallFunctionNode.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:51:09

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PCALL_FUNCTION_NODE_H_
#define _XE_PCALL_FUNCTION_NODE_H_

#include "XEPatchNode.h"
X_EEH_FILE//don't export for lua

class XEPCallFunctionNode : public XEPatchNode
{
public:
	XEPCallFunctionNode();
	virtual ~XEPCallFunctionNode();
};
#endif // !defined_XE_PCALL_FUNCTION_NODE_H_
