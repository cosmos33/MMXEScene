/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUILABEL_H
#define XEPROPERTYOBJECTUILABEL_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUILabel
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUILabel() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUILabel(){};
	enum{ 
		PROPERTY_LABEL = PROPERTY_UIWIDGET_END,
		PROPERTY_TEXT_POINT_SIZE,
		PROPERTY_TTFFONT_PATH,
		PROPERTY_STRING,

		PROPERTY_HALIGNMENT,
		PROPERTY_VALIGNMENT,
		PROPERTY_DIMENSIONS,
		PROPERTY_TEXT_COLOR,
		PROPERTY_ADDITIONAL_KERNING,
		PROPERTY_LINE_SPACING,
		PROPERTY_ENABLE_WRAP,
		PROPERTY_BREAK_OF_WESTERN_WORD,

		PROPERTY_LABEL_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
