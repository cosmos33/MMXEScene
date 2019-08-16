/******************************************************************************

@File         XEScriptInstance.h

@Version       1.0

@Created      2017,12, 22

@HISTORY:

******************************************************************************/
#ifndef _XE_SCRIPT_INSTANCE_H_
#define _XE_SCRIPT_INSTANCE_H_
#include "XEUserNode.h"
#include "XGestureManager.h"

class XEWorld;
class XEViewport;
class XEActor;
class XEActorComponent;
class XEScript;
class XEScriptContainerInstance;


class XEScriptInstance 
	: public XEUserNodeInstance
{
public:
	XEScriptInstance(XEScript* pNodeTl);
	virtual ~XEScriptInstance();
public:
	virtual void                                  Release() override;
	virtual void                                  Apply() override;//apply parameters from node-template.
	xbool                                         Execute();
	XEScript*                                     GetScriptTemplate();
	xbool                                         AcceptHolder(void* pHolder);//will cast to the type matched to the template automatically.
	XEScriptContainerInstance*                    GetScriptContainerInstance();//script instance may located in the script container.(AS ROOT)
	//holder behaviors( similar to the concept of "EventGraph" in the UE4)
	virtual xbool                                 OnHolderEntrance();
	virtual xbool                                 OnHolderRelease();
	virtual xbool                                 OnHolderTick(xfloat32 fIntervalMs);//in milliseconds.
	virtual xbool                                 OnHolderRender(XEViewport *pViewport);
	virtual xbool                                 OnHolderTigger(xbool bTrigger);

	//gesture events.
	virtual xbool                                 OnTouchClickEvent(GestureClickParam* pParam);
	virtual xbool                                 OnTouchMoveEvent(GestureMoveParam* pParam);
	virtual xbool                                 OnTouchMove2Event(GestureMove2Param* pParam);
	virtual xbool                                 OnTouchPinchEvent(GesturePinchParam* pParam);
	virtual xbool                                 OnNativeTouchesBeginEvent(xint32 number, intptr_t* ids, xfloat32* posX, xfloat32* posY);
	virtual xbool                                 OnNativeTouchesMoveEvent(xint32 number, intptr_t* ids, xfloat32* posX, xfloat32* posY);
	virtual xbool                                 OnNativeTouchesEndEvent(xint32 number, intptr_t* ids, xfloat32* posX, xfloat32* posY);

	//holder settings.
	void*                                         GetHolder();
	XEWorld*                                      GetHolderWorld();
	XEActor*                                      GetHolderActor();
	XEActorComponent*                             GetHolderActorComponent();
	XEUserNode*                                   GetHolderUserNode();
	const XString                                 GetHolderTypeName();
	const xint32                                  GetHolderType();
	X_FORCEINLINE xint32                          GetAssignedID() const{ return m_nAssignedID; }
	X_FORCEINLINE void                            SetAssignedID(xint32 nID){ m_nAssignedID = nID; }
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
public:
	XE_USER_NODE_CAST(XEScriptInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	union
	{
		void*                                     m_pHolder;
		XEWorld*                                  m_pHolderWorld;
		XEActor*                                  m_pHolderActor;
		XEActorComponent*                         m_pHolderActorComponent;
		XEUserNode*                               m_pHolderUserNode;
	};
	xint32                                        m_nAssignedID;
};

#endif // _XE_SCRIPT_INSTANCE_H_
