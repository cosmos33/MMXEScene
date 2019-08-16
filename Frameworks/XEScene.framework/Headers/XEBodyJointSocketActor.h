/******************************************************************************

@File         XEBodyJointSocketActor.h

@Version       1.0

@Created      2019, 6, 4

@Description  此类Actor是基于身体关节点、并且可以挂载2D/3D Actor的容器.

@HISTORY:

******************************************************************************/
#ifndef XE_MAGIC_BODY_KEY_POINTSOCKET_ACTOR_H
#define XE_MAGIC_BODY_KEY_POINTSOCKET_ACTOR_H
#include <mutex>
#include "XEMagicCoreTrackingActorBase.h"
#include "XEMagicCore.h"
/*
* Note:此类Actor只能Attach到XEFaceTrackerActor，不支持附加到其他类型Actor.
*/

class XEViewport;
class XEBodyJointSocketActor
	: public XEMagicCoreTrackingActorBase
{
public:
	XEBodyJointSocketActor();
	virtual ~XEBodyJointSocketActor(){};
public:
	virtual void					Initialize(XEWorld* pWorld) override;
	virtual const XArray<XString>&	GetParentActorTypeFilterList()const override;
	virtual void                    Render(XEViewport* pViewport) override;
	virtual void				    Tick(xfloat32 fDels, xbool bForceTick = xtrue) override;

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet		GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
public:
	X_FORCEINLINE void              SetRenderLandmarksEnable(xbool bEnable){ m_bRenderLandmarks = bEnable; }
	X_FORCEINLINE xbool             IsRenderLandmarksEnable()const{ return m_bRenderLandmarks; }
	X_FORCEINLINE void              SetLandmarkColor(const XCOLORBASE& color){ m_clLandmark = color; }
	X_FORCEINLINE const XCOLORBASE& GetLandmarkColor()const{ return m_clLandmark; }
public:
	const XArray<XEMagicCore::XEBodyJoint>&			GetLandMark() const;
	XVECTOR2                        GetLandMarkPoint(xint32 nPointIndex) const;
	void                            CopyLandMark(XArray<XEMagicCore::XEBodyJoint>& arrLandmark) const;
	void		                    BodyEntityDetected(xbool bDetectCurrentBody, const XEMagicCore::XEBodyEntity& entity);
	void		                    BodyEntitiesChangeDetected(xbool bDetectCurrentBody, const XEMagicCore::BodyEntityList& entities);
public:
	XE_ACTOR_CAST(XEBodyJointSocketActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEBodyJointSocketActor)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)

	static const XString	       ACTOR_TYPENAME;
	static const XString	       ACTOR_SHORT_NAME;
protected:
	static XArray<XString>	         s_aFilterParentActorType;
	xbool							 m_bRenderLandmarks;
	mutable std::mutex		         m_mutexLandMark;
	XArray<XEMagicCore::XEBodyJoint> m_aJointsCache;
	XCOLORBASE					     m_clLandmark;
};

#endif