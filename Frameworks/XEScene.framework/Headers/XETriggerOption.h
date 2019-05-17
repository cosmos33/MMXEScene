/******************************************************************************

@File         XETriggerOption.h

@Version       1.0

@Created      2019, 3, 12

@Description 

@HISTORY:

******************************************************************************/
#ifndef XE_TRIGGER_OPTION_H
#define XE_TRIGGER_OPTION_H
namespace XETriggerOption
{
	enum EmotionalAnimationType{
		EAT_NONE = 0,
		EAT_MOUTH_OPENING = 1 << 0,
		EAT_MOUTH_OPEN = 1 << 1,
		EAT_LEFT_EYE_OPEN = 1 << 2,
		EAT_LEFT_EYE_CLOSING = 1 << 3,
		EAT_LEFT_EYE_BLINK = 1 << 4,
		EAT_RIGHT_EYE_OPEN = 1 << 5,
		EAT_RIGHT_EYE_CLOSING = 1 << 6,
		EAT_RIGHT_EYE_BLINK = 1 << 7,
		EAT_EYE_BLINK = 1 << 8,
		EAT_SMILE = 1 << 9,
		EAT_DUCKFACE = 1 << 10,
		EAT_NOD = 1 << 11
	};

	enum EmotionAnimationPlayMode
	{
		EAPM_IMMEDIATELY = 0,//立刻播放
		EAPM_DISCARD = 1 << 0//丢弃此次触发
	};
	enum GestureType{
		GT_NONE,
		GT_HEART,
		GT_FIVE,
		GT_YEAH,
		GT_ONE,
		GT_BAOQUAN,
		GT_BAINIAN,
		GT_FINGERHEART,
		GT_EIGHT,
		GT_ZAN,
		GT_FIST
	};
};

#endif