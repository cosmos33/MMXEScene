//
// Created by momo783 on 2019/3/31.
//

#ifndef PODS_XESSCENEMAGICCONFIG_H
#define PODS_XESSCENEMAGICCONFIG_H

#include "XESDefine.h"
#include "filter/XESSceneFilter.h"

XESCENE_NAMESPACE_BEGIN

class SceneMagicConfig : public SceneConfig {
public:

    XES_SCENE_TYPE_DEFINE(SCENE_TYPENAME);
    static const XString  SCENE_TYPENAME;

public:
    SceneMagicConfig();

    ~SceneMagicConfig() override;

    void Release() override;

    void LoadConfig(const XString &mJsonBuffer, const XString &mScenePath) override;
};

XESCENE_NAMESPACE_END


#endif //PODS_XESSCENEMAGICCONFIG_H
