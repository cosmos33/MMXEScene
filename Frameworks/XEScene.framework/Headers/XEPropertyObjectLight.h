/******************************************************************************

@File         l.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTLIGHT_H
#define XEPROPERTYOBJECTLIGHT_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectLight 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectLight(){};
	~XEPropertyObjectLight(){};
	enum{ PROPERTY_LIGHT_COLOR = XEPropertyTree::USER_PROPRETY_INDEX, PROPERTY_LIGHT_LUMINANCE, PROPERTY_LIGHT_RADIUS,
		PROPERTY_LIGHT_FALLOFFEXP, PROPERTY_LIGHT_INNERANGLE, PROPERTY_LIGHT_OUTERANGLE};
	struct XELightWidgetData
	{
		xfloat32    fMinValue;
		xfloat32    fMaxValue;
		xfloat32    fSpan;
		xfloat32    bInit;
		XELightWidgetData() :bInit(xfalse){}
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

	XELightWidgetData GetLightWidgetData(){ return m_LightWidgetData; }
private:
	XELightWidgetData m_LightWidgetData;
};

#endif // XEPROPERTYOBJECTLIGHT_H
