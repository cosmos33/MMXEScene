/******************************************************************************

@File         XEPropertyObjectSpawnParticleEventData.h

@Version       1.0

@Created      2018, 12, 29 add by yanglj

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#pragma once
#include "XEPropertyObjectBase.h"

class XEPropertyObjectSpawnParticleEventData
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectSpawnParticleEventData(){}
	~XEPropertyObjectSpawnParticleEventData(){}

	enum{
		PROPERTY_ACTOR_MOVE_EVENT_DATA_ASSET_PATH = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_ACTOR_MOVE_EVENT_DATA_LOCATION,
		PROPERTY_ACTOR_MOVE_EVENT_DATA_ROTATION,
		PROPERTY_ACTOR_MOVE_EVENT_DATA_SCALE,
	};

public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};


