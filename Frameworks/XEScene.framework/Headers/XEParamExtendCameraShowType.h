/******************************************************************************

@File         XEParamExtendCameraShowType.h

@Version       1.0

@Created      2017, 9, 21

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/


#ifndef _XE_PARAMEXTENDCAMERASHOWTYPE_H_
#define _XE_PARAMEXTENDCAMERASHOWTYPE_H_

#include "XEActor.h"

class XEParamExtendCameraShowType
	:public IXEExtendParam
{
public:  
	enum{ PARAM_SHOWTYPE_FRONT, PARAM_SHOWTYPE_BACK };
	enum eCameraShowType{
		CST_Front = 1 << 0,
		CST_Back  = 1 << 1 
	};
public:
	         XEParamExtendCameraShowType();
	virtual ~XEParamExtendCameraShowType();

	XE_EXT_PARAM_TYPE_DEF(EXTEND_PARAM_NAME)
	virtual XMLElement* Serialize(XMLElement* pEleParent) override;
	virtual void        Deserialize(const XMLElement* pEleExtendParam) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual xbool       SetValueProperty(xint32 nMemberIndex, const XEValueProperty* pValueProperty, XEPropertyObject* pPropertyObject) override;
	virtual void        GetValueProperty(xint32 nMemberIndex, XEValueProperty* pValueProperty, XEPropertyObject* pPropertyObject) override;
	virtual xint32      GetParamMemberCount() override;
	virtual XString     GetParamMemberName(xint32 nIndex) override;
#endif
public:
	static XString EXTEND_PARAM_NAME;
	xint32 m_nShowTypeMask;
};


#endif //_XE_PARAMEXTENDCAMERASHOWTYPE_H_
