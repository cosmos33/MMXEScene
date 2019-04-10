/******************************************************************************

@File         XEPropertyObjectPinchSkeleton.h

@Version       1.0

@Created      2018, 8, 17

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTYOBJECT_PINCH_SKELETON_H
#define _XE_PROPERTYOBJECT_PINCH_SKELETON_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectPinchSkeleton 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectPinchSkeleton(){}
	~XEPropertyObjectPinchSkeleton(){}
	enum
	{ 
		PROPERTY_LOAD_ELEMENT = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_RESET,
		PROPERTY_SAVE_CFG_INSTANCE,
		PROPERTY_LOAD_CFG_INSTANCE,
		PROPERTY_ELEMENT_ROOT,
		PROPERTY_ELEMENT_BEGIN,
		PROPERTY_ELEMENT_END = PROPERTY_ELEMENT_BEGIN + 1000//AS MAX AS 1000? ENOUGH?
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTYOBJECT_PINCH_SKELETON_H   