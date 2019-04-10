/******************************************************************************

@File         XEPropertyObjectAnimElementAnimation.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUSERNODEANIMELEMENTANIMATION_H
#define XEPROPERTYOBJECTUSERNODEANIMELEMENTANIMATION_H
#include "XEPropertyObjectAnimElement.h"

class XEPropertyObjectAnimElementAnimation 
	:public XEPropertyObjectAnimElement
{
public:
	XEPropertyObjectAnimElementAnimation(){};
	~XEPropertyObjectAnimElementAnimation(){};
	enum{ PROPERTY_SEQ_PATH = XEPropertyObjectAnimElement::PROPERTY_INDEX_END, PROPERTY_SEQ_DURATION };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTUSERNODEANIMELEMENTANIMATION_H
