/******************************************************************************

@File         XEImgInstanceManagerFilter.h

@Version       1.0

@Created      2019,6, 22

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_FILTER_MANAGER_H_
#define _XE_FILTER_MANAGER_H_
#include "XEInstanceManagerBase.h"

class XEImgInstanceManagerFilter
	: public XEInstanceManagerBase
{
public:
	XEImgInstanceManagerFilter(){}
	~XEImgInstanceManagerFilter(){}
public:
	virtual XEUserNode*                    CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*                    GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                           Reload(const xchar* szAssetFile = NULL) override;
	virtual void                           SaveImpl() const override;
	virtual void                           SaveAsImpl(const xchar* pPath) const override;
	virtual xbool                          IsNodesModifiedImpl()const override;
	virtual xbool						   IsMatchFileType(const XString& szPath) override;
};


//runtime only.
class XEImgInstanceManagerFilterRuntime
	: public XEImgInstanceManagerFilter
{
public:
	INSTANCE_MANAGER_IMPL(XEImgInstanceManagerFilterRuntime)
};

#endif // _XE_FILTER_MANAGER_H_
