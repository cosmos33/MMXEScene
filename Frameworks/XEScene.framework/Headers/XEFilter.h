/******************************************************************************

@File         XEFilter.h

@Version       1.0

@Created      2019, 6, 22

@HISTORY:    Filter node

******************************************************************************/
#ifndef _XE_FILTER_H_
#define _XE_FILTER_H_
#include "XEUserNode.h"
#include "XEFilterUtility.h"
#include "XEMagicCoreFaceMaskUtility.h"
class IXMaterialInstance;
class XEFilter 
	: public XEUserNode
{
public:
	XEFilter();
	virtual ~XEFilter();
	friend class XEFilterInstance;
public:
	virtual void                                  Deserialize(const XMLElement* pEleRoot,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	virtual void                                  Release() override;
	X_FORCEINLINE void                            SetFilterNodeType(XEFilterUtility::FilterNodeType fnt){ m_eFilerNodeType = fnt; }
	X_FORCEINLINE XEFilterUtility::FilterNodeType GetFilterNodeType()const{ return m_eFilerNodeType; }
	X_FORCEINLINE void                            SetAssetPathShaderVS(const xchar* pAssetPath){ m_filterShaderPath.strAssetPathShaderVSFile = pAssetPath; }
	X_FORCEINLINE void                            SetAssetPathShaderPS(const xchar* pAssetPath){ m_filterShaderPath.strAssetPathShaderPSFile = pAssetPath; }
	X_FORCEINLINE void                            SetAssetPathMaterialDesc(const xchar* pAssetPath){ m_filterShaderPath.strAssetPathMaterialDesc = pAssetPath; }
	X_FORCEINLINE const XString&                  GetAssetPathShaderVS() const{ return m_filterShaderPath.strAssetPathShaderVSFile; }
	X_FORCEINLINE const XString&                  GetAssetPathShaderPS() const{ return m_filterShaderPath.strAssetPathShaderPSFile; }
	X_FORCEINLINE const XString&                  GetAssetPathMaterialDesc() const { return m_filterShaderPath.strAssetPathMaterialDesc; }
	X_FORCEINLINE void                            SetEnabled(xbool bEnabled){ m_bEnable = bEnabled; }
	X_FORCEINLINE xbool                           IsEnabled()const{ return m_bEnable; }
	X_FORCEINLINE void                            SetMaterialInsParamContent(const xchar* pContent){ if (pContent)m_strMaterialInsParamContent = pContent; }
	X_FORCEINLINE xint32                          GetFaceTrackerIndex()const { return m_nFaceTrackerIndex; }
	X_FORCEINLINE void                            SetFaceTrackerIndex(xint32 nIndex){ m_nFaceTrackerIndex = nIndex; }
	X_FORCEINLINE void							  SetFacePartType(XEMagicCoreFaceMaskUtility::EFacePartType eType){ m_eFacePartType = eType; }
	X_FORCEINLINE XEMagicCoreFaceMaskUtility::EFacePartType GetFacePartType(){ return m_eFacePartType; }
public:
	enum CodeOption{ CODE_ALL, CODE_MATERIAL, CODE_SHADER_VS, CODE_SHADER_PS };
	const xchar*                                  ReLoadCode(CodeOption eCodeOption = CODE_ALL);//reload code from file.
	const xchar*                                  GetCodeBuffer(CodeOption eCodeOption);//can't be CODE_ALL
	void                                          SetCodeBuffer(CodeOption eCodeOption, const xchar* pCodeBuffer);//can't be CODE_ALL
	const xchar*                                  GetAssetPathCodeFile(CodeOption eCodeOption) const;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	xbool                                         BuildEntranceCodeFile(CodeOption eCodeOption = CODE_ALL);
	xbool                                         SaveToCodeFile(CodeOption eCodeOption = CODE_ALL);
	X_FORCEINLINE CodeOption                      GetCurEditCodeOption()const{ return m_eCurEditCodeOption; }
	X_FORCEINLINE void                            SetCurEditCodeOption(CodeOption eCodeOption){ m_eCurEditCodeOption = eCodeOption; }
#endif
protected:
	void                                          ReleaseCodeBuffer(CodeOption eCodeOption = CODE_ALL);
	void										  RemoveAsset(const XString& strRelativePath);
public:
	XE_USER_NODE_CAST(XEFilter)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	XEFilterUtility::FilterNodeType               m_eFilerNodeType;
	XEFilterUtility::XEFilterShaderAsset          m_filterShaderPath;
	xbool                                         m_bEnable;//whether can take effect
	xbool                                         m_bCopyOriginAsBackgroundEnable;//whether can copy origin texture as background
	xchar*                                        m_szMaterialCodeBuffer;
	xchar*                                        m_szShaderVSCodeBuffer;
	xchar*                                        m_szShaderPSCodeBuffer;
	XString                                       m_strMaterialInsParamContent;
	xint32                                        m_nFaceTrackerIndex;
	XEMagicCoreFaceMaskUtility::EFacePartType     m_eFacePartType;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC	      
	CodeOption							          m_eCurEditCodeOption;
#endif
	
};

#endif // _XE_FILTER_H_
