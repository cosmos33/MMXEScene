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

class XEMagicSeqFrameInstance;
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
	/*
	* @Deprecated from 1.5 version
	* 添加一个序列帧动画 
	* 注意：此函数为了兼容sence低于1.5版本，大于等于1.5版本的函数，应该使用BuildSeqFrameAnimIns函数
	*/
	XE2DSequenceFrameAnimController*	Add2DSequenceFrameAnim(const XEMagicCoreUtility::XE2DSequenceFrameListInfo& aFrameListInfo);
	void								RemoveAllSeqFrameAnim();//remove all seq frame anim ins
	xbool								RemoveSeqFrameAnim(xint32 nIndex);//remove seq frame anim ins
	//获取某个序列帧动画的控制器
	XE2DSequenceFrameAnimController*    Get2DSeqFrameAnimController(xint32 nIndex);
	//获取当前播放的序列帧动画控制器
	XE2DSequenceFrameAnimController*	GetCurrentSeqFrameAnimController();
	void								SetCurrentController(const xint32& nIndex){ m_nCurIndex = nIndex; }
	//设置是否仅仅更新当前序列帧动画
	void								SetOnlyTickCurrentController(xbool bTickOnlyCurrentController);
	//延迟时间
	void								SetDelayTime(xfloat32 fDelayTime){ m_fDelayTime = fDelayTime; }
	xfloat32							GetDelayTime(){ return m_fDelayTime; }
public:
	//1.5 version adding 
	XArray<XE2DSequenceFrameAnimController*>	GetAllSequenceFrameAnimController();
	const XArray<XEMagicSeqFrameInstance*>&		GetSeqFrameAnimInstanceList(){ return m_aSequenceFrameIns; }
	XEMagicSeqFrameInstance*			BuildSeqFrameAnimIns(const XString& strAssetPath);
	xbool								DestorySeqFrameAnimIns(XEMagicSeqFrameInstance* pIns);
	XEMagicSeqFrameInstance*			GetSeqFrameIns(xint32 nIndex);
public:
 #if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	struct AnimWrapper
	{
	public:
		AnimWrapper() :nAddIndex(0){}
		~AnimWrapper(){}
	public:
		xbool operator == (const AnimWrapper& aw) const;
	public:
		xint32         nAddIndex;
		XString        strAnimAssetPath;///using path to generate the actual animation.
	};

	typedef XArray<AnimWrapper> AnimWrapperArray;
	xint32                              AddAnimWrapper(const xchar* pAssetPath);
	xbool                               RemoveAnimWrapper(const xchar* pAssetPath, xint32 nAddIndex = -1);//if nAddIndex set to -1, means try to remove all animwrapper in the same asset path.
	xbool                               RemoveAnimWrapperForAddIndex(xint32 nAddIndex);
	void                                RemoveAllAnimWrapper();
	xint32                              GetMaxAddIndex();
	X_FORCEINLINE const AnimWrapperArray& GetAnimWrapperList() const{ return m_aAnimWrapper; }
	X_FORCEINLINE AnimWrapperArray&       GetAnimWrapperList(){ return m_aAnimWrapper; }
 #endif
private:
	XE2DSequenceFrameAnimController*	Get2DSequenceFrameAnimController(const XEMagicCoreUtility::XE2DSequenceFrameListInfo& aFrameListInfo);
	void								NextAnimation();
	xbool								Delay(xfloat32 fInterval);
	xbool								DestorySeqFrameAnimInsImpl(XEMagicSeqFrameInstance* pIns);
private:
	XEImgSequenceFrameComponent*			m_pComponentOwner;
	xint32									m_nCurIndex;
	xbool									m_bOnlyTickCurrentController;//是否仅仅更新当前控制器
	xfloat32								m_fDelayTime;
	XArray<XEMagicSeqFrameInstance*>		m_aSequenceFrameIns;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	AnimWrapperArray                        m_aAnimWrapper;
#endif
};

#endif