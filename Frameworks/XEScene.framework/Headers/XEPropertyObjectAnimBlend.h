/******************************************************************************

@File         XEPropertyObjectAnimBlend.h

@Version       1.0

@Created      2018, 9, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTE_ANIMBLEND_H
#define _XEPROPERTYOBJECTE_ANIMBLEND_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimBlend 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimBlend(){};
	~XEPropertyObjectAnimBlend(){};
	enum{ 
		PROPERTY_DURATION = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_PREVIEW_MODEL,
		PROPERTY_PIVOT_ROTATION,
		PROPERTY_RENDER_SKELETON,
		PROPERTY_START_TIME,
		PROPERTY_END_TIME,
		PROPERTY_LOOP_AT_END, 
		PROPERTY_LOOP_AT_END_START_TIME };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTYOBJECTE_ANIMBLEND_H
