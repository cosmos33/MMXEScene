/******************************************************************************

@File         XEPropertyObjectActorComponentCommon.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTYOBJECT_ACTOR_COMPONENT_COMMON_H
#define _XE_PROPERTYOBJECT_ACTOR_COMPONENT_COMMON_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectActorComponentCommon 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectActorComponentCommon(){}
	~XEPropertyObjectActorComponentCommon(){}
	enum
	{ 
		PROPERTY_HIDDEN = XEPropertyTree::USER_PROPRETY_INDEX
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTYOBJECT_ACTOR_COMPONENT_COMMON_H   