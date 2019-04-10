/******************************************************************************

@File         XEPropertyObjectActorCommon.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTACTORCOMMON_H
#define XEPROPERTYOBJECTACTORCOMMON_H
#include "XEPropertyObjectBase.h"

class XEPropertyObjectActorCommon 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectActorCommon(){}
	~XEPropertyObjectActorCommon(){}
	enum
	{ 
		PROPERTY_DUMMYVISIBLE = XEPropertyTree::USER_PROPRETY_INDEX
		, PROPERTY_BOUNDINGBOXVISIBLE
		, PROPERTY_HIDDEN
		, PROPERTY_DRAW_AUXILIARY
		, PROPERTY_BOUNDINGBOXCOLOR
		, PROPERTY_ENABLEHIT
		, PROPERTY_PICKWITHPRIORITY
		, PROPERTY_PICKPRIORITY
		, PROPERTY_FILTERPATH 
		, PROPERTY_COLLISTION_CHANNEL
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	virtual xbool	IsEqualPropertyValue(void* pSourceHandleObject, void* pDestHandleObject, XEProperty& Node) override;
};

#endif // XEPROPERTYOBJECTACTORCOMMON_H   