//
//  XESWindow.h
//  XEScene
//
//  Created by momo783 on 02/02/2018.
//

#ifndef XESWINDOW_H_
#define XESWINDOW_H_

#include "xcommon/XPlatformWindow.h"
#include "core/XESDefine.h"
#include "core/XESGeometry.h"
#include "core/events/XESTouchEvent.h"
#include "XECore/XEEngine/XEViewport.h"
#include <vector>

XESCENE_NAMESPACE_BEGIN

class Touch;

class TouchEvent;

/**
 * 窗口类
 * @lua enable
 */
class Window : public IXPlatformWindow, public XClass {
public:

    X_CLASS_DEF(xes::Window);

    Window();

    Window(unsigned int nwidht, unsigned int height);

    virtual ~Window() {
    };

public://IXPlatformWindow 接口实现
    virtual void *GetWinHandle() override {
        return _winHandler;
    }

    virtual unsigned int GetWidth() override {
        return m_nWidth;
    }

    virtual unsigned int GetHeight() override {
        return m_nHeight;
    }

    virtual bool IsFullScreen() override {
        return true;
    }

    virtual int GetMouseX() override {
        return 0;
    }

    virtual int GetMouseY() override {
        return 0;
    }

    void SetWidthHeight(int width, int height) override;

public:

    virtual xbool HandleToucheHitTest(xfloat32 xs, xfloat32 ys);

    virtual void HandleTouchesBegin(xint32 num, intptr_t ids[], xfloat32 xs[], xfloat32 ys[]);

    virtual void HandleTouchesMove(xint32 num, intptr_t ids[], xfloat32 xs[], xfloat32 ys[]);

    virtual void HandleTouchesMove(xint32 num, intptr_t ids[], xfloat32 xs[], xfloat32 ys[], xfloat32 fs[], xfloat32 ms[]);

    virtual void HandleTouchesEnd(xint32 num, intptr_t ids[], xfloat32 xs[], xfloat32 ys[]);

    virtual void HandleTouchesCancel(xint32 num, intptr_t ids[], xfloat32 xs[], xfloat32 ys[]);

public:
    /**
     * 获取视口范围
     * @lua enable
     * @return
     */
    const Rect &GetViewPortRect() const;

    /**
     * 获取所有触摸模型
     * @lua enable
     * @return
     */
    std::vector<Touch *> GetAllTouches() const;

    /**
     * 获取X方向缩放系数
     * @lua enable
     * @return
     */
    xfloat32 GetScaleX() const;

    /**
     * 获取Y方向缩放系数
     * @lua enable
     * @return
     */
    xfloat32 GetScaleY() const;

    /**
     * 获取视口
     * @lua enable
     * @return
     */
    X_FORCEINLINE XEViewport *GetViewport() {
        return m_pViewport;
    }

    /**
     * 设置视口
     * @lua enable
     * @param mViewport
     */
    void SetViewport(XEViewport *mViewport) {
        m_pViewport = mViewport;
    }

    /**
     * 设置缩放系数 ios为nativeScale
     * @lua enable
     * @param scale
     */
    void SetScreenScale(xfloat32 scale);

public:

    void SetWinHandler(void *_winHandler);

private:

    void HandleTouchesOfEndOrCancel(TouchEvent::EventCode nEventCode, int num, intptr_t ids[], float xs[], float ys[]);

private:

    unsigned int m_nWidth;
    unsigned int m_nHeight;

    xfloat32 m_ScaleX;
    xfloat32 m_ScaleY;

    Size m_ScreenSize;
    Rect m_rViewPortRect;

    XEViewport *m_pViewport;

    void *_winHandler;


};

XESCENE_NAMESPACE_END

XESS_IGNORE extern IXPlatformWindow *g_pXWindow;

#endif /* XESWINDOW_H_ */
