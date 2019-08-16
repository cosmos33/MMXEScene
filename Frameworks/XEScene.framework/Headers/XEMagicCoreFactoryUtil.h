/******************************************************************************

@File         XEImgFactoryUtil.h

@Version       1.0

@Created      2019, 3, 14

@Description

@HISTORY:

******************************************************************************/
#ifndef XE_IMG_FACTORY_UTIL_H
#define XE_IMG_FACTORY_UTIL_H
#include "XEFactoryActorUtil.h"
#include "XEFactoryActorComponentUtil.h"
#include "XEFactoryPropertyObjectUtil.h"
#include "XEFactoryUserNodeUtil.h"

//XEMagicCoreActorFactoryManager
class XEMagicCoreActorFactoryManager :public XEActorFactoryManager
{
public:
	XEMagicCoreActorFactoryManager();
	virtual ~XEMagicCoreActorFactoryManager();
	virtual void                          CollectFactory() override;
protected:
	virtual IXEActorFactory*              GetFactoryForDerived(const XString &strActorTypeName) override{ return NULL; }//warning, if you don't want to call this in your derived class, override it and return NULL
public:
	INSTANCE_FACTORY_IMPL(XEMagicCoreActorFactoryManager)
};

//XEMagicCoreActorComponentFactoryManager
class XEMagicCoreActorComponentFactoryManager :public XEActorComponentFactoryManager
{
public:
	XEMagicCoreActorComponentFactoryManager();
	virtual ~XEMagicCoreActorComponentFactoryManager();
	virtual void                          CollectFactory() override;
protected:
	virtual IXEActorComponentFactory*     GetFactoryForDerived(const XString &strComponentTypeName) override{ return NULL; }//warning, if you don't want to call this in your derived class, override it and return NULL
public:
	INSTANCE_FACTORY_IMPL(XEMagicCoreActorComponentFactoryManager)
};

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
//XEMagicCorePropertyObjectFactoryManager
class XEMagicCorePropertyObjectFactoryManager :public XEPropertyObjectFactoryManager
{
public:
	XEMagicCorePropertyObjectFactoryManager();
	virtual ~XEMagicCorePropertyObjectFactoryManager();
	virtual void                          CollectFactory() override;
protected:
	//warning, if you don't want to call this in your derived class, override it and return NULL
	virtual IXEPropertyObjectFactory*     GetFactoryForDerived(const XString &strFactoryName){ return NULL; }

public:
	INSTANCE_FACTORY_IMPL(XEMagicCorePropertyObjectFactoryManager)
};
#endif

//////////////////////////////////////////////////////////////////////////XEMagicCoreUserNodeFactoryManager
class XEMagicCoreUserNodeFactoryManager : public XEUserNodeFactoryManager
{
public:
	XEMagicCoreUserNodeFactoryManager();
	virtual ~XEMagicCoreUserNodeFactoryManager();
	virtual void                          CollectFactory() override;
protected:
	//warning, if you don't want to call this in your derived class, override it and return NULL
	virtual IXEUserNodeFactory*           GetFactoryForDerived(const XString &strFactoryName){ return NULL; }
	virtual IXEUserNodeFactory*			  GetFactoryForDerived(const XString &strNodeTypeName, const XString& strNodeInsTypeName){ return NULL; }
public:
	INSTANCE_FACTORY_IMPL(XEMagicCoreUserNodeFactoryManager)
};

#endif
