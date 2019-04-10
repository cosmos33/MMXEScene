/******************************************************************************

@File         XESeqTrackSectionAnimation.h

@Version       1.0

@Created      2018,2, 27

@HISTORY:

******************************************************************************/
#ifndef XE_TRACK_SECTION_ANIMATION_H
#define XE_TRACK_SECTION_ANIMATION_H
#include "XETrackSection.h"
#include "XESeqSingleAnimation.h"

class XESeqTrackSectionAnimationInstance;
class XEAnimBlendLayer;
class XESeqBindingActor;
class XELayersAnimaPlay;



class XESeqTrackSectionAnimation 
	: public XETrackSection
	, public XESeqSingleAnimation
{
	friend class XESeqTrackSectionAnimationInstance;
public:
	XESeqTrackSectionAnimation();
	virtual ~XESeqTrackSectionAnimation();

public:

	struct MetaBlendData
	{
		MetaBlendData() : bValid(xtrue){}

		XString strAssetPath;
		XString strAssetAreaName; //area name
		MetaSegmentList metaDataList;
		xbool bValid;//when it is false, data can not be used.
	};
	typedef XArray<MetaBlendData>  MetaBlendDataList;

public:
	virtual void                         Deserialize(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL)override;
	virtual XMLElement*                  Serialize(XMLElement* pEleParent)override;
	virtual void						 Release() override;
	virtual void                         ReverseRecover();//do something BEFORE detach from parent.
	virtual void                         Recover();//do something AFTER attach to the parent.
public:
	virtual xbool						 AcceptAnimation(const XString& path, XESeqTrackSectionAnimationInstance* pIns);
	virtual xbool						 ReplaceAnimation(const XString& path, XESeqTrackSectionAnimationInstance* pIns);//replace one asset of the exist layer.
	virtual void						 UpdateCurActiveMetaData(xfloat32 fCurTime);
	virtual void						 UpdateCurActiveMetaData();
	virtual xbool						 ExpandSegmentEndTime(xint32 nMetaIndex, xint32 nDeltaTime);//treated as a whole.
	virtual xbool						 MoveSegment(xint32 nMetaIndex, xint32 nDeltaTime);
	virtual xbool                        SetOffsetStartTime(xint32 nMetaIndex, xint32 nOffsetTime);//will be applied to all-segments, to calculate the splitting positions.
	virtual xbool                        SetOffsetEndTime(xint32 nMetaIndex, xint32 nOffsetTime);//will be applied to all-segments, to calculate the splitting positions.
	virtual xbool                        SetSegmentPlayRate(xint32 nMetaIndex, xfloat32 fPlayRate);
	virtual xbool                        SetSegmentActive(xint32 nMetaIndex, xbool bActive);
	virtual xbool                        RemoveSegment(xint32 nMetaIndex);

	xbool                                CalculateSegmentAnimationSplitPos(xint32 nBlendDataIndex, xint32 nMetaIndex, XArray<xint32>& aTimePositions, XESeqTrackSectionAnimationInstance* pIns);
	xint32								 GetFirstSegmentEndtime(xint32 nBlendDataIndex, xint32 nMetaIndex, XESeqTrackSectionAnimationInstance* pIns);
	xint32                               ConvertToAnimationTime(xint32 nBlendDataIndex, xint32 nMetaIndex, xint32 nAtTime, XESeqTrackSectionAnimationInstance* pIns);
	xbool								 ClipSegmentStartTime(xint32 nBlendDataIndex, xint32 nMetaIndex, xint32 nDeltaTime, XESeqTrackSectionAnimationInstance* pIns);//treated as a whole.
	xint32                               GetSplitStartOffsetTime(xint32 nBlendDataIndex, xint32 nMetaIndex, xint32 nSplitTimePos, XESeqTrackSectionAnimationInstance* pIns);
	xbool                                SplitToSegments(xint32 nBlendDataIndex, xint32 nMetaIndex, xint32 nSplitTimePos, XESeqTrackSectionAnimationInstance* pIns);


	virtual void						 SetCurActiveIndex(xint32 nIndex){ m_nCurActiveIndex = nIndex; }
	virtual xint32						 GetCurActiveIndex(){ return m_nCurActiveIndex; }

	virtual void						 CreateSubWeightTrack(XETreeNode::Manager* pNodeMgr); //Weight track.
	virtual XETrackBase*				 GetTrackWeight(){ return m_pTrackWeight; }

	XEAnimBlendLayer*					 GetAnimBlendLayer();
	XESeqBindingActor*					 GetBindingActor();
	void								 UpdateLayerActiveState(xbool bActive);//update layer active state when delete or redo/undo operation in UI layer.

	void								 AddMetaSegmentData(XESeqTrackSectionAnimation* pAnim);
	void								 RemoveMetaSegmentData(const XString& strPath);
	void								 RemoveMetaSegmentData(xint32 nIndex);
	const MetaBlendDataList&			 GetMetaBlendDataList(){ return m_vMetaBlendData; }
	xint32								 GetMetaBlendDataListNum(){ return m_vMetaBlendData.Num(); }
	void								 ReleaseBlendDataList();
	xfloat32							 GetMinStartTime(); // the min of m_vMetaBlendData
	xfloat32							 GetMaxEndTime();// the max of m_vMetaBlendData
	void								 UpdateAreaStartEndTime(xfloat32 fMinStartTime);

	void								 SetAnimPlayer(XELayersAnimaPlay* pPlayer);
	XELayersAnimaPlay*					 GetAnimPlayer();

	void								 SetAllSeqLayerMinStartTime(xfloat32 fMin){ m_fMinStartTime = fMin; };
	xfloat32							 GetAllSeqLayerMinStartTime(){ return m_fMinStartTime; }

	xbool								 GetIsMontageTrack();

	xbool								 IsValidContainPlayTime(xfloat32 fCurTime);

	xbool								 IsReloadAnimation(){ return m_bReloadAnimation; }

	static void							 UpdateLayersStartEndTime(XESeqTrackSectionAnimation* pNodel);
protected:
	void								 SerializeMetaData(XMLElement* pEleNode, const MetaData& metaData);
	void								 DerializeMetaData(const XMLElement* pEleNode, MetaData& metaData);
	void								 DerializeVersion_1_0(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL);
	void								 DerializeVersion_2_0(const XMLElement* pEleParent, XETreeNode::Manager* pNodeMgr = NULL);

	xbool								 ApplyAnimation(const XString& path, XESeqTrackSectionAnimationInstance* pIns);

	void								 UpdateCurActiveIndex();
	virtual void						 UpdateCurMetaData();
	void								 AddBlendData(const MetaBlendData& data);
	
public:
	XE_USER_NODE_CAST(XESeqTrackSectionAnimation)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
	XString		          m_strLayerPathName; //layer name.
protected:				                 
	XETrackBase*						 m_pTrackWeight;

	MetaBlendDataList					 m_vMetaBlendData;
	xint32								 m_nCurActiveIndex; //cur active array index.
	XELayersAnimaPlay*					 m_pAnimPlayer;
	xfloat32							 m_fMinStartTime;//all seq layer.
	XString								 m_strTrackVersion;
	static xuint32                       m_nLayerAutoAssignedID;//compatible with old version
	xbool								 m_bReloadAnimation;
};

#endif // XE_TRACK_SECTION_ANIMATION_H
