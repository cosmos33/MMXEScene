
#ifndef _XEPROPERTYOBJECTEANIMSOUNDNOTIFY_H
#define _XEPROPERTYOBJECTEANIMSOUNDNOTIFY_H
#include "XEPropertyObjectAnimNotify.h"

class XEPropertyObjectAnimSoundNotify
	:public XEPropertyObjectAnimNotify
{
public:
	XEPropertyObjectAnimSoundNotify(){};
	~XEPropertyObjectAnimSoundNotify(){};
	enum
	{
		PROPERTY_AUDIO_PATH = XEPropertyObjectAnimNotify::PROPERTY_INDEX_END
		, PROPERTY_AUDIO_PREVIEW
		, PROPERTY_AUDIO_SPAWN_MODE
		, PROPERTY_DESTROY_IMMEDIATELY
		, PROPERTY_LOCATION
		, PROPERTY_ROTATION
		, PROPERTY_SCALE
		, PROPERTY_BIND_SOCKET
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // _XEPROPERTYOBJECTEANIMSOUNDNOTIFY_H
