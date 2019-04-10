/******************************************************************************

@File         XEPropertyObjectActorMoveEventData.h

@Version       1.0

@Created      2018, 12, 28 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#pragma once
#include "XEPropertyObjectBase.h"

class XEPropertyObjectActorMoveEventData
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectActorMoveEventData(){}
	~XEPropertyObjectActorMoveEventData(){}

	enum{
		PROPERTY_ACTOR_MOVE_EVENT_DATA_LOCATION = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ACTOR_MOVE_EVENT_DATA_ROTATION,
		PROPERTY_ACTOR_MOVE_EVENT_DATA_SCALE,
	};

public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};


