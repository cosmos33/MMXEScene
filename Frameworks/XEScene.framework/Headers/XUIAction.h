#ifndef _UIACTION_H_
#define _UIACTION_H_

#include "XMemBase.h"
#include "XUINode.h"

#include "XUIActionManager.h"

typedef XUIAction* XUIActionPtr;

class XUIAction : public XMemBase, public XClass
{
public:
	static const int INVALID_TAG;
public:

	X_CLASS_DEF(XUIAction)

	virtual XUIAction* Clone() const { return NULL; };
	virtual XUIAction* Reverse() const{ return NULL; };
	virtual xbool IsDone() const = 0;

	virtual ~XUIAction() {};



	// �ڲ�ʹ��
	virtual xbool					SerilizeXML(XXMLExtendTool& outXmlArchive);


protected: 
	XUIAction();


	friend class IXUIActionManager;
	//以下方法只有IXUIActionManager以及其派生类可以访问到

	virtual void StartWithTarget(XUINode* pTarget);
	virtual void Stop();
	virtual void Step(const xfloat32& dt) = 0;

	virtual void ActionUpdate(const xfloat32& fProgress);



	void SetTarget(XUINode* pTarget){ m_pTarget = pTarget; }
	XUINode* GetTarget() { return m_pTarget; }

	void SetTag(const xint32& nTag){ m_nTag = nTag; }
	xint32 GetTag(){ return m_nTag; }


protected:
	void ActionStartWithTarget(XUIAction* pAction, XUINode* pTarget);
	void ActionStop(XUIAction* pAction);
	void ActionStep(XUIAction* pAction, const xfloat32& dt);
	xbool ActionIsDone(XUIAction* pAction) const;
	void ActionActionUpdate(XUIAction* pAction, const xfloat32& fProgress);
	XUINode* ActionGetTarget(XUIAction* pAction);
	void ActionSafeDelete(XUIAction* pAction);

protected:
	XUINode* m_pTarget;
	xint32 m_nTag;
	xbool m_bDone;
};
#endif
