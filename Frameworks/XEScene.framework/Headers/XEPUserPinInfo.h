/******************************************************************************

@File         XEPUserPinInfo.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:58:26

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_P_USER_PIN_INFO_H_
#define _XE_P_USER_PIN_INFO_H_
#include "XEPGraphPinType.h"
#include "XString.h"
#include "XEVariant.h"
X_EEH_FILE//don't export for lua

struct XEPUserPinInfo
{
public:
	XString PinDefaultValue;
	XString PinName;
	EGraphPinDirection DesiredPinDirection;
	XEPGraphPinType	   PinType;
	XEVariant          Data;
	XEPUserPinInfo():  DesiredPinDirection(EGPD_MAX)
	{

	}
};
#endif // !defined(_XE_P_USER_PIN_INFO_H_)
