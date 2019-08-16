
/******************************************************************************

@File     XEPStateMachine.h

@Version    1.0

@Created   2019,5,31

@Description The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_PATCH_STATE_MACHINE_H_
#define _XE_PATCH_STATE_MACHINE_H_

//patch graph state machine
#include "XEStateMachine.h"
#include "XClass.h"
X_EEH_FILE//don't export for lua

class XEPatchGraph;
enum PG_FSM_STATE
{
	PG_FSM_DEACTIVE,
	PG_FSM_ACTIVE,
	PG_FSM_EXECUTING,
	PG_FSM_EXECUTED
};
//states
class XEPatchGraphState:public XEFSMState
{
public:
	XEPatchGraphState(XEPatchGraph* pPatchGraph) : m_pPatchGraph(pPatchGraph), m_eFSMState(PG_FSM_DEACTIVE){}
	virtual ~XEPatchGraphState() {}
public:
	XEPatchGraph* m_pPatchGraph;
	PG_FSM_STATE  m_eFSMState;
};

class XEPatchGraphDeactiveState:public XEPatchGraphState
{
public:
	XEPatchGraphDeactiveState(XEPatchGraph* pPatchGraph):XEPatchGraphState(pPatchGraph)
	{
		m_strStateName = "patch_state_deative";
		m_eFSMState = PG_FSM_DEACTIVE;
	}
};

class XEPatchGraphActiveState :public XEPatchGraphState
{
public:
	XEPatchGraphActiveState(XEPatchGraph* pPatchGraph):XEPatchGraphState(pPatchGraph)
	{
		m_strStateName = "patch_state_ative";
		m_eFSMState = PG_FSM_ACTIVE;
	}
};

class XEPatchGraphExecutingState :public XEPatchGraphState
{
public:
	XEPatchGraphExecutingState(XEPatchGraph* pPatchGraph) :XEPatchGraphState(pPatchGraph)
	{
		m_strStateName = "patch_state_executing";
		m_eFSMState = PG_FSM_EXECUTING;
	}
};

class XEPatchGraphExecutedState :public XEPatchGraphState
{
public:
	XEPatchGraphExecutedState(XEPatchGraph* pPatchGraph) :XEPatchGraphState(pPatchGraph)
	{
		m_strStateName = "patch_state_executed";
		m_eFSMState = PG_FSM_EXECUTED;
	}
};

//functions

class XEPatchGraphFunction:public XEFSMFunction
{
public:
	XEPatchGraphFunction(const XEFSMState& ownState) :XEFSMFunction(ownState) {}
	typedef XEPatchGraphFunction Super;
public:
	virtual xbool Explain() override;
};

//state machine object
typedef void(*OnPatchGraphStateChanged)(XEPatchGraphState* pgs);
class XEPatchGraphStateMachine:public XEFSMObject
{
public:
	XEPatchGraphStateMachine();
	~XEPatchGraphStateMachine();
public:
	virtual void			 Clear() override;
	void                     SetupFSM(XEPatchGraph* pPatchGraph, OnPatchGraphStateChanged onStateChangedFunc);
	xbool                    ExplainCurrentFunction();
	xbool                    IsFSMSetuped();
	void                     SetNextStateFunction(const XString& stateName);
	static XEFSMFunction*    ProducePatchGraphFuction(const XEFSMState & ownState);
private:
	void				     ProduceFSMComponent();
public:
	XEPatchGraph*			 m_pPatchGraph;
	OnPatchGraphStateChanged m_onStateChangedFunc;
};
#endif//_XE_PATCH_STATE_MACHINE_H_