/******************************************************************************

@File         XEPropertyObjectSkeletalPhysicsRes.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTY_OBJECT_SKELETAL_PHYICS_INSTANCE_H
#define _XEPROPERTY_OBJECT_SKELETAL_PHYICS_INSTANCE_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectSkeletalPhysicsRes
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectSkeletalPhysicsRes(){};
	~XEPropertyObjectSkeletalPhysicsRes(){};
	enum
	{
		PROPERTY_PHYSICAL_ASSET_PATH = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_SIMULATE_PHYSICAL_INSTACEN,
		PROPERTY_BEBUG_RENDER,
		PROPERTY_SIMULATE_PHYSICAL_SIMULATE,
		PROPERTY_PHYSICAL_ASSET_REMOVE
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTY_OBJECT_SKELETAL_PHYICS_INSTANCE_H
