/******************************************************************************

@File         XEInstanceManagerSkeleton.h

@Version       1.0

@Created      2018,4, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_INSTANCE_MANAGER_SKELETON_H
#define _XE_INSTANCE_MANAGER_SKELETON_H

#include "XEInstanceManagerBase.h"
class XEInstanceManagerSkeletonBase
	: public XEInstanceManagerBase
{
public:
	XEInstanceManagerSkeletonBase();
	~XEInstanceManagerSkeletonBase();
public:
	virtual XEUserNode*               CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*               GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                      Reload(const xchar* szAssetFile = NULL) override;
	virtual xbool					  IsMatchFileType(const XString& szPath) override;
};


//runtime only.
class XEInstanceManagerSkeleton
	: public XEInstanceManagerSkeletonBase
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerSkeleton)
};

//#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
////editing only.
//class XEInstanceManagerSkeletonEditing
//	: public XEInstanceManagerSkeletonBase
//	, public XESingleton<XEInstanceManagerSkeletonEditing>
//{
//};
//#endif

#endif // _XE_INSTANCE_MANAGER_SKELETON_H
