#ifndef _IX2DJOINT_H_
#define _IX2DJOINT_H_

#include "XMemBase.h"
#include "XMath3D.h"

enum X2DJointType
{
	X_2DPHYSICS_JT_UNKNOWN,
	X_2DPHYSICS_JT_REVOLUTE,
	X_2DPHYSICS_JT_PRISMATIC,
	X_2DPHYSICS_JT_DISTANCE,
	X_2DPHYSICS_JT_PULLEY,
	X_2DPHYSICS_JT_MOUSE,
	X_2DPHYSICS_JT_GEAR,
	X_2DPHYSICS_JT_WHEEL,
	X_2DPHYSICS_JT_WELD,
	X_2DPHYSICS_JT_FRICTION,
	X_2DPHYSICS_JT_ROPE,
	X_2DPHYSICS_JT_MOTOR
};
class IX2DRigidBody;
struct X2DJointDesc
{
	X2DJointDesc()
	{
		eType = X_2DPHYSICS_JT_UNKNOWN;
		pUserData = NULL;
		pBodyA = NULL;
		pBodyB = NULL;
		bCollideConnected = xfalse;
	}
	X2DJointType eType;
	void* pUserData;
	IX2DRigidBody* pBodyA;
	IX2DRigidBody* pBodyB;
	xbool bCollideConnected;
};

struct X2DRevoluteJointDesc : public X2DJointDesc
{
	X2DRevoluteJointDesc()
		: vLocalAnchorA(0.0f)
		, vLocalAnchorB(0.0f)
		, fReferenceAngle(0.0f)
		, bEnableLimit(xfalse)
		, fLowerAngle(0.0f)
		, fUpperAngle(0.0f)
		, bEnableMotor(xfalse)
		, fMotorSpeed(0.0f)
		, fMaxMotorTorque(0.0f)
	{
		eType = X_2DPHYSICS_JT_REVOLUTE;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, const XVECTOR2& vAnchor);
	XVECTOR2	vLocalAnchorA;
	XVECTOR2	vLocalAnchorB;
	xfloat32	fReferenceAngle;
	xbool		bEnableLimit;
	xfloat32	fLowerAngle;
	xfloat32	fUpperAngle;
	xbool		bEnableMotor;
	xfloat32	fMotorSpeed;
	xfloat32	fMaxMotorTorque;
};

struct X2DPrismaticJointDesc : public X2DJointDesc
{
public:
	X2DPrismaticJointDesc()
		: vLocalAnchorA(0.0f)
		, vLocalAnchorB(0.0f)
		, vLocalAxisA(1.0f, 0.0f)
		, fReferenceAngle(0.0f)
		, bEnableLimit(xfalse)
		, fLowerTranslation(0.0f)
		, fUpperTranslation(0.0f)
		, bEnableMotor(xfalse)
		, fMotorSpeed(0.0f)
		, fMaxMotorForce(0.0f)
	{
		eType = X_2DPHYSICS_JT_PRISMATIC;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, const XVECTOR2& vAnchor, const XVECTOR2& vAxis);
	XVECTOR2	vLocalAnchorA;
	XVECTOR2	vLocalAnchorB; 
	XVECTOR2	vLocalAxisA;
	xfloat32	fReferenceAngle;
	xbool		bEnableLimit;
	xfloat32	fLowerTranslation;
	xfloat32	fUpperTranslation;
	xbool		bEnableMotor;
	xfloat32	fMotorSpeed;
	xfloat32	fMaxMotorForce;
};

struct X2DDistanceJointDesc : public X2DJointDesc
{
	X2DDistanceJointDesc()
		: vLocalAnchorA(0.0f)
		, vLocalAnchorB(0.0f)
		, fLength(1.0f)
		, fFrequencyHz(0.0f)
		, fDampingRatio(0.0f)
	{
		eType = X_2DPHYSICS_JT_DISTANCE;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, const XVECTOR2& vAnchorA, const XVECTOR2& vAnchorB);
	XVECTOR2	vLocalAnchorA;
	XVECTOR2	vLocalAnchorB;
	xfloat32	fLength;
	xfloat32	fFrequencyHz;
	xfloat32	fDampingRatio;
};

struct X2DPulleyJointDesc : public X2DJointDesc
{
	X2DPulleyJointDesc()
		: vGroundAnchorA(-1.0f, 1.0f)
		, vGroundAnchorB(1.0f, 1.0f)
		, vLocalAnchorA(-1.0f, 0.0f)
		, vLocalAnchorB(1.0f, 0.0f)
		, fLengthA(0.0f)
		, fLengthB(0.0f)
		, fRatio(1.0f)
	{
		eType = X_2DPHYSICS_JT_PULLEY;
		bCollideConnected = xtrue;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, 
				const XVECTOR2& vGAnchorA, const XVECTOR2& vGAnchorB,
				const XVECTOR2& vAnchorA, const XVECTOR2& vAnchorB,
				xfloat32 ratio);
	XVECTOR2	vGroundAnchorA;
	XVECTOR2	vGroundAnchorB;
	XVECTOR2	vLocalAnchorA;
	XVECTOR2	vLocalAnchorB;
	xfloat32	fLengthA;
	xfloat32	fLengthB;
	xfloat32	fRatio;
};

struct X2DMouseJointDesc : public X2DJointDesc
{
	X2DMouseJointDesc()
		: vTarget(0.0f)
		, fMaxForce(0.0f)
		, fFrequencyHz(5.0f)
		, fDampingRatio(0.7f)
	{
		eType = X_2DPHYSICS_JT_MOUSE;
	}
	XVECTOR2 vTarget;
	xfloat32 fMaxForce;
	xfloat32 fFrequencyHz;
	xfloat32 fDampingRatio;
};

class IX2DJoint;
struct X2DGearJointDesc : public X2DJointDesc
{
	X2DGearJointDesc()
		: pJointA(NULL)
		, pJointB(NULL)
		, fRatio(1.0f)
	{
		eType = X_2DPHYSICS_JT_GEAR;
	}
	IX2DJoint* pJointA;
	IX2DJoint* pJointB;
	xfloat32 fRatio;
};

struct X2DWheelJointDesc : public X2DJointDesc
{
	X2DWheelJointDesc()
		: vLocalAnchorA(0.0f)
		, vLocalAnchorB(0.0f)
		, vLocalAxisA(1.0f, 0.0f)
		, bEnableMotor(xfalse)
		, fMaxMotorTorque(0.0f)
		, fMotorSpeed(0.0f)
		, fFrequencyHz(2.0f)
		, fDampingRatio(0.7f)
	{
		eType = X_2DPHYSICS_JT_WHEEL;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, const XVECTOR2& vAnchor, const XVECTOR2& vAxis);
	XVECTOR2 vLocalAnchorA;
	XVECTOR2 vLocalAnchorB;
	XVECTOR2 vLocalAxisA;
	xbool	 bEnableMotor;
	xfloat32 fMaxMotorTorque;
	xfloat32 fMotorSpeed;
	xfloat32 fFrequencyHz;
	xfloat32 fDampingRatio;
};

struct X2DWeldJointDesc : public X2DJointDesc
{
	X2DWeldJointDesc()
		: vLocalAnchorA(0.0f)
		, vLocalAnchorB(0.0f)
		, fReferenceAngle(0.0f)
		, fFrequencyHz(0.0f)
		, fDampingRatio(0.0f)
	{
		eType = X_2DPHYSICS_JT_WELD;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, const XVECTOR2& vAnchor);
	XVECTOR2 vLocalAnchorA;
	XVECTOR2 vLocalAnchorB;
	xfloat32 fReferenceAngle;
	xfloat32 fFrequencyHz;
	xfloat32 fDampingRatio;
};

struct X2DFrictionJointDesc : public X2DJointDesc
{
	X2DFrictionJointDesc()
		: vLocalAnchorA(0.0f)
		, vLocalAnchorB(0.0f)
		, fMaxForce(0.0f)
		, fMaxTorque(0.0f)
	{
		eType = X_2DPHYSICS_JT_FRICTION;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB, const XVECTOR2& vAnchor);
	XVECTOR2 vLocalAnchorA;
	XVECTOR2 vLocalAnchorB;
	xfloat32 fMaxForce;
	xfloat32 fMaxTorque;
};

struct X2DRopeJointDesc : public X2DJointDesc
{
	X2DRopeJointDesc()
		: vLocalAnchorA(-1.0f, 0.0f)
		, vLocalAnchorB(1.0f, 0.0f)
		, fMaxLength(0.0f)
	{
		eType = X_2DPHYSICS_JT_ROPE;
	}
	XVECTOR2 vLocalAnchorA;
	XVECTOR2 vLocalAnchorB;
	xfloat32 fMaxLength;
};
struct X2DMotorJointDesc : public X2DJointDesc
{
	X2DMotorJointDesc()
		: vLinearOffset(0.0f)
		, fAngularOffset(0.0f)
		, fMaxForce(1.0f)
		, fMaxTorque(1.0f)
		, fCorrectionFactor(0.3f)
	{
		eType = X_2DPHYSICS_JT_MOTOR;
	}
	xbool Init(IX2DRigidBody* pA, IX2DRigidBody* pB);
	XVECTOR2 vLinearOffset;
	xfloat32 fAngularOffset;
	xfloat32 fMaxForce;
	xfloat32 fMaxTorque;
	xfloat32 fCorrectionFactor;
};

class IX2DJoint : public XMemBase
{
public:
	virtual ~IX2DJoint(){}
	virtual X2DJointType	GetType() const = 0;
	virtual IX2DRigidBody*	GetBodyA() = 0;
	virtual IX2DRigidBody*	GetBodyB() = 0;
	virtual void*			GetUserData() const = 0;
	virtual void			SetUserData(void* pUserData) = 0;
	virtual xbool			IsActive() const = 0;

	virtual XVECTOR2		GetAnchorA() const = 0;
	virtual XVECTOR2		GetAnchorB() const = 0;
	virtual XVECTOR2		GetReactionForce(xfloat32 inv_dt) const = 0;
	virtual xfloat32		GetReactionTorque(xfloat32 inv_dt) const = 0;

	virtual void*			GetPrivateData() = 0;
};

class IX2DRevoluteJoint : public IX2DJoint
{
public:
	virtual ~IX2DRevoluteJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual xfloat32	GetReferenceAngle() const = 0;
	virtual xfloat32	GetJointAngle() const = 0;
	virtual xfloat32	GetJointSpeed() const = 0;
	virtual xbool		IsLimitEnabled() const = 0;
	virtual void		EnableLimit(xbool flag) = 0;
	virtual xfloat32	GetLowerLimit() const = 0;
	virtual xfloat32	GetUpperLimit() const = 0;
	virtual void		SetLimits(xfloat32 lower, xfloat32 upper) = 0;
	virtual xbool		IsMotorEnabled() const = 0;
	virtual void		EnableMotor(xbool flag) = 0;
	virtual void		SetMotorSpeed(xfloat32 speed) = 0;
	virtual xfloat32	GetMotorSpeed() const = 0;
	virtual void		SetMaxMotorTorque(xfloat32 torque) = 0;
	virtual xfloat32	GetMaxMotorTorque() const = 0;
};

class IX2DPrismaticJoint : public IX2DJoint
{
public:
	virtual ~IX2DPrismaticJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual XVECTOR2	GetLocalAxisA() const = 0;
	virtual xfloat32	GetReferenceAngle() const = 0;
	virtual xfloat32	GetJointTranslation() const = 0;
	virtual xfloat32	GetJointSpeed() const = 0;
	virtual xbool		IsLimitEnabled() const = 0;
	virtual void		EnableLimit(xbool flag) = 0;
	virtual xfloat32	GetLowerLimit() const = 0;
	virtual xfloat32	GetUpperLimit() const = 0;
	virtual void		SetLimits(xfloat32 lower, xfloat32 upper) = 0;
	virtual xbool		IsMotorEnabled() const = 0;
	virtual void		EnableMotor(xbool flag) = 0;
	virtual void		SetMotorSpeed(xfloat32 speed) = 0;
	virtual xfloat32	GetMotorSpeed() const = 0;
	virtual void		SetMaxMotorForce(xfloat32 force) = 0;
	virtual xfloat32	GetMaxMotorForce() const = 0;
	virtual xfloat32	GetMotorForce(xfloat32 inv_dt) const = 0;
};

class IX2DDistanceJoint : public IX2DJoint
{
public:
	virtual ~IX2DDistanceJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual void		SetLength(xfloat32 length) = 0;
	virtual xfloat32	GetLength() const = 0;
	virtual void		SetFrequency(xfloat32 hz) = 0;
	virtual xfloat32	GetFrequency() const = 0;
	virtual void		SetDampingRatio(xfloat32 ratio) = 0;
	virtual xfloat32	GetDampingRatio() const = 0;
};

class IX2DPulleyJoint : public IX2DJoint
{
public:
	virtual ~IX2DPulleyJoint(){}
	virtual XVECTOR2 GetGroundAnchorA() const = 0;
	virtual XVECTOR2 GetGroundAnchorB() const = 0;
	virtual xfloat32 GetLengthA() const = 0;
	virtual xfloat32 GetLengthB() const = 0;
	virtual xfloat32 GetRatio() const = 0;
	virtual xfloat32 GetCurrentLengthA() const = 0;
	virtual xfloat32 GetCurrentLengthB() const = 0;
};

class IX2DMouseJoint : public IX2DJoint
{
public:
	virtual ~IX2DMouseJoint(){}
	virtual void	 SetTarget(const XVECTOR2& target) = 0;
	virtual XVECTOR2 GetTarget() const = 0;
	virtual void	 SetMaxForce(xfloat32 force) = 0;
	virtual xfloat32 GetMaxForce() const = 0;
	virtual void	 SetFrequency(xfloat32 hz) = 0;
	virtual xfloat32 GetFrequency() const = 0;
	virtual void	 SetDampingRatio(xfloat32 ratio) = 0;
	virtual xfloat32 GetDampingRatio() const = 0;
};
 
class IX2DGearJoint : public IX2DJoint
{
public:
	virtual ~IX2DGearJoint(){}
	virtual IX2DJoint*	GetJointA() = 0;
	virtual IX2DJoint*	GetJointB() = 0;
	virtual void		SetRatio(xfloat32 fRatio) = 0;
	virtual xfloat32	GetRatio() const = 0;
};

class IX2DWheelJoint : public IX2DJoint
{
public:
	virtual ~IX2DWheelJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual XVECTOR2	GetLocalAxisA() const = 0;
	virtual xfloat32	GetJointTranslation() const = 0;
	virtual xfloat32	GetJointLinearSpeed() const = 0;
	virtual xfloat32	GetJointAngle() const = 0;
	virtual xfloat32	GetJointAngularSpeed() const = 0;
	virtual xbool		IsMotorEnabled() const = 0;
	virtual void		EnableMotor(xbool flag) = 0;
	virtual void		SetMotorSpeed(xfloat32 speed) = 0;
	virtual xfloat32	GetMotorSpeed() const = 0;
	virtual void		SetMaxMotorTorque(xfloat32 torque) = 0;
	virtual xfloat32	GetMaxMotorTorque() const = 0;
	virtual xfloat32	GetMotorTorque(xfloat32 inv_dt) const = 0;
	virtual void		SetSpringFrequencyHz(xfloat32 hz) = 0;
	virtual xfloat32	GetSpringFrequencyHz() const = 0;
	virtual void		SetSpringDampingRatio(xfloat32 ratio) = 0;
	virtual xfloat32	GetSpringDampingRatio() const = 0;
};

class IX2DWeldJoint : public IX2DJoint
{
public:
	virtual ~IX2DWeldJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual xfloat32	GetReferenceAngle() const = 0;
	virtual void		SetFrequency(xfloat32 hz) = 0;
	virtual xfloat32	GetFrequency() const = 0;
	virtual void		SetDampingRatio(xfloat32 ratio) = 0;
	virtual xfloat32	GetDampingRatio() const = 0;
};

class IX2DFrictionJoint : public IX2DJoint
{
public:
	virtual ~IX2DFrictionJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual void		SetMaxForce(xfloat32 force) = 0;
	virtual xfloat32	GetMaxForce() const = 0;
	virtual void		SetMaxTorque(xfloat32 torque) = 0;
	virtual xfloat32	GetMaxTorque() const = 0;
};

class IX2DRopeJoint : public IX2DJoint
{
public:
	virtual ~IX2DRopeJoint(){}
	virtual XVECTOR2	GetLocalAnchorA() const = 0;
	virtual XVECTOR2	GetLocalAnchorB() const = 0;
	virtual void		SetMaxLength(xfloat32 length) = 0;
	virtual xfloat32	GetMaxLength() const = 0;
};

class IX2DMotorJoint : public IX2DJoint
{
public:
	virtual ~IX2DMotorJoint(){}
	virtual void		SetLinearOffset(const XVECTOR2& linearOffset) = 0;
	virtual XVECTOR2	GetLinearOffset() const = 0;
	virtual void		SetAngularOffset(xfloat32 angularOffset) = 0;
	virtual xfloat32	GetAngularOffset() const = 0;
	virtual void		SetMaxForce(xfloat32 force) = 0;
	virtual xfloat32	GetMaxForce() const = 0;
	virtual void		SetMaxTorque(xfloat32 torque) = 0;
	virtual xfloat32	GetMaxTorque() const = 0;
	virtual void		SetCorrectionFactor(xfloat32 factor) = 0;
	virtual xfloat32	GetCorrectionFactor() const = 0;
};
#endif
