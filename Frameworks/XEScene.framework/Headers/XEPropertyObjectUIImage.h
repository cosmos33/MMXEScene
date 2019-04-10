/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIIMAGE_H
#define XEPROPERTYOBJECTUIIMAGE_H
#include "XEPropertyObjectUIWidget.h"
class XUINode;
class XEPropertyObjectUIImage
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIImage() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUIImage(){};
	enum{ 
		PROPERTY_IMAGE = PROPERTY_UIWIDGET_END,
		PROPERTY_TEXTURE,
		PROPERTY_FOLLOWTEXTURESIZE,
		PROPERTY_FLIPX,

		PROPERTY_USE_SEQUENCE,
		PROPERTY_UVTILE,
		PROPERTY_SEQUENCE_FPS,
		PROPERTY_ACTUAL_FRAME_NUM,
		PROPERTY_CURRENT_FRAME,

		PROPERTY_USE_9SLICE,
		PROPERTY_9SLICE,

		PROPERTY_IMAGE_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
