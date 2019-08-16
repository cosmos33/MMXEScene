/******************************************************************************

@File        XEUIAnimBindingUINodeInstance.h

@Version       1.0

@Created      2018,5, 3

@HISTORY:

******************************************************************************/
#ifndef _XE_UIANIM_BINDING_UINODE_INSTANCE_H
#define _XE_UIANIM_BINDING_UINODE_INSTANCE_H
#include "XEUIAnimBase.h"
#include "XETransform.h"

class XUINode;
class XEUIAnimBindingUINode;
class XEUIAnimBindingUINodeInstance
	:public XEUIAnimBaseInstance
{
public:
	XEUIAnimBindingUINodeInstance(XEUIAnimBindingUINode* pNodeTl);
	virtual ~XEUIAnimBindingUINodeInstance();
public:
	virtual void			SetTime(xint32 nMicrosecond) override;//in microsecond.
	virtual void			Apply() override;
	virtual xbool			AcceptUINode(XUINode* pUINode);
	XUINode*				GetAcceptUINode(){ return m_pUINode; }
	XEUIAnimBindingUINode*  GetUIAnimBindingUINodeTemplate();
protected:
	//virtual void		 SetActorTemplateAssetPath(XEUIAnimBindingUINode* pBindingActorTemplate, XEActor* pActor);
protected:
	XUINode*             m_pUINode;
public:
	XE_USER_NODE_CAST(XEUIAnimBindingUINodeInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;

};

#endif // _XE_SEQ_BINDING_ACTOR_INSTANCE_H
