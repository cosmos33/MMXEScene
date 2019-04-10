/******************************************************************************

@File         XEMultActorPropertyCustomization.h

@Version      1.0

@Created      2018, 6, 2

@Description  The class ids of each class in X Editor.Customization Property

@HISTORY:

******************************************************************************/
#ifndef _XE_ACTOR_PROPERTY_CUSTOMIZATION_H_
#define _XE_ACTOR_PROPERTY_CUSTOMIZATION_H_
#include "XEPropertyCustomization.h"

class XEActor;
class XEMultActorPropertyCustomization : public XEPropertyCustomization
{
public:
	XEMultActorPropertyCustomization(XEPropertyCustomizationType eType);
	virtual								~XEMultActorPropertyCustomization();
	virtual void						CustomizeProperties(XArray<XEActor*>& aEditActors,
											XEPropertyObjectProxy* pPropertyObjectProxy) override;
	virtual void						Release() override;
#if X_PLATFORM_WIN_DESKTOP				    
	virtual XEPropertyObjectSet         GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy);
#endif	
	XArray<XEActor*>&					GetEditActors(){ return m_aEditActors; }
	xbool								IsExistPropertyObjectInList(XEPropertyObject* pPropertyObject);
protected:
	static const XString NODE_TYPENAME;
	XArray<XEActor*>					m_aEditActors;
};

#endif
