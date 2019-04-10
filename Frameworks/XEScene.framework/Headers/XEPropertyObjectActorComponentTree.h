/******************************************************************************

@File         XEPropertyObjectActorComponentTree.h

@Version       1.0

@Created      2018, 8, 17

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTYOBJECT_ACTORCOMPONENTTREE_H
#define _XE_PROPERTYOBJECT_ACTORCOMPONENTTREE_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectActorComponentTree 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectActorComponentTree(){}
	~XEPropertyObjectActorComponentTree(){}
	enum
	{ 
		PROPERTY_ACTOR_SELF = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ROOTCOMPONENT,
		PROPERTY_CHILDREN_COMPONENT_BEGIN,
		PROPERTY_CHILDREN_COMPONENT_END = PROPERTY_CHILDREN_COMPONENT_BEGIN + 1000//AS MAX AS 1000? ENOUGH?
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTYOBJECT_ACTORCOMPONENTTREE_H   