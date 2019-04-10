/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUILISTVIEW_H
#define XEPROPERTYOBJECTUILISTVIEW_H
#include "XEPropertyObjectUIScrollView.h"
class XUINode;
class XEPropertyObjectUIListView
	:public XEPropertyObjectUIScrollView
{
public:
	XEPropertyObjectUIListView() :XEPropertyObjectUIScrollView(){};
	~XEPropertyObjectUIListView(){};
	enum{ 
		PROPERTY_LISTVIEW = PROPERTY_SCROLLVIEW_END,

		PROPERTY_MAGNETIC_TYPE,
		PROPERTY_MAGNETICALLOWED_OUTOF_BOUNDARY,
		PROPERTY_ITEMSMARGIN,
		PROPERTY_SCROLL_DURATION,

		PROPERTY_LISTVIEW_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
