/******************************************************************************

@File         XEPropertyObjectPhyConeConstraint.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_PHYSICS_CONE_CONSTRAINT_H
#define _XE_PROPERTY_OBJECT_PHYSICS_CONE_CONSTRAINT_H
#include "XEPropertyObjectConstraintBaseParams.h"

class XEPropertyObjectPhyConeConstraint
	:public XEPropertyObjectConstraintBaseParams
{
public:
	XEPropertyObjectPhyConeConstraint(){};
	~XEPropertyObjectPhyConeConstraint(){};

	enum
	{
		//Cone
		PROPERTY_CONE_CONSTRAINT_SWING1_LIMIT_DEGREES = PROPERTY_CONSTRAINT_BASE_INDEX_LAST,
		PROPERTY_CONE_CONSTRAINT_SWING2_LIMIT_DEGREES,
		PROPERTY_CONE_CONSTRAINT_SWING1_MOTION,
		PROPERTY_CONE_CONSTRAINT_SWING2_MOTION
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTY_OBJECT_PHYSICS_CONE_CONSTRAINT_H
