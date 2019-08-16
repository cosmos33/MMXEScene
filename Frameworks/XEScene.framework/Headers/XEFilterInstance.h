/******************************************************************************

@File         XEFilterInstance.h

@Version       1.0

@Created      2019, 6, 22

@HISTORY:    Filter node instance

******************************************************************************/
#ifndef _XE_FILTER_INSTANCE_H_
#define _XE_FILTER_INSTANCE_H_
#include "XEUserNode.h"
#include "XEUtility.h"
#include "XMaterial.h"
#include "XEFilterUtility.h"

class XImageEffectNodeUser;
class XEFilter;
class XEFilterContainerInstance;

class XEFilterInstance 
	: public XEUserNodeInstance
{
public:
	enum FilterRuntimeMode{ FRM_FILTER_DONTCARE, FRM_FILTER_USER, FRM_FILTER_INTERNAL };
	XEFilterInstance(XEFilter* pNodeTl);
	virtual ~XEFilterInstance();
public:
	virtual void                                  Release() override;
	virtual void                                  Apply() override;//apply parameters from node-template.
	virtual void								  Tick(xfloat32 fInterval) override;
	virtual void								  Render(XEViewport* pViewport);
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
	XEFilter*                                     GetFilterTemplate() const;
	XEFilterContainerInstance*                    GetFilterContainerInstance();//filter instance may located in the filter container.(AS ROOT)
public:
	xbool                                         IsPreprocessNode();
	xbool                                         IsPostprocessNode();
	xbool                                         RebuildPrimitiveNode();//for rendering...
	xbool                                         BuildMaterailInstance();
	IXMaterialInstance*                           GetMaterialInstance();
	X_FORCEINLINE void                            AcceptPrimitiveFxUserNode(XImageEffectNodeUser* pFxNode){ m_pPrimitiveFxUserNode = pFxNode; }
	X_FORCEINLINE XImageEffectNodeUser*           GetPrimitiveFxUserNode(){ return m_pPrimitiveFxUserNode; }
	X_FORCEINLINE void                            SetFilterRuntimeMode(FilterRuntimeMode eRtMode){ m_eFilterRtMode = eRtMode; }
	X_FORCEINLINE FilterRuntimeMode               GetFilterRuntimeMode() const{ return m_eFilterRtMode; }
	virtual void								  SetEnabled(xbool bEnabled);//may be rebuild-material
	X_FORCEINLINE xbool                           IsEnabled()const{ return m_bEnable; }
	X_FORCEINLINE xbool							  IsEnableDelete(){ return m_bEnableDelete; }
	X_FORCEINLINE void							  SetEnableDelete(xbool bDelete){ m_bEnableDelete = bDelete; }
	virtual xbool                                 IsValidForRender();

public:
	//advanced options. -primitive image usernode
	virtual void                                  SetVertexDesc(IXVertexDesc* pVertexDesc);
	virtual void                                  SetVertexBuffer(IXVertexBuffer* pVertexBuffer);
	virtual void                                  SetIndexBuffer(IXIndexBuffer* pIndexBuffer);
	const IXVertexDesc*                           GetVertexDesc() const;
	const IXVertexBuffer*                         GetVertexBuffer() const;
	const IXIndexBuffer*                          GetIndexBuffer() const;
	void										  SetCopyOriginAsBackgroundEnabled(xbool bEnabled);
	xbool										  IsCopyOriginAsBackgroundEnabled()const;
public:
	//convenient for lua side.
	xbool                                         SetVertexFromVariantVertex(XEFilterUtility::XEVaraintVertex* pVariantVertex);
public:
	//face-related.
	xbool                                         ApplyVBOFromSetting();
	xbool                                         IsFaceDetect();
public:
	XE_USER_NODE_CAST(XEFilterInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	IXMaterialInstance*                           m_pMatIns;
	XImageEffectNodeUser*                         m_pPrimitiveFxUserNode;
	xbool                                         m_bEnable;//whether can take effect[run time] 
	FilterRuntimeMode							  m_eFilterRtMode;//indicated the use-case for this filter.[usually the editor side]
	xbool										  m_bEnableDelete;//whether it can be deleted by outside's call
	XArray<XString>                               m_aSystemMaterialParam;
	xfloat32                                      m_fElapseStartTime;
};



#endif // _XE_FILTER_INSTANCE_H_
