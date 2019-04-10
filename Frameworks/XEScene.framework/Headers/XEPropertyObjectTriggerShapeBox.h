/******************************************************************************

@File         XEPropertyObjectTriggerShapeBox.h

@Version       1.0

@Created      2018, 12, 29 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#pragma once
#include "XEPropertyObjectBase.h"



class XEPropertyObjectTriggerShapeBox
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectTriggerShapeBox(){}
	~XEPropertyObjectTriggerShapeBox(){}

	enum
	{
		PROPERTY_TRIGGER_BOX_EXT = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_TRIGGER_BOX_COLOR,
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};