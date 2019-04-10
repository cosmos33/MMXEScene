/******************************************************************************

@File         XEPropertyObjectSceneSequence.h

@Version       1.0

@Created      2018, 03, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTSCENESEQUENCE_H
#define XEPROPERTYOBJECTSCENESEQUENCE_H
#include "XEPropertyObjectBase.h"

class XEPrimitiveComponent;
class XEPropertyObjectSceneSequence
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectSceneSequence(){};
	~XEPropertyObjectSceneSequence(){};
	enum{
		PROPERTY_SEQUENCE_PATH = XEPropertyTree::USER_PROPRETY_INDEX, 
		PROPERTY_SEQUENCE_OPEN_EDITOR,
		PROPERTY_SEQUENCE_PLAY_CONTROLL_ROOT,
		PROPERTY_SEQUENCE_PLAY_CONTROLL_AUTO_PLAY,
		PROPERTY_SEQUENCE_PLAY_CONTROLL_PREVIEW,
		PROPERTY_SEQUENCE_PLAY_CONTROLL_LOOP,
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

#endif // XEPropertyObjectSceneSequence_H
