/******************************************************************************

@File         XEInstanceManagerARAds.h

@Version       1.0

@Created      2018/5/30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_ARADS_MANAGER_H
#define _XE_ARADS_MANAGER_H

#include "XEInstanceManagerBase.h"

class XEInstanceManagerARAds
	: public XEInstanceManagerBase
{
public:
	XEInstanceManagerARAds(){}
	~XEInstanceManagerARAds(){}
public:
	virtual XEUserNode*                  CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld = NULL) override;
	virtual XEUserNode*                  GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                         Reload(const xchar* szAssetFile = NULL) override;
	virtual void                         SaveImpl() const override;
	virtual void                         SaveAsImpl(const xchar* pPath) const override;
	virtual xbool                        IsNodesModifiedImpl()const override;
	virtual xbool						 IsMatchFileType(const XString& szPath) override;
};


//runtime only.
class XEInstanceManagerARAdsRuntime
	: public XEInstanceManagerARAds
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerARAdsRuntime)
};

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
//editing only.
class XEInstanceManagerARAdsEditing
	: public XEInstanceManagerARAds
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerARAdsEditing)
};
#endif

#endif // _XE_ARADS_MANAGER_H
