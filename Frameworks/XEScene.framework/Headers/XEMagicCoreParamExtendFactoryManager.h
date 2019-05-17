/******************************************************************************

@File         XEMagicCoreParamExtendFactoryManager.h

@Version       1.0

@Created      2019, 3, 13

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/


#ifndef _XE_MAGICCORE_PARAM_EXTEND_FACTORY_MANAGER_H_
#define _XE_MAGICCORE_PARAM_EXTEND_FACTORY_MANAGER_H_

#include "XEFactoryExtendParamUtil.h"

//in FXCore
class XEMagicCoreParamExtendFactoryManager :public XEParamExtendFactoryManager
{
public:
	XEMagicCoreParamExtendFactoryManager();
	virtual ~XEMagicCoreParamExtendFactoryManager();
public:
	virtual void                   CollectFactory() override;
	virtual IXEExtendParamFactory* GetFactoryForDerived(const XString &strParamName) override { return NULL; }
public:
	INSTANCE_FACTORY_IMPL(XEMagicCoreParamExtendFactoryManager)
};


#endif //_XE_MAGICCORE_PARAM_EXTEND_FACTORY_MANAGER_H_
