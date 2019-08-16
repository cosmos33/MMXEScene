/******************************************************************************

@File         XEImgFilterChainActor.h

@Version       1.0

@Created     2019,6,24

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_IMG_FILTER_ACTOR_H_
#define _XE_IMG_FILTER_ACTOR_H_
#include "XEMagicCoreActorBase.h"
#include "XEUtility.h"

class XEFilterContainerInstance;
class XEImgFilterChainActor
	:public XEMagicCoreActorBase
{
public:
	XEImgFilterChainActor();
	virtual ~XEImgFilterChainActor(){};
public:
	virtual void							 Initialize(XEWorld* pWorld) override;
	virtual void							 Release() override;
	virtual void							 Tick(xfloat32 fDelMs, xbool bForceTick = xtrue) override;// in milliseconds.
	virtual void							 Render(XEViewport* pViewport);

	virtual void                             Deserialize(const XMLElement* pEleActor) override;
	virtual XMLElement*                      Serialize(XMLElement* pEleParent) override;
	xbool                                    AttachFilterChainAsset(const xchar* pAssetPath);//path will be fixed.
	void                                     DetachFilterChainInstance();
	X_FORCEINLINE XEFilterContainerInstance* GetFilterContainerInstance(){ return m_pFilterContainerIns; }
	XString                                  GetFilterContainerAssetPath()const;
	xbool                                    ApplyFilterChain();//Exclusive mode
	void									 ClearFilterChain();
	xbool									 RebuildFilterChain();
	X_FORCEINLINE void						 SetActive(xbool bActive){ m_bActived = bActive; }
	X_FORCEINLINE xbool						 IsActive(){ return m_bActived; }
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet				 GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy) override;
#endif

protected:
	class _DelayApplyFilterChain :public XEUtility::XETemporalObject
	{
		friend class XEImgFilterChainActor;
		_DelayApplyFilterChain(XEImgFilterChainActor* holder) :holder_(holder){}
		virtual xbool ShouldBeDeleted() override{ holder_->ApplyFilterChain();  return xtrue; }
		virtual void  Release(){}
		virtual void  Tick(xfloat32 fDel){}//in milliseconds.
		virtual void  Render(XEViewport* pViewport){}
		XEImgFilterChainActor* holder_;
	};

public:
	XE_ACTOR_CAST(XEImgFilterChainActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XEImgFilterChainActor)
	XE_ACTOR_SHORT_NAME_DEF(ACTOR_SHORT_NAME)
	static const XString	   ACTOR_TYPENAME;
	static const XString	   ACTOR_SHORT_NAME;
protected:
	XEFilterContainerInstance*               m_pFilterContainerIns;
	xbool									 m_bActived;
};

#endif // _XE_IMG_FILTER_ACTOR_H_
