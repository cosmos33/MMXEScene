/******************************************************************************

@File         XEImgFaceTrackerComponent.h

@Version       1.0

@Created      2019, 3,25

@Description  人脸美妆,必须附加到XEFaceTrackerActor

@HISTORY:

******************************************************************************/
#ifndef XE_IMG_FACE_MASK_COMPONENT_H
#define XE_IMG_FACE_MASK_COMPONENT_H
#include "XEActorComponent.h"
#include "XTexture.h"
#include "XETexCustomPrimitive.h"
#include <mutex>
/*
* 基于104个关键点的三角剖分
*/

class IXTexture;
class XEImgFaceTrackerComponent : public XEActorComponent, public XETexCustomPrimitive
{
public:
	XEImgFaceTrackerComponent();
	~XEImgFaceTrackerComponent();
public:
	virtual void			   Initialize(XEActor* pWorld) override;
	virtual void               Empty() override;
	virtual void			   Tick(xfloat32 fDel, xbool bForceTick = xtrue) override;
	virtual void               Render(XEViewport* pViewport) override;
	virtual XMLElement*		   Serialize(XMLElement* pEleParent) override;
	virtual void			   Deserialize(const XMLElement* pEleComponent) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void               GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif
public:
	//load texture
	xbool					   LoadAsset(const xchar* pRelativeTexPath);
	//remove texture
	void					   ClearAsset();
	//load uv xml
	xbool					   LoadUVAsset(const xchar* pRelativeUVPath);
	//remove uv xml
	void					   ClearUVAsset();
	//save to uv cml
	xbool					   SaveUVToXml(const xchar* pFullPath);
	//vUpdateUV可以是96点的数据，也可以104点的数据，目前只支持这两种数据
	xbool					   UpdateTexcoords(const XArray<XVECTOR2>& vUpdateUV);
	//将96点的UV转为104点
	xbool					   ConvertLandmarkUV96To104(const XArray<XVECTOR2>& vUpdateUV96, XArray<XVECTOR2>& vUpdateUV104);
	//根据人脸关键点更新顶点
	void					   UpdateVerticesFromFacePoints(const XArray<xfloat32>& aLandmarks);
public:
	//设置是否检测到人脸
	X_FORCEINLINE void		   SetDetectedFace(xbool bDetectedFace){ m_bDetectedFace = bDetectedFace; }
	X_FORCEINLINE xbool		   IsDetectedFace(){ return m_bDetectedFace; }
	X_FORCEINLINE const XString& GetAssetPath(){ return m_strTexturePath; }
	X_FORCEINLINE const XString& GetUVAssetPath(){ return m_strUVAssetPath; }
	X_FORCEINLINE const XArray<XVECTOR2>& GetTexcoords(){ return m_aTexcoord; }

	//是否显示人脸特效
	X_FORCEINLINE void		   SetShowFaceEffect(xbool bShow){ m_bShowFaceEffect = bShow; }
	X_FORCEINLINE xbool		   IsShowFaceEffect(){ return m_bShowFaceEffect; }
	X_FORCEINLINE xint32	   GetVertexNum(){ return m_nFacePointNum; }
	X_FORCEINLINE void		   SetModifyUV(xbool bModify){ m_bModifyUV = bModify; }
protected:
	virtual IXTexture2D*       ProvideTexture2D();
	virtual XMATRIX4           ProvideWVPMatrix();
	virtual xint32             ProvideRenderPrimitiveNum();//usually is the triangle num.
	virtual IXVertexDesc*      ProvideVertexDesc();
	virtual IXVertexBuffer*    GetVB();
	virtual IXIndexBuffer*	   GetIB();
private:
	//是否渲染primitive
	xbool                      IsRenderGeometry()const;
	XViewport*				   GetXViewport();
public:
	XE_COMPONENT_CAST(XEImgFaceTrackerComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEImgFaceTrackerComponent)
	static const XString COMPONENT_TYPENAME;
private:
	XVertexDesc*					m_pVertexDesc;
	XTypeVertexBuffer<Vertex>*		m_pVB;
	XIndexBuffer16*					m_pIB;
	IXTexture2D*					m_pMaskTex;//mask纹理
	XVECTOR3*						m_pVertices;//顶点坐标数组(与人脸关键点相关)
	XArray<XVECTOR2>				m_aTexcoord;//纹理坐标数组(可编辑)
	xint32*							m_pIndices;//索引数组(三角剖分后的索引数据)
	xint32							m_iIndexNum;//索引数(三角剖分后索引数量)
	xint32							m_nFacePointNum;//顶点数量，也就是人脸关键点数量，必须是104
	xbool							m_bDetectedFace;//是否检测到人脸
	xbool							m_bShowFaceEffect;//是否显示人脸特效
	XString							m_strTexturePath;//mask texture path	
	XString							m_strUVAssetPath;//uv xml path
	xbool							m_bModifyUV;
};

#endif // XE_IMG_FACE_MASK_COMPONENT_H
