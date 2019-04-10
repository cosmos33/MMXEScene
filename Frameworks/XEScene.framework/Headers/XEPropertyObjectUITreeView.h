/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUITREEVIEW_H
#define XEPROPERTYOBJECTUITREEVIEW_H
#include "XEPropertyObjectUIScrollView.h"
class XUINode;
class XEPropertyObjectUITreeView
	:public XEPropertyObjectUIScrollView
{
public:
	XEPropertyObjectUITreeView() :XEPropertyObjectUIScrollView(){};
	~XEPropertyObjectUITreeView(){};
	enum{ 
		PROPERTY_TREEVIEW = PROPERTY_SCROLLVIEW_END,

		PROPERTY_LINE_INDENT,
		PROPERTY_ROW_HEIGHT,
		PROPERTY_DEFAULT_FONTSIZE,

		PROPERTY_TREEVIEW_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
