//
// Created by momo783 on 07/05/2018.
//

#ifndef XES_XESLUAENGINE_H
#define XES_XESLUAENGINE_H

#include "XESScriptEngine.h"
#include "XESLuaStack.h"

class XELuaInterpreter;

XESCENE_NAMESPACE_BEGIN

class LuaEngine : public ScriptEngine {

public:

    LuaEngine();

    virtual ~LuaEngine() override;

    static LuaEngine *GetInstance();

public:
    /**
     * 获取lua状态机
     * @return
     */
    LuaStack *GetLuaStack();

    virtual void AddLuaLoader(lua_CFunction func);

    virtual void Reload(const XString strModuleFileName);

public:
    // Script Engine Protocol
    virtual void AddSearchPath(const XString strPath) override;

    virtual const XString &GetScritpType() override;

    virtual void RemoveScriptHandler(xint32 nHandler) override;

    virtual xint32 ReallocateScriptHandler(xint32 nHandler) override;

    virtual void ExecuteString(const XString &strCodes) override;

    virtual void ExecuteScriptFile(const XString &strFileName) override;

    virtual void StartGameScriptFile(const XString &strFileName) override;

    virtual void ExecuteGlobalFunction(const XString &strFunction) override;

    virtual xbool HandleAssert(const XString &msg) override;

    virtual void SetSecretKey(const char *key) override;


#ifdef X_PLATFORM_MOBILE

    virtual SceneConfig *MakeScriptSceneConfig(const char *string, const char *string1) override;

    virtual SceneFilter *MakeScriptSceneFilter() override;

#endif

private:

    xbool Init();

    static LuaEngine *g_DefaultEngine;

    LuaStack *m_Stack;

//    XELuaInterpreter *_luaInterpreter;

};

XESCENE_NAMESPACE_END

#endif //XES_XESLUAENGINE_H
