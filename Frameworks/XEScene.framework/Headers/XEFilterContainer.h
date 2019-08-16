/******************************************************************************

@File         XEFilterContainer.h

@Version       1.0

@Created      2019, 6, 22

@HISTORY:    Filter node container

******************************************************************************/
#ifndef _XE_FILTER_CONTAINER_H_
#define _XE_FILTER_CONTAINER_H_
#include "XEFilter.h"

class XEFilterContainer 
	: public XEUserNode
{
public:
	XEFilterContainer();
	virtual ~XEFilterContainer();
public:
	virtual void                                  Deserialize(const XMLElement* pEleRoot,XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                           Serialize(XMLElement* pEleParent)override;
	virtual void                                  Release() override;
	virtual Manager*                              GetNodeManager() override { return m_pNodeManager; }
	void                                          Initialize(const XString& strAssetPath);
	xbool                                         Save();
	xbool                                         SaveAs(const XString& strAssetPath);


	X_FORCEINLINE const XString&                  GetAssetPath(){ return m_strFileAssetPath; }
	X_FORCEINLINE void			                  UpdateFileAssetPath(const xchar* szAssetPath){ m_strFileAssetPath = szAssetPath; }
	X_FORCEINLINE void                            SetModified(xbool bSet){ m_bModify = bSet; }
	X_FORCEINLINE xbool                           IsModified()const{ return m_bModify; }

	XEFilter*                                     CreateFilter(XEUserNode* pFilterParentNode = NULL, const xchar* pFilterTl = NULL);//if pFilterTl is NULL, then create defualt XEFilter

public:
	XE_USER_NODE_CAST(XEFilterContainer)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
	static const XString  SUFFIX;
protected:
	Manager*                                      m_pNodeManager;
	XString                                       m_strFileAssetPath;//filter asset path
	xbool                                         m_bModify;
};





#endif // _XE_FILTER_CONTAINER_H_
