#ifndef _X_IMAGE_EFFECT_NODE_USER_H_
#define _X_IMAGE_EFFECT_NODE_USER_H_

#include "XImageEffectNode.h"

#define NODE_USER_TYPE_NAME "User"

class XImageEffectNodeUser : public XImageEffectNodeBase<1, 1>
{
public:
	static const XString				TYPE_NAME;

public:
	virtual XRenderTargetDesc			ComputeOutputDesc(ENodeOutputId eOutputId) const override;
	virtual IXMaterialInstance*			GetParameterSet() override { return m_pMatIns; }

	void								SetMaterialInstance(IXMaterialInstance* pMatIns);
	void                                SetVertexDesc(IXVertexDesc* pVertexDesc){ m_pVertexDesc = pVertexDesc; }
	void                                SetVertexBuffer(IXVertexBuffer* pVertexBuffer){ m_pVertexBuffer = pVertexBuffer; }
	void                                SetIndexBuffer(IXIndexBuffer* pIndexBuffer){ m_pIndexBuffer = pIndexBuffer; }
	void                                SetCopyOriginAsBackgroundEnabled(xbool bEnabled){ m_bEnableCopyOriginAsBackground = bEnabled; }
	const IXVertexDesc*                 GetVertexDesc() const{ return m_pVertexDesc; }
	const IXVertexBuffer*               GetVertexBuffer() const{ return m_pVertexBuffer; }
	const IXIndexBuffer*                GetIndexBuffer() const{ return m_pIndexBuffer; }
	xbool                               GetCopyOriginAsBackgroundEnabled()const{ return m_bEnableCopyOriginAsBackground; }

protected:
	XImageEffectNodeUser() : m_pMatIns(NULL), m_pVertexDesc(NULL), m_pVertexBuffer(NULL), m_pIndexBuffer(NULL), m_bMaterialInsReset(xfalse), m_bEnableCopyOriginAsBackground(xtrue){}
	virtual ~XImageEffectNodeUser();

protected:
	IXMaterialInstance*					m_pMatIns;
	IXVertexDesc*                       m_pVertexDesc;
	IXVertexBuffer*                     m_pVertexBuffer;
	IXIndexBuffer*                      m_pIndexBuffer;
	xbool                               m_bEnableCopyOriginAsBackground;//indicate whether you need to render an origin texture as background. (otherwise will render the specific vertex you've set only. )
	xbool								m_bMaterialInsReset;
};

#endif
