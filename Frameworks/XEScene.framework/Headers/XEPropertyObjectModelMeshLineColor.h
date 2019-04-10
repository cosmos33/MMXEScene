/******************************************************************************

@File         XEPropertyObjectModelMeshLineColor.h

@Version       1.0

@Created      2019, 1, 14 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE_PROPERTY_OBJECT_MODEL_MESH_LINE_COLOR_H
#define XE_PROPERTY_OBJECT_MODEL_MESH_LINE_COLOR_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectModelMeshLineColor
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectModelMeshLineColor(){}
	~XEPropertyObjectModelMeshLineColor(){}

	enum{
		PROPERTY_MODELMESH_LINE_COLOR_NODE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_MODELMESH_BOUNDING_BOX_COLOR,
		PROPERTY_MODELMESH_VERTEX_NORMAL_LINE_COLOR,
		PROPERTY_MODELMESH_VERTEX_TANGENT_LINE_COLOR,
		PROPERTY_MODELMESH_VERTEX_BINORMAL_LINE_COLOR,
		PROPERTY_MODELMESH_VERTEX_COLOR,
		PROPERTY_MODELMESH_WIREFRAME_BEGIN_COLOR,
	};

public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif //XE_PROPERTY_OBJECT_MODEL_MESH_LINE_COLOR_H