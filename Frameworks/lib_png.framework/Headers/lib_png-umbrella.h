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

#import "png.h"
#import "pngconf.h"
#import "pnglibconf.h"

FOUNDATION_EXPORT double lib_pngVersionNumber;
FOUNDATION_EXPORT const unsigned char lib_pngVersionString[];

