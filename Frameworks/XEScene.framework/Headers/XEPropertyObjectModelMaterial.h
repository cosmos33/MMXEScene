/******************************************************************************

@File         XEPropertyObjectModelMaterial.h

@Version       1.0

@Created      2018, 5, 28

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_MODEL_MATERIAL_H
#define _XE_PROPERTY_OBJECT_MODEL_MATERIAL_H
#include "XEPropertyObjectBase.h"

class IXMaterialInstance;
class XEModelComponent;

class XEPropertyObjectModelMaterial 
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectModelMaterial() :m_bEnableMaterialFxCurveEdit(xfalse) {}
	virtual ~XEPropertyObjectModelMaterial(){};
	enum{
		PROPERTY_MATERIAL_FX_RELATED = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_MATERIAL_FIRST,
		PROPERTY_MATERIAL_LAST = PROPERTY_MATERIAL_FIRST + 5000
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	virtual void    ClearCache() override;
	void            SetMaterialFxEditEnable(xbool bEnable){ m_bEnableMaterialFxCurveEdit = bEnable; }
	static  xbool   Serialize(XEModelComponent* pHandleComponent);//save material.
private:
	void            DuplicateMaterialParam(IXMaterialInstance* pMaterialIns,xint32 nSkinID,xint32 nMeshID,xint32 nLodID);
public:
	struct XEMaterialKey
	{
		//xint32 nID;
		XString strParamName;
		XString strParamDesc;
		XString strSkinName;
		XString strMeshName;
		xint32 nSkinID;
		xint32 nMeshID;
		xint32 nLodID;
		xint32 nKeyType;
		enum{ MKT_UNKOWN, MKT_MATERIALINSFILE, MKT_SHADERMODEL, MKT_MARCRO, MKT_PARAM };
		XEMaterialKey() :nKeyType(MKT_UNKOWN),/*nID(0), */nSkinID(0), nMeshID(0), nLodID(0){}
	};
	struct XEMaterialDataCache
	{
		xint32 nSkinID;
		xint32 nMeshID;
		xint32 nLodID;
		xint32 nCurSel;
		XHashTable<XString, xbool>    mapMacroEnable;//id-macro
		XHashTable<XString, XString>  mapParamTexturePath;//id-texture
		XHashTable<XString, XCOLOR>   mapParamColor;//id-color
		XHashTable<XString, xfloat32> mapParamFloat;//id-float
		XHashTable<XString, XVECTOR2> mapParamVector2;//id-vector2
		XHashTable<XString, XVECTOR3> mapParamVector3;//id-vector3
		XHashTable<XString, XVECTOR4> mapParamVector4;//id-vector4
		XEMaterialDataCache() : nSkinID(0), nMeshID(0), nLodID(0), nCurSel(0){}
		XEMaterialDataCache(xint32 s, xint32 m, xint32 l) : nSkinID(s), nMeshID(m), nLodID(l), nCurSel(0){}
		xbool operator < (const XEMaterialDataCache& cmpCache) const
		{
			if (nSkinID == cmpCache.nSkinID && nMeshID == cmpCache.nMeshID && nLodID == cmpCache.nLodID)
				return 0;
			if (nSkinID < cmpCache.nSkinID)
				return -1;
			if (nMeshID < cmpCache.nMeshID)
				return -1;
			if (nLodID < cmpCache.nLodID)
				return -1;
			return 1;
		}
		xbool operator == (const XEMaterialDataCache& cmpCache) const
		{
			return nSkinID == cmpCache.nSkinID
				&& nMeshID == cmpCache.nMeshID
				&& nLodID == cmpCache.nLodID ? xtrue : xfalse;
		}
	};
protected:
	XHashTable<xint32, XEMaterialKey> m_mIndexKey;
	XArray<XEMaterialDataCache>       m_mMaterialDataCache;
	xbool                             m_bEnableMaterialFxCurveEdit;//xfalse by default.
protected:
	//warning! this is not a good idea.
	struct matInsSameCheck
	{
		IXMaterialInstance* pIns;
		XEMaterialKey       mk;
		xbool operator == (const matInsSameCheck& msc) const
		{
			return msc.pIns == pIns;
		}
	};
	XHashTable<XString, XArray<matInsSameCheck>> m_mSameMaterialIns;
protected:
	void            ExclusiveMacroGroup(IXMaterialInstance* pMaterialIns,const XString strCurMacroName,xint32 nCurMacroGroupID, XEMaterialDataCache& curDataCache);//will exclusive status in the cache.
};

#endif // _XE_PROPERTY_OBJECT_MODEL_MATERIAL_H
