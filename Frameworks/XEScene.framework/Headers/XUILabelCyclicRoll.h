
/******************************************************************************

@File         XUILabelCyclicRoll.h

@Version      1.0

@Created      2019, 1, 29

@Description

@HISTORY:

******************************************************************************/

#ifndef _XUI_LABEL_CYCLICROLL_H_
#define _XUI_LABEL_CYCLICROLL_H_

#include "XUILabel.h"

X_EEH_FILE

enum XUIELabelRollType {
	XUI_LABELROLL_LEFT_TO_RIGHT = 0,
	XUI_LABELROLL_RIGHT_TO_LEFT,
	XUI_LABELROLL_UP_TO_DOWN,
	XUI_LABELROLL_DOWN_TO_UP,
	XUI_LABELROLL_NUM
};

class XUILabelCyclicRoll : public XUILabel
{
public:
	X_CLASS_DEF(XUILabel)
public:
	


public:
										XUILabelCyclicRoll(XUIELabelRollType RollType = XUI_LABELROLL_LEFT_TO_RIGHT);
	virtual								~XUILabelCyclicRoll();
	void								SetRollArea(xint32 nRollHeight, xint32 nRollWidth);
	X_FORCEINLINE xint32				GetRollAreaHeight() const { return m_nRollHeight; }
	X_FORCEINLINE xint32				GetRollAreaWidth() const { return m_nRollWidth; }

	X_FORCEINLINE void					SetRollSpeed(xint32 nRollSpeed)  { m_nRollSpeed = nRollSpeed; }
	X_FORCEINLINE xint32				GetRollSpeed() const { return m_nRollSpeed; }
	X_FORCEINLINE void					SetRollType(XUIELabelRollType eRollType) { m_eRollType = eRollType; }
	X_FORCEINLINE XUIELabelRollType		GetRollType() { return m_eRollType; }

	virtual	const XVECTOR2&				GetContentSize() const override;
	virtual void						Visit(IXWorld* pWorld, const XMATRIX4& matParentTransform, xuint32 unParentFlags) override;
	virtual void						Draw(IXWorld* pWorld, xuint32 unParentFlags) override;

	/*
	设置文本区域, 在本类中无效
	*/
	virtual void						SetDimensions(xfloat32 fWidth, xfloat32 fHeight);
	virtual XVECTOR2					GetDimensions() const { return XVECTOR2(m_fTextAreaWidth, m_fTextAreaHeight); }

	virtual void						SetEnableWrap(xbool bEnableWrap);
	virtual xbool						GetEnableWrap() const { return m_bEnableWrap; }

	X_FORCEINLINE void					PauseRoll() { m_bRun = xfalse; }
	X_FORCEINLINE xbool					IsRolling() { return m_bRun; }
	void								ResetToStart();

											
protected:

	void								UpdateRoll();
	void								UpdateCurrentPostion();
	void								UpdateLabelLayout();

	xint32								m_nRollHeight;
	xint32								m_nRollWidth;

	XUIELabelRollType					m_eRollType;
	xint32								m_nCurrentPos;
	xint32								m_nRollSpeed;
	xbool								m_bRun;
	

};



#endif // !_XUI_LABEL_CYCLICROLL_H_



