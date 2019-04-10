/******************************************************************************

@File         XEPropertyObjectSkeletalBody.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTSKELETALBODY_H
#define _XEPROPERTYOBJECTSKELETALBODY_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectSkeletalBody
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectSkeletalBody(){};
	~XEPropertyObjectSkeletalBody(){};
	enum
	{
		PROPERTY_BONE_NAME = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ENABLE_SIMULATE_PHYSICS,
// 		PROPRETY_PHYSICS_BLEND_WEIGHT,
// 		PROPERTY_SHAPE_MATERIAL,
// 		PROPERTY_GRAVITY_ENABLE,
// 		PROPERTY_MASS,
		PROPERTY_LINEAR_DAMPING,
		PROPERTY_ANGULAR_DAMPING,
		PROPERTY_DRAW,
		PROPERTY_PHYSICAL_MATERIAL_START,
		PROPERTY_PHYSICAL_MATERIAL_END = 5000
	};

	enum XParamWidgetType
	{
		EWTFP_FLOAT
	};

	struct XShapeMaterialParamDesc
	{
		XShapeMaterialParamDesc(){}
		XShapeMaterialParamDesc(xint32 nCurIndex, XString strCurParamName, XParamWidgetType eCurType)
			:nIndex(nCurIndex), strParamName(strCurParamName), eType(eCurType){}
		xint32				nIndex;
		XString				strParamName;
		XParamWidgetType	eType;
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

private:
	XHashTable<xint32, XShapeMaterialParamDesc>		m_tbParamCache;
};

#endif // _XEPROPERTYOBJECTSKELETALBODY_H
