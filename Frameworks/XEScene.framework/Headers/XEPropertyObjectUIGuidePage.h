/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIGUIDEPAGE_H
#define XEPROPERTYOBJECTUIGUIDEPAGE_H
#include "XEPropertyObjectUINode.h"
class XUINode;
class XEPropertyObjectUIGuidePage
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectUIGuidePage() :XEPropertyObjectBase(){};
	virtual ~XEPropertyObjectUIGuidePage(){};
	enum{ 
		PROPERTY_GUIDEPAGE,

		PROPERTY_VISIBLE,
		PROPERTY_ALPHA,

		PROPERTY_GUIDEPAGE_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
