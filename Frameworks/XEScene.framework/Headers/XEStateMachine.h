
/******************************************************************************

@File         XETreeNode.h

@Version       1.0

@Created      2017, 12, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_STATE_MACHINE_H_
#define _XE_STATE_MACHINE_H_
#include "XTypes.h"
#include "XString.h"
#include "XEUtility.h"
#include "XClass.h"
X_EEH_FILE//don't export for lua

class XEFSMComponent
{
public:
	XEFSMComponent() {}
public:
	virtual ~XEFSMComponent() {}
	virtual xbool Explain() { return xfalse; }
};

class XEFSMSymbol :
	public XEFSMComponent
{
public:
	XEFSMSymbol() {}
	virtual ~XEFSMSymbol() {}
public:
	XString m_strSymbol;

};//included fsm input symbol and output symbol
typedef XLinkList<XEFSMSymbol> FSMSymbolListNode;

class XEFSMState :
	public XEFSMComponent
{
public:
	XEFSMState() {}
	virtual ~XEFSMState() {}
public:
	XString m_strStateName;
};
typedef XLinkList<XEFSMState> FSMStateListNode;

class XEFSMFunction :
	public XEFSMComponent
{
public:
	XEFSMFunction(const XEFSMState& ownState) :m_pOwnState(new XEFSMState(ownState)), m_pNextSymbol(NULL){}
	virtual ~XEFSMFunction() 
	{
		X_SAFEDELETE(m_pOwnState);
		X_SAFEDELETE(m_pNextSymbol);
	}
public:
	void SetupNextSymbol(const XEFSMSymbol& nextSymbol)
	{
		//new here
		X_SAFEDELETE(m_pNextSymbol);
		m_pNextSymbol = new XEFSMSymbol(nextSymbol);
	}
public:
	XEFSMState*  m_pOwnState;
	XEFSMSymbol* m_pNextSymbol;
};//include fsm next state function and output function

class XEFSMObject
{
public:
	XEFSMObject() :m_pBeginingState(NULL), m_pCurrentState(NULL), m_pInputNextStateFunc(NULL), m_pOutputFunc(NULL){};
	virtual ~XEFSMObject() {};
	virtual void Clear() 
	{
		XEUtility::CleanLinkListOptionally(m_aInputSymbol);
		XEUtility::CleanLinkListOptionally(m_aOutputSymbol);
		XEUtility::CleanLinkListOptionally(m_aFiniteStateList);
		m_pBeginingState = NULL;
		m_pCurrentState = NULL;
		X_SAFEDELETE(m_pInputNextStateFunc);
		X_SAFEDELETE(m_pOutputFunc);
	}
public:
	FSMSymbolListNode  m_aInputSymbol;
	FSMSymbolListNode  m_aOutputSymbol;
	FSMStateListNode   m_aFiniteStateList;
	XEFSMState*        m_pBeginingState;
	XEFSMState*        m_pCurrentState;
	XEFSMFunction*     m_pInputNextStateFunc;
	XEFSMFunction*     m_pOutputFunc;
};

#endif