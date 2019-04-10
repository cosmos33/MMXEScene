/******************************************************************************

@File         XEPropertyObjectBone.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTEBONE_H
#define _XEPROPERTYOBJECTEBONE_H
#include "XEPropertyObjectBase.h"

//modify running instances and its unique template.
class XEPropertyObjectBone 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectBone() :m_nRelativeWorldToggle(TRANSFORM_RELATIVE){};
	~XEPropertyObjectBone(){};
	enum
	{ 
		PROPERTY_BONE_INDEX = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_TRANSFORM_NODE, 
		PROPRETY_RELATIVE_WORLD_TOGGLE,
		PROPERTY_LOCATION, 
		PROPERTY_ROTATION, 
		PROPERTY_SCALE 
	};
	enum{ TRANSFORM_RELATIVE, TRANSFORM_WORLD};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	void			SetRelativeWorldToggle(const xint32 nReleativeWorldToggle);
	xint32			GetRelativeWorldToggle(){ return m_nRelativeWorldToggle; }
	
protected:
	xint32 m_nRelativeWorldToggle;
	
};

#endif // _XEPROPERTYOBJECTEBONE_H
