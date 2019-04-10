/******************************************************************************

@File         XEPropertyObjectConstraintBaseParams.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_BASE_PARAMS_H
#define _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_BASE_PARAMS_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectConstraintBaseParams
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectConstraintBaseParams(){};
	~XEPropertyObjectConstraintBaseParams(){};
	enum
	{
		PROPERTY_CONSTRAINT_OTHER = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_CONSTRAINT_STIFFINESS,
		PROPERTY_CONSTRAINT_DAMPING,//具体作用效果未研究透彻
		PROPERTY_CONSTRAINT_RESTITUTION,//具体作用效果未研究透彻
		PROPERTY_CONSTRAINT_CONTACTDISTANCE,//还不支持，不必调整。
		PROPERTY_CONSTRAINT_SOFT_CONSTRAINT,//还不支持，不必调整。
		PROPERTY_CONSTRAINT_BASE_INDEX_LAST		
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
};

#endif // _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_BASE_PARAMS_H
