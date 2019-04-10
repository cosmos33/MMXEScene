/******************************************************************************

@File         XEPropertyObjectAnimBlendEleAnimation.h

@Version       1.0

@Created      2018, 9, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECT_USERNODE_ANIMBLENDELEANIMATION_H
#define XEPROPERTYOBJECT_USERNODE_ANIMBLENDELEANIMATION_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimBlendEleAnimation
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimBlendEleAnimation(){};
	~XEPropertyObjectAnimBlendEleAnimation(){};
	enum{
		PROPERTY_ANIMATION = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_SEQ_PATH,
		PROPERTY_SEQ_DURATION,		
		PROPERTY_INDEX_END
	};	
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECT_USERNODE_ANIMBLENDELEANIMATION_H
