/******************************************************************************

@File         XEImgInstanceManagerSeqFrame.h

@Version       1.0

@Created      2018,4, 18

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_IMG_SEQFRAME_MANAGER_H
#define _XE_IMG_SEQFRAME_MANAGER_H
#include "XEInstanceManagerBase.h"

class XEAnimMontage;
class XEAnimMontageInstance;
class XEImgInstanceManagerSeqFrameRuntime;
class XEImgInstanceManagerSeqFrame
	: public XEInstanceManagerBase
{
public:
	XEImgInstanceManagerSeqFrame(){}
	~XEImgInstanceManagerSeqFrame(){}
public:
	virtual XEUserNode*                     CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*                     GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                            Reload(const xchar* szAssetFile = NULL) override;
	virtual void                            SaveImpl() const override;
	virtual void                            SaveAsImpl(const xchar* pPath) const override;
	virtual xbool                           IsNodesModifiedImpl()const override;
	virtual xbool						    IsMatchFileType(const XString& szPath) override;
public:
	xbool									HasInstanceForTemplate(XEUserNode* pNodeT1);
};


//runtime only.
class XEImgInstanceManagerSeqFrameRuntime
	: public XEImgInstanceManagerSeqFrame
{
public:
	INSTANCE_MANAGER_IMPL(XEImgInstanceManagerSeqFrameRuntime)
};

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
//editing only.
class XEImgInstanceManagerSeqFrameEditing
	: public XEImgInstanceManagerSeqFrame
{
public:
	INSTANCE_MANAGER_IMPL(XEImgInstanceManagerSeqFrameEditing)
};
#endif

#endif // _XE_IMG_SEQFRAME_MANAGER_H
