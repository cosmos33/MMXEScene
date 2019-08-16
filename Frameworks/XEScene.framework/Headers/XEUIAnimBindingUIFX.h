/******************************************************************************

@File         XEUIAnimBindingUIFX.h

@Version       1.0

@Created      2019,6, 14

@HISTORY:

******************************************************************************/
#ifndef XE_UIANIM_BINDING_UINODE_UIFX_H
#define XE_UIANIM_BINDING_UINODE_UIFX_H
#include "XEUIAnimBindingUINode.h"

class XEUIAnimBindingUIFX : public XEUIAnimBindingUINode
{
	friend class XEUIAnimBindingUINodeLableInstance;
public:
	XEUIAnimBindingUIFX();
	virtual ~XEUIAnimBindingUIFX();
public:
	virtual void                 Deserialize(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL) override;
	virtual XMLElement*          Serialize(XMLElement* pEleParent) override;
public:
	XE_USER_NODE_CAST(XEUIAnimBindingUIFX)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};


#endif