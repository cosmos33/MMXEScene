/******************************************************************************

@File         XEInstanceManagerBlend.h

@Version       1.0

@Created      2018,9, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_BLEND_MANAGER_H
#define _XE_BLEND_MANAGER_H
#include "XEInstanceManagerBase.h"

class XEInstanceManagerBlend
	: public XEInstanceManagerBase
{
public:
	XEInstanceManagerBlend(){}
	~XEInstanceManagerBlend(){}
public:
	virtual XEUserNode*                  CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*                  GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                         Reload(const xchar* szAssetFile = NULL) override;
	virtual void                         SaveImpl() const override;
	virtual void                         SaveAsImpl(const xchar* pPath) const override;
	virtual xbool                        IsNodesModifiedImpl()const override;
	virtual xbool						 IsMatchFileType(const XString& szPath) override;
};


//runtime only.
class XEInstanceManagerBlendRuntime
	: public XEInstanceManagerBlend
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerBlendRuntime)
};

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
//editing only.
class XEInstanceManagerBlendEditing
	: public XEInstanceManagerBlend
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerBlendEditing)
};
#endif

#endif // _XE_BLEND_MANAGER_H
