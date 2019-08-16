/******************************************************************************

@File         XEUIAnimBinding.h

@Version       1.0

@Created      2019,5, 24

@HISTORY:

******************************************************************************/
#ifndef XE_UIANIM_BINDING_H
#define XE_UIANIM_BINDING_H
#include "XEUIAnimBase.h"
class XETrackBase;
class XEUIAnimation;
class XEUIAnimBinding :public XEUIAnimBase
{
public:
	XEUIAnimBinding();
	virtual ~XEUIAnimBinding();
public:
	virtual void         Deserialize(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL) override;
	virtual XMLElement*  Serialize(XMLElement* pEleParent) override;
public:
	XETrackBase*         CreateTrack(const XString& szTrackType, XETreeNode::Manager* pNodeMgr);
public:
	XE_USER_NODE_CAST(XEUIAnimBinding)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};

#endif // XE_SEQ_BINDING_H