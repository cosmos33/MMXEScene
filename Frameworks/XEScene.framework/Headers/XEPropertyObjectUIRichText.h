/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUIRICHTEXT_H
#define XEPROPERTYOBJECTUIRICHTEXT_H
#include "XEPropertyObjectUIWidget.h"
#include "XUIRichText.h"

class RichTextHelper
{
public:
	void InitRichText(XUIRichText* pRichText, const XString& strString);

	enum RichType
	{
		RT_UNKNOW,
		RT_TEXT_COLOR,
		RT_TEXT_FONT_SIZE,
		RT_TEXT_FONT_PATH,
		RT_IMAGE_PATH,
		RT_TEXT,
	};

	struct RichTextData
	{
		RichTextData() :pEle(NULL){}
		RichType eType;
		xbool bReverse;

		XCOLORBASE mColor;
		xfloat32 mFloat;
		XString mString;

		XUIRichElement* pEle;
	};

	struct RichElementHead
	{
		XString mHeadString;

		RichTextData Format();
	};

protected:
	static xchar CharToLower(const xchar& ch);

	static xfloat32 CharToFloat16(const xchar& ch);

	static XCOLORBASE StringConvColor(const XString& strColor);

	static xfloat32 StringConvFloat32(const XString& strFloat);

	XArray<RichTextData> m_vRichTextData;
};

class XUINode;
class XEPropertyObjectUIRichText
	:public XEPropertyObjectUIWidget
{
public:
	XEPropertyObjectUIRichText() :XEPropertyObjectUIWidget(){};
	~XEPropertyObjectUIRichText(){};
	enum{ 
		PROPERTY_RICHTEXT = PROPERTY_UIWIDGET_END,
		PROPERTY_TEXT,
		PROPERTY_WRAPMODE,

		PROPERTY_RICHTEXT_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;


private:
	RichTextHelper	m_RichTextHelper;
};


#endif // XEPROPERTYOBJECTWORLD_H
