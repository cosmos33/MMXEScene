/******************************************************************************

@File         XEPropertyObjectBase.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_FACTORY_PROPERTYOBJECTBASE_UTIL_H
#define _XE_FACTORY_PROPERTYOBJECTBASE_UTIL_H

#include "XPlatform.h"
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC

#include "XEFactoryUtil.h"

enum XEMatchHandleType
{
	MHT_UNKOWN = 0,
	MHT_ACTOR = 1 << 0,
	MHT_COMPONENT = 1 << 1,
	MHT_USERNODE = 1 << 2,
	MHT_USERNODE_PHISYCS = 1 << 3,
	MHT_USERNODE_ANIMATION = 1 << 4,
	MHT_UINODE = 1 << 5,
	MHT_USERNODE_SELF_DEFINE_01 = 1 << 6,
	MHT_USERNODE_SELF_DEFINE_02 = 1 << 7,
	MHT_USERNODE_SELF_DEFINE_03 = 1 << 8,
	MHT_USERNODE_SELF_DEFINE_04 = 1 << 9,
	MHT_USERNODE_SELF_DEFINE_05 = 1 << 10,
	MHT_USERNODE_SELF_DEFINE_06 = 1 << 11,
	MHT_USERNODE_SELF_DEFINE_07 = 1 << 12,
	MHT_USERNODE_SELF_DEFINE_08 = 1 << 13,
	MHT_USERNODE_SELF_DEFINE_09 = 1 << 14,
	MHT_USERNODE_SELF_DEFINE_10 = 1 << 15,//AS MAX AS 10 OF THE SELF-DEFINE-NODE PROPERTIES.
	MHT_WORLD = 1 << 16
};

class XEPropertyObjectBase;
class IXEPropertyObjectFactory : public XMemBase
{
public:
	IXEPropertyObjectFactory(const XString& strTypeName, const XEMatchHandleType& eMHT)
		:m_strPropertyObjTypeName(strTypeName), m_eMatchHandleType(eMHT){}
	virtual ~IXEPropertyObjectFactory(){}
public:
	virtual XEPropertyObjectBase*             CreatePropertyObject() = 0;
	virtual void                              ReleasePropertyObject(XEPropertyObjectBase *pPropertyObject);
	XString                                   GetTypeName(){ return m_strPropertyObjTypeName; }
	XEMatchHandleType                         GetMatchHandleType(){ return m_eMatchHandleType; }
protected:
	XString             m_strPropertyObjTypeName;
	XEMatchHandleType   m_eMatchHandleType;//handle type that matched to this property object.
};

template<typename T>
class XEPropertyObjectFactory : public IXEPropertyObjectFactory
{
public:
	XEPropertyObjectFactory(const XString& strTypeName, const XEMatchHandleType& eMHT): IXEPropertyObjectFactory(strTypeName, eMHT){}
	virtual XEPropertyObjectBase* CreatePropertyObject();
};

class XEPropertyObjectFactoryManager:public XEFactoryManagerBase
{
public:
	XEPropertyObjectFactoryManager();
	virtual ~XEPropertyObjectFactoryManager();
	virtual void                           CollectFactory() override;
	virtual void                           ReleaseFactory() override;
public:
	INSTANCE_FACTORY_IMPL(XEPropertyObjectFactoryManager)
	XArray<IXEPropertyObjectFactory*>&     GetFactoryList(){ return m_aFactories; }
	xbool                                  AddFactory(IXEPropertyObjectFactory* pFactory);
	IXEPropertyObjectFactory*              GetFactory(const XString& strFactoryName);
protected:
	virtual IXEPropertyObjectFactory*      GetFactoryForDerived(const XString &strFactoryName);//warning, if you don't want to call this in your derived class, override it and return NULL

protected:
	template<typename T>
	xbool                                 _Register(const XString strTypeName, const XEMatchHandleType& eMHT);
private:
	XArray<IXEPropertyObjectFactory*>      m_aFactories;
};

#define REGISTER_PROPERTY_OBJ(T,E) _Register<T>(#T,E)

class XEPropertyObjectProxy :public XMemBase
{
public:
	XEPropertyObjectProxy(const xint32 nBitMatchHandlerType = -1);//can be several types, in each bit(test if it is 1).
	~XEPropertyObjectProxy();

	struct ProxyObject
	{
		XEPropertyObjectBase*                    pPropertyObject;
		void*                                    pHandleObject;
		XEMatchHandleType                        eMatchHandleType;
		ProxyObject()                          : pPropertyObject(NULL), pHandleObject(NULL), eMatchHandleType(MHT_UNKOWN){}
		ProxyObject(XEPropertyObjectBase* pPo) : pPropertyObject(pPo), pHandleObject(NULL), eMatchHandleType(MHT_UNKOWN){}
	};
public:
	void                                         RegisterPropertyObject(XEPropertyObjectBase* pPropertyObject, const xchar* pPropertyObjTypeName);
	XEPropertyObjectBase*                        GetPropertyObject(const XString& strPropertyObjTypeName);
	xint32                                       GetPropertyObject(void* pHandleObject, XArray<const ProxyObject*>& poList) const;
	XArray<ProxyObject>&                         GetPropertyObjectList(){ return m_arrProxyObjectList; }
	XEPropertyObjectBase*                        HandlePropertyObject(const XString& strPropertyObjTypeName, void* pHandleObject, const XEMatchHandleType& mht);
	void*                                        GetHandleObject(const XString& strPropertyObjTypeName);
	const XEMatchHandleType                      GetHandleObjectMatchType(const XString& strPropertyObjTypeName) const;
	void                                         ClearCache();
	template<typename T>
	T*                                           GetHandleObjectCast(const XString& strPropertyObjTypeName);
private:
	ProxyObject*                                 GetPropertyObjectProxy(const XString& strPropertyObjTypeName);
	const ProxyObject*                           GetPropertyObjectProxy(const XString& strPropertyObjTypeName) const;
private:
	XArray<ProxyObject> m_arrProxyObjectList;
};


//implement with template
template<typename T>
XEPropertyObjectBase* XEPropertyObjectFactory<T>::CreatePropertyObject()
{
	T* p = new T;
	p->SetTypeName(m_strPropertyObjTypeName);
	return p;
}

template<typename T>
T* XEPropertyObjectProxy::GetHandleObjectCast(const XString& strPropertyObjTypeName)
{
	return reinterpret_cast<T*>(GetHandleObject(strPropertyObjTypeName));
}

template<typename T>
xbool XEPropertyObjectFactoryManager::_Register(const XString strTypeName, const XEMatchHandleType& eMHT)
{
	IXEPropertyObjectFactory* pFactory = new XEPropertyObjectFactory<T>(strTypeName, eMHT);
	if (!AddFactory(pFactory))
	{
		X_SAFEDELETE(pFactory);
		return xfalse;
	}
	return xtrue;
}

#endif //X_PLATFORM_WIN_DESKTOP
#endif // _XE_FACTORY_PROPERTYOBJECTBASE_UTIL_H
