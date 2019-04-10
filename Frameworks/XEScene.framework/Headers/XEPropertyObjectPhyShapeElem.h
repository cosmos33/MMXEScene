/******************************************************************************

@File         XEPropertyObjectPhyShapeElem.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_PHY_SHAPE_ELEM_H
#define _XE_PROPERTY_OBJECT_PHY_SHAPE_ELEM_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectPhyShapeElem
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectPhyShapeElem(){};
	~XEPropertyObjectPhyShapeElem(){};
	enum
	{
		PROPERTY_CYLINDER_RADIUS = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_CYLINDER_HEIGHT,
		PROPERTY_SHAPE_CENTER,
		PROPERTY_SHAPE_ROTATION
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTY_OBJECT_PHY_SHAPE_ELEM_H	
