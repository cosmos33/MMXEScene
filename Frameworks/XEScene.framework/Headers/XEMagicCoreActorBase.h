/******************************************************************************

@File         XEMagicCoreActorBase.h

@Version       1.0

@Created     2019,3,21

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE_MAGIC_CORE_ACTOR_BASE_H
#define XE_MAGIC_CORE_ACTOR_BASE_H
#include "XEActor.h"


#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
class XEPropertyObject;
#endif

class XEViewport;
class XEMagicCoreActorBase 
	:public XEActor
{
public:
	XEMagicCoreActorBase(){ m_szActorShortName = "MagicCoreActorBase"; }
	~XEMagicCoreActorBase(){};
public:
	XE_ACTOR_CAST(XEMagicCoreActorBase)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
		virtual XEPropertyObjectSet GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
private:
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	void							UpdateActorCommonPropertyObj(XEPropertyObject* pPropertyObj);
#endif
public:
	static const XString ACTOR_TYPENAME;
};

#endif // XE_MAGIC_CORE_ACTOR_BASE_H
