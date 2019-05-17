//
// Created by momo783 on 2019/3/31.
//

#ifndef PODS_XESSCENEMAGICFILTER_H
#define PODS_XESSCENEMAGICFILTER_H

#include "core/XESDefine.h"
#include "filter/XESSceneFilter.h"
#include "filter/magicscene/XESSceneMagicConfig.h"

XESCENE_NAMESPACE_BEGIN

class SceneMagicFilter : public SceneFilter {
public:
    SceneMagicFilter();

    ~SceneMagicFilter() override;

    void LoadScene(SceneConfig *pSceneConfig, const XString &mSceneID) override;

    void Release() override;

    void Tick(xfloat32 fTickTime) override;

protected:

};

XESCENE_NAMESPACE_END


#endif //PODS_XESSCENEMAGICFILTER_H
