//
// Created by HongjieFu on 2018/7/2.
//

#ifndef PODS_XESCHEDULER_H
#define PODS_XESCHEDULER_H


#include <functional>
#include <list>
#include <ctime>
#include "XESDefine.h"
#include "XESObject.h"

XESCENE_NAMESPACE_BEGIN

typedef int SchduleTaskId;
typedef std::function<void(SchduleTaskId)> SchedulerFunc;

class Task : public XMemBase {
public:
    void *tag;
    SchduleTaskId taskId;
    float interval;
    int repeat;
    float delay;
    SchedulerFunc callFunc;
    xuint64 nextCallTime;
    int repeated;
};

/**
 * 调度器
 * @lua
 */
class Scheduler {

public:
    static const int INTERVAL_NEXT_TICK = -2;

public:

    /**
     * 普通调度
     * @lua
     * @param callFunc  回调函数
     * @param interval  执行间隔
     * @param repeat    重复次数
     * @param delay     延迟时间
     * @return
     */
    static Task *schedule(SchedulerFunc callFunc,
            float interval = -1,
            int repeat = -1,
            float delay = 0);

    /**
     * 普通调度
     * @lua
     * @param tag       绑定对象
     * @param callFunc  回调函数
     * @param interval  执行间隔
     * @param repeat    重复次数
     * @param delay     延迟时间
     * @return
     */
    static Task *schedule(void *tag,
            SchedulerFunc callFunc,
            float interval = -1,
            int repeat = -1,
            float delay = 0);

    /**
     * 单次调度
     * @param callFunc  回调函数
     * @param interval  延时时间
     * @param delay     无效参数，兼容旧代码 传入后会和interval相加
     * @return
     */
    static Task *scheduleOnce(SchedulerFunc callFunc,
            float interval,
            float delay = 0);

    /**
     * 单次调度
     * @param tag       绑定对象
     * @param callFunc  回调函数
     * @param interval  延迟时间
     * @return
     */
    static Task *scheduleOnce(void *tag,
            SchedulerFunc callFunc,
            float interval);

    /**
     * 移除一次调度
     * @param taskId
     * @return
     */
    static bool unschedule(SchduleTaskId taskId);

    /**
     * 移除全部的调度器
     */
    static void unscheduleAll();

    /**
     * 根据绑定对象移除调度器
     * @param tag       绑定对象
     */
    static void unscheduleByTag(void *tag);

    /**
     * 当前时间戳
     * @return
     */
    static xuint64 time();

    static void doUpdate();

    class SchedulerTaskPool {

    public:
        SchedulerTaskPool();

        virtual ~SchedulerTaskPool();

    public:
        std::list<SchduleTaskId> _tasksShouldBeRemove;
        std::list<Task *> _tasks;

        void doUpdate();


    };

private:
    static SchedulerTaskPool *getSchedulerTaskPool();
};

XESCENE_NAMESPACE_END

#endif //PODS_XESCHEDULER_H
