/******************************************************************************

@File         XEActorFactory.h

@Version       1.0

@Created      2017,9, 20

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_FACTORY_ACTOR_UTIL_H
#define _XE_FACTORY_ACTOR_UTIL_H
#include "XEFactoryUtil.h"

class XEActor;
class XEWorld;
class IXEActorFactory : public XMemBase
{
public:
    typedef XArray<IXEActorFactory*> ActorFactoryArray;
    IXEActorFactory(){}
    virtual ~IXEActorFactory(){}
public:
	virtual XEActor*           CreateActor(XEWorld* pWorld, const xchar* pActorName = NULL) = 0;
	virtual const XString&     GetActorTypeName() = 0;
    virtual void               ReleaseActor(XEActor *pActor);
};

template<typename T>
class XEActorFactory : public IXEActorFactory
{
public:
    virtual XEActor*          CreateActor(XEWorld* pWorld, const xchar* pActorName = NULL);    
    virtual const XString&    GetActorTypeName();
};

class XEActorFactoryManager :public XEFactoryManagerBase
{
public:
	XEActorFactoryManager();
	virtual ~XEActorFactoryManager();
	virtual void                          CollectFactory() override;
	virtual void                          ReleaseFactory() override;
protected:
	virtual IXEActorFactory*              GetFactoryForDerived(const XString &strActorTypeName);//warning, if you don't want to call this in your derived class, override it and return NULL
public:
	INSTANCE_FACTORY_IMPL(XEActorFactoryManager)
	IXEActorFactory*                      GetFactory(const XString &strActorTypeName);
    IXEActorFactory::ActorFactoryArray&   GetFactoryList(){ return m_aFactories; }
    xbool                                 AddFactory(IXEActorFactory* pFactory);
protected:
	template<typename T>
	xbool                                 _Register();
	void                                  _RegSystemMetaCollisionChannel(const XString& strActorTypeName);
protected:
    IXEActorFactory::ActorFactoryArray     m_aFactories;
};

//implement with template.
template<typename T>
XEActor* XEActorFactory<T>::CreateActor(XEWorld* pWorld, const xchar* pActorName /*= NULL*/)
{
	T* p = new T;
	if (NULL != pActorName)
		p->SetActorName(pActorName, pWorld);
	p->Initialize(pWorld);
	return p;
}

template<typename T>
const XString& XEActorFactory<T>::GetActorTypeName()
{
	return T::ACTOR_TYPENAME;
}

template<typename T>
xbool XEActorFactoryManager::_Register()
{
	IXEActorFactory* pFactory = new XEActorFactory<T>();
	if (!AddFactory(pFactory))
	{
		X_SAFEDELETE(pFactory);
		return xfalse;
	}
	//THE TYPE OF THE ACTOR.
	_RegSystemMetaCollisionChannel(T::ACTOR_TYPENAME);
	return xtrue;
}


#endif // _XE_FACTORY_ACTOR_UTIL_H
