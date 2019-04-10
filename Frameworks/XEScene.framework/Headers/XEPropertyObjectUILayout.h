/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUILAYOUT_H
#define XEPROPERTYOBJECTUILAYOUT_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUILayout
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUILayout() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUILayout(){};
	enum{ 
		PROPERTY_LAYOUT = PROPERTY_UIWIDGET_END,

		PROPERTY_BACKGROUND,
		PROPERTY_PADDING,
		PROPERTY_SPACE,
		
		PROPERTY_CLIPPING,
		PROPERTY_CLIPPINGTYPE,
		PROPERTY_LAYOUTTYPE,
		PROPERTY_LOOPFOCUS,
		PROPERTY_PASSFOCUSTOCHILD,

		PROPERTY_LAYOUT_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
