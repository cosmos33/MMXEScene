/******************************************************************************

@File         XEImgFaceTrackerComponent.h

@Version       1.0

@Created      2019, 3,25

@Description 

@HISTORY:

******************************************************************************/
#ifndef XE_IMG_FACE_MASK_COMPONENT_H
#define XE_IMG_FACE_MASK_COMPONENT_H
#include "XEActorComponent.h"
#include "XTexture.h"
#include <mutex>
#include "XInternalResource.h"
/*
* 基于104/137个关键点的三角剖分
*/
class IXTexture;
class XEImgFaceTrackerComponent 
	: public XEActorComponent
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
	virtual xbool              MergeToWorldTransform(const XMATRIX4& mat) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual void               GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy, XEPropertyObjectSet& po) override;
#endif
public:
	//重新初始化顶点内存
	xbool					   RebuildVertexInfo(xint32 nFacePointNum);
	XArray<xfloat32>&		   GetOriginLandmarkCache(){ return m_aOriginLandmarkCache; }
	XArray<xfloat32>&		   GetShapeLandmarkCache(){ return m_aReShapeLandmarkCache; }
	XViewport*				   GetXViewport();
	void					   NormalizeVertex(XVECTOR2& vVertex, xint32 nWidth, xint32 nHeight);

public:
	//设置是否检测到人脸
	X_FORCEINLINE void		   SetDetectedFace(xbool bDetectedFace){ m_bDetectedFace = bDetectedFace; }
	X_FORCEINLINE xbool		   IsDetectedFace(){ return m_bDetectedFace; }
	X_FORCEINLINE const XArray<XVECTOR2>& GetTexcoords(){ return m_aTexcoord; }

	X_FORCEINLINE xint32	   GetVertexNum(){ return m_nFacePointNum; }
	X_FORCEINLINE xint32	   GetIndexNum(){ return m_iIndexNum; }
	X_FORCEINLINE xint32*      GetIndexList(){ return m_pIndices; }
	void					   GetIndexList(XArray<xint32>& aIndexList);
public:
	virtual IXVertexDesc*      ProvideVertexDesc(xbool bUpdate = xtrue);
	virtual IXVertexBuffer*    GetVB(xbool bUpdate = xtrue);
	virtual IXIndexBuffer*	   GetIB(xbool bUpdate = xtrue);
private:
	xbool                      IsEnableTick()const;
	//vUpdateUV可以是96点的数据，也可以104/137点的数据
	xbool					   UpdateTexcoords(const XArray<XVECTOR2>& vUpdateUV);
	//通知滤镜实例更新VB/IV/Vertex Desc
	void					   InformFilterInstanceVBIBDescChanged();
	void					   UpdateVertexInfo();
public:
	XE_COMPONENT_CAST(XEImgFaceTrackerComponent)
	XE_COMPONENT_TYPE_DEF(COMPONENT_TYPENAME)
	X_CLASS_DEF(XEImgFaceTrackerComponent)
	static const XString COMPONENT_TYPENAME;
	//可以挂载到当前Component的子Socket Component
	static void						RegisterChildSocketActorComponentType(const XString& strChildSocketActorComponentType);
	static XArray<XString>&			GetChildSocketActorComponentTypeList(){ return s_aChildSocketActorComponentType; }
protected:
	static XArray<XString>			s_aChildSocketActorComponentType;
public:
	struct FaceVertex
	{
		FaceVertex() : pos(0.0f), uv(0.0f), uvBack(0.0f){}
		XVECTOR3	pos;
		XVECTOR2	uv;//用于采集视频的UV 
		XVECTOR2    uvBack;
		void Set(xfloat32 x, xfloat32 y, xfloat32 z, xfloat32 u, xfloat32 v, xfloat32 u1, xfloat32 v1)
		{
			pos.Set(x, y, z);
			uv.Set(u, v);
			uvBack.Set(u1, v1);
		}
	};
private:
	XVertexDesc*					m_pVertexDesc;
	XTypeVertexBuffer<FaceVertex>*	m_pVB;
	XIndexBuffer16*					m_pIB;

	XArray<xfloat32>                m_aOriginLandmarkCache;//104 or 137(x1,x2,x3....y1,y2,y3)
	XArray<xfloat32>                m_aReShapeLandmarkCache;//104 or 137(x1,x2,x3....y1,y2,y3)

	XArray<XVECTOR2>				m_aTexcoord;//纹理坐标数组，用于人脸关键点采样
	xint32*							m_pIndices;//索引数组(三角剖分后的索引数据)
	xint32							m_iIndexNum;//索引数(三角剖分后索引数量)
	xint32							m_nFacePointNum;//顶点数量，也就是人脸关键点数量，104或137
	xbool							m_bDetectedFace;//是否检测到人脸
};

#endif // XE_IMG_FACE_MASK_COMPONENT_H
