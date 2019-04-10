
/******************************************************************************

@File         XEPropertyObjectExtendParam.h

@Version       1.0

@Created      2017, 11, 14

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTEXTENDPARAM_H
#define XEPROPERTYOBJECTEXTENDPARAM_H

#include "XEPropertyObjectBase.h"

class XEPropertyObjectExtendParam
	:public XEPropertyObjectBase
{
public:
	enum{ 
		PROPERTY_EXTEND_PARAM_NODE_START = XEPropertyTree::USER_PROPRETY_INDEX, PROPERTY_EXTEND_PARAM_NODE_END = 200, 
		PROPERTY_EXTEND_PARAM_SUB_NODE_START, PROPERTY_EXTEND_PARAM_SUB_NODE_END = 300,
		PROPERTY_EXTEND_PARAM_START };
	XEPropertyObjectExtendParam();
	~XEPropertyObjectExtendParam();
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTEXTENDPARAM_H 