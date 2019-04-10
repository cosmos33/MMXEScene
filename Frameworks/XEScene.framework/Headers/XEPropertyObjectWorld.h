/******************************************************************************

@File         XEPropertyObjectWorld.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTWORLD_H
#define XEPROPERTYOBJECTWORLD_H
#include "XEPropertyObjectBase.h"

typedef void (*OnChannelMetaNameChanged)(xint32 nChannelValue, const xchar* pChannelName);

class XEPropertyObjectWorld 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectWorld(){};
	~XEPropertyObjectWorld(){};
	enum{ 
		PROPERTY_PHYSICS_GRAVITY_OVERRIDE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_PHYSICS_GRAVITY_SET ,
		PROPERTY_WIND_SPEED,
		PROPERTY_WIND_DIR,
		PROPERTY_AA_METHOD,
		PROPERTY_DEBUG_DRAW_PHYSICS,
		PROPERTY_OIT,
		PROPERTY_OIT_LAYER_NUM,
		PROPERTY_SHADOW,
		PROPERTY_SHADOW_MAP_RESOLUTION,
		PROPERTY_SHADOW_DISTANCE,
		PROPERTY_SHADOW_CASCADE_NUM,
		PROPERTY_SHADOW_DEPTH_BIAS,
		PROPERTY_SHADOW_SOFTNESS,
		PROPERTY_BINDING_SCRIPT,
		PROPERTY_BLENDSHAPENORMAL_METHOD,
		PROPERTY_COLLISION_CHANNEL_SETTING_ROOT,
		PROPERTY_COLLISION_CHANNEL_SETTING_SYSTEM_ROOT,
		PROPERTY_COLLISION_CHANNEL_SETTING_SYSTEM_START,
		PROPERTY_COLLISION_CHANNEL_SETTING_SYSTEM_END = PROPERTY_COLLISION_CHANNEL_SETTING_SYSTEM_START + 100,
		PROPERTY_COLLISION_CHANNEL_SETTING_CUSTOM_ROOT,
		PROPERTY_COLLISION_CHANNEL_SETTING_CUSTOM_START,
		PROPERTY_COLLISION_CHANNEL_SETTING_CUSTOM_END = PROPERTY_COLLISION_CHANNEL_SETTING_CUSTOM_START + 100,
		PROPERTY_BLOOMROOT,
		PROPERTY_BLOOMENABLE,
		PROPERTY_BLOOMCOLORTHRESHOLD,
		PROPERTY_BLOOMSAMPLERSCALE,
		PROPERTY_FOGROOT,
		PROPERTY_FOGENABLE,
		PROPERTY_FOGSTART,
		PROPERTY_FOGEND,
		PROPERTY_FOGDENSITY,
		PROPERTY_FOGCOLORUPPER,
		PROPERTY_FOGCOLORLOWER,
		PROPERTY_FOGGRADIENTANGLEUPPER,
		PROPERTY_FOGGRADIENTANGLELOWER
		
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
};

#endif // XEPROPERTYOBJECTWORLD_H
