/******************************************************************************

@File         XEUIAnimation.h

@Version       1.0

@Created      2019,5, 22

@HISTORY:

******************************************************************************/
#ifndef XE_ANIMATION_H
#define XE_ANIMATION_H
#include "XEUIAnimBase.h"
class XEUIAnimBinding;
class XETrackBase;

class XEUIAnimation : public XEUIAnimBase
{
public:
	XEUIAnimation();
	virtual ~XEUIAnimation();
public:
	class NodeManager :public XETreeNode::Manager{};
public:
	virtual void                       Deserialize(const XMLElement* pEleSequencer, XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                Serialize(XMLElement* pEleParent)override;
	virtual void                       Release() override;
	virtual Manager*                   GetNodeManager() override { return m_pNodeManager; }
	void                               Initialize(const XString& strAssetPath);
	xbool                              Save();
	xbool                              SaveAs(const XString& strAssetPath);
	XEUIAnimBinding*                   GetBindingForUINode(const xchar* pUINodeName);
	XEUIAnimBinding*                   CreateBinding(const XString& szBindingType);
public:
	X_FORCEINLINE const XString&       GetAssetPath(){ return m_strFileAssetPath; }
	X_FORCEINLINE void                 SetManaulStartTime(xint32 nTime){ m_nManualStartTime = nTime; }
	X_FORCEINLINE xint32               GetManualStartTime() const{ return m_nManualStartTime; }
	X_FORCEINLINE void                 SetManualEndTime(xint32 nTime){ m_nManualEndTime = nTime; }
	X_FORCEINLINE xint32               GetManualEndTime() const{ return m_nManualEndTime; }
	X_FORCEINLINE void                 SetManualTimeMode(xbool bManual){ m_bManualTimeMode = bManual; }
	X_FORCEINLINE xbool                IsManualTimeMode() const{ return m_bManualTimeMode; }
	X_FORCEINLINE void                 SetModified(xbool bSet){ m_bModify = bSet; }
	X_FORCEINLINE xbool                IsModified()const{ return m_bModify; }

	
	XETrackBase*                       CreateTrack(const XString& szTrackType);

public:
		XE_USER_NODE_CAST(XEUIAnimation)
		XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
		static const XString  NODE_TYPENAME;
		static const XString  SUFFIX;
private:
	Manager*                           m_pNodeManager;//node manager.
	XString                            m_strFileAssetPath;//self file asset path.
	//for controller.			       
	xint32                             m_nManualStartTime;
	xint32                             m_nManualEndTime;
	xbool                              m_bManualTimeMode;
	//modified?
	xbool                              m_bModify;
};


#endif