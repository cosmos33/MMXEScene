/******************************************************************************

@File         XEUIAnimtionInstance.h

@Version       1.0

@Created      2018,5, 23

@HISTORY:

******************************************************************************/
#ifndef _XE_UIANIMATION_INSTANCE_H
#define _XE_UIANIMATION_INSTANCE_H
#include "XEUIAnimBase.h"
class XEUIAnimation;
class XEWorld;
class XEUIAnimController;
class XEUISceneActor;
class XEUIAnimationInstance : public XEUIAnimBaseInstance
{
public:
	XEUIAnimationInstance(XEUIAnimation* pNodeTl);
	virtual ~XEUIAnimationInstance();
public:
	virtual void                       Tick(xfloat32 fInterval) override;
	virtual void                       Release() override;
	virtual void                       Apply() override;
	virtual Manager*                   GetNodeManager() override{ return m_pNodeManager; }
	XEUIAnimation*                     GetUIAnimationTemplate();
	void                               AcceptWorld(XEWorld* pWorld);// set to node manager
	void							   AcceptUISceneActor(XEUISceneActor* _pActor){ m_pUISceneActor = _pActor; }
	XEUISceneActor*					   GetUISceneActor(){ return m_pUISceneActor; }
	XEWorld*                           GetWorld();// comes from node manager
	void						       ReleaseAllAnimResources();
	//xbool                              VerifyModelActor(XEActor* pActor);
public:
	X_EES_LINE X_FORCEINLINE const Manager* GetNodeManager() const{ return m_pNodeManager; }
	X_FORCEINLINE XEUIAnimController* GetUIAnimController(){ return m_pUIAnimController; }
public:
	XE_USER_NODE_CAST(XEUIAnimationInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
private:
	XETreeNode::Manager*               m_pNodeManager;//node manager.
	XEUIAnimController*               m_pUIAnimController;
	XEUISceneActor*					  m_pUISceneActor;
};


#endif