/******************************************************************************

@File         XEScriptInterpreter.h

@Version       1.0

@Created      2018,9, 6

@HISTORY:

******************************************************************************/
#ifndef _XE_SCRIPT_INTERPRETER_H_
#define _XE_SCRIPT_INTERPRETER_H_

#include "XEScript.h"
#include "XEEventReceiver.h"
#include "XGestureManager.h"

class XEScriptInstance;
class XEWorld;
class XEScriptInterpreterPool
{
public:
	class XEScriptInterpreter
	{
	public:
		XEScriptInterpreter(XEScript::ScriptType st):type_(st){}
		~XEScriptInterpreter(){}
	public:
		virtual xbool                Execute(const xchar* pCodeBuffer, XEScriptInstance* pScriptIns, xint32& assignedID) = 0;
		virtual xbool                GarbageClean(XEScriptInstance* pScriptIns) = 0;
		virtual xbool                OnHolderEntrance(XEScriptInstance* pScriptIns){ return xtrue; }
		virtual xbool                OnHolderRelease(XEScriptInstance* pScriptIns){ return xtrue; }
		virtual xbool                OnHolderTick(XEScriptInstance* pScriptIns, xfloat32 fIntervalMs){ return xtrue; }
		virtual xbool                OnHolderRender(XEScriptInstance* pScriptIns, XEViewport *pViewport){ return xtrue; }
		virtual xbool                OnHolderTrigger(XEScriptInstance* pScriptIns, xbool bTrigger){ return xtrue; }
		//gesture events.		     
		virtual xbool                OnTouchClickEvent(XEScriptInstance* pScriptIns, GestureClickParam* pParam){ return xtrue; }
		virtual xbool                OnTouchMoveEvent(XEScriptInstance* pScriptIns, GestureMoveParam* pParam){ return xtrue; }
		virtual xbool                OnTouchMove2Event(XEScriptInstance* pScriptIns, GestureMove2Param* pParam){ return xtrue; }
		virtual xbool                OnTouchPinchEvent(XEScriptInstance* pScriptIns, GesturePinchParam* pParam){ return xtrue; }
		virtual xbool                OnNativeTouchesBeginEvent(XEScriptInstance* pScriptIns, xint32 number, intptr_t* ids, xfloat32* posX, xfloat32* posY){ return xtrue; }
		virtual xbool                OnNativeTouchesMoveEvent(XEScriptInstance* pScriptIns, xint32 number, intptr_t* ids, xfloat32* posX, xfloat32* posY){ return xtrue; }
		virtual xbool                OnNativeTouchesEndEvent(XEScriptInstance* pScriptIns, xint32 number, intptr_t* ids, xfloat32* posX, xfloat32* posY){ return xtrue; }
		XEScript::ScriptType	     type_;
	};
	typedef XArray<XEScriptInterpreter*> ScriptInterpreterPool;
public:
	xint32                          AddScriptInterpreter(XEScriptInterpreter* sip);
	xbool                           RemoveScriptInterpreter(XEScriptInterpreter* sip);
	XEScriptInterpreter*            GetScriptInterpreter(XEScript::ScriptType st, xint32 index = 0);
	static XEScriptInterpreterPool* GetInstance();
protected:
	ScriptInterpreterPool m_aInterpreterPool;
};

#endif // _XE_SCRIPT_INTERPRETER_H_
