/******************************************************************************

@File         XEFilterShapeFace.h

@Version       1.0

@Created      2019, 6, 27

@HISTORY:    Filter node

******************************************************************************/
#ifndef _XE_FILTER_SHAPE_FACE_H_
#define _XE_FILTER_SHAPE_FACE_H_

#include "XEFilter.h"

//other params will be saved to the material instance.
class XEFilterShapeFace 
	: public XEFilter
{
public:
	enum eShapeFaceMode{ SFM_ANYWHERE, SFM_EYES, SFM_FACE, SFM_MOUTH};
	XEFilterShapeFace();
	virtual ~XEFilterShapeFace();
	friend class XEFilterShapeFaceInstance;
public:
	virtual void                                  Deserialize(const XMLElement* pEleRoot,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	virtual void                                  Release() override;
public:
	X_FORCEINLINE void                            SetShapeFaceMode(eShapeFaceMode sfm){ m_eShapeFaceMode = sfm; }
	X_FORCEINLINE eShapeFaceMode                  GetShapeFaceMode()const{ return m_eShapeFaceMode; }
	X_FORCEINLINE void                            SetShapeFaceIntensity(xfloat32 fVal ){ m_fShapeIntensity= fVal; }
	X_FORCEINLINE xfloat32                        GetShapeFaceIntensity()const{ return m_fShapeIntensity; }
public:
	XE_USER_NODE_CAST(XEFilterShapeFace)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	eShapeFaceMode                                m_eShapeFaceMode;
	xfloat32                                      m_fShapeIntensity;// distance between vertex and the center will be multiplied by this


};

#endif // _XE_FILTER_SHAPE_FACE_H_
