/******************************************************************************

@File         XEPGraphPinType.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:54:38

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_P_GRAPH_PIN_TYPE_H_
#define _XE_P_GRAPH_PIN_TYPE_H_
#include "XTypes.h"
#include "XString.h"
#include "XClass.h"

X_EEH_FILE//don't export for lua

/**
 * Struct used to define the type of information carried on this pin
 */

enum EPinContainerType
{
	None,
	Array,
	Set,
	Map
};

enum EGraphPinDirection
{
	EGPD_Input,
	EGPD_Output,
	EGPD_MAX
};


struct XEPGraphPinType
{
public:
	EPinContainerType ContainerType;
	XString PinCategory;
	XString PinSubCategory;
	XEPGraphPinType(): ContainerType(EPinContainerType::None)
	{

	}
private:
	xbool IsArray() const
	{
		return ContainerType == EPinContainerType::Array;
	}
	xbool IsContainer() const
	{
		return ContainerType != EPinContainerType::None;
	}
	xbool IsMap() const
	{
		return ContainerType == EPinContainerType::Map;
	}
	xbool IsSet() const
	{
		return ContainerType == EPinContainerType::Set;
	}
};
#endif //_XE_P_GRAPH_PIN_TYPE_H_
