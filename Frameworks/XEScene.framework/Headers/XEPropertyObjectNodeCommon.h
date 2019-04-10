/******************************************************************************

@File         XEPropertyObjectNodeCommon.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTECOMMON_H
#define _XEPROPERTYOBJECTECOMMON_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectNodeCommon 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectNodeCommon(){};
	~XEPropertyObjectNodeCommon(){};
	enum
	{ 
		PROPERTY_NODE_NAME = XEPropertyTree::USER_PROPRETY_INDEX, PROPERTY_NODE_TYPE,
		PROPERTY_BINDING_SCRIPT
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTYOBJECTECOMMON_H
