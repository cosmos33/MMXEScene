/******************************************************************************

@File         XEPropertyObjectAnimSocketMounter.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTEANIMSOCKETMOUNTER_H
#define _XEPROPERTYOBJECTEANIMSOCKETMOUNTER_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimSocketMounter 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimSocketMounter(){};
	~XEPropertyObjectAnimSocketMounter(){};
	enum{ 
		PROPERTY_RENDER_SKELETON = XEPropertyTree::USER_PROPRETY_INDEX
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};
#endif // _XEPROPERTYOBJECTEANIMSOCKETMOUNTER_H
