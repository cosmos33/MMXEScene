/******************************************************************************

@File         XEPEventNode.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:51:50

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_P_EVENT_NODE_H_
#define _XE_P_EVENT_NODE_H_
#include "XEPatchGraphNode.h"
X_EEH_FILE//don't export for lua
class XEPEventNode : public XEPatchGraphNode
{
public:
	XEPEventNode();
	virtual ~XEPEventNode();
};
#endif // !defined_XE_P_EVENT_NODE_H_
