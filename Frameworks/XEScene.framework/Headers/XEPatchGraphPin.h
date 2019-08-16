/******************************************************************************

@File         XEPatchGraphPin.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:59:15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PATCH_GRAPH_PIN_H_
#define _XE_PATCH_GRAPH_PIN_H_

#include "XEPGraphPinType.h"
#include "XEPatchGraphNode.h"
#include "XArray.h"
#include "tinyxml2_XEngine.h"
X_EEH_FILE//don't export for lua

class XEPatchGraphNode;
class XEPGraphSchema;
class XEPatchGraphPin
{
public:
	XEPatchGraphPin();
	XEPatchGraphPin(XEPatchGraphNode* pInOwningNode, const xint64 nPinGuid);
	virtual ~XEPatchGraphPin();
public:
	virtual void					Serialize(tinyxml2_XEngine::XMLElement* pEleParent);
	void                            BreakAllPinLinks(xbool bNotifyNodes = xfalse);
	void                            BreakLinkTo(XEPatchGraphPin* pToPin);
	X_FORCEINLINE const XString&    GetName() const{return  m_strPinName;}
	X_FORCEINLINE XEPatchGraphNode* GetOwningNode() const{ return m_pOwningNode; }
	X_FORCEINLINE xbool				WasTrashed() const{ return xfalse; }
	X_FORCEINLINE xbool				IsPendingKill() const{ return xfalse; }
	const XEPGraphSchema*			GetSchema() const;
	void							MakeLinkTo(XEPatchGraphPin* pToPin);
	void						    MarkPendingKill();
	xbool							Modify(xbool bAlwaysMarkDirty = xtrue);
	void							SetOwningNode(XEPatchGraphNode* pNewOwningNode);
private:
	void							DestroyImpl(xbool bClearLinks);
protected:
	/**
	* If true, the pin may be hidden by user.
	*/
	xbool m_bAdvancedView;

	/**
	* If true, this connector is currently hidden.
	*/
	xbool m_bHidden;

	/**
	* If true, this connector is unconnectable, and present only to allow the editing
	* of the default text.
	*/
	xbool m_bNotConnectable;

	/**
	* True when InvalidateAndTrash was called. This pin is intended to be discarded
	* and destroyed.
	*/
	xbool m_bWasTrashed;

	/**
	* The pin that was split and generated this pin
	*/
	XEPatchGraphPin* m_pParentPin;

	/**
	* The pin's unique ID.
	*/
	xint64 m_nPinId;

	/**
	* Name of this pin.
	*/
	XString m_strPinName;

	/**
	* The type of information carried on this pin
	*/
	XEPGraphPinType m_pinType;

	/** Direction of flow of this pin (input or output) */
	EGraphPinDirection m_eDirection;

	/**
	* Pin that this pin uses for passing through reference connection
	*/
	XEPatchGraphPin* m_pReferencePassThroughConnection;

	/**
	* The node that owns this pin.
	*/
	XEPatchGraphNode* m_pOwningNode;

	/**
	* The pins created when a pin is split and hidden
	*/
	XArray<XEPatchGraphPin*> m_aSubPins;

	/**
	* Set of pins that we are linked to
	*/
	XArray<XEPatchGraphPin*> m_aLinkedTo;

};
#endif // !defined_XE_PATCH_GRAPH_PIN_H_
