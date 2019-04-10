/******************************************************************************

@File         XEPropertyObjectScript.h

@Version       1.0

@Created      2018, 9, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECT_SCRIPT_H_
#define _XEPROPERTYOBJECT_SCRIPT_H_
#include "XEPropertyObjectBase.h"

//modify running instances and its unique template.
class XEPropertyObjectScript 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectScript(){};
	~XEPropertyObjectScript(){};
	enum{ 
		PROPERTY_SCRIPT_TYPE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_SCRIPT_HOLDER_TYPE,
		PROPERTY_SCRIPT_AUTO_RUN,
		PROPERTY_SCRIPT_RELOAD,
		PROPERTY_SCRIPT_CREATE_CODE_FILE,
		PROPERTY_SCRIPT_ASSET_PATH
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
protected:
	static XArray<XString>& GetScriptTypeDict();
	static XArray<XString>& GetScriptHolderTypeDict();
	static XString          GetExtByScriptType(int nType);
};

#endif // _XEPROPERTYOBJECT_SCRIPT_H_
