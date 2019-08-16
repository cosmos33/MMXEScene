/******************************************************************************

@File         XEPGraphSchema.h

@Version       1.0

@Created      28-ÎåÔÂ-2019 11:11:49

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_P_GRAPH_SCHEMA_H_
#define _XE_P_GRAPH_SCHEMA_H_
#include "XEPatchGraphNode.h"
#include "XEPatchGraphPin.h"
X_EEH_FILE//don't export for lua

enum ECanCreateConnectionResponse
{
	/** Make the connection; there are no issues (message string is displayed if not empty). */
	CONNECT_RESPONSE_MAKE,

	/** Cannot make this connection; display the message string as an error. */
	CONNECT_RESPONSE_DISALLOW,

	/** Break all existing connections on A and make the new connection (it's exclusive); display the message string as a warning/notice. */
	CONNECT_RESPONSE_BREAK_OTHERS_A,

	/** Break all existing connections on B and make the new connection (it's exclusive); display the message string as a warning/notice. */
	CONNECT_RESPONSE_BREAK_OTHERS_B,

	/** Break all existing connections on A and B, and make the new connection (it's exclusive); display the message string as a warning/notice. */
	CONNECT_RESPONSE_BREAK_OTHERS_AB,

	/** Make the connection via an intermediate cast node, or some other conversion node. */
	CONNECT_RESPONSE_MAKE_WITH_CONVERSION_NODE,

	CONNECT_RESPONSE_MAX,
};

struct XEPinConnectionResponse
{
public:
	XEPinConnectionResponse()
		: Response(CONNECT_RESPONSE_MAKE)
		, bIsFatal(xfalse)
	{
	}

	XEPinConnectionResponse(const ECanCreateConnectionResponse InResponse, XString InMessage)
		: Message(InMessage)
		, Response(InResponse)
		, bIsFatal(false)
	{
	}

	friend bool operator==(const XEPinConnectionResponse& A, const XEPinConnectionResponse& B)
	{
		return (A.Message == B.Message) && (A.Response == B.Response) && (A.bIsFatal == B.bIsFatal);
	}

	/** If a connection can be made without breaking existing connections */
	bool CanSafeConnect() const
	{
		return (Response == CONNECT_RESPONSE_MAKE);
	}

	bool IsFatal() const
	{
		return (Response == CONNECT_RESPONSE_DISALLOW) && bIsFatal;
	}

	void SetFatal()
	{
		Response = CONNECT_RESPONSE_DISALLOW;
		bIsFatal = true;
	}
public:
	XString						 Message;
	ECanCreateConnectionResponse Response;
private:
	xbool						 bIsFatal;
};


class XEPGraphSchema
{
public:
	XEPGraphSchema();
	virtual ~XEPGraphSchema();

private:
	virtual void            BreakNodeLinks(XEPatchGraphNode& TargetNode) const;
	virtual void            BreakPinLinks(XEPatchGraphPin& TargetPin, xbool bSendsNodeNotifcation) const;
	virtual void            BreakSinglePinLink(XEPatchGraphPin* pSourcePin, XEPatchGraphPin* pTargetPin);
	XEPinConnectionResponse MovePinLinks(XEPatchGraphPin& MoveFromPin, XEPatchGraphPin& MoveToPin, xbool bIsIntermediateMove) const;
};
#endif // !defined(_XE_P_GRAPH_SCHEMA_H_)
