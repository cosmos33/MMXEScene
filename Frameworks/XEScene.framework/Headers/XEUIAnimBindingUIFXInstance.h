/******************************************************************************

@File        XEUIAnimBindingUIFXInstance.h

@Version       1.0

@Created      2019,6, 14

@HISTORY:

******************************************************************************/
#ifndef _XE_UIANIM_BINDING_UINODE_UIFX_INSTANCE_H
#define _XE_UIANIM_BINDING_UINODE_UIFX_INSTANCE_H
#include "XEUIAnimBindingUINodeInstance.h"
#include "XEUIAnimBindingUIFX.h"
class XEUIAnimBindingUIFXInstance : public XEUIAnimBindingUINodeInstance
{
public:
	XEUIAnimBindingUIFXInstance(XEUIAnimBindingUIFX* pNodeTl);
	virtual ~XEUIAnimBindingUIFXInstance();
public:
	virtual void			SetTime(xint32 nMicrosecond) override;//in microsecond.
private:
	xint32 m_nActiveState = -1; // useed for xuifx
};

#endif