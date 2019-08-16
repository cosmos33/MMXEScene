/******************************************************************************

@File         XEMagicSequenceFrame.h

@Version       1.0

@Created      2019,5, 23

@HISTORY:

******************************************************************************/
#ifndef XE_MAGIC_SEQUENCE_FRAME_H
#define XE_MAGIC_SEQUENCE_FRAME_H
#include "XEUserNode.h"
#include "XEMagicCoreUtility.h"

class XEMagicSequenceFrame
	: public XEUserNode
{
public:
	XEMagicSequenceFrame();
	virtual ~XEMagicSequenceFrame();
public:
	virtual void                                  Deserialize(const XMLElement* pEleSeqFrame, XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	virtual void                                  Release() override;
	virtual Manager*                              GetNodeManager() override{ return m_pNodeManager; }
public:
	void                                          Initialize(const XString& strAssetPath);
	xbool                                         Save();
	xbool                                         SaveAs(const XString& strAssetPath);
	X_FORCEINLINE const XString&                  GetAssetPath()const{ return m_strFileAssetPath; }
	X_FORCEINLINE void							  SetAssetPath(const XString& strAssetPath){ m_strFileAssetPath = strAssetPath; }
	X_FORCEINLINE void                            SetModified(xbool bSet){ m_bModify = bSet; }
	X_FORCEINLINE xbool                           IsModified()const{ return m_bModify; }
	X_FORCEINLINE void							  SetReverse(xbool bReverse){ m_bIsReverse = bReverse; }
	X_FORCEINLINE xbool							  IsReverse(){ return m_bIsReverse; }
	X_FORCEINLINE void							  SetFPS(xint32 nFPS){ m_nFPS = nFPS; }
	X_FORCEINLINE xint32						  GetFPS(){ return m_nFPS; }
	X_FORCEINLINE xint32						  GetFirstTexWidth(){ return m_nFirstTexWidth; }
	X_FORCEINLINE void							  SetFirstTexWidth(xint32 nWidth){ m_nFirstTexWidth = nWidth; }
	X_FORCEINLINE xint32						  GetFirstTexHeight(){ return m_nFirstTexHeight; }
	X_FORCEINLINE void							  SetFirstTexHeight(xint32 nHeight){ m_nFirstTexHeight = nHeight; }

	X_FORCEINLINE void							  SetLoopMode(XEMagicCoreUtility::EFrameLoopMode eMode){ m_FrameLoopInfo.eMode = eMode; }
	X_FORCEINLINE XEMagicCoreUtility::EFrameLoopMode GetLoopMode(){ return m_FrameLoopInfo.eMode; }
	X_FORCEINLINE void							  SetLoopStartIndex(xint32 nStartIndex){ m_FrameLoopInfo.nStartIndex = nStartIndex; }
	X_FORCEINLINE xint32						  GetLoopStartIndex(){ return m_FrameLoopInfo.nStartIndex; }
	X_FORCEINLINE void							  SetLoopEndIndex(xint32 nEndIndex){ m_FrameLoopInfo.nEndIndex = nEndIndex; }
	X_FORCEINLINE xint32						  GetLoopEndIndex(){ return m_FrameLoopInfo.nEndIndex; }
	X_FORCEINLINE XEMagicCoreUtility::XESequenceFrameLoopInfo GetFrameLoopInfo(){ return m_FrameLoopInfo; }

	const XEMagicCoreUtility::XE2DSequenceFrameListInfo& Get2DSequenceFrameListInfo(){ return m_aSeqFrameList; }
	void										  Set2DSequenceFrameListInfo(const XEMagicCoreUtility::XE2DSequenceFrameListInfo& aFrameListInfo);
	void										  RemoveTexture(xint32 nIndex);
	void										  SetColForTexture(xint32 nTextureIndex, xint32 nCol);
	void										  SetRowForTexture(xint32 nTextureIndex, xint32 nRow);
	void										  RemoveAllTextures();
	xbool										  IsFinishLoadingTexture();
private:
	void										  CalculateFrameCount();
public:
	XE_USER_NODE_CAST(XEMagicSequenceFrame)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
	static const XString  SUFFIX;
protected:
	XString                                       m_strFileAssetPath;//self file asset path.
	Manager*                                      m_pNodeManager;//node manager.
	XEMagicCoreUtility::XE2DSequenceFrameListInfo m_aSeqFrameList;
	xbool                                         m_bModify;
	//for controller
	xbool										  m_bIsReverse;
	xint32										  m_nFrameCount;
	xint32										  m_nFPS;
	xint32										  m_nFirstTexWidth;
	xint32										  m_nFirstTexHeight;
	XEMagicCoreUtility::XESequenceFrameLoopInfo   m_FrameLoopInfo;
};

#endif // XE_MAGIC_SEQUENCE_FRAME_H
