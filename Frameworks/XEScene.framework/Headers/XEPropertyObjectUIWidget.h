/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIWIDGET_H
#define XEPROPERTYOBJECTUIWIDGET_H
#include "XEPropertyObjectUINode.h"
class XUINode;
class XEPropertyObjectUIWidget
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectUIWidget();
	virtual ~XEPropertyObjectUIWidget(){};
	enum{ 
		PROPERTY_WIDGET,
		PROPERTY_ENABLED,
		PROPERTY_COLOR,

		PROPERTY_UIWIDGET_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
