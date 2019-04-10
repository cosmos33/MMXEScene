//
// Created by HongjieFu on 2019/1/9.
//

#ifndef PODS_XESGestureEventListenerV1_H
#define PODS_XESGestureEventListenerV1_H

#include "core/events/XESEventListener.h"
#include "core/events/XESGestureEvent.h"

XESCENE_NAMESPACE_BEGIN


class GestureEventListenerV1 : public EventListener {

    typedef std::function<void(Scene *, GestureClickParam *)> ClickCallBack;
    typedef std::function<void(Scene *, GesturePinchParam *)> PinchCallBack;
    typedef std::function<void(Scene *, GestureMoveParam *)> MoveCallBack;
    typedef std::function<void(Scene *, GestureMove2Param *)> Move2CallBack;
    typedef std::function<void(Scene *, GestureRotate2Param *)> Rotate2CallBack;
    
    typedef std::function<void(Scene *, GestureTouchPoint *)> NativeTouchesCallback;

XESCENE_CONSTRUCTOR_ACCESS:

    GestureEventListenerV1();

    xbool Init();

public:
    static const ListenerID LISTENER_ID;

    static GestureEventListenerV1 *Create();

    virtual ~GestureEventListenerV1() override;

    virtual void Release() override;

    virtual xbool CheckAvailable() override;

    virtual GestureEventListenerV1 *Clone() override;

    void SendEvent(Event *event) override;

public:
    ClickCallBack OnClickCallBack;
    PinchCallBack OnPinchCallBack;
    MoveCallBack OnMoveCallBack;
    Move2CallBack OnMove2CallBack;
    Rotate2CallBack OnRotate2CallBack;

    NativeTouchesCallback onTouchBegin;
    NativeTouchesCallback onTouchMove;
    NativeTouchesCallback onTouchEnd;
};

XESCENE_NAMESPACE_END


#endif //PODS_XESGestureEventListenerV1_H
