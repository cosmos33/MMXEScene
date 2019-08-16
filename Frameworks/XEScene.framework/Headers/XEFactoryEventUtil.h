/******************************************************************************

@File         XEFactoryEventUtil.h

@Version       1.0

@Created      2018,6,12

@HISTORY:

******************************************************************************/
#ifndef _XE_FACTORY_EVENT_UTILITY_H
#define _XE_FACTORY_EVENT_UTILITY_H

#include "XEEventBase.h"
#include "XEFactoryUtil.h"

class IXEEventFactory : public XMemBase
{
public:
	typedef XArray<IXEEventFactory*> XEEventFactoryArray;
	IXEEventFactory(){}
	virtual ~IXEEventFactory(){}
public:
	virtual XEEventBase*                              CreateEvent() = 0;
	virtual const XString&	                          GetEventTypeName() = 0;
};

template<typename T>
class XEEventFactory : public IXEEventFactory
{
public:
	virtual XEEventBase*                              CreateEvent() override;
	virtual const XString&	                          GetEventTypeName() override;
};

class XEEventFactoryManager:public XEFactoryManagerBase
{
public:
	XEEventFactoryManager();
	virtual ~XEEventFactoryManager();
public:
	virtual void                                      CollectFactory() override;
	virtual void                                      ReleaseFactory() override;
public:
	INSTANCE_FACTORY_IMPL(XEEventFactoryManager)
	IXEEventFactory*	                              GetFactory(const XString &strEventTypeName);
	xbool                                             AddFactory(IXEEventFactory* pFactory);
	const IXEEventFactory::XEEventFactoryArray&       GetFactoryList() const;
protected:
	template<typename T>
	xbool                                             _Register();
private:
	IXEEventFactory::XEEventFactoryArray			  m_aFactories;
};

//implement with template
template<typename T>
XEEventBase* XEEventFactory<T>::CreateEvent()
{
	T* pEvent = new T;
	return pEvent;
}

template<typename T>
const XString& XEEventFactory<T>::GetEventTypeName()
{
	return T::EVENT_TYPENAME;
}

template<typename T>
xbool XEEventFactoryManager::_Register()
{
	IXEEventFactory* pFactory = new XEEventFactory<T>();
	if (!AddFactory(pFactory))
	{
		X_SAFEDELETE(pFactory);
		return xfalse;
	}
	return xtrue;
}

#endif // _XE_FACTORY_EVENT_UTILITY_H
