/******************************************************************************

@File         XEPropertyObjectTriger.h

@Version       1.0

@Created      2018, 12, 20 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#pragma once
#include "XEPropertyObjectBase.h"


class XEActor;
class XEWorld;

class XEPropertyObjectTrigger
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectTrigger(){}
	~XEPropertyObjectTrigger(){}

	//For each event type, event data type may be different, sender/exector/delaytime can use same property type.
	enum
	{
		PROPERTY_OVERLAP_BEGIN_NODE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ADD_OVERLAP_BEGIN_EVENT,
		PROPERTY_OVERLAP_STAY_NODE,
		PROPERTY_ADD_OVERLAP_STAY_EVENT,
		PROPERTY_OVERLAP_END_NODE,
		PROPERTY_ADD_OVERLAP_END_EVENT,
		PROPERTY_OVERLAP_EVENT_ROOT_FIRST,
		PROPERTY_OVERLAP_EVENT_ROOT_LAST = PROPERTY_OVERLAP_EVENT_ROOT_FIRST + 100, //event root
		PROPERTY_OVERLAP_EVENT_DATA_FIRST,
 		PROPERTY_OVERLAP_EVENT_DATA_LAST = PROPERTY_OVERLAP_EVENT_DATA_FIRST + 500, //event data
		PROPERTY_OVERLAP_SENDER_DATA_FIRST,
		PROPERTY_OVERLAP_SENDER_DATA_LAST = PROPERTY_OVERLAP_SENDER_DATA_FIRST + 100, //sender
		PROPERTY_OVERLAP_EXECTOR_DATA_FIRST,
		PROPERTY_OVERLAP_EXECTOR_DATA_LAST = PROPERTY_OVERLAP_EXECTOR_DATA_FIRST + 100, //excutor
		PROPERTY_OVERLAP_DELAY_TIME_FIRST,
		PROPERTY_OVERLAP_DELAY_TIME_LAST = PROPERTY_OVERLAP_DELAY_TIME_FIRST + 100, //delay time
		PROPERTY_OVERLAP_TRIGGER_REPEAT_FIRST,
		PROPERTY_OVERLAP_TRIGGER_REPEAT_LAST = PROPERTY_OVERLAP_TRIGGER_REPEAT_FIRST + 100, //trigger repeat
		PROPERTY_OVERLAP_EVENT_DELETE_FIRST,
		PROPERTY_OVERLAP_EVENT_DELETE_LAST = PROPERTY_OVERLAP_EVENT_DELETE_FIRST + 100, //event delete
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	//virtual xbool	IsEqualPropertyValue(void* pSourceHandleObject, void* pDestHandleObject, XEProperty& Node) override;

protected:
	void	GetWorldAllActorNames(XEActor* pActor, XArray<XString>& aActorNameList);
};