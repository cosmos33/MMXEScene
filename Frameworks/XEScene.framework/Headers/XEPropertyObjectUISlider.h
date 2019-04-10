/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUISLIDER_H
#define XEPROPERTYOBJECTUISLIDER_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUISlider
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUISlider() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUISlider(){};
	enum{ 
		PROPERTY_SLIDER = PROPERTY_UIWIDGET_END,

		PROPERTY_BAR_TEXTURE,
		PROPERTY_PROGRESSBAR_TEXTURE,
		PROPERTY_BALL_NORMAL_TEXTURE,
		PROPERTY_BALL_PRESSED_TEXTURE,
		PROPERTY_BALL_DISABLED_TEXTURE,
		PROPERTY_PERCENT,
		PROPERTY_MAX_PERCENT,
		PROPERTY_BALLSIZE,

		PROPERTY_SLIDER_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
