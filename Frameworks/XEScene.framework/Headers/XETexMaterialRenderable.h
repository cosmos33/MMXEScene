/******************************************************************************

@File         XETexMaterialRenderable.h

@Version       1.0

@Created      2019, 3, 13

@Description  renderable from material.

@HISTORY:

******************************************************************************/
#ifndef _XE_TEX_MATERIAL_RENDERABLE_H
#define _XE_TEX_MATERIAL_RENDERABLE_H

#include "XPrimitiveBase.h"
#include "XObject.h"
#include "XInternalResource.h"
#include "XWorld.h"

class XETexMaterialRenderable : public IXPrimitiveBase, public IXObject
{
public:
	XETexMaterialRenderable();
	virtual ~XETexMaterialRenderable();
	typedef XETexMaterialRenderable Super;
public:
	virtual void						  Render(IXMeshRenderBase* pPriRender, const XPriRenderParam& priRenderParam) override;
	virtual void						  RenderDepth(IXMeshRenderBase* pPriRender, const XPriRenderParam& priRenderParam) override;
	virtual xuint32						  GetPrimitiveLayerMask() const override;
	virtual const XCusAABB&				  GetAABB() const override;
	virtual xbool						  IsVisible(XCameraViewFrustum* pFrustum, XRectI* pRect) override;
	virtual void						  BeginView() override;
	virtual void						  EndView() override;
	// interface of IXObject			  
	virtual void						  RegisterToScene(IXWorld* pScene) override;
	virtual IXPrimitiveBase*			  GetPrimitive() override;
public:
	virtual xbool                         SetupMaterialParameter();
	virtual xbool                         BuildMaterialIns(const xchar* szMaterialFile, const xchar* szReplaceShaderMacro = NULL);
	xbool                                 SetMacroEnable(const char* szShaderMacro, xbool bEnable);
public:
	//you should provide these.
	virtual IXTexture2D*                  ProvideTexture2D() = 0;
	virtual XMATRIX4                      ProvideWVPMatrix() = 0;
	virtual xint32                        ProvideRenderPrimitiveNum() = 0;//usually is the triangle num.
	virtual IXVertexDesc*                 ProvideVertexDesc() = 0;
	virtual IXVertexBuffer*               GetVB() = 0;
	virtual IXIndexBuffer*				  GetIB() = 0;
protected:
	XCusAABB							  m_AABB;
	IXMaterialInstance*					  m_pMaterialIns;
	XString								  m_strMaterialInsName;
	xbool                                 m_bDirty;
};


#endif//_XE_TEX_MATERIAL_RENDERABLE_H