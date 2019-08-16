/******************************************************************************

@File         XEUIAnimBindingTransform.h

@Version       1.0

@Created      2018,2, 27

@HISTORY:

******************************************************************************/
#ifndef XE_UIANIM_BINDING_TRANSFORM_H
#define XE_UIANIM_BINDING_TRANSFORM_H
#include "XEUIAnimBinding.h"
class XETrackTransform;

class XEUIAnimBindingTransform :public XEUIAnimBinding
{
public:
	XEUIAnimBindingTransform();
	virtual ~XEUIAnimBindingTransform();
public:
	virtual void         Deserialize(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL) override;
	virtual XMLElement*  Serialize(XMLElement* pEleParent) override;
public:
	XETrackTransform*    AddTransformTrack(XETreeNode::Manager* pNodeMgr);
	XETrackTransform*    GetTransformTrack();
	void                 RemoveTransformTrack(XETreeNode::Manager* pNodeMgr);
public:
	XE_USER_NODE_CAST(XEUIAnimBindingTransform)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};




#endif