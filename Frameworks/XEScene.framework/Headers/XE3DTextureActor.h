/******************************************************************************

@File         XE3DTextureActor.h

@Version       1.0

@Created      2017, 11, 9

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XE3DTEXTUREACTOR_H
#define XE3DTEXTUREACTOR_H
#include "XEActor.h"

class XE3DTextureActor :public XEActor
{
public:
	XE3DTextureActor();
	~XE3DTextureActor(){};
public:
	virtual void Initialize(XEWorld* pWorld) override;
	XE_ACTOR_CAST(XE3DTextureActor)
	XE_ACTOR_TYPE_DEF(ACTOR_TYPENAME)
	X_CLASS_DEF(XE3DTextureActor)
	   
	static const XString	ACTOR_TYPENAME;
	  
};

#endif // XE3DTEXTUREACTOR_H
