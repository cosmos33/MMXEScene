/******************************************************************************

@File         XETrackSocketComponentBase.h

@Version       1.0

@Created      2019, 6,4

@Description  

@HISTORY:

******************************************************************************/
#ifndef XE_TRACK_SOCKET_COMPONENT_H
#define XE_TRACK_SOCKET_COMPONENT_H
#include "XEActorComponent.h"
#include "XEFaceKeyPointInstance.h"

class XEMagicTrackingBaseInstance;
class XETrackSocketComponentBase
	: public XEActorComponent
{
public:
	XETrackSocketComponentBase();
	virtual ~XETrackSocketComponentBase();
	virtual void                            Empty()override;
	virtual void							Render(XEViewport* pViewport) override;
	virtual void							Tick(xfloat32 fDel, xbool bForceTick = xtrue) override;
	virtual XMLElement*						Serialize(XMLElement* pEleParent) override;
	virtual void							Deserialize(const XMLElement* pEleComponent) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC		  	                            
	virtual void							GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif		
public:
	XEMagicTrackingBaseInstance*			GetMagicTrackingInfo(){ return m_pTrackingInfo; }
	XVECTOR2								GetRefDeviceWidthHeight(){ return m_vRefDeviceWidthHeight; }
	virtual void                            UpdateDeviceWidthHeight(xfloat32 fWidth, xfloat32 fHeight);
	void									SetZDelta(xfloat32 fZDelta){ m_fZDelta = fZDelta; }
	xfloat32								GetZDelta(){ return m_fZDelta; }
protected:
	virtual void							UpdateTransform(){}
	XEViewport*								GetXEViewport();
	virtual	void							SerializeTransform(XMLElement* pEleComponent)override{}
public:
	XE_COMPONENT_CAST(XETrackSocketComponentBase)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	static const XString COMPONENT_TYPENAME;
protected:
	XEMagicTrackingBaseInstance*		    m_pTrackingInfo;
	XVECTOR2                                m_vRefDeviceWidthHeight;//参照设备宽高
	xfloat32								m_fZDelta;//[0,1]
	xfloat32								m_fDeviceScale;
};

#endif // XE_TRACK_SOCKET_COMPONENT_H