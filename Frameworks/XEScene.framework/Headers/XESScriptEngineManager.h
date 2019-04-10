//
// Created by momo783 on 06/05/2018.
//

#ifndef XES_XESSCRIPTENGINEMANAGER_H
#define XES_XESSCRIPTENGINEMANAGER_H

#include "script/XESScriptEngine.h"
#include "filter/XESSceneFilter.h"


XESCENE_NAMESPACE_BEGIN

class ScriptEngineManager : public Object {

public:
    static ScriptEngineManager *GetInstance();

    SceneConfig *MakeScriptSceneConfig(const char *, const char *);

    SceneFilter *MakeScriptSceneFilter();

    ScriptEngine *GetScriptEngine();

    void SetScriptEngine(ScriptEngine *pScriptEngine);

    void RemoveScriptEngine();

    static void DestoryInstance();

private:

    ScriptEngineManager() : m_ScriptEngine(nullptr) {
    };

    virtual ~ScriptEngineManager() override;

    void Release() override;

protected:

    ScriptEngine *m_ScriptEngine;

};

XESCENE_NAMESPACE_END


#endif
