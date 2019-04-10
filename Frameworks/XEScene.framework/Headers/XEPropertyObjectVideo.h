/******************************************************************************

@File         XEPropertyObjectVideo.h

@Version       1.0

@Created      2018/5/30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTVIDEO_H
#define XEPROPERTYOBJECTVIDEO_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectVideo 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectVideo(){};
	~XEPropertyObjectVideo(){};
	enum{ PROPERTY_RECT = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ARADS_NODE,
		PROPERTY_ARADS_REFERENCE
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTVIDEO_H
