/******************************************************************************

@File         XEPropertyObjectPhysicsRigid.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTPHYSICSRIGID_H
#define XEPROPERTYOBJECTPHYSICSRIGID_H
#include "XEPropertyObjectBase.h"

class XEPrimitiveComponent;
class XEPropertyObjectPhysicsRigid
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectPhysicsRigid(){};
	~XEPropertyObjectPhysicsRigid(){};
	enum{ 
		PROPERTY_PHYSICAL_PATH = XEPropertyTree::USER_PROPRETY_INDEX, 
		PROPERTY_SIMULATE_PHYSICAL, 
		PROPERTY_LINER_DAMPING,
		PROPERTY_ANGULAR_DAMPING,
		PROPERTY_RIGID_UCC,
		PROPERTY_RIGID_TYPE,
		PROPERTY_RIGID_GRAVITY,
		PROPERTY_RIGID_MASS,
		PROPERTY_RIGID_LINEAR_SPEED,
		PROPERTY_RIGID_ANGULAR_SPEED,
		PROPERTY_PHYSICAL_MATERIA_NAME,
		PROPERTY_PHYSICAL_MATERIAL_START, 
		PROPERTY_PHYSICAL_MATERIAL_END = 50,
		PROPERTY_PHYSICAL_ASSET_REMOVE
	};

	enum XParamWidgetType
	{
		EWTFP_FLOAT
	};

	struct XShapeMaterialParamDesc
	{
		XShapeMaterialParamDesc(){}
		XShapeMaterialParamDesc(xint32 nCurIndex, XString strCurParamName, XParamWidgetType eCurType)
			:nIndex(nCurIndex), strParamName(strCurParamName),eType(eCurType){}
		xint32				nIndex;
		XString				strParamName;
		XParamWidgetType	eType;
	};


public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

private:
	XHashTable<xint32,XShapeMaterialParamDesc>		m_tbParamCache;
};

#endif // XEPROPERTYOBJECTPHYSICSRIGID_H
