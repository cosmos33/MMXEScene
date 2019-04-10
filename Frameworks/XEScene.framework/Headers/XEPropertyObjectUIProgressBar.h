/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTPROGRESSBAR_H
#define XEPROPERTYOBJECTPROGRESSBAR_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUIProgressBar
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIProgressBar() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUIProgressBar(){};
	enum{ 
		PROPERTY_PROGRESSBAR = PROPERTY_UIWIDGET_END,
		PROPERTY_BACKGROUND,
		PROPERTY_DIRECTION,
		PROPERTY_PERCENT,

		PROPERTY_PROGRESSBAR_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
