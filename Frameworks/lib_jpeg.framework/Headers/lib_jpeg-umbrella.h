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

#import "jconfig.h"
#import "jerror.h"
#import "jmorecfg.h"
#import "jpeglib.h"

FOUNDATION_EXPORT double lib_jpegVersionNumber;
FOUNDATION_EXPORT const unsigned char lib_jpegVersionString[];

