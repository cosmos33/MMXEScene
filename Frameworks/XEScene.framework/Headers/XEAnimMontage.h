﻿/******************************************************************************

@File         XEAnimMontage.h

@Version       1.0

@Created      2017,12, 22

@HISTORY:

******************************************************************************/
#ifndef XE_ANIM_MONTAGE_H
#define XE_ANIM_MONTAGE_H
#include "XEAnimMonBase.h"
class XEAnimMonTrack;
class XESkeleton;
class XEAnimMonController;
class XEAnimMontage
	: public XEAnimMonBase
{
public:
	XEAnimMontage();
	virtual ~XEAnimMontage();
public:
	virtual void                                  Deserialize(const XMLElement* pEleMontage,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	virtual void                                  Release() override;
	virtual Manager*                              GetNodeManager() override{ return m_pNodeManager; }
public:
	void                                          Initialize(const XString& strAssetPath);
	xbool                                         Save();
	xbool                                         SaveAs(const XString& strAssetPath);
	XEAnimMonTrack*                               FindTrack(const XString& strTrackName);
	X_FORCEINLINE void                            SetLoopAtEnd(xbool bSet){ m_bLoopAtEnd = bSet; }
	X_FORCEINLINE void                            SetLoopAtEndStartTime(xint32 nTime){ m_nLoopStartTime = nTime; }
	X_FORCEINLINE xint32                          GetLoopAtEndStartTime(){ return m_nLoopStartTime; }
	X_FORCEINLINE const XString&                  GetSkinModelAssetPath()const{ return m_strSkinModelAssetPath; }
	X_FORCEINLINE const XString&                  GetAssetPath()const{ return m_strFileAssetPath; }
	X_FORCEINLINE xbool                           IsLoopAtEnd()const { return m_bLoopAtEnd; }
	X_FORCEINLINE void                            SetManaulStartTime(xint32 nTime){ m_nManualStartTime = nTime; }
	X_FORCEINLINE xint32                          GetManualStartTime() const{ return m_nManualStartTime; }
	X_FORCEINLINE void                            SetManualEndTime(xint32 nTime){ m_nManualEndTime = nTime; }
	X_FORCEINLINE xint32                          GetManualEndTime() const{ return m_nManualEndTime; }
	X_FORCEINLINE void                            SetManualTimeMode(xbool bManual){ m_bManualTimeMode = bManual; }
	X_FORCEINLINE xbool                           IsManualTimeMode() const{ return m_bManualTimeMode; }
	X_FORCEINLINE void                            SetModified(xbool bSet){ m_bModify = bSet; }
	X_FORCEINLINE xbool                           IsModified()const{ return m_bModify; }
	X_FORCEINLINE Manager*                        GetNodeManager() const{ return m_pNodeManager; }
	xint32                                        GetLoopAtEndStartTime(const XEAnimMonController* pAnimMonController)const;
public:
	XE_USER_NODE_CAST(XEAnimMontage)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
	static const XString  SUFFIX;
protected:
	XString                                       m_strSkinModelAssetPath;//for matching.
	XString                                       m_strFileAssetPath;//self file asset path.
	Manager*                                      m_pNodeManager;//node manager.
	xbool                                         m_bLoopAtEnd;
	xint32                                        m_nLoopStartTime;
	//for controller.			                  
	xint32                                        m_nManualStartTime;
	xint32                                        m_nManualEndTime;
	xbool                                         m_bManualTimeMode;
	//modified?
	xbool                                         m_bModify;
};

#endif // XE_ANIM_MONTAGE_H
