/******************************************************************************

@File         XEPropertyObjectSkeletalActorProperty.h

@Version       1.0

@Created      2018, 1, 15

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTY_OBJECT_SKELETAL_PHYICS_ACTOR_PROPERTY_H
#define _XEPROPERTY_OBJECT_SKELETAL_PHYICS_ACTOR_PROPERTY_H
#include "XEPropertyObjectBase.h"

class XEModelComponent;
class XEAnimatableModelComponent;
class XEPropertyObjectSkeletalActorProperty
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectSkeletalActorProperty() :m_bAutoPlay(xfalse),m_bLoop(xfalse){};
	~XEPropertyObjectSkeletalActorProperty(){};
	enum
	{
		PROPERTY_PHYSICAL_ACTOR_RENDER = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_PHYSICAL_ACTOR_RENDER_SKELETA ,
		PROPERTY_PHYSICAL_ACTOR_RENDER_BODY_SHAPE,
		PROPERTY_PHYSICAL_ACTOR_RENDER_SKELETA_SIZE,
		PROPERTY_PHYSICAL_ACTOR_RENDER_SKELETA_CONE,
		PROPERTY_SESSION_ANIMATION_NODE,
		PROPERTY_SESSION_ANIMATION_ASSET,
		PROPERTY_SESSION_ANIMATION_SEQ_ACTIVE,
		PROPERTY_SESSION_ANIMATION_SEQ_LOOP,
		PROPERTY_SESSION_ANIMATION_SEQ_AUTO,
		PROPERTY_SIMULATE
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

private:
	void			InitAnimValues();
	xbool			GetSeqAnimationList(XEAnimatableModelComponent* pHandleComponent, XArray<XString>& list);
	xbool			HasAnimation(XEAnimatableModelComponent* pHandleComponent);
private:
	xbool           m_bAutoPlay;
	xbool           m_bLoop;
};

#endif // _XEPROPERTY_OBJECT_SKELETAL_PHYICS_ACTOR_PROPERTY_H
