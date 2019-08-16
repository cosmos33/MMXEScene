/******************************************************************************

@File         XEActorComponent.h

@Version       1.0

@Created      2017, 9, 20

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_FACTORY_COMPONENT_UTIL_H
#define _XE_FACTORY_COMPONENT_UTIL_H

#include "XEFactoryUtil.h"
class XEActor;
class XEActorComponent;
class IXEActorComponentFactory : public XMemBase
{
public:
	typedef XArray<IXEActorComponentFactory*> ActorComponentFactoryArray;
	IXEActorComponentFactory(){}
	virtual ~IXEActorComponentFactory(){}
public:
	virtual XEActorComponent*  CreateActorComponent(XEActor* pActor) = 0;
	virtual const XString&	   GetActorComponentTypeName() = 0;
	virtual void               ReleaseActorComponent(XEActorComponent *pComponent);
};

template<typename T>
class XEActorComponentFactory : public IXEActorComponentFactory
{
public:
	virtual XEActorComponent*  CreateActorComponent(XEActor* pActor);
	virtual const XString&	   GetActorComponentTypeName();
};

class XEActorComponentFactoryManager:public XEFactoryManagerBase
{
public:
	XEActorComponentFactoryManager();
	virtual ~XEActorComponentFactoryManager();
	virtual void                           CollectFactory() override;
	virtual void                           ReleaseFactory() override;
protected:
	virtual IXEActorComponentFactory*      GetFactoryForDerived(const XString &strComponentTypeName);//warning, if you don't want to call this in your derived class, override it and return NULL
public:
	INSTANCE_FACTORY_IMPL(XEActorComponentFactoryManager)
	IXEActorComponentFactory*              GetFactory(const XString &strComponentTypeName);
	xbool                                  AddFactory(IXEActorComponentFactory* pFactory);
	XEActorComponent*                      CreateActorComponent(const XString& strComponentTypeName, XEActor* pActor = NULL);
protected:					               
	template<typename T>	               
	xbool                                  _Register();
private:
	IXEActorComponentFactory::ActorComponentFactoryArray m_aFactories;
};

//implement with template
template<typename T>
XEActorComponent* XEActorComponentFactory<T>::CreateActorComponent(XEActor* pActor)
{
	T* p = new T;
	p->Initialize(pActor);
	return p;
}

template<typename T>
const XString& XEActorComponentFactory<T>::GetActorComponentTypeName()
{
	return T::COMPONENT_TYPENAME;
}

template<typename T>
xbool XEActorComponentFactoryManager::_Register()
{
	IXEActorComponentFactory* pFactory = new XEActorComponentFactory<T>();
	if (!AddFactory(pFactory))
	{
		X_SAFEDELETE(pFactory);
		return xfalse;
	}
	return xtrue;
}

//make sure that the type of component existed.
#define XE_CREATE_ACTOR_COMPONENT(T,A) static_cast<T*>(XEActorComponentFactoryManager::GetInstance()->GetFactory(T::COMPONENT_TYPENAME)->CreateActorComponent(A))
#define XE_CREATE_ACTOR_COMPONENT_CHAR(S,A) XEActorComponentFactoryManager::GetInstance()->CreateActorComponent(S,A)
#define XE_RELEASE_ACTOR_COMPONENT(T,C) XEActorComponentFactoryManager::GetInstance()->GetFactory(T::COMPONENT_TYPENAME)->ReleaseActorComponent(C)
#define XE_RELEASE_ACTOR_COMPONENT_CHAR(S,C) XEActorComponentFactoryManager::GetInstance()->GetFactory(S)->ReleaseActorComponent(C)

#endif // _XE_FACTORY_COMPONENT_UTIL_H
