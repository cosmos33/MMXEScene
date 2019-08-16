/******************************************************************************

@File         XEPGUserDeclaredFunctionMetadata.h

@Version       1.0

@Created      27-ÎåÔÂ-2019 11:53:42

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PG_USER_DECLEARD_FUNCTION_META_DATA_H_
#define _XE_PG_USER_DECLEARD_FUNCTION_META_DATA_H_
#include "XString.h"
#include "XBase3DTypes.h"
X_EEH_FILE//don't export for lua

/**
 * This structure describes metadata associated with a user declared function or
 * macro It will be turned into regular metadata during compilation
 */
struct XEPGUserDeclaredFunctionMetadata
{
public:
	XString	    Category;
	XString		CompactNodeTitle;
	xint8       HasLatentFunctions;
	XCOLORBASE	InstanceTitleColor;
	XString		Keywords;
	XString		ToolTip;
	XEPGUserDeclaredFunctionMetadata()
		: InstanceTitleColor(XCOLORBASE(1,1,1,1)), HasLatentFunctions(X_INDEX_NONE)
	{

	}

};
#endif // !defined_XE_PG_USER_DECLEARD_FUNCTION_META_DATA_H_
