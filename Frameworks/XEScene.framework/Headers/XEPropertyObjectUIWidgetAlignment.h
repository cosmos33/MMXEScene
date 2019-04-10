/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIWIDGETALIGNMENT_H
#define XEPROPERTYOBJECTUIWIDGETALIGNMENT_H
#include "XEPropertyObjectUINode.h"
class XUINode;
class XEPropertyObjectUIWidgetAlignment
	:public XEPropertyObjectUINode
{
public:
	XEPropertyObjectUIWidgetAlignment();
	~XEPropertyObjectUIWidgetAlignment(){};
	enum{ 
		PROPERTY_WIDGETALIGNMENT = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ENABLED,
		PROPERTY_HORIZONTAL_EDGE,
		PROPERTY_VERTICAL_EDGE,
		PROPERTY_LEFT_MARGIN,
		PROPERTY_RIGHT_MARGIN,
		PROPERTY_TOP_MARGIN,
		PROPERTY_BOTTOM_MARGIN,

		PROPERTY_WIDGETALIGNMENT_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
