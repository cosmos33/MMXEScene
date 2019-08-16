/******************************************************************************

@File         XEPatchGraphNode.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:59:07

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PATCH_GRAPH_NODE_H_
#define _XE_PATCH_GRAPH_NODE_H_
#include "XEPatchGraphPin.h"
#include "XBase3DTypes.h"
#include "tinyxml2_XEngine.h"
#include "XArray.h"
#include "XClass.h"
X_EEH_FILE//don't export for lua
class XEPatchGraph;
class XEPGraphSchema;
class XEPatchGraphPin;

class XEPatchGraphNode
{
public:
	XEPatchGraphNode();
	virtual ~XEPatchGraphNode();
	/**
	 * If true, this node can be renamed in the editor
	 */
	xbool m_bCanRenameNode;
	/**
	 * If true, this node can be resized and should be drawn with a resize handle
	 */
	xbool m_bCanResizeNode;
	xbool m_bCommentBubbleMakeVisible;
	/**
	 * Comment bubble pinned state
	 */
	xbool m_bCommentBubblePinned;
	/**
	 * Comment bubble visibility
	 */
	xbool m_bCommentBubbleVisible;
	/**
	 * Comment string that is drawn on the node
	 */
	XString m_strNodeComment;
	/**
	 * snow flake id to uniquely identify this node, to facilitate diffing versions of this
	 * graph
	 */
	xint64 m_nNodeId;

public:
	virtual void			 Serialize(tinyxml2_XEngine::XMLElement* pEleParent);
	virtual XString          GetDocumentationExcerptName() const;
	virtual XString          GetDocumentationLink() const;
	virtual XString          GetKeywords() const;
	virtual XCOLORBASE	     GetNodeCommentColor() const;
	virtual XString          GetNodeTitle() const;
	virtual XCOLORBASE       GetNodeTitleColor() const;
	virtual XEPatchGraphPin* GetPassThroughPin(const XEPatchGraphPin* FromPin) const;
	virtual void             DestroyNode();
	virtual void			 RemovePinAt(const xint32 PinIndex, const EGraphPinDirection PinDirection);
	virtual void			 ResizeNode(const XVECTOR2& NewSize);
	virtual XString          GetPinDisplayName(const XEPatchGraphPin* Pin) const;
	virtual void             GetPinHoverText(const XEPatchGraphPin& Pin, XString& HoverTextOut) const;
	virtual XString			 GetPinMetaData(XString InPinName, XString InKey);
	virtual XString          GetPinNameOverride(const XEPatchGraphPin& Pin) const;
	virtual XString			 GetTooltip() const;
	void		             BreakAllNodeLinks();
	static void              DestroyPin(XEPatchGraphPin* pPin);
	void		             DisableNode();
	void		             EnableNode();
	XEPatchGraph*            GetGraph() const;
	XEPatchGraphPin*         GetPinAt(xint32 Index) const;
	xint32                   GetPinIndex(XEPatchGraphPin* pPin) const;
	const XEPGraphSchema*    GetSchema() const;
	xbool					 IsNodeEnabled() const;
	xbool					 RemovePin(XEPatchGraphPin* pPin);
	XEPatchGraphPin*		 FindPin(const XString& PinName, const EGraphPinDirection Direction) const;
	XEPatchGraphPin*         FindPinById(const xint64 PinId) const;
	void					 SnapToGrid(xfloat32 GridSnapSize);
private:
	/**
	 * Height of node in the editor; only used when the node can be resized
	 */
	xint32 m_nNodeHeight;
	/**
	* Width of node in the editor; only used when the node can be resized
	*/
	xint32 m_nNodeWidth;
	/**
	 * X position of node in the editor
	 */
	xint32 m_nNodePosX;
	/**
	 * Y position of node in the editor
	 */
	xint32 m_nNodePosY;
	/**
	 * When reconstructing a node should the orphaned pins be retained and transfered
	 * to the new pin list.
	 */
	XArray<XEPatchGraphPin*> m_aPins;
};
#endif // _XE_PATCH_GRAPH_NODE_H_
