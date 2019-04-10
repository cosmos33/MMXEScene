/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUITABCONTROL_H
#define XEPROPERTYOBJECTUITABCONTROL_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUITabControl
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUITabControl() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUITabControl(){};
	enum{ 
		PROPERTY_TabCONTROL = PROPERTY_UIWIDGET_END,
		PROPERTY_HEADER_WIDTH,
		PROPERTY_HEADER_HEIGHT,
		PROPERTY_SELECTED_ZOOM,
		PROPERTY_HEADER_DOCK_PLACE,

		PROPERTY_TabCONTROL_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
