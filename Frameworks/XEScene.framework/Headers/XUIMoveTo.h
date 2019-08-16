#ifndef _UI_MOVE_TO_H_
#define _UI_MOVE_TO_H_

#include "XUIMoveBy.h"

class XUIMoveTo : public XUIMoveBy
{
public:

	X_CLASS_DEF(XUIMoveTo)

	static XUIMoveTo* Create(const xfloat32& fDuration, const XVECTOR2& v2EndPosition);

	virtual XUIMoveTo* Clone() const override;
	virtual XUIMoveTo* Reverse() const override;

	virtual ~XUIMoveTo() {};

	// �ڲ�ʹ��
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUIMoveTo();


	virtual void StartWithTarget(XUINode* pTarget) override;
	

protected:

	xbool InitWithDuration(const xfloat32& fDuration, const XVECTOR2& v2EndPosition);

protected:
	
	XVECTOR2 m_v2EndPosition;


};
#endif
