/******************************************************************************

@File         XEPropertyObjectSceneARAds.h

@Version       1.0

@Created      2018/05/30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTSCENEARADS_H
#define XEPROPERTYOBJECTSCENEARADS_H
#include "XEPropertyObjectBase.h"

class XEPrimitiveComponent;
class XEPropertyObjectSceneARAds
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectSceneARAds(){};
	~XEPropertyObjectSceneARAds(){};
	enum{
		PROPERTY_ARADS_PATH = XEPropertyTree::USER_PROPRETY_INDEX, 
		PROPERTY_ARADS_OPEN_EDITOR,
		PROPERTY_ARADS_PLAY_CONTROLL_ROOT,
		PROPERTY_ARADS_PLAY_CONTROLL_AUTO_PLAY,
		PROPERTY_ARADS_PLAY_CONTROLL_PREVIEW,
		PROPERTY_ARADS_PLAY_CONTROLL_LOOP,
	};
	enum XParamWidgetType
	{
		EWTFP_FLOAT
	};

	struct XShapeMaterialParamDesc
	{
		XShapeMaterialParamDesc(){}
		XShapeMaterialParamDesc(xint32 nCurIndex, XString strCurParamName, XParamWidgetType eCurType)
			:nIndex(nCurIndex), strParamName(strCurParamName),eType(eCurType){}
		xint32				nIndex;
		XString				strParamName;
		XParamWidgetType	eType;
	};


public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	static  xbool   Serialize(XEPrimitiveComponent* pHandleComponent);

private:
	XHashTable<xint32,XShapeMaterialParamDesc>		m_tbParamCache;
};

#endif // XEPROPERTYOBJECTSCENEARADS_H
