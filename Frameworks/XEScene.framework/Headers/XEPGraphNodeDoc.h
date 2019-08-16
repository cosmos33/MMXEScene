/******************************************************************************

@File         XEPGraphNodeDoc.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:54:30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_PATCH_GRAPH_NODE_DOC_H_
#define _XE_PATCH_GRAPH_NODE_DOC_H_

#include "XEPatchGraphNode.h"
X_EEH_FILE//don't export for lua

class XEPGraphNodeDoc : public XEPatchGraphNode
{
public:
	XEPGraphNodeDoc();
	virtual ~XEPGraphNodeDoc();
	virtual XString    GetDocumentationExcerptName() const override;
	virtual XString    GetDocumentationLink() const override;
	virtual XString    GetNodeTitle() const override;
	virtual XCOLORBASE GetNodeTitleColor() const override;
	virtual XString    GetPinNameOverride(const XEPatchGraphPin& Pin) const override;
	virtual void	   ResizeNode(const XVECTOR2& NewSize);
private:
	XString m_strExcerpt;
	XString m_strLink;
};
#endif // !defined(_XE_PATCH_GRAPH_NODE_DOC_H_)
