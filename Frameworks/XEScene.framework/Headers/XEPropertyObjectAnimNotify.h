/******************************************************************************

@File         XEPropertyObjectAnimNotify.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTEANIMNOTIFY_H
#define _XEPROPERTYOBJECTEANIMNOTIFY_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectAnimNotify 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAnimNotify(){};
	~XEPropertyObjectAnimNotify(){};
	enum{ 
		PROPERTY_TIME_STAMP_NODE = XEPropertyTree::USER_PROPRETY_INDEX, 
		PROPERTY_STARTTIME, 
		PROPERTY_SECTION_MODE,
		PROPERTY_SECTION_ENDTIME,
		PROPERTY_NOTIFY_STATUS, 
		PROPERTY_INDEX_END };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTYOBJECTEANIMNOTIFY_H
