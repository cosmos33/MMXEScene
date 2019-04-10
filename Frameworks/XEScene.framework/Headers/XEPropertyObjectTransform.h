/******************************************************************************

@File         XEPropertyObjectTransform.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTTRANSFORM_H
#define XEPROPERTYOBJECTTRANSFORM_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectTransform 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectTransform();
	~XEPropertyObjectTransform(){};
	enum{ PROPERTY_ROOT=XEPropertyTree::ROOT_INDEX,PROPERTY_LOCATION = XEPropertyTree::USER_PROPRETY_INDEX, PROPERTY_ROTATION, PROPERTY_SCALE };
	enum{ TRANSFORM_RELATIVE, TRANSFORM_WORLD };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
/*
	inline void			SetRelativeWorldToggle(const xint32 nReleativeWorldToggle){ m_nRelativeWorldToggle = nReleativeWorldToggle; }
	inline xint32			GetRelativeWorldToggle(){ return m_nRelativeWorldToggle; }*/
	xint32 m_nRelativeWorldToggle;
};

#endif // XEPROPERTYOBJECTTRANSFORM_H
