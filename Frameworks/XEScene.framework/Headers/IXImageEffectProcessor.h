#ifndef _IX_IMAGE_EFFECT_PROCESSOR_H
#define _IX_IMAGE_EFFECT_PROCESSOR_H

#include "XTypes.h"

class IXPrimitiveBase;
class IXImageEffectProcessor
{
public:
	struct ImageEffectSource
	{
		xint32	nFrameBufferID;
		xint32	nTextureID;
		xint32	nWidth;
		xint32	nHeight;
	};

	virtual ~IXImageEffectProcessor() {}

	virtual xbool						Init() = 0;
	virtual void						Release() = 0;

	virtual void						SetPreprocessEffectSource(const ImageEffectSource& source) = 0;
	virtual void						SetPostprocessEffectSource(const ImageEffectSource& source) = 0;

	virtual xbool						ApplyPreprocessEffect() = 0;
	virtual xbool						ApplyPostprocessEffect() = 0;
};

#endif