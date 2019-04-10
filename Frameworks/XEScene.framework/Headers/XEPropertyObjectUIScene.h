/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUISCENE_H
#define XEPROPERTYOBJECTUISCENE_H
#include "XEPropertyObjectUINode.h"
class XUINode;
class XEPropertyObjectUIScene
	:public XEPropertyObjectUINode
{
public:
	XEPropertyObjectUIScene();
	~XEPropertyObjectUIScene(){};
	enum{ 
		PROPERTY_SCENE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_DESIGNRESOLUTION,
		PROPERTY_RESOLUTIONPOLICY,
		PROPERTY_BANGSSCREEN,

		PROPERTY_SCENE_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
