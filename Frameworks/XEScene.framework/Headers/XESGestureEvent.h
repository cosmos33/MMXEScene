//
// Created by HongjieFu on 2019/1/9.
//

#ifndef PODS_XESGESTUREEVENT_H
#define PODS_XESGESTUREEVENT_H

#include "XESEvent.h"
#include "XGestureManager.h"


XESCENE_NAMESPACE_BEGIN

struct GestureTouchPoint {
    long touchId;
    xfloat32 x;
    xfloat64 y;
};

struct GestureTouchParam {
    enum GestureTouchType {
        GestureTouchBegin,
        GestureTouchMove,
        GestureTouchEnd
    };
    GestureTouchType type;
    XArray<GestureTouchPoint> points;
};


/**
 * 手势事件
 * 对应接收器@link GestureEventListener
 * @lua
 */
class GestureEvent : public Event {

public:
    enum class GestureVersion {
        V0,
        V1,
    };
    
    enum class GestureType {
        Click,
        Move,
        Move2,
        Pinch,
        Rotate2,
        Native
    };

    union GestureParam {
        GestureClickParam *clickParam;
        GestureMoveParam *moveParam;
        GestureMove2Param *move2Param;
        GesturePinchParam *pinchParam;
        GestureRotate2Param *rotate2Param;
        GestureTouchParam *touchParam;
    };

public:
    GestureEvent() : Event(Event::Type::GESTURE), m_Version(GestureEvent::GestureVersion::V0){

    };

    virtual ~GestureEvent() {

    };

public:
    XES_PROPERTY(GestureVersion, Version);
public:
    XES_PROPERTY(GestureType, Type);
public:
    XES_PROPERTY(GestureParam, Param);


};

XESCENE_NAMESPACE_END

#endif //PODS_XESGESTUREEVENT_H
