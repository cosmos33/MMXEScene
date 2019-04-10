/******************************************************************************

@File         XEPropertyObjectOutline.h

@Version       1.0

@Created      2017, 12, 3

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XEPROPERTYOBJECT_OUTLINE_H_
#define _XEPROPERTYOBJECT_OUTLINE_H_
#include "XEPropertyObjectBase.h"


class XEPropertyObjectOutline : public XEPropertyObjectBase
{
public:
								XEPropertyObjectOutline(){};
	virtual						~XEPropertyObjectOutline(){};
	enum
	{
		PROPERTY_OUTLINEWIDTH = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_OUTLINECOLOR
	};

	virtual xbool				GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool				SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool				GetPropertyValue(XEProperty &Node) override;
};




#endif




