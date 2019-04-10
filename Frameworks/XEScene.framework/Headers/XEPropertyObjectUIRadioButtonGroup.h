/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIRADIOBUTTONGROUP_H
#define XEPROPERTYOBJECTUIRADIOBUTTONGROUP_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUIRadioButtonGroup
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIRadioButtonGroup();
	~XEPropertyObjectUIRadioButtonGroup(){};
	enum{ 
		PROPERTY_RADIOBUTTONGROUP = PROPERTY_UIWIDGET_END,
		PROPERTY_ALLOWEDNOSELECTION,

		PROPERTY_UIWIDGET_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
