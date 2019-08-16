/******************************************************************************

@File         XEFilterFaceMakeupInstance.h

@Version       1.0

@Created      2019, 6, 22

@HISTORY:    Filter node instance

******************************************************************************/
#ifndef _XE_FACE_MAKEUP_FILTER_INSTANCE_H_
#define _XE_FACE_MAKEUP_FILTER_INSTANCE_H_
#include "XEFilterInstance.h"

class XEFilter;
class XEFilterFaceMakeup;
class XEFilterFaceMakeupInstance 
	: public XEFilterInstance
{
public:
	XEFilterFaceMakeupInstance(XEFilter* pNodeTl);
	virtual ~XEFilterFaceMakeupInstance();
public:
	virtual void                                  Release() override;
	virtual void                                  Apply() override;//apply parameters from node-template.
	virtual void								  Tick(xfloat32 fInterval) override;
	virtual xbool                                 IsValidForRender() override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
	xbool										  IsEnableBlendMode(const XString& strBlendMode);
public:
	XE_USER_NODE_CAST(XEFilterFaceMakeupInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};



#endif // _XE_FACE_MAKEUP_FILTER_INSTANCE_H_
