//
//  XEGameView.h
//  XEScene
//
//  Created by HongjieFu on 2019/1/28.
//

#import <GLKit/GLKit.h>

NS_ASSUME_NONNULL_BEGIN

@class XEGameView;

@protocol XEGameViewDelegate <NSObject>

/**
 * 游戏开始回调
 * @param view XEGameView Instance
 */
- (void)onGameStartedOfGameView:(XEGameView *)view;

/**
 * 获取资源路径
 * @param view XEGameView Instance
 * @return
 */
- (NSString *)gameResPathOfGameView:(XEGameView *)view;

@end

@interface XEGameView : GLKView

/**
 * GameView代理
 */
@property(nonatomic, assign) id <XEGameViewDelegate> gameDelegate;

/**
 * 最大帧率
 */
@property(nonatomic, assign) float maxFps;

/**
 * 是否开启透明 默认为NO
 */
@property(nonatomic, assign) BOOL transparent;

/**
 * 开始游戏
 */
- (void)startGame;

/**
 * 在单独的线程内允许游戏
 */
- (void)startGameAsync;

/**
 * 结束游戏
 */
- (void)endGame;

@end

NS_ASSUME_NONNULL_END
