//
//  XESScene.h
//  Pods
//
//  Created by momo783 on 02/02/2018.
//
//

#ifndef XESCENE_H_
#define XESCENE_H_

#include "core/XESObject.h"
#include "scene/XESWorld.h"
#include "XECore/XEEngine/XEViewport.h"
#import "IX2DPhysicalScene.h"
#import "IX2DPhysicalManager.h"

#include <functional>
#include <set>

class IXModelInstance;

XESCENE_NAMESPACE_BEGIN

class Rect;

class Scene : public Object, public XClass, public World::WorldListener {

public:
    X_CLASS_DEF(xes::Scene);

public:

    /**
     * 创建一个场景
     * @param mSceneID
     * @return
     */
    static Scene *CreateScene(const char *mSceneID);

public:
    Scene(const XString &mSceneID);

    virtual ~Scene() override;

    virtual void Release() override;

    xfloat32 SceneTickTime();

public:

    /**
     * 获取场景ID
     * @return
     */
    X_FORCEINLINE XString GetSceneID() {
        return m_vSceneID;
    }

    /**
     * 获取World
     * @return
     */
    X_FORCEINLINE World *GetWorld() {
        return m_pSceneWorld;
    }


    static xbool IsActorInTheBackOfCamera(XEActor *pActor);

    /**
     * 判断Actor是否在场景中
     * @param pActor
     * @return
     */
    static xbool IsActorInScreen(XEActor *pActor);

    /**
     *
     * @param pActor
     * @return
     */
    static Rect GetActorScreenFrame(XEActor *pActor);

    /**
     *
     * @param pActor
     * @return
     */
    static Rect GetActorScreenFrameWithSkeleton(XEActor *pActor);

    /**
     *
     * @param pActor
     * @param fixScale
     * @return
     */
    static Rect GetActorScreenFrameWithSkeleton(XEActor *pActor, xfloat32 fixScale);

    /**
     *
     * @param pActor
     * @return
     */
    static XVECTOR2 GetActorDetectScreenPosition(XEActor *pActor);

    /**
     * 创建物理场景
     * @param szSceneName
     * @param vGravity
     * @return
     */
    IX2DPhysicalScene *Create2DPhysicalScene(const xchar *szSceneName, const XVECTOR2 &vGravity = XVECTOR2(0.0f, -9.8f));

public:

    typedef std::function<void(xfloat32 fDel)> SceneTickCallback;

    XESS_IGNORE SceneTickCallback OnTickCallback;

public:
    /**
     * 生命周期方法
     */
    XESS_IGNORE virtual void OnStart();

    /**
     * 生命周期方法
     */
    XESS_IGNORE virtual void OnResume();

    /**
     * 生命周期方法
     */
    XESS_IGNORE virtual void OnPause();

    /**
     * 生命周期方法
     */
    XESS_IGNORE virtual void OnEnd();

    /**
     * 渲染前会被调用
     * @param d
     */
    XESS_IGNORE virtual void OnTick(xfloat32 d);

    /**
     * 渲染后会被调用
     * @param d
     */
    XESS_IGNORE virtual void OnTickComplete(xfloat32 d);

private:
    virtual void OnWorldAddActor(XEActor *aActor) override;

    virtual void OnWorldWillRemoveActor(XEActor *aActor) override;

    virtual void OnWorldUpdateActor(XEActor *aActor, XString strOldActorName) override;

    virtual void OnWorldTick(xfloat32 fDel) override;

    virtual void OnWorldTickComplete(xfloat32 fDel) override;

    static Rect GetScreenFrameWithAABB(XCusAABB aabb);

    void PauseSceneForAction();

    void ResumeSceneForAction();

private:

    XString m_vSceneID;

    World *m_pSceneWorld;

    std::set<XString> m_sActorNames;

    xuint32 m_fStartTime;

    friend class Director;

    IX2DPhysicalScene *m_2DPhysicalScene;

};

XESCENE_NAMESPACE_END

#endif /* XESCENE_H_ */
