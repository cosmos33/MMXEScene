/******************************************************************************

@File         XEFilterFaceStretch.h

@Version       1.0

@Created      2019, 6, 27

@HISTORY:    Filter node

******************************************************************************/
#ifndef _XE_FILTER_FACE_STRETCH_H_
#define _XE_FILTER_FACE_STRETCH_H_

#include "XEFilter.h"

//other params will be saved to the material instance.
class XEFilterFaceStretch 
	: public XEFilter
{
public:
	XEFilterFaceStretch();
	virtual ~XEFilterFaceStretch();
	friend class XEFilterFaceStretchInstance;
public:
	virtual void                                  Deserialize(const XMLElement* pEleRoot,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
public:
	X_FORCEINLINE void							  SetLeftRightSymmetry(xbool bSymmetry){ m_bLeftRightSymmetry = bSymmetry; }
	X_FORCEINLINE xbool							  IsLeftRightSymmetry(){ return m_bLeftRightSymmetry; }
	X_FORCEINLINE void							  SetLockPoints(xbool bLocked){ m_bLockPoints = bLocked; }
	X_FORCEINLINE xbool							  IsLockPoints(){ return m_bLockPoints; }
	X_FORCEINLINE void							  SetStretchIntensity(xfloat32 fIntensity){ m_fStretchIntensity = fIntensity; }
	X_FORCEINLINE xfloat32						  GetStretchIntensity(){ return m_fStretchIntensity; }
public:
	XE_USER_NODE_CAST(XEFilterFaceStretch)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	xbool										  m_bLeftRightSymmetry;//left-right
	xbool										  m_bLockPoints;//lock points
	xfloat32									  m_fStretchIntensity;
};

#endif // _XE_FILTER_FACE_STRETCH_H_
