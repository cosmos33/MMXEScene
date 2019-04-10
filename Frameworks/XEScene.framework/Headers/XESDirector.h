//
//  XESDirector.h
//  Pods
//
//  Created by momo783 on 02/02/2018.
//
//

#ifndef XESDIRECTOR_H_
#define XESDIRECTOR_H_

#include "core/XESObject.h"
#include "scene/XESWindow.h"
#include "scene/XESScene.h"
#include "XECore/XEGame.h"
#include "XECore/XEEngine/XEEngine.h"
#include "platform/armodule/XESARModule.h"

//全局变量所在头文件
#include "XUIManager.h"
#include "XESWindow.h"
#include "XWorld.h"
#include "IX2DPhysicalManager.h"
#include "PhysicalManager.h"
#include "XCanvasBase.h"
#include "xcommon/XModel.h"

class IXEDressupManager;

class IXAnimationManager;

enum PLATFORM_OS {
    PLATFORM_OS_NONE,
    PLATFORM_OS_IOS,
    PLATFORM_OS_ANDROID
};

XESCENE_NAMESPACE_BEGIN

class EventDispatcher;

class ActionManager;

class Director : public Object, public XEEngine::XEFrameListener {

private:

    Director();

    virtual ~Director() override;

    virtual void Release() override;

public:

    /**
     * 获取实例
     * @return
     */
    static Director *GetInstance();

    /**
     * 获取引擎版本号
     * @return
     */
    static X_FORCEINLINE XString GetVersion() {
        return XESCENE_VERSION;
    }

    /**
     * 获取平台
     * @return
     */
    static PLATFORM_OS GetPlatform();

public:

    /**
     * 获取引擎运行状态
     * @return
     */
    X_FORCEINLINE xbool IsRunning() {
        return m_bRunning;
    }

    /**
     * 启动引擎
     * @param mBasePath         shader路径
     * @param mLibraryPath      资源路径
     * @return
     */
    xbool Run(const xchar *mBasePath, const xchar *mLibraryPath);

    /**
     * 启动引擎
     * @param mBasePath         shader路径
     * @param mLibraryPath      资源路径
     * @param nwidht            渲染尺寸宽
     * @param height            渲染尺寸高
     * @return
     */
    xbool Run(const xchar *mBasePath, const xchar *mLibraryPath, int nwidht, int height);

    /**
     * 结束引擎
     */
    void End();

    /**
     * 渲染一帧
     */
    void Render();

    /**
     * 根据场景ID渲染一帧
     * @param mSceneID
     */
    void Render(const xchar *mSceneID);

    /**
     * 重设窗口尺寸
     * @param mWidth
     * @param mHeight
     */
    void ResizeWindow(xint32 mWidth, xint32 mHeight);

    /**
     * 显示引擎调试信息
     * @param show
     */
    void ShowDebugInfo(xbool show);

public:

    X_FORCEINLINE Window *GetWindow() {
        return m_wCurrentWindow;
    }

    X_FORCEINLINE XEGame *GetGame() {
        return m_gCurrentGame;
    }

    X_FORCEINLINE XEEngine *GetEngine() {
        return m_eUseEngine;
    }

public:

    /**
     * 清楚背景
     */
    void ClearBackground();

    /**
     * 设置是否允许透明色
     * @param bClearColor
     */
    void EnableClearColor(xbool bClearColor);

    /**
     * 执行任务队列中的任务
     */
    void ExcuteQueueTask();

public:

    /**
     * 显示一个新的场景
     * @param mScene
     */
    void PushScene(Scene *mScene);

    /**
     * 弹出当前栈顶场景
     */
    void PopScene();

    /**
     * 获取当前栈顶场景
     * @return
     */
    Scene *GetTopScene();

    /**
     * 呈现一个场景
     * @param mScene        场景
     * @param mSceneID      场景ID
     */
    void PresentScene(Scene *mScene, const xchar *mSceneID);

    /**
     * 消除一个场景   此场景必须是通过@PresentScene添加的场景
     * @param mSceneID      场景ID
     */
    void DissmissScene(const xchar *mSceneID);

    /**
     * 获取要呈现的场景     此场景必须是通过@PresentScene添加的场景
     * @param mSceneID
     * @return
     */
    Scene *GetPresentScene(const xchar *mSceneID);

    /**
     * 获取正在运行的场景    报错场景栈中的场景和要呈现的场景
     * @return
     */
    XArray<Scene *> GetRunningScene();

public:

    /**
     * AR 是否处于可用状态
     * @return
     */
    X_FORCEINLINE xbool ARIsActive() const {
        return m_bARActive;
    }

    /**
     * 是否支持AR
     * @param bActive
     * @param bInternal
     */
    void ActiveARSupport(xbool bActive, xbool bInternal = true);

#if ARKIT_SUPPORT

    void *InternalARSessionDelegate();

#endif

    /**
     * 注册AR模块
     * @param pARModule
     */
    void RegisterARModule(AR::ARModule *pARModule);

    /**
     * 获取AR模块
     * @return
     */
    X_FORCEINLINE AR::ARModule *GetARModule() {
        return m_pARModule;
    };

public:

    virtual void OnPreFrame() override;

    virtual void OnPostFrame() override;

    virtual void OnFrameSizeChanged() override;

public:
    /**
     * 获取事件派发器
     * @return
     */
    EventDispatcher *GetEventDispatcher();

    /**
     * 设置事件派发器
     * @param pEventDispatcher
     */
    void SetEventDispatcher(EventDispatcher *pEventDispatcher = nullptr);

public:
    // Actions
    ActionManager *GetActionManager();

    void SetActionManager(ActionManager *pActionManager = nullptr);

public:

    /**
     * 获取Shader路径
     * @return
     */
    X_FORCEINLINE XString GetBasePath() const {
        return m_sBasePath;
    }

    /**
     * 获取资源路径
     * @return
     */
    X_FORCEINLINE XString GetLibraryPath() const {
        return m_sLibraryPath;
    }

public:

    IXAnimationManager *GetAnimationManager();

    /**
     * 获取DressupManager
     * @return
     */
    IXEDressupManager *GetDressupManager();

public:

    /**
     * 添加一个任务
     * @param task 任务
     */
    void queryTask(std::function<void()> task);


public://全局变量获取
    static X_FORCEINLINE IXUIManager *GetXUIManager() {
        return g_pIXUIManager;
    }

    static X_FORCEINLINE IXCanvasBase *GetXCanvasBase() {
        return g_pXCanvasBase;
    }

    static X_FORCEINLINE IXPlatformWindow *GetXWindow() {
        return g_pXWindow;
    }

    static X_FORCEINLINE IX2DPhysicalManager *GetX2DPhysicalManager() {
        return g_pIX2DPhysicalManager;
    }

    static X_FORCEINLINE IXWorld *GetXWorld() {
        return g_pXWorld;
    }

    static X_FORCEINLINE IXPhysicalManager *GetXPhysicalManager() {
        return g_pIXPhysicalManager;
    }

    static X_FORCEINLINE IXModelManager *GetXModelManager() {
        return g_pXModelManager;
    }

    static X_FORCEINLINE IXEditorModelManager *GetXEditorModelManager() {
        return g_pXEditorModelManager;
    }


protected:

    xbool m_bRunning;

    xbool m_bARActive;

    xbool m_bInternal;

    XString m_sBasePath;

    XString m_sLibraryPath;

    Window *m_wCurrentWindow;

    XEGame *m_gCurrentGame;

    XEEngine *m_eUseEngine;

    XEEngine::XEFrameListener *m_lFrameListener;

    XArray<Scene *> m_aSceneStack;

    XHashTable<XString, Scene *> m_mSceneCollection;

    Scene *m_RnederScene;

    xuint32 m_fStartTime;

    EventDispatcher *m_pEventDispatcher;

    ActionManager *m_pActionManager;

    AR::ARModule *m_pARModule;

    XArray<std::function<void()> > _taskQueue;
};

XESCENE_NAMESPACE_END

#endif /* XESDIRECTOR_H_ */
