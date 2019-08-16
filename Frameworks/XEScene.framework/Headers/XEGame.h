/******************************************************************************

@File         XEGame.h

@Version       1.0

@Created      2017, 6, 2

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_GAME_H_
#define _XE_GAME_H_

#include "XHashTable.h"
#include "XArray.h"
#include "XApplication.h"
#include "XPlatformWindow.h"
#include "XEngineRoot.h"
#include "XEViewport.h"
#include "XGestureManager.h"
#include "XConsoleManager.h"

extern XConsoleVariable g_CVarEnableWorldTickSubstepping;
extern XConsoleVariable g_CVarWorldTickMaxStepTimeMS;

class XEInputEventManager
	:public XGestureManager
{
public:
	XEInputEventManager() :m_bEnabled(xfalse){}//disabled by default.
	virtual ~XEInputEventManager(){}
public:
	//a status only.
	X_FORCEINLINE void                 SetEnabled(xbool bEnabled){ m_bEnabled = bEnabled; }
	X_FORCEINLINE xbool                IsEnabled()const{ return m_bEnabled; }
protected:
	xbool m_bEnabled;
};

class XEWorld;
class XEGame : public IXApplication
{
public:
	XEGame();
	virtual					           ~XEGame();
	typedef XArray<XEWorld*>           XEWorldList;
public:
	/// Engine init will call this func.
	virtual xbool			           Init(const XApplicationInitParameter* pParam) override;
	virtual void			           Release() override;
	virtual void			           FrameStep() override;
	virtual XViewport*		           GetAppViewPort() override { return m_pCurViewPort->GetXViewport(); }
public:
	static XEGame*			           GetInstance();

	void							   ReleaseAllWorld();
	inline void				           SetCurDeltaTime(xfloat32 fDel) { m_fCurDeltaTime = fDel; }
	inline void                        SetTickEnable(xbool bEnable){ m_bEnableTick = bEnable; }
	inline xfloat32			           GetCurDeltaTime() { return m_fCurDeltaTime; }

	XEWorld*				           CreateXEWorld(XEWorld* pWorld = NULL);

	X_FORCEINLINE XEWorldList&         GetWorldList(){ return m_vWorld; }
	X_FORCEINLINE const XEWorldList&   GetWorldList() const{ return m_vWorld; }
	void					           DeleteXEWorld(XEWorld *pWorld);
	void					           SetCurViewPort(XEViewport* pViewport) { m_pCurViewPort = pViewport; }
	XEViewport*                        GetCurViewPort(){ return m_pCurViewPort; }
public:
	class TickListener
	{
		friend class XEGame;
	public:
		TickListener(){};
		virtual                       ~TickListener(){};
	protected:
		virtual  void                  Tick(xfloat32 fDel) = 0;
	};
	xbool                              AddTickListener(TickListener* pTickListener);
	xbool                              RemoveTickListener(TickListener* pTickListener);

	X_FORCEINLINE XEInputEventManager* GetGameInputEventMgr(){ return m_pGameInputEventManager; }
	X_FORCEINLINE void                 SetGameInputEventMgr(XEInputEventManager* pMgr){ m_pGameInputEventManager = pMgr; }
protected:
	void					           Tick();
	void					           Render();
	void							   TickWorld(XEWorld* pWorld, xfloat32 fDeltaTime);
	XEViewport*				           m_pCurViewPort;
	XEWorldList				           m_vWorld;
	xfloat32				           m_fCurDeltaTime;
	xbool                              m_bEnableTick;
	XArray<TickListener*>              m_aTickListener;
	XEInputEventManager*               m_pGameInputEventManager;//gesture currently.
};

#endif



