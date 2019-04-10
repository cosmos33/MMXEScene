/******************************************************************************

@File         XEPropertyObjectMaterialFx.h

@Version       1.0

@Created      2018, 9, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECT_MATERIAL_FX_H_
#define _XEPROPERTYOBJECT_MATERIAL_FX_H_
#include "XEPropertyObjectBase.h"

//modify running instances and its unique template.
class XEPropertyObjectMaterialFx 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectMaterialFx(){};
	~XEPropertyObjectMaterialFx(){};
	enum{ 
		PROPERTY_MAT_HOLDER_TYPE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_MAT_AUTO_RUN
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
protected:
	static XArray<XString>& GetMaterialFxHolderTypeDict();
};

#endif // _XEPROPERTYOBJECT_MATERIAL_FX_H_
