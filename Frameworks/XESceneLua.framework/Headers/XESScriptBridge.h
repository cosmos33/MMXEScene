//
// Created by HongjieFu on 2018/7/2.
//

#ifndef PODS_XESLUABRIDGE_H
#define PODS_XESLUABRIDGE_H

#include  <functional>
#include "XESLuaStack.h"

XESCENE_NAMESPACE_BEGIN

class ScriptBridgeCallback {

public:
    ScriptBridgeCallback(LUA_FUNCTION i);

    virtual ~ScriptBridgeCallback();

    void call(const char *result);

private:
    LUA_FUNCTION lua_function;

};

class ScriptBridge {

public:
    typedef std::function<void(const char *)> CallbackFunc;

    /**
     * Lua 调用原生
     * @param handler
     * @param action
     * @param message
     * @return
     */
    static XString call(const char *handler, const char *action, const char *message);

    /**
     * Lua异步调用原生
     * @param handler
     * @param action
     * @param message
     * @param callback
     */
    static void callAsync(const char *handler, const char *action, const char *message,
                          ScriptBridgeCallback *callback);

    static void
    nativeCall(const char *handler, const char *action, const char *message, XString &rest);

    static void nativeCallAsync(const char *handler, const char *action, const char *message,
                                CallbackFunc callback);

private:

    static xuint32 g_callID;

    static XHashTable<XString, CallbackFunc> g_callbacks;

    static int luaCallback(lua_State *xelua_S);

};


XESCENE_NAMESPACE_END

#endif //PODS_XESLUABRIDGE_H
