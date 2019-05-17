/******************************************************************************

@File         XE2DSequenceFrameAnimController.h

@Version       1.0

@Created      2019, 3, 16

@Description  控制一个序列帧动画

@HISTORY:

******************************************************************************/
#ifndef XE_2D_SEQUENCE_FRAME_ANIMATION_CONTROLLER_H
#define XE_2D_SEQUENCE_FRAME_ANIMATION_CONTROLLER_H
#include "XEAnimControllerBase.h"
#include "XEMagicCoreUtility.h"

class XE2DSequenceFrameAnimController : public XEAnimControllerBase
{
public:
	XE2DSequenceFrameAnimController();
	virtual							~XE2DSequenceFrameAnimController();
	enum ETextureOperator
	{
		ETO_NONE,
		ETO_REMOVE,
		ETO_MODIFY
	};
public:
	virtual void                    Tick(xfloat32 fInterval)override;
	virtual void                    Stop()override;
	virtual void                    Pause()override;
	virtual void                    Resume()override;
	virtual void                    SetPlayRate(xfloat32 fRate)override;
public:						
	X_FORCEINLINE xint32			GetFrameCount(){ return m_nFrameCount; }
	X_FORCEINLINE void				SetDelayTime(xfloat32 fDelayTime){ m_fDelayTime = fDelayTime; }
	X_FORCEINLINE xfloat32			GetDelayTime(){ return m_fDelayTime; }
	X_FORCEINLINE xint32			GetCurIndex(){ return m_nCurIndex; }
	X_FORCEINLINE ETextureOperator	GetTextureOperator(){ return m_eTextureOperator; }
public:
	const XEMagicCoreUtility::XE2DSequenceFrameListInfo&		GetTextureFrameListInfo() const{ return m_aSequenceFrameListInfo; }
	X_FORCEINLINE XEMagicCoreUtility::ETextureAssetType			GetTextureAssetType() const{ return m_aSequenceFrameListInfo.eTextureAssetType; }
	void						    RemoveTexture(xint32 nIndex);
	void							SetColForTexture(xint32 nTextureIndex, xint32 nCol);
	xint32							GetColForTexture(xint32 nTextureIndex);
	void							SetRowForTexture(xint32 nTextureIndex, xint32 nRow);
	xint32							GetRowForTexture(xint32 nTextureIndex);
	xbool							GetCurrentTextureInfoByIndex(XEMagicCoreUtility::XERenderTextureInfo& renderTextureInfo);
	xbool							SetTextureFrameListInfo(const XEMagicCoreUtility::XE2DSequenceFrameListInfo& aInfos);
	xbool							IsCanTick();
public:
	void							SetTextureOperator(ETextureOperator eType){ m_eTextureOperator = eType; }
private:
	void							CalculateDuration();
	void							CalculateFrameCount();
	void							SetFrameCount(xint32 nFrameCount);
	void							Reset();
	xbool							Delay(xint32 nCurTime);
protected:
	XEMagicCoreUtility::XE2DSequenceFrameListInfo  m_aSequenceFrameListInfo;
	xint32							m_nFrameCount;//总帧数
private:
	xfloat32						m_fDelayTime;//延迟时间
	xfloat32						m_fDuration;//总时长,不保存
	xbool							m_bTicked;//是否tick
	xint32							m_nCurIndex;
	xint32							m_nRecordIndex;//暂停时，播放到的索引
	xbool							m_bPositive;//正序播放
	ETextureOperator				m_eTextureOperator;
};

#endif