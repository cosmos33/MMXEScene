/******************************************************************************

@File         XEMagicCoreTrackingActorBase.h

@Version       1.0

@Created     2019,3,21

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE_MAGIC_CORE_TRACKING_ACTOR_BASE_H
#define XE_MAGIC_CORE_TRACKING_ACTOR_BASE_H
#include "XEMagicCoreActorBase.h"

class XEMagicCoreTrackingActorBase : public XEMagicCoreActorBase
{
public:
	XEMagicCoreTrackingActorBase() :m_bEnableMMCVCore(xfalse), m_bDetected(xfalse){}
	virtual ~XEMagicCoreTrackingActorBase(){}
	virtual void                    Release() override;
public:
	virtual void					MMCVDetectEnableChange(xbool bEnable);
protected:
	virtual xbool				    PostDetachForParentActor(XEActor* pChildActor)override;
	virtual xbool				    PreAttachActorForParentActor(XEActor* pChildActor) override;
	void							RestoreActorTransform();
public:
	X_FORCEINLINE void		        SetEnableMMCVCore(xbool bEnable){ m_bEnableMMCVCore = bEnable; }
	X_FORCEINLINE xbool		        IsEnableMMCVCore(){ return m_bEnableMMCVCore; }
	X_FORCEINLINE void		        SetDetected(xbool bEnable){ m_bDetected = bEnable; }
	X_FORCEINLINE xbool		        IsDetected(){ return m_bDetected; }
public:
	XE_ACTOR_CAST(XEMagicCoreTrackingActorBase)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)
public:
	static const XString ACTOR_TYPENAME;
	static const XString ACTOR_SHORT_NAME;
protected:
	xbool						    m_bEnableMMCVCore;
	xbool						    m_bDetected;
};
#endif // XE_MAGIC_CORE_ACTOR_BASE_H
