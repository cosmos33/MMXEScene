#pragma once
#include "XEPropertyObjectBase.h"

class XEPropertyObjectModelMesh
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectModelMesh(){}
	~XEPropertyObjectModelMesh(){}

	enum{
		PROPERTY_RENDER_SKELETON = XEPropertyTree::USER_PROPRETY_INDEX
	};

public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

