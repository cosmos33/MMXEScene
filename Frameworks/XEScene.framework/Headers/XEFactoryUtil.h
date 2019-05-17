/******************************************************************************

@File         XEFactoryUtil.h

@Version       1.0

@Created      2019,3, 13

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_FACTORY_UTIL_H
#define _XE_FACTORY_UTIL_H
#include "XMemBase.h"
#include "XArray.h"
#include "XClass.h"

class XEFactoryManagerBase
{
public:
	XEFactoryManagerBase() :m_bIsCollected(xfalse){}
	typedef XArray<XEFactoryManagerBase*> FactoryManagers;
	~XEFactoryManagerBase(){}
	typedef XEFactoryManagerBase Super;
	virtual void                          CollectFactory() = 0;
	virtual void                          ReleaseFactory() = 0;
public:
	static FactoryManagers&               GetFactoryManagers(){ static FactoryManagers fm; return fm; }
	static void                           CollectFactories();
	static void                           ReleaseFactories();
public:
	template<typename T>
	static T*&                            GetInstance();
	template<typename T>
	static void                           RegisterManager(T* pMgr);
	template<typename T>
	static void                           UnregisterManager();
protected:
	xbool                                 m_bIsCollected;
};

template<typename T>
T*& XEFactoryManagerBase::GetInstance()
{
	static T* instance = NULL;
	return instance;
}


template<typename T>
void XEFactoryManagerBase::RegisterManager(T* pMgr)
{
	FactoryManagers& factoryMgrs = GetFactoryManagers();
	T*& mgr = GetInstance<T>();
	ASSERT(NULL == mgr);//check your manager instance,please.
	if (mgr) return;//ensure again.
	mgr = pMgr;
	factoryMgrs.AddUnique(mgr);//ensure again.
}

template<typename T>
void XEFactoryManagerBase::UnregisterManager()
{
	FactoryManagers& factoryMgrs = GetFactoryManagers();
	T*& mgr = GetInstance<T>();
	factoryMgrs.Remove(mgr);
	mgr = NULL;
}

template<typename T>
class XEFactoryManagerAutoRegisterWorker
{
public:
	XEFactoryManagerAutoRegisterWorker()
	{
		XEFactoryManagerBase::RegisterManager<T>(&factoryManager_);
	}
	~XEFactoryManagerAutoRegisterWorker()
	{
		XEFactoryManagerBase::UnregisterManager<T>();
	}
	T factoryManager_;
};

#define INSTANCE_FACTORY_IMPL(T) static T* GetInstance(){ if(T* pIns = Super::GetInstance<T>()) return pIns; ASSERT("#T::GetInstance() Is NULL"&&0);return NULL; }
#define INSTANCE_FACTORY_MGR_GENERATE(T) static XEFactoryManagerAutoRegisterWorker<T> s_ManagerAutoRegWorker##T;

#endif // _XE_FACTORY_UTIL_H
