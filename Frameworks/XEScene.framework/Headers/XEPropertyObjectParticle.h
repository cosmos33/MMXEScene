/******************************************************************************

@File         XEPropertyObjectParticle.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTPARTICLE_H
#define XEPROPERTYOBJECTPARTICLE_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectParticle 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectParticle(){};
	~XEPropertyObjectParticle(){};
	enum
	{ 
		PROPERTY_ASSETPATH = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_PARTICLE_PREVIEW,
		PROPERTY_AUTO_ACTIVE
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTPARTICLE_H
