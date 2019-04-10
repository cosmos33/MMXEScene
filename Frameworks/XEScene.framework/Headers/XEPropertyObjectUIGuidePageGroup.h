/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIGUIDEPAGEGROUP_H
#define XEPROPERTYOBJECTUIGUIDEPAGEGROUP_H
#include "XEPropertyObjectUINode.h"
class XUINode;
class XEPropertyObjectUIGuidePageGroup
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectUIGuidePageGroup() :XEPropertyObjectBase(){};
	virtual ~XEPropertyObjectUIGuidePageGroup(){};
	enum{ 
		PROPERTY_GUIDEPAGEGROUP,

		PROPERTY_LOCALZORDER,

		PROPERTY_GUIDEPAGEGROUP_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
