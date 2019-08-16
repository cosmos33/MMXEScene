#ifndef _UI_LOOP_ACTION_H_
#define _UI_LOOP_ACTION_H_

#include "XUIAction.h"

class XUIActionInterval;
class XUILoopAction : public XUIAction
{
public:

	X_CLASS_DEF(XUILoopAction)

	static XUILoopAction* Create(XUIActionInterval* pAction);

	virtual XUILoopAction* Clone() const override;
	virtual xbool IsDone() const override;

	virtual ~XUILoopAction();

	// 内部使用
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;
protected:
	XUILoopAction();


	virtual void StartWithTarget(XUINode* pTarget) override;
	virtual void Step(const xfloat32& dt) override;
	virtual void Stop() override;
	
protected:

	xbool InitWithAction(XUIActionInterval* pAction);

protected:
	
	XUIActionInterval* m_pAction;
	xbool m_bIsLoop;
	xfloat32 m_fElapsed;

};
#endif
