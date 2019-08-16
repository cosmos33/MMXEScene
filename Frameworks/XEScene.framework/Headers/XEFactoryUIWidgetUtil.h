#ifndef _XEFACTORYUIWIDGETUTIL_H
#define _XEFACTORYUIWIDGETUTIL_H
#include "XPlatform.h"
#include "XEFactoryUtil.h"

class XUINode;

class IXEUIWidgetFactory : public XMemBase
{
public:
	typedef XArray<IXEUIWidgetFactory*>			UIWIdgetFactoryArray;
	IXEUIWidgetFactory(const XString& _typeName):m_strTypeName(_typeName){}
	virtual ~IXEUIWidgetFactory(){}
public:

	virtual XUINode* CreateUIWidget() = 0;
	XString  GetFactoryType(){ return m_strTypeName; }

private:
	XString m_strTypeName;
};

template<typename T>
class XEUIWidgetFactory_Create : public IXEUIWidgetFactory
{
public:
	XEUIWidgetFactory_Create(const XString& _typeName) : IXEUIWidgetFactory(_typeName){}
	virtual XUINode*  CreateUIWidget()
	{
		T* pNode = T::Create();
		return pNode;
	}
};

template<typename T>
class XEUIWidgetFactory_CreateWithSystem : public IXEUIWidgetFactory
{
public:
	XEUIWidgetFactory_CreateWithSystem(const XString& _typeName) : IXEUIWidgetFactory(_typeName){}
	virtual XUINode*  CreateUIWidget()
	{
		T* pNode = T::CreateWithSystemFont();
		return pNode;
	}
};


#define CREATE_UIWIDGETFACTORY(T, FN, V) (new XEUIWidgetFactory_##FN<T>(V))


class XEUIWidgetFactoryManager:public XEFactoryManagerBase
{
public:
	XEUIWidgetFactoryManager();
	virtual ~XEUIWidgetFactoryManager();
	virtual void               CollectFactory() override;
	virtual void               ReleaseFactory() override;
public:
	INSTANCE_FACTORY_IMPL(XEUIWidgetFactoryManager)
	IXEUIWidgetFactory*		   GetFactory(const XString &strComponentTypeName);
	xbool                      AddFactory(IXEUIWidgetFactory* pFactory);
	XArray<XString>			   GetAllFactoryType();
private:
	IXEUIWidgetFactory::UIWIdgetFactoryArray m_aFactories;
};
#endif//_XEFACTORYUIWIDGETUTIL_H