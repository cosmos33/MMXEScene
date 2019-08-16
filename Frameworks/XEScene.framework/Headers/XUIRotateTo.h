#ifndef _UI_ROTATE_TO_H_
#define _UI_ROTATE_TO_H_

#include "XUIRotateBy.h"

class XUIRotateTo : public XUIRotateBy
{
public:

	X_CLASS_DEF(XUIRotateTo)

	static XUIRotateTo* Create(const xfloat32& fDuration, const xfloat32& fRotate);

	virtual XUIRotateTo* Clone() const override;
	virtual XUIRotateTo* Reverse() const override;

	virtual ~XUIRotateTo() {};

	// �ڲ�ʹ��
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUIRotateTo();


	virtual void StartWithTarget(XUINode* pTarget) override;

	xbool InitWithDuration(const xfloat32& fDuration, const xfloat32& fEndRotation);
	

protected:
	xfloat32 m_fEndRotation;

};
#endif
