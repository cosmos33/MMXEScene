/******************************************************************************

@File         XEExtendParamFactory.h

@Version       1.0

@Created      2018,2, 8

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_FACTORY_EXTEND_PARAM_UTIL_H
#define _XE_FACTORY_EXTEND_PARAM_UTIL_H
#include "XMemBase.h"
#include "XEFactoryUtil.h"
#include "tinyxml2_XEngine.h"

using namespace tinyxml2_XEngine;

class XEActor;
class XEValueProperty;
class XEPropertyObject;
class XEProperty;

class IXEExtendParam:public XMemBase
{
public:
	IXEExtendParam(){}
	virtual ~IXEExtendParam(){}
public:
	virtual const XString& GetParamName() const;
	virtual XMLElement*    Serialize(XMLElement* pEleParent);
	virtual void           Deserialize(const XMLElement* pEleExtendParam);
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEProperty*    CreateProperty(xint32 nParamIndex, xint32 nMemberIndex, XEProperty* pParent, XEPropertyObject* pPropertyObject){ return NULL; }
	virtual xbool          SetValueProperty(xint32 nMemberIndex, const XEValueProperty* pProperty, XEPropertyObject* pPropertyObject){ return xfalse; }//can be nodes or values.
	virtual void           GetValueProperty(xint32 nMemberIndex, XEValueProperty* pProperty, XEPropertyObject* pPropertyObject){}
	virtual xint32         GetParamMemberCount(){ return 0; }
	virtual XString        GetParamMemberName(xint32 nIndex){ return XString(); }
#endif
	virtual void           Tick(xfloat32 fDelMs){}
public:
	X_FORCEINLINE void     SetOwner(XEActor* pActor){ m_pActorOwner = pActor; }
	X_FORCEINLINE XEActor* GetOwner(){ return m_pActorOwner; }
protected:
	XEActor*               m_pActorOwner;
public:
	static const XString   EXTEND_PARAM_NAME;
};

class IXEExtendParamFactory : public XMemBase
{
public:
	typedef XArray<IXEExtendParamFactory*> ExtendParamFactoryArray;
	IXEExtendParamFactory(){}
	virtual ~IXEExtendParamFactory(){}
public:
	virtual IXEExtendParam*    CreateExtendParam(XEActor* pActorOwner) = 0;
	virtual const XString&	   GetExtendParamName() = 0;
	virtual void               ReleaseExtendParam(IXEExtendParam *pExtendParam);
};

template<typename T>
class XEExtendParamFactory : public IXEExtendParamFactory
{
public:
	virtual IXEExtendParam*    CreateExtendParam(XEActor* pActorOwner);
	virtual const XString&	   GetExtendParamName();
};

class XEParamExtendFactoryManager:public XEFactoryManagerBase
{
public:
	XEParamExtendFactoryManager();
	virtual ~XEParamExtendFactoryManager();
public:
	virtual void               CollectFactory() override;
	virtual void               ReleaseFactory() override;
protected:
	virtual IXEExtendParamFactory* GetFactoryForDerived(const XString &strParamName);//warning, if you don't want to call this in your derived class, override it and return NULL
public:
	INSTANCE_FACTORY_IMPL(XEParamExtendFactoryManager)
	IXEExtendParamFactory*     GetFactory(const XString &strParamName);
	xbool                      AddFactory(IXEExtendParamFactory* pFactory);
protected:
	template<typename T>
	xbool                      _Register();
private:
	IXEExtendParamFactory::ExtendParamFactoryArray m_aExtendParamFactories;
};


//implement with template.
template<typename T>
IXEExtendParam* XEExtendParamFactory<T>::CreateExtendParam(XEActor* pActorOwner)
{
	T* p = new T;
	p->SetOwner(pActorOwner);
	return p;
}

template<typename T>
const XString& XEExtendParamFactory<T>::GetExtendParamName()
{
	return T::EXTEND_PARAM_NAME;
}


template<typename T>
xbool XEParamExtendFactoryManager::_Register()
{
	IXEExtendParamFactory* pFactory = new XEExtendParamFactory<T>();
	if (!AddFactory(pFactory))
	{
		X_SAFEDELETE(pFactory);
		return xfalse;
	}
	return xtrue;
}

#define XE_EXT_PARAM_TYPE_DEF(T) virtual const XString &GetParamName()const override{return T;}
#endif // _XE_FACTORY_EXTEND_PARAM_UTIL_H
