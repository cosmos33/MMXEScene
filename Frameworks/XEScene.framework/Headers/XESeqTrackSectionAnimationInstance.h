/******************************************************************************

@File         XESeqTrackSectionAnimationInstance.h

@Version       1.0

@Created      2018,5, 3

@HISTORY:

******************************************************************************/
#ifndef _XE_TRACK_SECTION_ANIMATION_INSTANCE_H_
#define _XE_TRACK_SECTION_ANIMATION_INSTANCE_H_
#include "XESeqBase.h"
#include "XEAnimatableModelComponent.h"

class XEModelComponent;
class XESeqTrackSectionAnimation;
class XEAnimBlendLayer;
class XELayersAnimaPlay;
class XAnimationSequence;
class XEAnimTimeAreaBase;
class XESeqTrackSectionAnimationInstance 
	:public XESeqBaseInstance
{
public:
	XESeqTrackSectionAnimationInstance(XESeqTrackSectionAnimation* pNodeTl);
	virtual ~XESeqTrackSectionAnimationInstance();
public:
	virtual void                         SetTime(xint32 nMicrosecond) override;
	virtual void                         Apply() override;
	virtual void						 Release() override;
protected:
	void								 BuildAnimation(xbool bApply = xfalse);
	xbool								 IsCurAnimation();
	xbool								 IsCurMontage();
	void								 SetTimeMontage(XESeqTrackSectionAnimation* pNodeTl, xint32 nMicrosecond);
	void								 SetTimeSeq(XESeqTrackSectionAnimation* pNodeTl, xint32 nMicrosecond);
	xint32								 GetMontageAssetDuration();
	xint32								 GetAnimationLenth(const XString& strSeqAreaName); //sequence duration.

	void								 UpdateAreaTime(XEAnimTimeAreaBase* pArea, xint32 nDeltaTime);//update areas start time and end time at cur layer.
	xbool								 IsValidContainPlayTime(xfloat32 fCurTime);

	static XAnimationSequence*			 ManagerLoadAnimation(const XString& strName);
	xbool								 IsTimeInCross(xfloat32 fTime);
public:
	virtual xint32						 GetAnimationDuration(const XString& strSeqAreaName);
	xint32								 GetAnimationDurationWithScale(xint32 nBlendDataIndex, xint32 nMetaIndex);
	XEModelComponent*					 GetModelComponent();
	XESeqTrackSectionAnimation*			 GetSeqTrackSectionAnimationTemplate();
	xbool                                VerifyModelActor(XEActor* pActor);

	xbool								 AttachWeightCurveToLayer();
	xbool								 DetachWeightCurveToLayer();
	void								 SetCurAttachWeightVal(xint32 nMicrosecond, xbool bReset = xfalse);

	xint32								 GetLayerCurInterBlendType();
	void								 SetLayerInterBlendType(xint32 type);
	xint32								 GetLayerInterBlendTypeNames(XArray<XString>& arNameList);
	xint32								 GetLayerInterBlendTypeByDesc(const XString &strDesc);

	void								 AssignLayersAnimaPlayer(); //assign XELayersAnimaPlay.
	XELayersAnimaPlay*					 GetLayersAnimaPlayer();
	void								 RemoveLayer(const XString& strPath);
	void								 UpdateLayerActiveState(xbool bActive);

	xbool								 RemoveAnimation(const XString& strAreaName);//remove one area from cur layer.

	void								 GetCrossInfo(XArray<XVECTOR2>& arrCrossList);
public:
	static void							 SpiltAnimationToNewLayer(XESeqTrackSectionAnimationInstance* pDragIns, XESeqTrackSectionAnimationInstance* pDropIns); //a new layer.
	static xbool						 SpiltAnimationToOtherLayer(XESeqTrackSectionAnimationInstance* pDragIns, XESeqTrackSectionAnimationInstance* pDropIns);//a already layer.
	
	static xfloat32						 GetWeightFactor(xfloat32 fStart, xfloat32 fEnd, xfloat32 fCur, xint32 type);
	//static void							 GetDrawGrayAreas(XESeqTrackSectionAnimationInstance* pIns, XArray<XVECTOR2>& arrGrayBlend, XArray<XVECTOR2>& arrGrayMontage);

public:
	XE_USER_NODE_CAST(XESeqTrackSectionAnimationInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
protected:
	xint32								 m_nAnimLength;
};

#endif // _XE_TRACK_SECTION_ANIMATION_INSTANCE_H_
