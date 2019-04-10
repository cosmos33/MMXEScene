/******************************************************************************

@File         XEPropertyObjectMultActorProperty.h

@Version      1.0

@Created      2018, 6, 2

@Description  The class ids of each class in X Editor.Customization Property

@HISTORY:

******************************************************************************/

#ifndef _XE_PROPERTY_OBJECT_ACTOR_ARRAY_H_
#define _XE_PROPERTY_OBJECT_ACTOR_ARRAY_H_

#include "XEPropertyObjectBase.h"
#include "XEFactoryPropertyObjectUtil.h"

class XEPropertyObjectMultActorProperty 
	: public XEPropertyObjectBase
{
public:
	XEPropertyObjectMultActorProperty(){}
	~XEPropertyObjectMultActorProperty(){}
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
private:
	void			BuildPropertyTree(xint32 nFilter,XEPropertyTree& PropTree, XEPropertyObjectBase* pPropertyObject);
	XEValueProperty::EPropertyAccessType			GetPropertyAccessType(XEValueProperty* pSourceProperty, XEPropertyObjectBase* pPropertyObject);
};

#endif//_XE_PROPERTY_OBJECT_ACTOR_ARRAY_H_