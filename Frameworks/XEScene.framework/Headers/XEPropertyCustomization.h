/******************************************************************************

@File         XEPropertyCustomization.h

@Version      1.0

@Created      2018, 6, 2

@Description  The class ids of each class in X Editor.Customization Property

@HISTORY:

******************************************************************************/

#ifndef _XE_PROPERTY_CUSTOMIZATION_H_
#define _XE_PROPERTY_CUSTOMIZATION_H_

#include "XEngineRoot.h"
#include "XEActor.h"
#include "XESingleton.h"
#include "XEUserNode.h"

enum XEPropertyCustomizationType
{
	PCT_NONE,
	PCT_ACTOR,
	PCT_COMPONENT,
	PCT_NUM
};

/**
* Interface for actors or components that customize properties.
*/
class XEPropertyCustomization 
	: public XEUserNode
{
public:
	XEPropertyCustomization() :m_ePropertyCustomizationType(PCT_NONE){}
	XEPropertyCustomization(XEPropertyCustomizationType eType) :m_ePropertyCustomizationType(eType){}
	virtual								~XEPropertyCustomization(){}
	XEPropertyCustomizationType			GetCustomizePropertyType(){ return m_ePropertyCustomizationType; }
	XArray<XEPropertyObjectBase*>&		GetPropertyObjectListForBuildTree(){ return m_aPropertyObjectsForBuildTree; }
public:
	virtual void						CustomizeProperties(XArray<XEActor*>& aEditActors,XEPropertyObjectProxy* pPropertyObjectProxy) = 0;
	virtual void						Release();
#if X_PLATFORM_WIN_DESKTOP				    
	virtual XEPropertyObjectSet         GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy);
#endif	
protected:
	XEPropertyCustomizationType			m_ePropertyCustomizationType;
	XArray<XEPropertyObjectBase*>		m_aPropertyObjectsForBuildTree;
	static const XString NODE_TYPENAME;
};


class XEPropertyCustomizationManager 
	: public XESingleton<XEPropertyCustomizationManager>
{
public:
	XEPropertyCustomizationManager();
	~XEPropertyCustomizationManager(){}
public:
	void								Release();
	XEPropertyCustomization*			CreatePropertyCustomization(XArray<XEActor*>& aActors, XEPropertyCustomizationType eType);
	void								DeleteProperty(XEPropertyCustomization* pProperty);
private:
	XArray<XEPropertyCustomization*>	m_aCustomization;
};

#endif //_XE_PROPERTY_CUSTOMIZATION_H_