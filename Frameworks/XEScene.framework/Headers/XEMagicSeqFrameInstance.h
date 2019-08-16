/******************************************************************************

@File         XEMagicSeqFrameInstance.h

@Version       1.0

@Created      2019,5, 23

@HISTORY:     

******************************************************************************/
#ifndef XE_MAGIC_SEQ_FRAME_INSTANCE_H
#define XE_MAGIC_SEQ_FRAME_INSTANCE_H
#include "XEUserNode.h"

class XE2DSequenceFrameAnimController;
class XEMagicSequenceFrame;
class XEMagicSeqFrameInstance
	: public XEUserNodeInstance
{
public:
	XEMagicSeqFrameInstance(XEMagicSequenceFrame* pSeqFrameNode);
	virtual ~XEMagicSeqFrameInstance();
public:
	virtual void                                  Tick(xfloat32 fInterval) override;
	virtual void                                  Release() override;
	virtual void                                  Apply() override;
	virtual Manager*                              GetNodeManager() override{ return m_pNodeManager; }

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy) override;
#endif
public:
	XEMagicSequenceFrame*                         GetSeqFrameTemplate();
	X_EES_LINE X_FORCEINLINE const Manager*       GetNodeManager()const{ return m_pNodeManager; }
	XE2DSequenceFrameAnimController*			  GetController(){ return m_pController; }
	xbool										  GetDefaultTexSize(const XString& strPath, xint32& nTexWidth, xint32& nTexHeight);
public:
	XE_USER_NODE_CAST(XEMagicSeqFrameInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString                          NODE_TYPENAME;
protected:
	XETreeNode::Manager*                          m_pNodeManager;//node manager.
	XE2DSequenceFrameAnimController*			  m_pController;
};

#endif // XE_MAGIC_SEQ_FRAME_INSTANCE_H
