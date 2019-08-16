/******************************************************************************

@File         XEFilterLookupInstance.h

@Version       1.0

@Created      2019, 6, 27

@HISTORY:    Filter node instance

******************************************************************************/
#ifndef _XE_FILTER_LOOKUP_INSTANCE_H_
#define _XE_FILTER_LOOKUP_INSTANCE_H_

#include "XEFilterInstance.h"

class XEFilterLookupInstance 
	: public XEFilterInstance
{
public:
	XEFilterLookupInstance(XEFilter* pNodeTl);
	virtual ~XEFilterLookupInstance();
public:
	virtual void                                  Release() override;
	virtual void                                  Apply() override;//apply parameters from node-template.
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
public:
	XE_USER_NODE_CAST(XEFilterLookupInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};



#endif // _XE_FILTER_LOOKUP_INSTANCE_H_
