#ifndef _X_IMAGE_EFFECT_SHADER_CODEC_H_
#define _X_IMAGE_EFFECT_SHADER_CODEC_H_

#include "XMemBase.h"

class IXImageEffectShaderCodec : public XMemBase
{
public:
	virtual			~IXImageEffectShaderCodec() {}

	virtual void	EncodeShaderString(xchar *pBuffer, xuint32 nLength) = 0;
	virtual void	DecodeShaderString(xchar *pBuffer, xuint32 nLength) = 0;
};

extern IXImageEffectShaderCodec* g_pXImageEffectShaderCodec;

#endif