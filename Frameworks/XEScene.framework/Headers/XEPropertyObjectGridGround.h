/******************************************************************************

@File         XEPropertyObjectGridGround.h

@Version       1.0

@Created      2017, 11, 8

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTGRIDGROUND_H
#define XEPROPERTYOBJECTGRIDGROUND_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectGridGround 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectGridGround(){}
	~XEPropertyObjectGridGround(){}
	enum{ PROPERTY_GRID_MODE = XEPropertyTree::USER_PROPRETY_INDEX };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTGRIDGROUND_H   