/******************************************************************************

@File         XEPatchNode.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:59:23

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PATCH_NODE_H_
#define _XE_PATCH_NODE_H_

#include "XEPatchGraphNode.h"
#include "XEPatchGraphPin.h"
#include "XBase3DTypes.h"
X_EEH_FILE//don't export for lua

/**
 * Abstract base class of all blueprint graph nodes.
 */

class XEPatchNode : public XEPatchGraphNode
{
public:
	XEPatchNode();
	virtual ~XEPatchNode();
protected:
	enum ERedirectType
	{
		/* The pins do not match */
		ERedirectType_None,
		/* The pins match by name or redirect and have the same type (or we're ok with the mismatched type) */
		ERedirectType_Name,
		/* The pins match via a redirect and the value needs to also be redirected */
		ERedirectType_Value
	};

	enum EBaseNodeRefreshPriority
	{
		Low_UsesDependentWildcard = 100,
		Low_ReceivesDelegateSignature = 150,
		Normal = 200,
	};
public:
	virtual void		     Serialize(tinyxml2_XEngine::XMLElement* pEleParent) override;
	virtual XCOLORBASE	     GetNodeTitleColor() const override;
	virtual void		     AutowireNewNode(XEPatchGraphPin* pFromPin);//maybe editor only?
	virtual XString		     GetDocumentationLink() const override;
	virtual void		     GetPinHoverText(const XEPatchGraphPin& Pin, XString& HoverTextOut) const override;
	virtual XEPatchGraphPin* GetPassThroughPin(const XEPatchGraphPin* FromPin) const;
	virtual XString			 GetPinMetaData(XString InPinName, XString InKey);
	/** Return whether to draw this node as an entry */
	virtual xbool			 DrawNodeAsEntry() const { return xfalse; }

	/** Return whether to draw this node as an entry */
	virtual xbool			 DrawNodeAsExit() const { return xfalse; }

	/** Return whether to draw this node as a small variable node */
	virtual xbool			 DrawNodeAsVariable() const { return xfalse; }

	/** Get the input execution pin */
	XEPatchGraphPin*		 GetExecPin() const;
	virtual xint32			 GetNodeRefreshPriority() const;
	virtual xbool			 DoesInputWildcardPinAcceptArray(const XEPatchGraphPin* pPin) const;

};
#endif // !defined_XE_PATCH_NODE_H_
