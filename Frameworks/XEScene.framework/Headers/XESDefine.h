//
//  XEDefine.h
//  XEScene
//
//  Created by momo783 on 02/02/2018.
//

#ifndef XEDEFINE_H_
#define XEDEFINE_H_

/**  public include */

#include "xcommon/XPlatform.h"
#include "xcommon/XTypes.h"
#include "xcommon/XMath3D.h"
#include "xcommon/XMemBase.h"
#include "xcommon/XString.h"
#include "xcommon/XArray.h"
#include "xcommon/XHashTable.h"
#include "xcommon/XGlobalFuncs.h"

#include <stdio.h>
#include <string>



// Platform Define
#include "XPlatform.h"

#if (defined X_PLATFORM_WIN_DESKTOP) || (defined  X_PLATFORM_MAC)
#define X_PLATFORM_DESKTOP
#else
#define X_PLATFORM_MOBILE
#endif



/**  namespace define */

#define XESCENE_VERSION "3.0.0"

#define XESCENE_NAMESPACE            xes
#define XESCENE_NAMESPACE_BEGIN      namespace XESCENE_NAMESPACE {
#define XESCENE_NAMESPACE_END        }
#define USING_XESCENE                using namespace XESCENE_NAMESPACE;

#define AR_NAMESPACE                 AR
#define AR_NAMESPACE_BEGIN           namespace AR_NAMESPACE {
#define AR_NAMESPACE_END             }

XESCENE_NAMESPACE_BEGIN


/**
 *  @def XESCENE_REQUIRES_NULL_TERMINATION
 */
#if !defined(XESCENE_REQUIRES_NULL_TERMINATION)
#if defined(__APPLE_CC__) && (__APPLE_CC__ >= 5549)
#define XESCENE_REQUIRES_NULL_TERMINATION __attribute__((sentinel(0,1)))
#elif defined(__GNUC__)
#define XESCENE_REQUIRES_NULL_TERMINATION __attribute__((sentinel))
#else
#define XESCENE_REQUIRES_NULL_TERMINATION
#endif
#endif

/**
 * @def XESCENE_ENABLE_SCRIPT_BINDING
 */

#ifndef XESCENE_ENABLE_SCRIPT_BINDING
#define XESCENE_ENABLE_SCRIPT_BINDING = 1
#endif

#ifndef XESCENE_CONSTRUCTOR_ACCESS
#ifdef XESCENE_ENABLE_SCRIPT_BINDING
#define XESCENE_CONSTRUCTOR_ACCESS public
#else
#define XESCENE_CONSTRUCTOR_ACCESS protected
#endif
#endif

/**
 *  @def Debug
 */
//#define XES_DEBUG 0
//#define XES_DEBUG_LOG 0
//#define XES_DEBUG_LUA_LOG 1

#if XES_DEBUG
#define XESAssert(x) {}
#else
#define XESAssert(x) {}
#endif


namespace StringUtils {

XString Format(const char *format, ...);

void PrintLog(const char *format, ...);

}


#if (defined XE_LUA_ENABLE_LOG) || (defined XES_DEBUG_LOG) || (defined XE_LOG_ENABLE)
#define XESLog(format, args...) xes::StringUtils::PrintLog(format, ##args)
#define XE_Log(format, args...) xes::StringUtils::PrintLog(format, ##args)
#else
#define XESLog(format, args...) {}
#define XE_Log(...) {}
#endif

XESCENE_NAMESPACE_END

//属性声明
#define XES_PROPERTY(type, name)\
inline void Set##name(type v) {\
    m_##name = v;\
}\
inline type Get##name() {\
    return m_##name;\
}\
protected: type m_##name;

#define XES_READONLY_PROPERTY(type, name)\
inline type Get##name() {\
    return m_##name;\
}\
protected: type m_##name;\

#define XES_WRITEONLY_PROPERTY(type, name)\
inline void Set##name(type v) {\
    m_##name = v;\
}\
protected: type m_##name;\

//Scripting
#define XESS_IGNORE         //忽略导出方法    不允许加在实现方法上
#define XESS_MANUAL         //手动导出方法    不允许加在实现方法上
#define XESS_RETURN_VALUE   //作为返回值处理的参数
#define XESS_HIDE_START     //大段忽略-开始   不允许嵌套
#define XESS_HIDE_END       //大段忽略-结束   不允许嵌套


#define XESS_GET_CLASSNAME(__CLASS_NAME__)\
virtual const char* GetClassName(){\
    return #__CLASS_NAME__;\
}


#endif /* XEDEFINE_H_ */
