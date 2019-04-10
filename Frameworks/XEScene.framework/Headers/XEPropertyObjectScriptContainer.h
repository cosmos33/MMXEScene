/******************************************************************************

@File         XEPropertyObjectScriptContainer.h

@Version       1.0

@Created      2018, 9, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECT_SCRIPTCONTAINER_H_
#define _XEPROPERTYOBJECT_SCRIPTCONTAINER_H_
#include "XEPropertyObjectBase.h"

//modify running instances and its unique template.
class XEPropertyObjectScriptContainer 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectScriptContainer(){};
	~XEPropertyObjectScriptContainer(){};
	enum{ 
		PROPERTY_ASSET_PATH = XEPropertyTree::USER_PROPRETY_INDEX
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // _XEPROPERTYOBJECT_SCRIPTCONTAINER_H_
