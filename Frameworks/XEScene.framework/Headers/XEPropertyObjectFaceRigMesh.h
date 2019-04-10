/******************************************************************************

@File         XEPropertyObjectFaceRigMesh.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE_PROPERTYOBJECT_FACERIG_MESH_H
#define XE_PROPERTYOBJECT_FACERIG_MESH_H
#include "XEPropertyObjectAnimationMesh.h"

class XEPropertyObjectFaceRigMesh 
	:public XEPropertyObjectAnimationMesh
{
public:
	XEPropertyObjectFaceRigMesh(){};
	~XEPropertyObjectFaceRigMesh(){};
	enum{
		PROPERTY_ANIMATION_PATH_LIST_AS_SCREEN_SAVER_FIRST = PROPERTY_INDEX_LAST + 2,
		PROPERTY_ANIMATION_PATH_LIST_AS_SCREEN_SAVER_LAST = PROPERTY_ANIMATION_PATH_LIST_AS_SCREEN_SAVER_FIRST + 100
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	virtual void    AnimationPropertyExtend(XEPropertyTree &PropTree,XEProperty* pAnimNode, xint32 nAnimIndex) override;
};

#endif // XE_PROPERTYOBJECT_FACERIG_MESH_H
