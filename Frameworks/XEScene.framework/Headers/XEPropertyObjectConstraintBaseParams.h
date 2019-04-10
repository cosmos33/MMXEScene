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
		PROPERTY_CONSTRAINT_DAMPING,//��������Ч��δ�о�͸��
		PROPERTY_CONSTRAINT_RESTITUTION,//��������Ч��δ�о�͸��
		PROPERTY_CONSTRAINT_CONTACTDISTANCE,//����֧�֣����ص�����
		PROPERTY_CONSTRAINT_SOFT_CONSTRAINT,//����֧�֣����ص�����
		PROPERTY_CONSTRAINT_BASE_INDEX_LAST		
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
};

#endif // _XE_PROPERTY_OBJECT_PHYSICS_CONSTRAINT_BASE_PARAMS_H