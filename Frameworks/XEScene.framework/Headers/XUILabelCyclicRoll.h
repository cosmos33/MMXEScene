
/******************************************************************************

@File         XUILabelCyclicRoll.h

@Version      1.0

@Created      2019, 1, 29

@Description

@HISTORY:

******************************************************************************/

#ifndef _XUI_LABEL_CYCLICROLL_H_
#define _XUI_LABEL_CYCLICROLL_H_

#include "XUIWidget.h"
#include "XUILabel.h"


X_EEH_FILE


class XUILabelCyclicRoll : public XUIWidget
{
public:
	X_CLASS_DEF(XUILabelCyclicRoll)

	enum XUIELabelRollType {
		XUI_LABELROLL_LEFT_TO_RIGHT = 0,
		XUI_LABELROLL_RIGHT_TO_LEFT,
		XUI_LABELROLL_UP_TO_DOWN,
		XUI_LABELROLL_DOWN_TO_UP,
		XUI_LABELROLL_NUM
	};

	
	static XUILabelCyclicRoll*			CreateRollOfTTF(XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);
	static XUILabelCyclicRoll*			CreateRollOfTTF(const XUITTFConfig& ttfConfig, XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);
	static XUILabelCyclicRoll*			CreateRollOfSys(XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);
	static XUILabelCyclicRoll*			CreateRollOfSys(const XString& strSysFontName, xfloat32 fFontPointSize, XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);

public:
										XUILabelCyclicRoll(XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);
										XUILabelCyclicRoll(const XUITTFConfig& ttfConfig, XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);
										XUILabelCyclicRoll(const XString& strSysFontName, xfloat32 fFontPointSize, XUIELabelRollType eRollType = XUI_LABELROLL_LEFT_TO_RIGHT);
	virtual								~XUILabelCyclicRoll();	
	virtual xint32						GetTypeID() const override;
	
	virtual void						Tick(xfloat32 fDelta) override;
	virtual void						Draw(IXWorld* pWorld, xuint32 unParentFlags) override;
	virtual void						SetScreenMask(const XVECTOR2& vPos, const XVECTOR2& vWAxis, const XVECTOR2& vHAxis, xfloat32 fWidth, xfloat32 fHeight) override{}
	virtual xbool						SerilizeSelfXML(XXMLExtendTool& outXmlArchive) override;
	

	/*	设置，文本滚动区域	*/
	void								SetRollArea(xint32 nRollWidth, xint32 nRollHeight);
	X_FORCEINLINE xint32				GetRollAreaHeight() const { return m_nRollHeight; }
	X_FORCEINLINE xint32				GetRollAreaWidth() const { return m_nRollWidth; }

	/*	设置，文本滚动速度	*/
	X_FORCEINLINE void					SetRollSpeed(xfloat32 fRollSpeed)  { m_fRollSpeed = fRollSpeed; }
	X_FORCEINLINE xfloat32				GetRollSpeed() const { return m_fRollSpeed; }

	/*	设置，文本滚动类型	*/
	void								SetRollType(XUIELabelRollType eRollType);
	X_FORCEINLINE XUIELabelRollType		GetRollType() { return m_eRollType; }

	/*
		设置，是否ContentSize自动适应文本大小;
		开启时：	如果滚动类型为左向右或右向左时，则ContentSize的高度自动与文本高度相等；
		        如果滚动类型为上向下或下向上时，则ContentSize的宽度自动与文本宽度相等；
		关闭时：ContentSize = RollArea
	*/
	void								SetFitTextSize(xbool bFitText);
	X_FORCEINLINE xbool					IsFitTextSize() const { return m_bFitTextSize; }

	/*
		设置循环播放周期时间；
		如果设置的循环播放周期时间 < 文字滚动时间， 实际循环播放周期时间 = 文字滚动时间；
		如果设置的循环播放周期时间 > 文字滚动时间， 实际循环播放周期时间 = 设置的循环播放周期时间；
	*/
	X_FORCEINLINE void					SetLoopTime(xfloat32 fLoopTime) { m_fLoopTime = fLoopTime; }
	X_FORCEINLINE xfloat32				GetLoopTime() const { return m_fLoopTime; }

	/*	滚动控制  */
	X_FORCEINLINE void					PauseRoll() { m_bRolling = xfalse; }
	X_FORCEINLINE void					ResumeRoll() { m_bRolling = xtrue; }
	X_FORCEINLINE xbool					IsRolling() { return m_bRolling; }
	void								ResetToStart();
	

	/*	设置文本内容 */
	void								SetString(const XString &strUtf8Text);
	const XString&						GetString() const;
	xint32								GetStringCount() const;

	/*	设置文本颜色	*/
	void								SetTextColor(const XCOLORBASE &clr);
	X_FORCEINLINE const XCOLORBASE&		GetTextColor() const;

	/*	设置字体大小	*/
	void								SetTextPointSize(xfloat32 fPointSize);
	X_FORCEINLINE xfloat32				GetTextPointSize() const;
											
protected:

	void								UpdateRoll(xfloat32 fDelta);	
	void								UpdateContentSize();
	xbool								IntersectionArea(const XVECTOR2 &vMin1, const XVECTOR2 &vMax1, const XVECTOR2 &vMin2,
											const XVECTOR2 &vMax2, XVECTOR2 &vMinRes, XVECTOR2 &vMaxRes);
	void								LayoutSet();
	//void								

	xbool								m_bRolling;

	xint32								m_nRollHeight;
	xint32								m_nRollWidth;
	xbool								m_bFitTextSize;

	XUIELabelRollType					m_eRollType;
	xfloat32							m_fRollSpeed;	
	xfloat32							m_fLoopTime;
	
	xfloat32							m_fCurLoopLostTime;

	XUILabel							*m_pLabel;
};



#endif // !_XUI_LABEL_CYCLICROLL_H_



