/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUISCROLLVIEW_H
#define XEPROPERTYOBJECTUISCROLLVIEW_H
#include "XEPropertyObjectUILayout.h"
class XUINode;
class XEPropertyObjectUIScrollView
	:public XEPropertyObjectUILayout
{
public:
	XEPropertyObjectUIScrollView() :XEPropertyObjectUILayout(){};
	~XEPropertyObjectUIScrollView(){};
	enum{ 
		PROPERTY_SCROLLVIEW = PROPERTY_LAYOUT_END,

		PROPERTY_DIRECTION,
		PROPERTY_INNERCONTAINER_SIZE,
		PROPERTY_INNERCONTAINER_POSITION,
		
		PROPERTY_BOUNCEENABLED,
		PROPERTY_INERTIA_SCROLL_ENABLED,
		PROPERTY_SCROLLBARENABLED,
		PROPERTY_SCROLLBARWIDTH,
		PROPERTY_SCROLLBARCOLOR,
		PROPERTY_SCROLLBAR_AUTOHIDE_ENABLED,
		PROPERTY_SCROLLBAR_AUTOHIDE_TIME,

		PROPERTY_SCROLLVIEW_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
