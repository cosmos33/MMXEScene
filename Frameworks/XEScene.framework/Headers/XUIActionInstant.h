#ifndef _UIACTIONINSTANT_H_
#define _UIACTIONINSTANT_H_

#include "XUIFiniteTimeAction.h"

class XUIActionInstant : public XUIFiniteTimeAction
{
public:

	X_CLASS_DEF(XUIActionInstant)

	virtual xbool IsDone() const override;

	// 内部使用
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUIActionInstant();
	virtual ~XUIActionInstant() {};

	virtual void StartWithTarget(XUINode* pTarget) override;
	virtual void Step(const xfloat32& dt) override;

protected:

};
#endif 
