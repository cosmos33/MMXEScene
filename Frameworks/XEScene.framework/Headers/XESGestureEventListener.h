//
// Created by HongjieFu on 2019/1/9.
//

#ifndef PODS_XESGESTUREEVENTLISTENER_H
#define PODS_XESGESTUREEVENTLISTENER_H

#include "core/events/XESEventListener.h"
#include "core/events/XESGestureEvent.h"

XESCENE_NAMESPACE_BEGIN

class GestureEventListener : public EventListener {

    typedef std::function<void(Scene *, GestureClickParam *)> ClickCallBack;
    typedef std::function<void(Scene *, GesturePinchParam *)> PinchCallBack;
    typedef std::function<void(Scene *, GestureMoveParam *)> MoveCallBack;
    typedef std::function<void(Scene *, GestureMove2Param *)> Move2CallBack;
    typedef std::function<void(Scene *, GestureRotate2Param *)> Rotate2CallBack;

XESCENE_CONSTRUCTOR_ACCESS:

    GestureEventListener();

    xbool Init();

public:
    static const ListenerID LISTENER_ID;

    static GestureEventListener *Create();

    virtual ~GestureEventListener() override;

    virtual void Release() override;

    virtual xbool CheckAvailable() override;

    virtual GestureEventListener *Clone() override;

    void SendEvent(Event *event) override;

public:
    ClickCallBack OnClickCallBack;
    PinchCallBack OnPinchCallBack;
    MoveCallBack OnMoveCallBack;
    Move2CallBack OnMove2CallBack;
    Rotate2CallBack OnRotate2CallBack;

};

XESCENE_NAMESPACE_END


#endif //PODS_XESGESTUREEVENTLISTENER_H
