/******************************************************************************

@File         XE2DRectangleComponent.h

@Version       1.0

@Created      2017, 9, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE2DRECTANGLECOMPONENT_H
#define XE2DRECTANGLECOMPONENT_H
#include "XEActorComponent.h"

class XE2DRectangleComponent:public XEActorComponent
{
public:
	XE2DRectangleComponent();
	~XE2DRectangleComponent(){};
public:
	virtual void                 Release() override;
	virtual void                 Render(XEViewport* pViewport) override;
	virtual void                 Deserialize(const XMLElement* pEleComponent) override;
	virtual XMLElement*          Serialize(XMLElement* pEleParent) override;

	xfloat32                     GetXRelative() const;
	xfloat32                     GetYRelative() const;
	xfloat32                     GetWRelative() const;
	xfloat32                     GetHRelative() const;
public:
	XE_COMPONENT_CAST(XE2DRectangleComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XE2DRectangleComponent)
	static const XString COMPONENT_TYPENAME;
public:
	xint32                       m_nX; ///rect start point.x
	xint32                       m_nY; ///rect start point.y
	xint32                       m_nWidth;  ///paint w
	xint32                       m_nHeight; ///paint h
	XCOLORBASE                   m_clr; 
	xbool                        m_bSolid; 
	//relative width and height
	xint32                       m_nRelativeWidth;  
	xint32                       m_nRelativeHeight; 
};

#endif // XE2DRECTANGLECOMPONENT_H
