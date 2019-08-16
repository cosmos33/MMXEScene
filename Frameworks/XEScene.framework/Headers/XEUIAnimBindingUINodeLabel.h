/******************************************************************************

@File         XEUIAnimBindingUINodeLabel.h

@Version       1.0

@Created      2019,6, 11

@HISTORY:

******************************************************************************/
#ifndef XE_UIANIM_BINDING_UINODE_LABEL_H
#define XE_UIANIM_BINDING_UINODE_LABEL_H
#include "XEUIAnimBindingUINode.h"

class XEUIAnimBindingUINodeLabel : public XEUIAnimBindingUINode
{
	friend class XEUIAnimBindingUINodeLableInstance;
public:
	XEUIAnimBindingUINodeLabel();
	virtual ~XEUIAnimBindingUINodeLabel();
public:
	virtual void                 Deserialize(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL) override;
	virtual XMLElement*          Serialize(XMLElement* pEleParent) override;
public:
	XE_USER_NODE_CAST(XEUIAnimBindingUINodeLabel)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};


#endif