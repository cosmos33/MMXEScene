//
// Created by HongjieFu on 2019/1/8.
//

#ifndef PODS_XESDATAEVENTLISTENER_H
#define PODS_XESDATAEVENTLISTENER_H

#include "core/events/XESEventListener.h"
#include <map>

XESCENE_NAMESPACE_BEGIN

class DataEventListener : public EventListener {
    
    typedef std::function<void(Event *event, XString data)> DataCallback;
    
XESCENE_CONSTRUCTOR_ACCESS:

    DataEventListener();

    xbool Init();

public:
    static const ListenerID LISTENER_ID;

    static DataEventListener *Create();

    virtual ~DataEventListener() override;

    virtual void Release() override;

    virtual xbool CheckAvailable() override;

    virtual DataEventListener *Clone() override;

    void SendEvent(Event *event) override;

    void RegisterHandler(DataCallback handler,XString dataName);
    

private:
    friend class EventDispatcher;
    
    std::map<XString, DataCallback> handlerMap;

};

XESCENE_NAMESPACE_END


#endif //PODS_XESDATAEVENTLISTENER_H
