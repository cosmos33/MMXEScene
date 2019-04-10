/******************************************************************************

@File         XEPropertyObjectWind.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTWIND_H
#define _XEPROPERTYOBJECTWIND_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectWind :public XEPropertyObjectBase
{
public:
	XEPropertyObjectWind(){};
	~XEPropertyObjectWind(){};
	enum{ WIND_DIRECTION = XEPropertyTree::USER_PROPRETY_INDEX,WIND_SPEED};

public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

//XE_PROPERTY_OBJ_FACTORY_AUTO_REGISTER(XEPropertyObjectWind,MHT_USERNODE_PHISYCS);
#endif // _XEPROPERTYOBJECTWIND_H
