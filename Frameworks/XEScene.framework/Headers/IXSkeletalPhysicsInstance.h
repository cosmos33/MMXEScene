/******************************************************************************

@File         IXSkeletalPhysicsInstance.h

@Version      1.0

@Created      2018, 7, 13

@Description  XSkeletalPhysicsInstance is an runtime instance of XSkeletalPhysicsRes.

@HISTORY:

******************************************************************************/
#ifndef _IX_SKELETAL_PHYSICS_INSTANCE_H_
#define _IX_SKELETAL_PHYSICS_INSTANCE_H_

#include "XMemBase.h"
#include "XTypes.h"
#include "XBase3DTypes.h"

class IXSkeletalPhysicsRes;
class IXModelInstance;
class IXRigidBody;
class IXSkeletalBody;
class IXSkeletalPhysicsInstance : public XMemBase
{
public:
	virtual					~IXSkeletalPhysicsInstance(){}

	virtual void			Release() = 0;

	virtual void			SetAllBodiesSimulatePhysics(xbool bSimulate) = 0;
	virtual void			SetAllBodiesBelowSimulatePhysics(const xchar* szBoneName, xbool bSimulate, xbool bIncludeSelf = xtrue) = 0;

	virtual void			OnBindModelInstanceTransformChanged(xfloat32 fScaleEpsilon = X_EPSILON_FLT32) = 0;
	virtual void			DebugDraw(const XCOLORBASE& Color = XCOLORBASE(1.0f, 0.0f, 0.0f, 1.0f)) const = 0;

	virtual IXSkeletalBody*	GetBody(const XString& strBoneName) const = 0;
	virtual xint32			GetBodyNumber() const = 0;
	virtual IXSkeletalBody* GetBody(xint32 nBodyIndex) const = 0;
};

#endif // !_IX_SKELETAL_PHYSICS_INSTANCE_H_
