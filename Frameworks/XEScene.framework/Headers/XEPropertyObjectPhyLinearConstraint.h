/******************************************************************************

@File         XEPropertyObjectPhyLinearConstraint.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_PHYSICS_LINEAR_CONSTRAINT_H
#define _XE_PROPERTY_OBJECT_PHYSICS_LINEAR_CONSTRAINT_H
#include "XEPropertyObjectConstraintBaseParams.h"

class XEPropertyObjectPhyLinearConstraint
	:public XEPropertyObjectConstraintBaseParams
{
public:
	XEPropertyObjectPhyLinearConstraint(){};
	~XEPropertyObjectPhyLinearConstraint(){};

	enum
	{
		//Linear
		PROPERTY_LINEAR_CONSTRAINT_LIMIT = PROPERTY_CONSTRAINT_BASE_INDEX_LAST,
		PROPERTY_LINEAR_CONSTRAINT_X_MOTION,
		PROPERTY_LINEAR_CONSTRAINT_Y_MOTION,
		PROPERTY_LINEAR_CONSTRAINT_Z_MOTION,//ÔÝÊ±²»¿É±à¼­
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XE_PROPERTY_OBJECT_PHYSICS_LINEAR_CONSTRAINT_H
