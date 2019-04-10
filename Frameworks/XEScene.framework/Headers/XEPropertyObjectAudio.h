#ifndef XEPROPERTYOBJECTAUDIO_H
#define XEPROPERTYOBJECTAUDIO_H

#include "XEPropertyObjectBase.h"

class XEPropertyObjectAudio
	:public XEPropertyObjectBase
{
public:
	XEPropertyObjectAudio(){}
	~XEPropertyObjectAudio(){}

	enum{
		PROPERTY_ASSETPATH = XEPropertyTree::USER_PROPRETY_INDEX,	
		PROPERTY_SOUND_NODE,
		PROPERTY_SOUND_AUTO_PLAY,
		PROPERTY_SOUND_LOOP,
		PROPERTY_SOUND_PLAY_MODE,
		PROPERTY_SOUND_ADD_AUDIO,
		PROPERTY_SOUND_PREVIEW,
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

protected:
	XString         m_strSelectedAudio;
	xbool           m_bLoop;
	xbool           m_bAutoPlay;
	xint32          m_nPlayModeOptionIndex;
};


#endif