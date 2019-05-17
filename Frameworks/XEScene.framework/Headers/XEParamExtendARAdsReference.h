/******************************************************************************

@File         XEParamExtendARAdsReference.h

@Version       1.0

@Created      2018/8/21

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/


#ifndef _XE_PARAMEXTENDARADSREFERENCE_H_
#define _XE_PARAMEXTENDARADSREFERENCE_H_

#include "XEActor.h"

class XEParamExtendARAdsReference
	:public IXEExtendParam
{
public:  
	enum{ PARAM_IS_ANCHOR, PARAM_REFERENCE_TARGET, PARAM_REFERENCE_TYPE, PARAM_LAYOUTTYPE };	
	
	enum eReferenceType{
		AD_REFERENCE_BACKGROUND = 0,
		AD_REFERENCE_VIDEO,
		AD_REFERENCE_AVATAR,
		AD_REFERENCE_LIKE,
		AD_REFERENCE_BAR,
		AD_REFERENCE_NUM
	};
	enum eLayoutType{
		AD_LAYOUTTYPE_CENTER = 0,
		AD_LAYOUTTYPE_TOP,
		AD_LAYOUTTYPE_LEFT,
		AD_LAYOUTTYPE_BOTTOM,
		AD_LAYOUTTYPE_RIGHT,
		AD_LAYOUTTYPE_NUM
	};
public:
	XEParamExtendARAdsReference();
	virtual ~XEParamExtendARAdsReference();

	XE_EXT_PARAM_TYPE_DEF(EXTEND_PARAM_NAME)
	virtual XMLElement* Serialize(XMLElement* pEleParent) override;
	virtual void        Deserialize(const XMLElement* pEleExtendParam) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual xbool       SetValueProperty(xint32 nMemberIndex, const XEValueProperty* pValueProperty, XEPropertyObject* pPropertyObject) override;
	virtual void        GetValueProperty(xint32 nMemberIndex, XEValueProperty* pValueProperty, XEPropertyObject* pPropertyObject) override;
	virtual xint32      GetParamMemberCount() override;
	virtual XString     GetParamMemberName(xint32 nIndex) override;
#endif
	xint32              GetAllReferenceTargetList(XArray<XString>& list);
	xint32              GetAllReferenceTypeNameList(XArray<XString>& list);
	xint32              GetReferenceTargetListByReferenceType(XArray<XString>& list, int refType);
	xint32              GetAllLayoutTypeNameList(XArray<XString>& list);
	static const std::string  GetReferenceTypeName(eReferenceType eType);
	static const std::string  GetReferenceTypeModel(eReferenceType eType);
	static const std::string  GetLayoutTypeName(eLayoutType eType);
	void                AttachToOtherByLayoutTypeChange();
	void                RefreshReferenceTarget();
public:
	static const XString EXTEND_PARAM_NAME;	
};


#endif //_XE_PARAMEXTENDARADSREFERENCE_H_
