//
// Created by momo783 on 06/05/2018.
//

#ifndef XES_XESSCRIPTENGINE_H
#define XES_XESSCRIPTENGINE_H

#include "core/XESObject.h"

#ifndef X_PLATFORM_WIN_DESKTOP

#include "filter/XESSceneFilter.h"

#endif

class XEActor;

XESCENE_NAMESPACE_BEGIN

class ScriptEngine {

public:
    
    virtual ~ScriptEngine() {};
    
    virtual const XString &GetScritpType() = 0;

    virtual void AddSearchPath(const XString strPath) = 0;

    virtual void RemoveScriptHandler(xint32 nHandler) = 0;

    virtual xint32 ReallocateScriptHandler(xint32 nHandler) = 0;

    virtual void ExecuteString(const XString &strCodes) = 0;

    virtual void ExecuteScriptFile(const XString &strFileName) = 0;

    virtual void StartGameScriptFile(const XString &strFileName) = 0;

    virtual void ExecuteGlobalFunction(const XString &strFunction) = 0;

    virtual xbool HandleAssert(const XString &msg) = 0;

    virtual void SetSecretKey(const char *key) = 0;
    
    virtual void CleanStack() = 0;

#ifndef X_PLATFORM_WIN_DESKTOP

    virtual SceneConfig *MakeScriptSceneConfig(const char *string, const char *string1) = 0;

    virtual SceneFilter *MakeScriptSceneFilter() = 0;

#endif

};

XESCENE_NAMESPACE_END


#endif //XES_XESSCRIPTENGINE_H
