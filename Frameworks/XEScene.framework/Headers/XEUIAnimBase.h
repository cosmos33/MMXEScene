/******************************************************************************

@File         XEUIAnimBase.h

@Version       1.0

@Created      2019,5, 22

@HISTORY:

******************************************************************************/
#ifndef _XE_UIANIM_BASE_H
#define _XE_UIANIM_BASE_H

#include "XEFactoryUserNodeUtil.h"

class XEUIAnimation;
class XEUIAnimationInstance;
class XEUISceneActor;
class XEUIAnimBase :public XEUserNode
{
public:
	XEUIAnimBase(){}
	virtual ~XEUIAnimBase(){}
	typedef XArray<XEUIAnimBase*>      UIAimaBaseList;
public:
	XEUIAnimation* GetUIAnimation();
public:
	XE_USER_NODE_CAST(XEUIAnimBase)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};


class XEWorld;
class XEUIAnimBaseInstance
	:public XEUserNodeInstance
{
public:
	XEUIAnimBaseInstance(XEUserNode* pNodeTl) :XEUserNodeInstance(pNodeTl){}
	virtual ~XEUIAnimBaseInstance(){}
	typedef XArray<XEUIAnimBaseInstance*>AnimBaseInstanceList;
public:
	virtual void         SetTime(xint32 nMicrosecond) override;//in microsecond.
	XEWorld*             GetWorld();
	XEUISceneActor*		 GetUISceneActor();
	XEUIAnimationInstance* GetUIAnimationInstance();
public:
	XE_USER_NODE_CAST(XEUIAnimBaseInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};

#endif