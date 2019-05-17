/******************************************************************************

@File         XEFactoryUserNodeUtil.h

@Version       1.0

@Created      2018,2, 8

@HISTORY:

******************************************************************************/
#ifndef XE_FACTORY_USER_NODE_UTILITY_H
#define XE_FACTORY_USER_NODE_UTILITY_H

#include "XEUserNode.h"
#include "XEFactoryUtil.h"

class XEUserNodeInstance;
class IXEUserNodeFactory : public XMemBase
{
public:
	typedef XArray<IXEUserNodeFactory*> XEUserNodeFactoryArray;
	IXEUserNodeFactory(){}
	virtual ~IXEUserNodeFactory(){}
public:
	virtual XEUserNode*                               CreateUserNode(XEUserNode* pNodeContext) = 0;
	virtual XEUserNodeInstance*                       CreateUserNodeInstance(XEUserNode* pNodeTemplate) = 0;
	virtual const XString&	                          GetUserNodeTypeName() = 0;
};

template<typename T, typename I>
class XEUserNodeFactory : public IXEUserNodeFactory
{
public:
	virtual XEUserNode*                               CreateUserNode(XEUserNode* pNodeContext) override;
	virtual XEUserNodeInstance*                       CreateUserNodeInstance(XEUserNode* pNodeTemplate) override;
	virtual const XString&	                          GetUserNodeTypeName() override;
};

class XEUserNodeFactoryManager:public XEFactoryManagerBase
{
public:
	XEUserNodeFactoryManager();
	virtual ~XEUserNodeFactoryManager();
	virtual void                                      CollectFactory() override;
	virtual void                                      ReleaseFactory() override;
public:
	INSTANCE_FACTORY_IMPL(XEUserNodeFactoryManager)
	IXEUserNodeFactory*	                              GetFactory(const XString &strNodeTypeName);
	xbool                                             AddFactory(IXEUserNodeFactory* pFactory);
	const IXEUserNodeFactory::XEUserNodeFactoryArray& GetFactoryList() const;
private:
	template<typename T,typename I>
	xbool                                             _Register();
private:
	IXEUserNodeFactory::XEUserNodeFactoryArray m_aFactories;
	xbool m_bIsCollected;
};


//implement with template
template<typename T, typename I>
XEUserNode* XEUserNodeFactory<T,I>::CreateUserNode( XEUserNode* pNodeContext)
{
	T* pNode = new T;
	pNode->SetNodeName(pNode->GetValidNodeName(pNodeContext));
	return pNode;
}


template<typename T, typename I>
XEUserNodeInstance* XEUserNodeFactory<T, I>::CreateUserNodeInstance(XEUserNode* pNodeTemplate)
{
	//to generate instance node from the template. Don't forget to setup the instance and spawn its children instance. 
	if (NULL == pNodeTemplate)
		return xfalse;

	return new I(pNodeTemplate->CastToUserNode<T>());
}

template<typename T, typename I>
const XString& XEUserNodeFactory<T,I>::GetUserNodeTypeName()
{
	return T::NODE_TYPENAME;
}

template<typename T, typename I>
xbool XEUserNodeFactoryManager::_Register()
{
	IXEUserNodeFactory* pFactory = new XEUserNodeFactory<T,I>();
	if (!AddFactory(pFactory))
	{
		X_SAFEDELETE(pFactory);
		return xfalse;
	}
	return xtrue;
}

#endif // XE_FACTORY_USER_NODE_UTILITY_H
