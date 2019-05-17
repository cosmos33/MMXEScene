/******************************************************************************

@File         XEModelMeshLineVolorInstance.h

@Version       1.0

@Created      2019, 1, 14 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef XE_MODEL_MESH_LINE_COLOR_INSTANCE_H
#define XE_MODEL_MESH_LINE_COLOR_INSTANCE_H
#include "XEUserNode.h"

class XEActor;
class XEModelMeshLineColorInstance
	:public XEUserNodeInstance
{
public:
	XEModelMeshLineColorInstance();
	virtual ~XEModelMeshLineColorInstance();

	void										SetAttachActor(XEActor* pActor){ m_pActor = pActor; }
	XEActor*									GetAttachActor(){ return m_pActor; }

	void										SetBoundingBoxColor(XCOLOR clVal);
	XCOLOR										GetBoundingBoxColor();
	void										SetNormalLineColor(XCOLOR clVal){ m_clNormalLineColor = clVal; }
	XCOLOR										GetNormalLineColor(){ return m_clNormalLineColor; }
	void										SetTangentLineColor(XCOLOR clVal){ m_clTangentLineColor = clVal; }
	XCOLOR										GetTangentLineColor(){ return m_clTangentLineColor; }
	void										SetBiNormalLineColor(XCOLOR clVal){ m_clBiNormalLineColor = clVal; }
	XCOLOR										GetBiNormalLineColor(){ return m_clBiNormalLineColor; }
	void										SetVertexNodeColor(XCOLOR clVal){ m_clVertexNodeColor = clVal; }
	XCOLOR										GetVertexNodeColor(){ return m_clVertexNodeColor; }
	void										SetWireFrameBeginColor(XCOLOR clVal){ m_clWireFrameBeginColor = clVal; }
	XCOLOR										GetWireFrameBeginColor(){ return m_clWireFrameBeginColor; }

public:
	virtual void								Release() override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet					GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy) override;
#endif

public:
	XE_USER_NODE_CAST(XEModelMeshLineColorInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
	static const XCOLOR m_defaultBoundingBoxColor;
private:
	XEActor*			m_pActor;
	XCOLOR              m_clNormalLineColor;
	XCOLOR              m_clTangentLineColor;
	XCOLOR              m_clBiNormalLineColor;
	XCOLOR              m_clVertexNodeColor;
	XCOLOR              m_clWireFrameBeginColor;
};
#endif //XE_MODEL_MESH_LINE_COLOR_INSTANCE_H