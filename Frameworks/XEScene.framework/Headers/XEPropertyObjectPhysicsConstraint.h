/******************************************************************************

@File         XEPropertyObjectPhysicsConstraint.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_H
#define _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectPhysicsConstraint
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectPhysicsConstraint(){};
	~XEPropertyObjectPhysicsConstraint(){};

	enum
	{
		PROPERTY_BONE1_NAME = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_BONE2_NAME,
		PROPERTY_BONE1_POS,
		PROPERTY_BONE2_POS,
		PROPERTY_BONE1_PRIAXIS,
		PROPERTY_BONE2_PRIAXIS,
		PROPERTY_BONE1_SECAXIS,
		PROPERTY_BONE2_SECAXIS,//以上参数均为程序自动算出，不要修改。
		PEOPERTY_RENDER,
		PEOPERTY_RENDER_SIZE
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_H
