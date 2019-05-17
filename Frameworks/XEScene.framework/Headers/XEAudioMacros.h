//
// Created by HongjieFu on 2018/6/8.
// AudioEngine Macros
//

#ifndef PODS_XEAUDIO_DEFINE_H
#define PODS_XEAUDIO_DEFINE_H

#define AUDIO_ENGINE_NAMESPACE_START    namespace audio{
#define AUDIO_ENGINE_NAMESPACE_END      };
#define USING_AUDIO                     using namespace audio;

//#define XE_AUDIO_DEBUG

//#ifdef XE_AUDIO_LOG
#define AUDIO_LOG_D(...) NSLog(__VA_ARGS__)
#define AUDIO_LOG_I(...) NSLog(__VA_ARGS__)
//#else
//#define AUDIO_LOG_D(args...) {}
//#define AUDIO_LOG_I(args...) {}
//#endif


/**
 * for iOS
 * The total number of sounds/buffers that can be loaded assuming memory is sufficient
 */
//Number of buffers slots that will be initially created
#define XE_BUFFERS_START 64
//Number of buffers that will be added
#define XE_BUFFERS_INCREMENT 16

#endif
