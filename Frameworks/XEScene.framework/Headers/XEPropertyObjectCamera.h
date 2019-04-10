/******************************************************************************

@File         XEPropertyObjectCamera.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTCAMERA_H
#define XEPROPERTYOBJECTCAMERA_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectCamera 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectCamera(){};
	~XEPropertyObjectCamera(){};
	enum
	{ 
		PROPERTY_SYSTEM_CAMERA = XEPropertyTree::USER_PROPRETY_INDEX, 
		PROPERTY_PICK_SCENE_CAMERA_PARAM,
		PROPERTY_PROJECTION, 
		PROPERTY_ZNEAR_ZFAR, 
		PROPERTY_FOV, 
		PROPERTY_RATIO, 
		PROPERTY_ORTHOWIDTH 
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTCAMERA_H
