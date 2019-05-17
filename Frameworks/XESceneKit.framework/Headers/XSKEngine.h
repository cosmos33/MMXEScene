//
// Created by momo783 on 02/08/2018.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


typedef void (^XSKEnginePrintFunc)(const char *);

@interface XSKEngine : NSObject

@property(nonatomic, strong, readonly) NSString *resourcePath;


- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)shareInstance;

+ (NSString *)version;

- (BOOL)configResourcePath:(NSString *)resourcePath;

- (BOOL)runEngine;

- (BOOL)runEngineWithRenderSize:(CGSize)renderSize;

- (BOOL)isRunning;

- (void)updateRenderSize:(CGSize)renderSize;

- (void)render;

- (void)render:(NSString *)renderID;

- (void)endRunEngine;

- (void)enableClearColor:(BOOL)enable;

- (void)addSearchPath:(NSString *)relationSearchPatch;

- (void)setLogEnable:(BOOL)logEnable;

- (void)setPrintFunc:(XSKEnginePrintFunc)printFunc;

- (void)setErrFunc:(XSKEnginePrintFunc)printFunc;

- (void)putInfoEx:(NSString *)infoEx;

@end

NS_ASSUME_NONNULL_END
