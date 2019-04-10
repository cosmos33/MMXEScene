/******************************************************************************

@File         XEPropertyObjectAnimElement.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTANIMELEMENT_H
#define _XEPROPERTYOBJECTANIMELEMENT_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimElement 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimElement(){};
	~XEPropertyObjectAnimElement(){};
	enum{ 
		PROPERTY_TIME_STAMP_NODE = XEPropertyTree::USER_PROPRETY_INDEX, 
		PROPERTY_START_TIME, PROPERTY_END_TIME,
		PROPERTY_CLIP_START_END_TIME,
		PROPERTY_SEGMENT_CLIP_START_TIME,
		PROPERTY_SEGMENT_CLIP_END_TIME,
		PROPERTY_SEGMENT_PLAY_RATE, 
		PROPERTY_INDEX_END };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTYOBJECTANIMELEMENT_H
