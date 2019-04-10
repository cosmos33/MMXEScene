/******************************************************************************

@File         XEPropertyObjectAnimMontage.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTEANIMMONTAGE_H
#define _XEPROPERTYOBJECTEANIMMONTAGE_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimMontage 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimMontage(){};
	~XEPropertyObjectAnimMontage(){};
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

#endif // _XEPROPERTYOBJECTEANIMMONTAGE_H
