/******************************************************************************

@File         XEPropertyObjectClothConfig.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPropertyObjectClothConfig_H
#define _XEPropertyObjectClothConfig_H
#include "XEPropertyObjectBase.h"
#include "XEAnimatableModelComponent.h"
class XEPhysicsClothSection;
class XEPhysicsClothConfig;
class IXCloth;
class XEPropertyObjectClothConfig:public XEPropertyObjectBase
{
public:
	XEPropertyObjectClothConfig() :m_bAutoPlay(xfalse),m_bLoop(xfalse){};
	~XEPropertyObjectClothConfig(){};
	enum{ 
		PROPERTY_SESSION_MATERIAL_FIRST = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_SESSION_MATERIAL_LAST = 200,
		PROPERTY_SESSION_MESHS_START,
		PROPERTY_SESSION_MESHS_END = 300,
		PROPERTY_SESSION_ANIMATION_NODE,
		PROPERTY_SESSION_ANIMATION_ASSET,
		PROPERTY_SESSION_ANIMATION_SEQ_ACTIVE,
		PROPERTY_SESSION_ANIMATION_SEQ_LOOP,
		PROPERTY_SESSION_ANIMATION_SEQ_AUTO
	};

	enum EParamType
	{
		ECOLLISION_VISIBLE,
		ECOLLISION_CLOLOR,
		ECLOTH,
		ECLOTH_PATH,
		ECLOTH_PARAM_STRETCHCONFIG,
		ECLOTH_PARAM_TETHERCONFIG,
		ECLOTH_PARAM_FLOAT
	};

	struct XEMeshInfo
	{
		IXModelInstance* pInstance;
		EParamType		 eType;
		XString			 strParentParamName;
		XString			 strParamName;
		XString			 strClothPath;
		xint32			 nSkinIndex;

		XEMeshInfo(){}
		XEMeshInfo(IXModelInstance* pInst,
			EParamType	eCType,
			XString		strCParentParamName,
			XString		strCParamName,
			XString		strClothPathTemp,
			xint32		nSkinIndexTemp)
			:pInstance(pInst), eType(eCType), strParentParamName(strCParentParamName), 
			strParamName(strCParamName), strClothPath(strClothPathTemp), nSkinIndex(nSkinIndexTemp)
		{}
	};

public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	virtual void    ClearCache() override;
	XEMeshInfo*		GetCurNodeInfo(xint32 nIndex){ return m_htMeshInfo.Find(nIndex); }
private:
	bool			GetMeshNameBindCloth(IXCloth* pSourceCloth, XArray<XString>& aMeshNames, XEPhysicsClothConfig* pHandleNode);
	void			CreateClothNode(XEProperty* pParentNode, XEPropertyTree &PropTree,
									XEPhysicsClothConfig* pHandleNode,
									IXModelInstance* pInstance,
									xint32& nMaterialIndex,
									xint32&	nSKinIndex);
	void            CreateClothPropertyNode(XEProperty* pParentNode, XEPropertyTree &PropTree,
											XEPhysicsClothConfig* pHandleNode, 
											IXModelInstance* pInstance, 
											xint32& nMaterialIndex,xint32&	nSKinIndex,const XString& strClothPath);

	void			PlayAnimation(XEModelComponent* pComponent);

	IXCloth*		GetClothFromListByClothPath(const XArray<IXCloth*>& aCloths,const XString& strClothPath);

	xbool			SetClothFloatProperty(IXCloth* pCloth, XEMeshInfo* pMeshInfo, const XEValueProperty* pValueProperty);
	xbool			SetStretchConfigProperty(IXCloth* pCloth, XEMeshInfo* pMeshInfo, const XEValueProperty* pValueProperty);


private:
	void			InitAnimValues();
	xbool			GetSeqAnimationList(XEAnimatableModelComponent* pHandleComponent, XArray<XString>& list);
	xbool			HasAnimation(XEAnimatableModelComponent* pHandleComponent);
private:
	XHashTable<xint32, XEMeshInfo>			m_htMeshInfo;
	XHashTable<XString, IXCloth*>			m_htClothPathToCloth;
	xbool									m_bAutoPlay;
	xbool									m_bLoop;

};

//XE_PROPERTY_OBJ_FACTORY_AUTO_REGISTER(XEPropertyObjectClothConfig,XEPropertyObjectBase::MHT_USERNODE_PHISYCS);
#endif // _XEPropertyObjectClothConfigSTATICMODEL_H
