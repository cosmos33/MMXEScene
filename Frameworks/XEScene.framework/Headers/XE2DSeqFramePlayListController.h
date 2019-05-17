/******************************************************************************

@File         XE2DSeqFramePlayListController.h

@Version       1.0

@Created      2019, 3, 16

@Description  控制一组序列帧动画

@HISTORY:

******************************************************************************/
#ifndef XE_2D_SEQUENCE_FRAME_PLAYLIST_CONTROLLER_H
#define XE_2D_SEQUENCE_FRAME_PLAYLIST_CONTROLLER_H
#include "XEAnimControllerBase.h"
#include "XEMagicCoreUtility.h"
#include "XEImgSequenceFrameComponent.h"

class XE2DSequenceFrameAnimController;
class XE2DSeqFramePlayListController : public XEAnimControllerBase
{
public:
	XE2DSeqFramePlayListController(XEImgSequenceFrameComponent* pComponent);
	virtual								~XE2DSeqFramePlayListController();
public:
	virtual void						Tick(xfloat32 fInterval) override;
	virtual void						Play() override;//goto 0, and play again. and set m_bOnlyTickCurrentController = xfalse
	virtual void						Resume() override;
	virtual void						Stop() override;
	virtual void						Pause() override;
	virtual void                        SetTime(xint32 nTime) override;//in micro seconds.
public:
	XEImgSequenceFrameComponent*		GetComponentOwner(){ return m_pComponentOwner; }
	//添加一个序列帧动画
	XE2DSequenceFrameAnimController*	Add2DSequenceFrameAnim(const XEMagicCoreUtility::XE2DSequenceFrameListInfo& aFrameListInfo);
	void								RemoveAllSeqFrameAnim();
	xbool								RemoveSeqFrameAnim(xint32 nIndex);
	//获取某个序列帧动画的控制器
	XE2DSequenceFrameAnimController*    Get2DSeqFrameAnimController(xint32 nIndex);
	//获取当前播放的序列帧动画控制器
	XE2DSequenceFrameAnimController*	GetCurrentSeqFrameAnimController();
	XArray<XE2DSequenceFrameAnimController*>&	GetAllSequenceFrameAnimController(){ return m_aSeqFrameAnimController; }
	void								SetCurrentController(const xint32& nIndex){ m_nCurIndex = nIndex; }
	//设置是否仅仅更新当前序列帧动画
	void								SetOnlyTickCurrentController(xbool bTickOnlyCurrentController);
	//延迟时间
	void								SetDelayTime(xfloat32 fDelayTime){ m_fDelayTime = fDelayTime; }
	xfloat32							GetDelayTime(){ return m_fDelayTime; }
private:
	XE2DSequenceFrameAnimController*	Get2DSequenceFrameAnimController(const XEMagicCoreUtility::XE2DSequenceFrameListInfo& aFrameListInfo);
	void								NextAnimation();
	xbool								Delay(xfloat32 fInterval);
private:
	XEImgSequenceFrameComponent*			m_pComponentOwner;
	XArray<XE2DSequenceFrameAnimController*>m_aSeqFrameAnimController;
	xint32									m_nCurIndex;
	xbool									m_bOnlyTickCurrentController;//是否仅仅更新当前控制器
	xfloat32								m_fDelayTime;
};

#endif