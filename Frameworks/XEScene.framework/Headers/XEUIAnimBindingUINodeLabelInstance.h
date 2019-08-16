/******************************************************************************

@File        XEUIAnimBindingUINodeLabelInstance.h

@Version       1.0

@Created      2018,5, 3

@HISTORY:

******************************************************************************/
#ifndef _XE_UIANIM_BINDING_UINODE_LABEL_INSTANCE_H
#define _XE_UIANIM_BINDING_UINODE_LABEL_INSTANCE_H
#include "XEUIAnimBindingUINodeInstance.h"
#include "XEUIAnimBindingUINodeLabel.h"
class XEUIAnimBindingUINodeLabelInstance : public XEUIAnimBindingUINodeInstance
{
public:
	XEUIAnimBindingUINodeLabelInstance(XEUIAnimBindingUINodeLabel* pNodeTl);
	virtual ~XEUIAnimBindingUINodeLabelInstance();
public:
	virtual void			SetTime(xint32 nMicrosecond) override;//in microsecond.
};

#endif