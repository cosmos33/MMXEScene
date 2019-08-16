/******************************************************************************

@File         XEInstanceManagerUIAnimation.h

@Version       1.0

@Created      2019,5,23

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_UIANIMATION_MANAGER_H
#define _XE_UIANIMATION_MANAGER_H

#include "XEInstanceManagerBase.h"
#include "XESingleton.h"

class XEInstanceManagerUIAnimation :public XEInstanceManagerBase
{
public:
	XEInstanceManagerUIAnimation(){}
	~XEInstanceManagerUIAnimation(){}
public:
	virtual XEUserNode*                       CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*                       GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                              Reload(const xchar* szAssetFile = NULL) override;
	virtual void                              SaveImpl() const override;
	virtual void                              SaveAsImpl(const xchar* pPath) const override;
	virtual xbool                             IsNodesModifiedImpl()const override;
	virtual xbool							  IsMatchFileType(const XString& szPath) override;
};

class XEInstanceManagerUIAnimationRuntime : public XEInstanceManagerUIAnimation
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerUIAnimationRuntime)
};

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
class XEInstanceManagerUIAnimationEditing : public XEInstanceManagerUIAnimation
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerUIAnimationEditing)
};
#endif
#endif