/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUICOMBOBOX_H
#define XEPROPERTYOBJECTUICOMBOBOX_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUIComboBox
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIComboBox() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUIComboBox(){};
	enum{ 
		PROPERTY_COMBOBOX = PROPERTY_UIWIDGET_END,

		PROPERTY_EDITBOX_BACKGROUNDB_TEXTURE,
		PROPERTY_BUTTON_NORMAL_TEXTURE,
		PROPERTY_BUTTON_SELECTED_TEXTURE,
		PROPERTY_LISTVIEW_BACKGROUND_TEXTURE,
		PROPERTY_ITEM_BACKGROUND_TEXTURE,
		PROPERTY_ITEM_BACKGROUND_SELECTED_TEXTURE,

		PROPERTY_ALLOW_EDIT,
		PROPERTY_ITEM_HEIGHT,
		PROPERTY_FONT_COLOR,
		PROPERTY_LISTVIEW_HEIGHT,

		PROPERTY_COMBOBOX_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
