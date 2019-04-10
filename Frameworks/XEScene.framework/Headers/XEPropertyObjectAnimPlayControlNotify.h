/******************************************************************************

@File         XEPropertyObjectAnimPlayControlNotify.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTEANIMPLAYCONTROLNOTIFY_H
#define _XEPROPERTYOBJECTEANIMPLAYCONTROLNOTIFY_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimPlayControlNotify 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimPlayControlNotify(){};
	~XEPropertyObjectAnimPlayControlNotify(){};
	enum{ PROPERTY_ = XEPropertyTree::USER_PROPRETY_INDEX };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTYOBJECTEANIMPLAYCONTROLNOTIFY_H
