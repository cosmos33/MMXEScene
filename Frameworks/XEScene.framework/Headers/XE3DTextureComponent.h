/******************************************************************************

@File         XE3DTextureComponent.h

@Version       1.0

@Created      2017, 9, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE3DTextureComponent_H
#define XE3DTextureComponent_H
#include "XEActorComponent.h"
#include "XTexture.h"


class XE3DTextureComponent:public XEActorComponent
{
public:
	XE3DTextureComponent();
	~XE3DTextureComponent(){};
public:
	enum eTexcoordOrigin{ TO_LEFT_TOP, TO_LEFT_BOTTOM};
	virtual void                 Release() override;
	virtual xbool                LoadAsset(const xchar* pTexPath);
	virtual void                 Render(XEViewport* pViewport) override;
	virtual void                 Deserialize(const XMLElement* pEleComponent) override;
	virtual XMLElement*          Serialize(XMLElement* pEleParent) override;
	X_FORCEINLINE const XString& GetAssetPath()const{ return m_szAssetPath; }
	xbool                        BuildVertices();
	void                         ResetAndBuildStanderData(xfloat32 fScale = 1.f, eTexcoordOrigin eTexcoordOriginType = TO_LEFT_TOP);
	xbool                        IsDataValid()const;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void                 GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif
public:
	XE_COMPONENT_CAST(XE3DTextureComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XE3DTextureComponent)
	static const XString         COMPONENT_TYPENAME;
public:
	XVECTOR3*                    m_pShapeVertsp;
	XCOLORBASE*                  m_pColors;
	XVECTOR2*                    m_pTexcoord;
	xint32                       m_iVertNum;

	xint32*                      m_pIndices;
	xint32                       m_iIndexNum;

	IXTexture*                   m_pTex;
	xbool                        m_bZEnable;
	XString                      m_szAssetPath;
protected:
	XVECTOR3*                    m_pVertices;
};

#endif // XE3DTextureComponent_H
