#ifndef _UI_SPAWN_H_
#define _UI_SPAWN_H_

#include "XArray.h"
#include "XUIActionInterval.h"

class XUIFiniteTimeAction;
class XUISpawn : public XUIActionInterval
{
public:

	X_CLASS_DEF(XUISpawn)

	static XUISpawn* Create(const XArray<XUIFiniteTimeAction*>& vActions);
	virtual XUISpawn* Clone() const override;

	virtual xbool IsDone() const override;

	virtual ~XUISpawn() {};

	// 内部使用
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive) override;

	virtual void ActionUpdate(const xfloat32& fProgress) override;
protected:

	XUISpawn();


	virtual void StartWithTarget(XUINode* pTarget) override;
	virtual void Stop() override;
	

	virtual void Step(const xfloat32& dt) override;


protected:

	xbool InitWithArray(const XArray<XUIFiniteTimeAction*>& vActions);

protected:

	XArray<XUIFiniteTimeAction*> m_vActions;

};
#endif
