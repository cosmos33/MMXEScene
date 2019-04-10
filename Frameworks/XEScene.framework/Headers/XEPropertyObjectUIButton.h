/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIBUTTON_H
#define XEPROPERTYOBJECTUIBUTTON_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUIButton
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIButton() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUIButton(){};
	enum{ 
		PROPERTY_BUTTON = PROPERTY_UIWIDGET_END,
		PROPERTY_NORMAL_TEXTURE,
		PROPERTY_PRESSED_TEXTURE,
		PROPERTY_DISABLED_TEXTURE,

		PROPERTY_BUTTON_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
