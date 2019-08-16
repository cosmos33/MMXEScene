/******************************************************************************

@File         XEUIAnimBindingUINode.h

@Version       1.0

@Created      2019,5, 24

@HISTORY:

******************************************************************************/
#ifndef XE_UIANIM_BINDING_UINODE_H
#define XE_UIANIM_BINDING_UINODE_H
#include "XEUIAnimBindingTransform.h"

class XEUIAnimBindingUINode
	:public XEUIAnimBindingTransform
{
	friend class XEUIAnimBindingUINodeInstance;
public:
	XEUIAnimBindingUINode();
	virtual ~XEUIAnimBindingUINode();
public:
	virtual void                 Deserialize(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL) override;
	virtual XMLElement*          Serialize(XMLElement* pEleParent) override;
	virtual XETrackBase*         SetupComponentTrack(XETreeNode::Manager* pNodeMgr);
	X_FORCEINLINE const XString& GetBindUINodeName()const{ return m_strBindUINodeName; }
	X_FORCEINLINE void           SetBindUINodeName(const XString& strName){ m_strBindUINodeName = strName; }
	X_FORCEINLINE const XString& GetBindAssetPath(){ return m_strBindAssetPath; }
	X_FORCEINLINE void           SetBindAssetPath(const XString& strAssetPath){ m_strBindAssetPath = strAssetPath; }
public:
	XE_USER_NODE_CAST(XEUIAnimBindingUINode)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	XString              m_strBindUINodeName;
	XString				 m_strBindAssetPath;
};

#endif // XE_SEQ_BINDING_ACTOR_H
