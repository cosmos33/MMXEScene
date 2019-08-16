/******************************************************************************

@File         XEAnimCurveFlyController.h

@Version       1.0

@Created      2018, 12, 28

@Description  The class ids of each class in X Editor, A fly controller using a curve that can apply to an actor, etc.

@HISTORY:

******************************************************************************/

#include "XCurve.h"
#include "XClassReflector.h"
#include "XEUtility.h"
#include "XEAnimController.h"

class XEWorld;
class XEActor;
class XEActorComponent;
class XBaseCamera;
class XEAnimCurveFlyController
	:public XEAnimController
{
	typedef XEAnimController Super;
public:
	// Called every frame
	XEAnimCurveFlyController();
	virtual ~XEAnimCurveFlyController(){}
	enum eCanDriveObjectType{ AT_ACTOR, AT_COMPONENT, AT_CAMERA_BASE, AT_USER_DATA };
	enum eFlyAccelerationType{ FAT_LINEAR, FAT_ATAN };

	X_CLASS_DEF(XEAnimCurveFlyController)
	class Listener
		:public XEAnimController::Listener
	{
	public:
		Listener(){}
		virtual ~Listener(){}
		X_EES_LINE virtual void Ls_Flying(XEAnimCurveFlyController* pController, xfloat32 fCurTime, const XMATRIX4& mat4){}//you can do something with the controller, e.g, pause the flying at a pecific.
	};
private:
	class TemporalObject :public XEUtility::XETemporalObject
	{
		friend class XEAnimCurveFlyController;
	protected:
		TemporalObject(XEAnimCurveFlyController* pController, eCanDriveObjectType type, void* target) :controller(pController), eType(type), done(xfalse), target(target){}
		virtual xbool ShouldBeDeleted() override{ return done; }
		virtual void  Tick(xfloat32 fDel) override;
		virtual void  Release() override{ done = xtrue; }
		XEAnimCurveFlyController* controller;
		xbool done;
		eCanDriveObjectType eType;
		union
		{
			void* target;
			XEActor* actor;
			XEActorComponent* component;
			XBaseCamera* baseCamera;  
		};
	};
public:
	virtual xint32                     GetTimeLength() const override;
	virtual void                       SetTime(xint32 nTime) override;//in micro seconds.
	virtual void                       Stop() override;
	virtual void                       BroadcastPlayOneTimeFinished(xbool bReversePlaying) override;
public:						           
	X_FORCEINLINE void                 SetFlyDuration(xfloat32 fTime){ m_fDuration = fTime; }//in seconds.
	X_FORCEINLINE xfloat32             GetFlyDuration()const{ return m_fDuration; }
	X_FORCEINLINE xfloat32             GetCurElapseTime()const{ return m_fElapseTime; }
	X_FORCEINLINE void                 SetFlyAccelerateLinearVelocity(xfloat32 fVelocity = 3.14159f){ m_fFlyAccelerateLinearVelocity = fVelocity; }//the accelerate will be changed according to the linear velocity
	X_FORCEINLINE xfloat32             GetFlyAccelerateLinearVelocity()const{ return m_fFlyAccelerateLinearVelocity; }
	X_FORCEINLINE void                 SetMinFlyDuration(xfloat32 fDuration){ m_fMinFlyDuration = fDuration; }
	X_FORCEINLINE xfloat32             GetMinFlyDuration()const{ return m_fMinFlyDuration; }
	X_FORCEINLINE void                 SetMaxFlyDuration(xfloat32 fDuration){ m_fMaxFlyDuration = fDuration; }
	X_FORCEINLINE xfloat32             GetMaxFlyDuration()const{ return m_fMaxFlyDuration; }
	void     						   SetFlyEndFadeFactor(xfloat32 fEndingRate = 5.f, xfloat32 fFlyInterval = 5.f);//ending area will be [-fFlyInterval, fEndingRate*fFlyInterval] of arctan(x)
	//curve mini-point-count: start,end.
	void                               SetFlyBegin(const XMATRIX4& mat4);
	void                               SetFlyBegin(const XVECTOR3& vLocation, const XVECTOR3& vForwardDir, const XVECTOR3&vUp);
	void                               SetFlyBegin(const XVECTOR3& vLocation, const XQUATERNION& quat);
	void                               SetFlyBegin(const XVECTOR3& vLocation, xfloat32 fRoll, xfloat32 fYaw, xfloat32 fPitch = 0.f);//z round - is forbidden by default.
	void                               SetFlyEnd(const XMATRIX4& mat4);
	void                               SetFlyEnd(const XVECTOR3& vLocation, const XVECTOR3& vForwardDir, const XVECTOR3& vUp);
	void                               SetFlyEnd(const XVECTOR3& vLocation, const XQUATERNION& quat);
	void                               SetFlyEnd(const XVECTOR3& vLocation, xfloat32 fRoll, xfloat32 fYaw, xfloat32 fPitch = 0.f);//z round - is forbidden by default.
	void                               SetupFlyPoint(const XMATRIX4& mat4, xfloat32 fPercent);//optional for adding a point to the curve. points with the explicit inValue(fPercent) will be replaced.
	xbool                              FlyToPercent(xfloat32 fPercent, XMATRIX4& matResult);//0-1
	xbool                              FlyToTimestamp(xfloat32 fTimestamp, XMATRIX4& matResult);//0-duration, in seconds.
	xfloat32                           GetCurFlyPercent()const;
	void                               Fly(XEWorld* pWorld, eCanDriveObjectType objType, void* pFlyObject, eFlyAccelerationType accelerateType = FAT_ATAN);//fly in world
private:				               
	xfloat32                           m_fDuration;//in seconds.
	xfloat32                           m_fElapseTime;//in seconds.
	xfloat32                           m_fFlyEndRate;//end fading factor: >= 1.0, 5.0 maybe the best.
	xfloat32                           m_fOutMinVal;
	xfloat32                           m_fOutMaxVal;
	xfloat32                           m_fMinFlyDuration;
	xfloat32                           m_fMaxFlyDuration;
	xfloat32                           m_fFlyInterval;
	xfloat32                           m_fFlyAccelerateLinearVelocity;
	eFlyAccelerationType               m_eFlyAccelerationType;
	XInterpCurveVector                 m_flyLocationCurve;
	FInterpCurve<XQUATERNION>          m_flyRotationcurve;//in quaternion.
	TemporalObject*                    m_pCurFlyTemporalObject;
};
