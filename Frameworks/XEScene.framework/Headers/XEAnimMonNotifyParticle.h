﻿/******************************************************************************

@File         XEAnimMonNotifyParticle.h

@Version       1.0

@Created      2017,12, 22

@HISTORY:

******************************************************************************/
#ifndef XE_ANIM_MON_NOTIFY_PARTICLE_H
#define XE_ANIM_MON_NOTIFY_PARTICLE_H
#include "XEAnimMonNotify.h"
#include "XETransform.h"

class XEBindSocket;
class XEAnimMonNotifyParticle
	: public XEAnimMonNotify
{
	friend class                             XEAnimMonNotifyParticleIns;
public:
	                                         XEAnimMonNotifyParticle();
	virtual                                 ~XEAnimMonNotifyParticle();
public:
	virtual void                             Release() override;
	virtual xbool                            IsTheLast(xint32 nUpperboundTime) override;
	virtual void                             Deserialize(const XMLElement* pEleNotify, XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                      Serialize(XMLElement* pEleParent)override;
	virtual xbool                            Verify(AnimMonBaseList* pUnsuggestedList = NULL) override;
public:
	X_FORCEINLINE xbool                      IsSpawnMode(){ return m_bSpawnMode; }
	X_FORCEINLINE xbool                      IsDestroyImmediately(){ return m_bDestroyImmediately; }
	X_FORCEINLINE XETransform&               GetRelativeTransform(){ return m_relativeTransform; }
	X_FORCEINLINE XString&                   GetParticleAssetPath(){ return m_strParticleTemplateAssetPath; }
	X_FORCEINLINE void                       SetParticleAssetPath(const XString& szPath){ m_strParticleTemplateAssetPath = szPath; }
	X_FORCEINLINE void                       SetDestroyImmediately(xbool bSet){ m_bDestroyImmediately = bSet; }
	X_FORCEINLINE void                       SetSpawnMode(xbool bSpawnMode = xtrue){ m_bSpawnMode = bSpawnMode; }

	xbool                                    BindXESocket(const XString& socketName);//template operating...
	XEBindSocket*                            GetBindSocket();
	X_EES_LINE const XEBindSocket*           GetBindSocket() const;
	const XString&                           GetBindSocketName()const;

	void                                     UnbindXESocket();//template operating...

public:
	XE_USER_NODE_CAST(XEAnimMonNotifyParticle)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	xbool                                    m_bSpawnMode;
	xbool                                    m_bDestroyImmediately;
	XETransform                              m_relativeTransform;
	XString                                  m_strParticleTemplateAssetPath;
	XString                                  m_strBindSocketName;//will not be changed!
};

#endif // XE_ANIM_MON_NOTIFY_PARTICLE_H
