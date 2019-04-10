/******************************************************************************

@File         XEAnimMonNotify.h

@Version       1.0

@Created      2017,12, 22

@HISTORY:

******************************************************************************/
#ifndef XE_ANIM_MON_NOTIFY_H
#define XE_ANIM_MON_NOTIFY_H
#include "XEAnimMonBase.h"

class XEAnimMontage;
class XEAnimMonNotify 
	:public XEAnimMonBase
{
	friend class XEAnimMonNotifyInstance;
public:
	enum NotifyState
	{
		NS_UNKOWN,
		NS_LIVE_EXPLAINED,
		NS_SILENT_EXPLAINED
	};
	XEAnimMonNotify();
	virtual ~XEAnimMonNotify();
public:
	XE_USER_NODE_CAST(XEAnimMonNotify)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
public:
	void                              SetStartTime(xint32 nMicroSeconds);//in microsecond
	X_FORCEINLINE xint32              GetStartTime(){ return m_nStartTime; }
	virtual xbool                     IsTheLast(xint32 nUpperboundTime);
	xbool                             IsInParentRange();
	virtual void                      Deserialize(const XMLElement* pEleNotify, XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*               Serialize(XMLElement* pEleParent)override;

	X_FORCEINLINE void                SetSectionMode(xbool bSectionMode = xtrue){ m_bSectionMode = bSectionMode; }
	X_FORCEINLINE xbool               IsSectionMode()const{ return m_bSectionMode; }
	X_FORCEINLINE xint32              GetSectionEndTime()const{ return m_nSectionEndTime; }
	void                              SetSectionEndTime(xint32 nMicroSeconds);
protected:
	xint32                            m_nStartTime;//in microsecond.
	xbool                             m_bSectionMode;//whether in a section
	xint32                            m_nSectionEndTime;//in microseconds
};

#endif // XE_ANIM_MON_NOTIFY_H
