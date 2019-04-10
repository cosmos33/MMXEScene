/******************************************************************************

@File         XEPropertyObjectAnimParticleNotify.h

@Version       1.0

@Created      2017, 10, 30

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XEPROPERTYOBJECTEANIMPARTICLENOTIFY_H
#define _XEPROPERTYOBJECTEANIMPARTICLENOTIFY_H
#include "XEPropertyObjectAnimNotify.h"

class XEPropertyObjectAnimParticleNotify 
	:public XEPropertyObjectAnimNotify
{
public:
	XEPropertyObjectAnimParticleNotify(){};
	~XEPropertyObjectAnimParticleNotify(){};
	enum
	{ 
		PROPERTY_PARTICLE_SYSTEM_PATH = XEPropertyObjectAnimNotify::PROPERTY_INDEX_END
		, PROPERTY_PARTICLE_PREVIEW
		, PROPERTY_PARTICLE_SPAWN_MODE
		, PROPERTY_DESTROY_IMMEDIATELY
		, PROPERTY_LOCATION
		, PROPERTY_ROTATION
		, PROPERTY_SCALE
		, PROPERTY_BIND_SOCKET
		, PROPERTY_BIND_NODE
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

// private:
// 	void            DeleteSocketSuffix(XArray<XString>& arrSocketNames);//È¥µô_Socket_nºó×º
// 	xbool		    DeleteSocketStr(XString& strSource);
};

#endif // _XEPROPERTYOBJECTEANIMPARTICLENOTIFY_H
