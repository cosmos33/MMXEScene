/******************************************************************************

@File         XEPropertyObjectTriggerShapeSphere.h

@Version       1.0

@Created      2019, 1, 2 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#pragma once
#include "XEPropertyObjectBase.h"



class XEPropertyObjectTriggerShapeSphere
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectTriggerShapeSphere(){}
	~XEPropertyObjectTriggerShapeSphere(){}

	enum
	{
		PROPERTY_TRIGGER_SPHERE_RADIUS = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_TRIGGER_SPHERE_COLOR,
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};