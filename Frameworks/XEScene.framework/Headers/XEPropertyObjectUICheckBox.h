/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUICHECKBOX_H
#define XEPROPERTYOBJECTUICHECKBOX_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUICheckBox
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUICheckBox() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUICheckBox(){};
	enum{ 
		PROPERTY_CHECKBOX = PROPERTY_UIWIDGET_END,

		PROPERTY_BACKGROUND_NORMAL_TEXTURE,
		PROPERTY_BACKGROUND_SELECTED_TEXTURE,
		PROPERTY_BACKGROUND_DISABLED_TEXTURE,
		PROPERTY_FRONTCROSS_NORMAL_TEXTURE,
		PROPERTY_FRONTCROSS_DISABLED_TEXTURE,

		PROPERTY_ZOOMSCALE,

		PROPERTY_CHECKBOX_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
