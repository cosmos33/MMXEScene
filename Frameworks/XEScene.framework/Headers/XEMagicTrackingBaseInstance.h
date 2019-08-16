/******************************************************************************

@File         XEMagicTrackingBaseInstance.h

@Version       1.0

@Created      2019, 6, 4

@Description 

@HISTORY:

******************************************************************************/
#ifndef _XE_TRACKING_BASE_INSTANCE_H
#define _XE_TRACKING_BASE_INSTANCE_H

#include "XTypes.h"
#include "XArray.h"
#include "XMath3D.h"
#include "XEUserNode.h"

class XEActorComponent;
class XEViewport;
class XEFaceTrackerActor;

class XEMagicTrackingBaseInstance : public XEUserNodeInstance
{
public:
	XEMagicTrackingBaseInstance(XEActorComponent* pComponent);
	virtual ~XEMagicTrackingBaseInstance(){}
public:
	virtual void                            RenderPivotPoint() const{};
	virtual void							Release();
	virtual XMLElement*                     Serialize(XMLElement* pEleParent) { return NULL; };
	virtual void                            Deserialize(const XMLElement* pEleComponent, XETreeNode::Manager* pNodeMgr = NULL){};
public:
	X_FORCEINLINE void                      SetShowPivotPoint(xbool bShow){ m_bShowPivotPoint = bShow; }
	X_FORCEINLINE xbool                     IsShowPivotPoint()const{ return m_bShowPivotPoint; }
	X_FORCEINLINE XEActorComponent*			GetAttachComponent(){ return m_pComponent; }
	X_FORCEINLINE const XArray<xint32>&		GetAllKeyPointIndex(){ return m_aIndex; }
	X_FORCEINLINE void						SetRefWidthHeight(const XVECTOR2& vRefDeviceWidthHeight){ m_vRefDeviceWidthHeight = vRefDeviceWidthHeight; }
public:
	void									RemoveAllKeyPointIndex();
	void									AddKeyPointIndex(xint32 nPointIndex);
	xbool									RemoveKeyPointIndex(xint32 nIndex);
	void									SetKeyPointIndex(xint32 nIndex, xint32 nFaceKeyPointIndex);
	virtual XVECTOR2                        GetPivotPoint() const{ return XVECTOR2(0); }
	virtual XMATRIX4						GetWorldTransform() const{ return XMATRIX4::IDENTITY; }
protected:
	virtual xbool							IsHasLandmarks() const{ return xfalse; }
	XEViewport*								GetXEViewPort() const;
	xbool									IsEnableRender() const;
public:
	XE_USER_NODE_CAST(XEMagicTrackingBaseInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	XEActorComponent*						m_pComponent;
	XArray<xint32>							m_aIndex;	
	xbool									m_bShowPivotPoint;
	XVECTOR2								m_vRefDeviceWidthHeight;
};

#endif