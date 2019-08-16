/******************************************************************************

@File         XEInstanceManagerSequencer.h

@Version       1.0

@Created      2018,5, 3

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_SEQUENCER_MANAGER_H
#define _XE_SEQUENCER_MANAGER_H
#include "XEInstanceManagerBase.h"
class XEInstanceManagerSequencer
	: public XEInstanceManagerBase
{
public:
	XEInstanceManagerSequencer(){}
	~XEInstanceManagerSequencer(){}
public:
	virtual XEUserNode*                       CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*                       GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void                              Reload(const xchar* szAssetFile = NULL) override;
	virtual void                              SaveImpl() const override;
	virtual void                              SaveAsImpl(const xchar* pPath) const override;
	virtual xbool                             IsNodesModifiedImpl()const override;
	virtual xbool							  IsMatchFileType(const XString& szPath) override;
};

//runtime only.
class XEInstanceManagerSequencerRuntime
	: public XEInstanceManagerSequencer
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerSequencerRuntime)
};

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
//editing only.
class XEInstanceManagerSequencerEditing
	: public XEInstanceManagerSequencer
{
public:
	INSTANCE_MANAGER_IMPL(XEInstanceManagerSequencerEditing)
};
#endif


#endif // _XE_SEQUENCER_MANAGER_H
