/******************************************************************************

@File         XEPropertyObjectPhyTwistConstraint.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_PHYSICS_TWIST_CONSTRAINT_H
#define _XE_PROPERTY_OBJECT_PHYSICS_TWIST_CONSTRAINT_H
#include "XEPropertyObjectConstraintBaseParams.h"

class XEPropertyObjectPhyTwistConstraint
	:public XEPropertyObjectConstraintBaseParams
{
public:
	XEPropertyObjectPhyTwistConstraint(){};
	~XEPropertyObjectPhyTwistConstraint(){};

	enum
	{
		//Twist
		PROPERTY_TWIST_CONSTRAINT_TWIST_LIMIT_DEGREES = PROPERTY_CONSTRAINT_BASE_INDEX_LAST,
		PROPERTY_TWIST_CONSTRAINT_TWIST_MOTION
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTY_OBJECT_PHYSICS_TWIST_CONSTRAINT_H
