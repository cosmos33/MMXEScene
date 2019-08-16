#ifndef _UI_ROTATE_BY_H_
#define _UI_ROTATE_BY_H_

#include "XUIActionInterval.h"

class XUIRotateBy : public XUIActionInterval
{
public:

	X_CLASS_DEF(XUIRotateBy)

	static XUIRotateBy* Create(const xfloat32& fDuration, const xfloat32& fRotate);

	virtual XUIRotateBy* Clone() const override;
	virtual XUIRotateBy* Reverse() const override;

	virtual ~XUIRotateBy() {};

	// 内部使用
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUIRotateBy();


	virtual void StartWithTarget(XUINode* pTarget) override;
	
	virtual void ActionUpdate(const xfloat32& fProgress) override;


protected:

	xbool InitWithDuration(const xfloat32& fDuration, const xfloat32& fRotate);

protected:
	
	//xfloat32 m_fStartRotate;
	//xfloat32 m_fEndRotate;
	//xfloat32 m_fDelta;

	xfloat32 m_fRotationDelta;
	xfloat32 m_fStartRotation;
	xfloat32 m_fPreviousRotation;


};
#endif
