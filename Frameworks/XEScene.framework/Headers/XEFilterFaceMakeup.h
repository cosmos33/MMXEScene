/******************************************************************************

@File         XEFilterFaceMakeup.h

@Version       1.0

@Created      2019, 6, 22

@HISTORY:    Filter node

******************************************************************************/
#ifndef _XE_FACE_MAKEUP_FILTER_H_
#define _XE_FACE_MAKEUP_FILTER_H_
#include "XEFilter.h"

class XEFilterFaceMakeup 
	: public XEFilter
{
public:
	XEFilterFaceMakeup();
	virtual ~XEFilterFaceMakeup();
	friend class XEFilterFaceMakeupInstance;
public:
	virtual void                                  Deserialize(const XMLElement* pEleRoot,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	X_FORCEINLINE void                            SetBlendMode(const xchar* pBlendMode){ m_strBlendMode = pBlendMode; }
	X_FORCEINLINE const XString&                  GetBlendMode() const{ return m_strBlendMode; }
public:
	XE_USER_NODE_CAST(XEFilterFaceMakeup)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	XString             m_strBlendMode;
};

#endif // _XE_FACE_MAKEUP_FILTER_H_
