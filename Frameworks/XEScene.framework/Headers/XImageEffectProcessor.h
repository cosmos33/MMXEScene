#ifndef _X_IMAGE_EFFECT_PROCESSOR_H_
#define _X_IMAGE_EFFECT_PROCESSOR_H_

#include "IXImageEffectProcessor.h"
#include "XImageEffectGraph.h"
#include "XArray.h"

class IXVertexBuffer;
class IXIndexBuffer;
class IXVertexDesc;
class IXImageEffectGraphBuilder;
class XImageEffectProcessor : public IXImageEffectProcessor
{
public:
	struct FaceData
	{
		IXVertexBuffer*		pVertexBuffer;
		IXIndexBuffer*		pIndexBuffer;
		IXVertexDesc*		pVertexDesc;

		FaceData() : pVertexBuffer(NULL), pIndexBuffer(NULL), pVertexDesc(NULL) {}
	};

public:
	XImageEffectProcessor() : m_bPreprocessSourceValid(xfalse), m_bPostprocessSourceValid(xfalse) {}
	virtual ~XImageEffectProcessor() {}

	// From IXImageEffectProcessor
	virtual xbool							Init() override;
	virtual void							Release() override;
	virtual void							SetPreprocessEffectSource(const ImageEffectSource& source) override;
	virtual void							SetPostprocessEffectSource(const ImageEffectSource& source) override;
	virtual xbool							ApplyPreprocessEffect() override;
	virtual xbool							ApplyPostprocessEffect() override;

	void									BuildPreprocessImageEffectGraph(IXImageEffectGraphBuilder* pBuilder);
	void									BuildPostprocessImageEffectGraph(IXImageEffectGraphBuilder* pBuilder);

	void									SetFaceData(const FaceData& faceData) { m_faceData = faceData; }

protected:
	XImageEffectGraph						m_preprocessGraph;
	XImageEffectGraph						m_postprocessGraph;
	xbool									m_bPreprocessSourceValid;
	xbool									m_bPostprocessSourceValid;

	FaceData								m_faceData;
};

extern XImageEffectProcessor* g_pXImageEffectProcessor;

#endif