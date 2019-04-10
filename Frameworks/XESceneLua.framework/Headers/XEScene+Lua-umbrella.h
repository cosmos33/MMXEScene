#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "XESLuaEngine.h"
#import "XESScriptBridge.h"
#import "XESScriptBridgeBinding.h"
#import "XESScriptBridge-iOS.h"

FOUNDATION_EXPORT double XESceneLuaVersionNumber;
FOUNDATION_EXPORT const unsigned char XESceneLuaVersionString[];

