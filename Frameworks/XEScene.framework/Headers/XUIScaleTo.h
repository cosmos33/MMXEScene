#ifndef _UI_SCALE_TO_H_
#define _UI_SCALE_TO_H_

#include "XUIScaleBy.h"

class XUIScaleTo : public XUIScaleBy
{
public:

	X_CLASS_DEF(XUIScaleTo)

	static XUIScaleTo* Create(const xfloat32& fDuration, const XVECTOR2& v2Scale);
	static XUIScaleTo* Create(const xfloat32& fDuration, const xfloat32& fScale);

	virtual XUIScaleTo* Clone() const override;
	virtual XUIScaleTo* Reverse() const override;

	virtual ~XUIScaleTo() {};

	// 内部使用
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUIScaleTo();

	virtual void StartWithTarget(XUINode* pTarget) override;

	xbool InitWithDuration(const xfloat32& fDuration, const XVECTOR2& v2EndPosition);

protected:

	XVECTOR2 m_v2EndScale;
};
#endif
