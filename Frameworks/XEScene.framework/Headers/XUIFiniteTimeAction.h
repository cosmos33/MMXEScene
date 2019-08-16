#ifndef _UIFINITETIMEACTION_H_
#define _UIFINITETIMEACTION_H_

#include "XUIAction.h"

class XUIFiniteTimeAction : public XUIAction
{
protected:
	XUIFiniteTimeAction();


public:

	X_CLASS_DEF(XUIFiniteTimeAction)

	virtual ~XUIFiniteTimeAction();
	virtual XUIFiniteTimeAction* Clone() const override { return NULL; }

	virtual xfloat32 GetDuration() const;
	void SetDuration(const xfloat32& fDuration);


	// �ڲ�ʹ��
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;


protected:
	xfloat32 m_fDuration;
};

#endif