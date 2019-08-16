/******************************************************************************

@File         XEFilterLookup.h

@Version       1.0

@Created      2019, 6, 27

@HISTORY:    Filter node

******************************************************************************/
#ifndef _XE_FILTER_LOOK_UP_H_
#define _XE_FILTER_LOOK_UP_H_

#include "XEFilter.h"

class XEFilterLookup 
	: public XEFilter
{
public:
	XEFilterLookup();
	virtual ~XEFilterLookup();
	friend class XEFilterLookupInstance;
public:
	virtual void                                  Deserialize(const XMLElement* pEleRoot,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	virtual void                                  Release() override;
public:
	XE_USER_NODE_CAST(XEFilterLookup)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:

};

#endif // _XE_FILTER_LOOK_UP_H_
