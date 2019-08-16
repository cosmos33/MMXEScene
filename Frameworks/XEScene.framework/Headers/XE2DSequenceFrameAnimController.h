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
	virtual void                    Play() override;
public:						
	X_FORCEINLINE xint32			GetFrameCount(){ return m_nFrameCount; }
	X_FORCEINLINE void				SetDelayTime(xfloat32 fDelayTime){ m_fDelayTime = fDelayTime; }
	X_FORCEINLINE xfloat32			GetDelayTime(){ return m_fDelayTime; }
	X_FORCEINLINE xint32			GetCurIndex(){ return m_nCurIndex; }
	X_FORCEINLINE ETextureOperator	GetTextureOperator(){ return m_eTextureOperator; }

	X_FORCEINLINE void				SetFrameLoopInfo(const XEMagicCoreUtility::XESequenceFrameLoopInfo& loopInfo){ m_LoopModeInfo = loopInfo; }
	X_FORCEINLINE XEMagicCoreUtility::XESequenceFrameLoopInfo& GetFrameLoopInfo(){ return m_LoopModeInfo; }

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
	void							RemoveAllTextures();
	xbool							IsValidLoop();
	xbool							IsDelayTime();
public:
	void							SetTextureOperator(ETextureOperator eType){ m_eTextureOperator = eType; }
private:
	void							CalculateDuration();
	void							CalculateFrameCount();
	void							SetFrameCount(xint32 nFrameCount);
	void							Reset();
	xbool							Delay(xint32 nCurTime);
	void							ReversePlay(xfloat32 fInterval);
	void							PostivePlay(xfloat32 fInterval);
	xint32							GetStartIndexForLoop();
	xint32							GetEndIndexForLoop();
protected:
	XEMagicCoreUtility::XE2DSequenceFrameListInfo  m_aSequenceFrameListInfo;
	xint32							m_nFrameCount;//总帧数
	xbool							m_bFirstPostive;
	xbool							m_bFirstReverse;
private:
	xfloat32						m_fDelayTime;//延迟时间
	xfloat32						m_fDuration;//总时长,不保存
	xbool							m_bTicked;//是否tick
	xint32							m_nCurIndex;
	xint32							m_nRecordIndex;//暂停时，播放到的索引
	ETextureOperator				m_eTextureOperator;
	XEMagicCoreUtility::XESequenceFrameLoopInfo	m_LoopModeInfo;
};

#endif