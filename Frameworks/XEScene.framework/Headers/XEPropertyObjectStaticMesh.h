/******************************************************************************

@File         XEPropertyObjectStaticMesh.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTY_OBJECT_STATICMESH_H
#define _XE_PROPERTY_OBJECT_STATICMESH_H
#include "XEPropertyObjectModelMaterial.h"

class XEPropertyObjectStaticMesh 
	:public XEPropertyObjectModelMaterial
{
public:
	XEPropertyObjectStaticMesh():m_bLoop(xfalse),m_bAutoPlay(xfalse),m_nPlayModeOptionIndex(0){}
	virtual ~XEPropertyObjectStaticMesh(){};
	enum{ 
		PROPERTY_ASSETPATH = XEPropertyObjectModelMaterial::PROPERTY_MATERIAL_LAST+1,
		PROPERTY_MOUNTER_PATH,
		PROPERTY_ANIMATION_NODE,
		PROPERTY_ANIMATION_AUTO_PLAY,
		PROPERTY_ANIMATION_LOOP,
		PROPERTY_ANIMATION_PLAY_MODE,
		PROPERTY_ANIMATION_ADD_ANIMATION,
		PROPERTY_ANIMATION_PREVIEW,
		PROPERTY_ARADS_NODE,
		PROPERTY_ARADS_ADD_ARADS,
		PROPERTY_ANIMATION_PATH_ROOT_FIRST,
		PROPERTY_ANIMATION_PATH_ROOT_LAST = PROPERTY_ANIMATION_PATH_ROOT_FIRST + 100,
		PROPERTY_ANIMATION_PATH_LIST_FIRST,
		PROPERTY_ANIMATION_PATH_LIST_LAST = PROPERTY_ANIMATION_PATH_LIST_FIRST + 100,
		PROPERTY_ANIMATION_MONTAGE_EDITOR_FIRST,
		PROPERTY_ANIMATION_MONTAGE_EDITOR_LAST = PROPERTY_ANIMATION_MONTAGE_EDITOR_FIRST + 100,
		PROPERTY_ANIMATION_BLEND_EDITOR_FIRST,
		PROPERTY_ANIMATION_BLEND_EDITOR_LAST = PROPERTY_ANIMATION_BLEND_EDITOR_FIRST + 100,
		PROPERTY_ARADS_PATH_ROOT_FIRST,
		PROPERTY_ARADS_PATH_ROOT_LAST = PROPERTY_ARADS_PATH_ROOT_FIRST + 100,
		PROPERTY_ARADS_PATH_LIST_FIRST,
		PROPERTY_ARADS_PATH_LIST_LAST = PROPERTY_ARADS_PATH_LIST_FIRST + 100,
		PROPERTY_ARADS_EDITOR_FIRST,
		PROPERTY_ARADS_EDITOR_LAST = PROPERTY_ARADS_EDITOR_FIRST + 100,
		PROPERTY_INDEX_LAST
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;
	virtual void    ClearCache() override;
	virtual void    AnimationPropertyExtend(XEPropertyTree &PropTree, XEProperty* pAnimNode, xint32 nAnimIndex){}
protected:
	void            MakePathFull(XString& simplePath);
	xbool           HasAnimation();
	void            InitAnimValues();
	xint32          GetUnUsedAniomationList(XArray<XString>& list);
	virtual xint32  GetAnimationList(XArray<XString>& list);
	virtual void    ClearAnimation();
	xint32          GetUnUsedARAdsList(XArray<XString>& list);
	virtual xint32  GetARAdsList(XArray<XString>& list);

protected:
	XString         m_strSelectedAnimation;
	xbool           m_bLoop;
	xbool           m_bAutoPlay;
	xint32          m_nPlayModeOptionIndex;
protected:
	void            ExclusiveMacroGroup(IXMaterialInstance* pMaterialIns,xint32 nCurMacroID,xint32 nCurMacroGroupID, XEMaterialDataCache& curDataCache);//will exclusive status in the cache.
};

#endif // _XE_PROPERTY_OBJECT_STATICMESH_H
