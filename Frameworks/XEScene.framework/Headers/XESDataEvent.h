//
// Created by HongjieFu on 2019/1/7.
//

#ifndef PODS_XESDATAEVENT_H
#define PODS_XESDATAEVENT_H


#include "XESEvent.h"

XESCENE_NAMESPACE_BEGIN

class DataEvent : public Event {

public:
    DataEvent();
    
    virtual ~DataEvent();
    
public:
    XES_PROPERTY(XString, Name);
public:
    XES_PROPERTY(XString, Content);

};


XESCENE_NAMESPACE_END


#endif //PODS_XESDATAEVENT_H
