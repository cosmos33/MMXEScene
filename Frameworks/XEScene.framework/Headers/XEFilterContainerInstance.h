/******************************************************************************

@File         XEFilterContainerInstance.h

@Version       1.0

@Created      2019,6, 22

@HISTORY:

******************************************************************************/
#ifndef _XE_FILTER_CONTAINER_INSTANCE_H_
#define _XE_FILTER_CONTAINER_INSTANCE_H_
#include "XEFilterInstance.h"
#include "XEFilterUtility.h"

class XEFilterContainer;
class XEActor;
class XEFilterContainerInstance 
	: public XEUserNodeInstance
{
public:
	XEFilterContainerInstance(XEFilterContainer* pNodeTl);
	virtual ~XEFilterContainerInstance();
public:
	virtual void                                  Release() override;
	virtual Manager*                              GetNodeManager() override { return m_pNodeManager; }
	virtual void                                  Apply() override;

	XEFilterContainer*                            GetFilterContainerTemplate();
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
    void                                          PrepareMaterialInstanceParamToSave();
public:
	void                                          AcceptHolder(XEActor* pActor);
	X_FORCEINLINE XEActor*                        GetHolder(){ return m_pActorHolder; }
	void                                          AcceptWorld(XEWorld* pWorld);// set to node manager
	XEWorld*                                      GetWorld();// comes from node manager
public:
	XEFilterUtility::InstanceListFilterNode*      GetPreprocessFilterListNodeHead();
	XEFilterUtility::InstanceListFilterNode*      GetPreprocessFilterListNodeTail();//traditional tail(by adding order)
	XEFilterUtility::InstanceListFilterNode*      GetPostprocessFilterListNodeHead();
	XEFilterUtility::InstanceListFilterNode*      GetPostprocessFilterListNodeTail();//traditional tail(by adding order)
	XEFilterUtility::InstanceListFilterNode*      GetFilterListNode(XEFilterInstance* pNodeIns);
	XEFilterUtility::InstanceListFilterNode*      AddToEnd(XEFilterInstance* pNodeIns);
	XEFilterUtility::InstanceListFilterNode*      AddToFront(XEFilterInstance* pNodeIns);
	XEFilterUtility::InstanceListFilterNode*      InsertAfter(XEFilterInstance* pNodeInsRef, XEFilterInstance* pNodeInsToInsert);
	XEFilterUtility::InstanceListFilterNode*      InsertBefore(XEFilterInstance* pNodeInsRef, XEFilterInstance* pNodeInsToInsert);
	xbool                                         SwapNode(XEFilterInstance* pNodeIns1, XEFilterInstance* pNodeIns2, xbool bSwapTemplate = xtrue);
	xbool                                         CanSwap(XEFilterInstance* pNodeIns1, XEFilterInstance* pNodeIns2);
	xbool                                         IsClockwise(XEFilterInstance* pNodeIns1, XEFilterInstance* pNodeIns2);
	xbool                                         RemoveNode(XEFilterInstance* pNodeIns, xbool bRemoveTemplate = xtrue);
	void                                          ReBuildFilterDoubleLinkList();//by tree-node order.
	void                                          ReBuildTreeNode(xbool bRebuildTemplate = xtrue);//by filter double link list
	void										  GetBindNodeIns(XETreeNode::NodeList& nl) ;
public:
	static XEFilterContainerInstance*             CreateFilterContainerInsFromAsset(const xchar* pAssetPath, XEActor* pHolder);//path will be fixed. ensure detach when you try to attach.
	static xbool                                  DestroyFilterContainerInstance(XEFilterContainerInstance*& pInstanceToDestroy);//pInstanceToDetach will be set to NULL.
public:
	XE_USER_NODE_CAST(XEFilterContainerInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	Manager*                                      m_pNodeManager;
	XEActor*                                      m_pActorHolder;
	XEFilterUtility::InstanceListFilterNode*      m_pInsListPreprocessFilterNodeContext;
	XEFilterUtility::InstanceListFilterNode*      m_pInsListPostprocessFilterNodeContext;
};

#endif // _XE_FILTER_CONTAINER_INSTANCE_H_
