/******************************************************************************

@File         XEPropertyObjectAnimationMesh.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTANIMATIONMESH_H
#define XEPROPERTYOBJECTANIMATIONMESH_H
#include "XEPropertyObjectStaticMesh.h"
#include "XEAnimatableModelComponent.h"

class XEPropertyObjectAnimationMesh 
	:public XEPropertyObjectStaticMesh
{
public:
	XEPropertyObjectAnimationMesh(){};
	~XEPropertyObjectAnimationMesh(){};
	enum{ PROPERTY_ = PROPERTY_INDEX_LAST + 1 };
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
protected:
	virtual xint32  GetAnimationList(XArray<XString>& list) override;
	virtual void    ClearAnimation() override;
};

#endif // XEPROPERTYOBJECTANIMATIONMESH_H
