/******************************************************************************

@File         XEImgSegmentationComponent.h

@Version       1.0

@Created      2019, 3,21

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE_IMG_SEGMENTATION_COMPONENT_H
#define XE_IMG_SEGMENTATION_COMPONENT_H
#include "XEActorComponent.h"
#include "XETexSegmentationMask.h"

class IXTexture;
class XEDecorationEnvBridgeBase;
class XEImgSegmentationComponent 
	: public XEActorComponent
	, public XETexSegmentationMask
{
public:
	XEImgSegmentationComponent();
	~XEImgSegmentationComponent();
public:
	virtual void                 Empty() override;//empty any instance for this component itself.
	virtual void                 Release() override;
	virtual void                 Render(XEViewport* pViewport) override;
	virtual void                 Initialize(XEActor* pActor) override;
	virtual XMLElement*			 Serialize(XMLElement* pEleParent) override;
	virtual void				 Deserialize(const XMLElement* pEleComponent) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC		  	                            
	virtual void                 GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif						     
public:
	virtual IXTexture2D*         ProvideTexture2D() override;
	virtual XMATRIX4             ProvideWVPMatrix() override;
	virtual xint32               ProvideRenderPrimitiveNum() override;//usually is the triangle num.
	virtual IXVertexDesc*        ProvideVertexDesc() override;
	virtual IXVertexBuffer*      GetVB() override;
	virtual IXIndexBuffer*	     GetIB() override;
public:						     
	xbool                        RebuildDiffuseTexture(const xchar* pTexPath);
public:
	enum eWVPType{ WVP_FIXED, WVP_CAMERA};
public:
	X_FORCEINLINE XCOLORBASE     GetBlendColor(){ return m_clBlend; }
	X_FORCEINLINE void           SetBlendColor(const XCOLORBASE& color){ m_clBlend = color; }
	X_FORCEINLINE void           SetWVPType(eWVPType type){ m_eWVPType = type; }
	X_FORCEINLINE eWVPType       GetWVPType()const{ return m_eWVPType; }
	X_FORCEINLINE const XString& GetDiffuseTexPath()const{ return m_strDiffuseTexPath; }
public:
	XE_COMPONENT_CAST(XEImgSegmentationComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEImgSegmentationComponent)
	static const XString COMPONENT_TYPENAME;
protected:
	XCOLORBASE				       m_clBlend;
	eWVPType                       m_eWVPType;
	XString                        m_strDiffuseTexPath;
	IXTexture2D*                   m_pDiffuseTexture2D;
	XVertexDesc*                   m_pVertexDesc;
	XTypeVertexBuffer<Vertex>*	   m_pVB;
	XIndexBuffer16*                m_pIB;
	xint32						   m_iVertNum;
	xint32						   m_iIndexNum;
	xbool						   m_bEnableRender;

};

#endif // XE_IMG_SEGMENTATION_COMPONENT_H