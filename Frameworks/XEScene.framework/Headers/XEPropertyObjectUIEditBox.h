/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIEDITBOX_H
#define XEPROPERTYOBJECTUIEDITBOX_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUIEditBox
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIEditBox() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUIEditBox(){};
	enum{ 
		PROPERTY_EDITBOX = PROPERTY_UIWIDGET_END,
		PROPERTY_TEXT,
		PROPERTY_FONTNAME,
		PROPERTY_FONTSIZE,
		PROPERTY_FONTCOLOR,
		PROPERTY_BACKGROUND,

		PROPERTY_PLACEHOLDER_TEXT,
		PROPERTY_PLACEHOLDER_FONTNAME,
		PROPERTY_PLACEHOLDER_FONTSIZE,
		PROPERTY_PLACEHOLDER_FONTCOLOR,
		PROPERTY_MAXLENGTH,

		PROPERTY_INPUTMODE,
		PROPERTY_INPUTFLAG,
		PROPERTY_RETURNTYPE,
		PROPERTY_TEXTHORIZONTAL_ALIGNMENT,

		PROPERTY_EDITBOX_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
