#ifndef _UI_SCALE_BY_H_
#define _UI_SCALE_BY_H_

#include "XUIActionInterval.h"

class XUIScaleBy : public XUIActionInterval
{
public:

	X_CLASS_DEF(XUIScaleBy)

		static XUIScaleBy* Create(const xfloat32& fDuration, const XVECTOR2& v2Scale);
	static XUIScaleBy* Create(const xfloat32& fDuration, const xfloat32& fScale);

	virtual XUIScaleBy* Clone() const override;
	virtual XUIScaleBy* Reverse() const override;

	virtual ~XUIScaleBy() {};

	// 内部使用
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUIScaleBy();


	virtual void StartWithTarget(XUINode* pTarget) override;
	
	virtual void ActionUpdate(const xfloat32& fProgress) override;


protected:

	xbool InitWithDuration(const xfloat32& fDuration, const XVECTOR2& v2Scale);

protected:
	
	XVECTOR2 m_v2ScaleDelta;
	XVECTOR2 m_v2StartScale;
	XVECTOR2 m_v2PreviousScale;


};
#endif
