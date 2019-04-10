/******************************************************************************

@File         XEPropertyObjectMeshApplique.h

@Version       1.0

@Created      2017, 12, 3

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XEPROPERTYOBJECT_MESH_APPLIQUE_H_
#define _XEPROPERTYOBJECT_MESH_APPLIQUE_H_
#include "XEPropertyObjectBase.h"
#include "XEMeshAppliqueComponent.h"

class XEPropertyObjectMeshApplique : public XEPropertyObjectBase
{
public:
								XEPropertyObjectMeshApplique(){};
	virtual						~XEPropertyObjectMeshApplique(){};
	enum
	{
		PROPERTY_MESH_APPLIQUE_LIST = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ADD_MESH_APPLIQUE,
		PROPERTY_MESH_APPLIQUE_FIRST,
		PROPERTY_MESH_APPLIQUE_END = PROPERTY_MESH_APPLIQUE_FIRST + 100,
		PROPERTY_APPLIQUE_MODEL_FILE_FIRST,
		PROPERTY_APPLIQUE_MODEL_FILE_END = PROPERTY_APPLIQUE_MODEL_FILE_FIRST + 100,
		PROPERTY_MESH_APPLIQUE_SKIN_NAME_FIRST,
		PROPERTY_MESH_APPLIQUE_SKIN_NAME_END = PROPERTY_MESH_APPLIQUE_SKIN_NAME_FIRST + 100,
		PROPERTY_MESH_APPLIQUE_MESH_NAME_FIRST,
		PROPERTY_MESH_APPLIQUE_MESH_NAME_END = PROPERTY_MESH_APPLIQUE_MESH_NAME_FIRST + 100,
		PROPERTY_MESH_APPLIQUE_DISTANCE_FIRST,
		PROPERTY_MESH_APPLIQUE_DISTANCE_END = PROPERTY_MESH_APPLIQUE_DISTANCE_FIRST + 100,
		PROPERTY_MESH_APPLIQUE_REMOVE_FIRST,
		PROPERTY_MESH_APPLIQUE_REMOVE_END = PROPERTY_MESH_APPLIQUE_REMOVE_FIRST + 100
	};

	virtual xbool				GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool				SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool				GetPropertyValue(XEProperty &Node) override;

private:
	XEMeshAppliqueComponent::XEAppliqueOperater*	GetAppliqueByIndex(xint32 nIndex, XArray<XEMeshAppliqueComponent::XEAppliqueOperater*>& aComponentOperaters);
};




#endif




