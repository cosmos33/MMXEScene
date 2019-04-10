//
//  XESEventDispatcher.h
//  XEScene
//
//  Created by momo783 on 06/02/2018.
//

#ifndef XESEVENTDISPATCHER_H_
#define XESEVENTDISPATCHER_H_

#include "core/XESObject.h"
#include "core/events/XESEventListener.h"


#include <set>
#include <map>
#include <vector>

XESCENE_NAMESPACE_BEGIN

typedef std::set<EventListener *> ListenerSet;
typedef std::map<EventListener::ListenerID, ListenerSet> ListenerMap;

class Event;

class EventDispatcher : public Object {

private:
    EventDispatcher();

public:
    virtual ~EventDispatcher() override;

    virtual void Release() override;

public:

    /**
     * 获取事件派发器实例
     * @return
     */
    static EventDispatcher *GetInstance();

    /**
     * 添加绑定Actor事件监听器
     * @param pListener
     * @param pActor
     */
    void AddEventListener(EventListener *pListener, XEActor *pActor);

    /**
     * 添加绑定场景事件监听器
     * @param pListener
     * @param pActor
     */
    void AddEventListener(EventListener *pListener, Scene *pScene);

    /**
     * 移除事件监听器
     * @param pListener
     */
    void RemoveEventListener(EventListener *pListener);

    /**
     * 通过绑定的场景移除事件监听器
     * @param pScene
     */
    void RemoveEventListenersForTarget(Scene *pScene);

    /**
     * 通过绑定的Actor移除事件监听器
     * @param pTarget
     */
    void RemoveEventListenersForTarget(XEActor *pTarget);

    /**
     * 移除所有事件监听器
     */
    void RemoveAllEventListeners();

    /**
     * 通过绑定的场景暂停监听器
     * @param pTarget
     */
    void PauseEventListenersForTarget(Scene *pTarget);

    /**
     * 通过绑定的场景恢复监听器
     * @param pTarget
     */
    void ResumeEventListenersForTarget(Scene *pTarget);

    /**
     * 通过绑定的Actor暂停监听器
     * @param pTarget
     */
    void PauseEventListenersForTarget(XEActor *pTarget);

    /**
     * 通过绑定的Actor恢复监听器
     * @param pTarget
     */
    void ResumeEventListenersForTarget(XEActor *pTarget);

    /**
     * 设置时候可用
     * @param bEnabled
     */
    X_INLINE void SetEnabled(xbool bEnabled) {
        m_bEnabled = bEnabled;
    };

    /**
     * 获取是否可用的状态
     * @return
     */
    X_INLINE xbool IsEnabled() const {
        return m_bEnabled;
    };

    /**
     * 派发事件
     * @param pEvent
     */
    void DispatchEvent(Event *pEvent);

    /**
     * @deprecated
     * 派发点击事件
     * @param pEvent
     * @return
     */
    xbool DispatchTouchHitTestEvent(Event *pEvent);


private:
    void ReleaseListener(EventListener *listener);

private:
    xbool m_bEnabled;

    ListenerSet mListenerTobeAdd;
    ListenerSet mListenerTobeRemove;
    ListenerMap mListenerMap;
    xbool mInDispatch;

};


XESCENE_NAMESPACE_END

#endif /* XESEVENTDISPATCHER_H_ */
