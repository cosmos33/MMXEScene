/******************************************************************************

@File         XEFaceTrackerListenerBridge.h

@Version       1.0

@Created      2019, 3, 11

@Description 

@HISTORY:

******************************************************************************/
#ifndef XE_FACE_TRACKER_LISNTEN_BRIDGE_H
#define XE_FACE_TRACKER_LISNTEN_BRIDGE_H

#include "XMemBase.h"
#include "XEDecorationEnvBridgeBase.h"

class XEFaceTrackerActor;
class XEFaceTrackListenerBridge : public XMemBase
{
public:
	XEFaceTrackListenerBridge(XEFaceTrackerActor* pAttachActor);
	virtual								~XEFaceTrackListenerBridge(){}
	void								Release();
	X_FORCEINLINE XEFaceTrackerActor*	GetAttachActor(){ return m_pAttachActor; }
	X_FORCEINLINE XEFaceTrackerActor*	GetAttachActor()const { return m_pAttachActor; }

public:
	void					            OnMMCVDetectEnableChange(xbool bEnable);
	void		                        OnBodyEntityDetected(xbool bDetectBody, const XEMagicCore::XEBodyEntity& entity);
	void		                        OnBodyEntitiesChangeDetected(xbool bDetectBody, const XEMagicCore::BodyEntityList& entities);
	void					            OnFaceEntitiesChangeDetected(xbool bDetectFace, const XEMagicCore::FaceEntityList& entities);

public:
	void								UpdateFaceKeySocketActor(const XMATRIX4& matFaceWorld);

private:
	XEFaceTrackerActor*					m_pAttachActor;
};
#endif

