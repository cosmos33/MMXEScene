#ifndef _XUIIMAGE_H_
#define _XUIIMAGE_H_

#include "XUIWidget.h"
#include "XHashTable.h"

const xint32 EMPTY_TAG = 0xFFFFFFFF;

class XUISprite;
class IXTexture2D;

class XUITexture
{
public:
	XUITexture(){}
	~XUITexture();
	IXTexture2D*				m_pTexture;
	XUIWidget::TextureResType	m_eTexType;
	XString						m_strPath;
	xbool						m_bRelative;	
};

enum XUIImageDirtyFlag
{
	XUI_DF_CLEAN = XBit(0),
	XUI_DF_VB_POS = XBit(1),
	XUI_DF_VB_COLOR = XBit(2),
	XUI_DF_IB = XBit(3),
	XUI_DF_TEX = XBit(4),
	XUI_DF_ALL = XUI_DF_VB_POS | XUI_DF_VB_COLOR | XUI_DF_IB | XUI_DF_TEX
};

class XUIImage : public XUIWidget
{
public:	
	X_CLASS_DEF(XUIImage)
	static XUIImage*		Create();
	static XUIImage*		Create(xint32 nTag, const XString& strTextureName, TextureResType texType = TextureResType::XUI_LOCAL);
	XUIImage();
	virtual ~XUIImage();
	virtual xint32			GetTypeID() const override;
	void					SetUseTexture(xbool bUse);
	xbool					IsUseTexture()const{ return m_bUseTexture; }
	xbool					LoadTexture(xint32 nTag, const XString& strTextureName, TextureResType texType = TextureResType::XUI_LOCAL);
	void					ShowTexture(xint32 nTag);
	void					RemoveTexture(xint32 nTag);
	xint32					GetTextureNum()const{ return m_tbTexture.Num(); }
	xint32					GetCurrentTag()const{ return m_nCurrentTag; }
	XString					GetTexturePath(xint32 nTag);
	xbool					IsTextureExisted(xint32 nTag);
	virtual void			Update(xfloat32 fDelta)override;
	virtual void			SetContentSize(const XVECTOR2& vContentSize)override;
	xbool					IsFollowTextureSize()const{ return m_bFollowTextureSize; }
	void					SetFollowTextureSize(xbool bFollow){ m_bFollowTextureSize = bFollow; }
	void					SetRectPercent(const XVECTOR2& vLTPercent, const XVECTOR2& vBRPercent);
	void					SetFlipX(xbool bFlip);
	xbool					IsFlipX()const;

	XVECTOR2				GetTextureOriginalSize(xint32 nTag);
	
	// sequence
	void					SetUseSequence(xbool bUse){ m_bUseSequence = bUse; }
	xbool					IsUseSequence()const{ return m_bUseSequence; }
	xbool					IsSequencePlaying()const{ return m_bPlaySequence; }
	void					PlaySequence(xbool bPlay);
	void					ResetSequence();
	void					SetUVTile(XVECTOR2 vTile){ m_vUVTile = vTile; }
	void					SetUVTile(xfloat32 fUTile, xfloat32 fVTile){ SetUVTile(XVECTOR2(fUTile, fVTile)); }
	const XVECTOR2&			GetUVTile()const{ return m_vUVTile; }
	void					SetSequenceFPS(xfloat32 fFPS){ m_fFPS = fFPS; }
	xfloat32				GetSequenceFPS()const{ return m_fFPS; }
	void					SetActualFrameNum(xint32 nNum){ m_nActualFrameNum = nNum; }
	xint32					GetActualFrameNum()const{ return m_nActualFrameNum; }
	void					SetCurrentFrame(xint32 nFrame){ m_nCurrentFrame = nFrame; }
	xint32					GetCurrentFrame()const{ return m_nCurrentFrame; }

	// Slice
	virtual void			Enable9Slice(xbool bSet);
	virtual xbool			Is9SliceEnabled()const;
	virtual void			SetSliceLeft(xfloat32 fLeft);
	virtual xfloat32		GetSliceLeft()const;
	virtual void			SetSliceRight(xfloat32 fRight);
	virtual xfloat32		GetSliceRight()const;
	virtual void			SetSliceTop(xfloat32 fTop);
	virtual xfloat32		GetSliceTop()const;
	virtual void			SetSliceBottom(xfloat32 fBottom);
	virtual xfloat32		GetSliceBottom()const;
	// serilize
	virtual xbool			SerilizeSelfXML(XXMLExtendTool& outXmlArchive) override;

	// new
	void					SetTListUV(const XVECTOR2& vLT, const XVECTOR2& vBR);
	void					GetTlistUV(XVECTOR2& vLT, XVECTOR2& vBR);
	XUIImageDirtyFlag		GetDirtyFlag();
	void					SetDirtyFlag(XUIImageDirtyFlag eFlag);
	void					CleanUpdateTransform();

	const XVECTOR2&			GetVertexPosLT()const;
	const XVECTOR2&			GetVertexPosBR()const;
	XVECTOR2				GetVertexUVLT()const;
	XVECTOR2				GetVertexUVBR()const;

	const XUITexture*		GetUITexture()const;
protected:
	virtual xbool			Init() override;
	virtual xbool			Init(xint32 nTag, const XString& strTextureName, TextureResType texType = TextureResType::XUI_LOCAL);
	virtual void			UpdateColor();
	virtual XUINode*		CreateClonedInstance() override;
	virtual void			CopyProperties(XUINode* pNode)override;
	void					ShowCurrentTexture();
	void					LoadTexture(xint32 nTag, IXTexture2D* pTexture, const XString& strPath, TextureResType texType = TextureResType::XUI_LOCAL);
	void					UpdateVertexPos();
	void					UpdateVertexUV();
	void					UpdateDirtyFlag(XUIImageDirtyFlag eFlag);
protected:
	xbool					m_bUseTexture;
	XHashTable<xint32, XUITexture*>	m_tbTexture;
	xint32					m_nCurrentTag;
	xbool					m_bFollowTextureSize;

	xbool					m_bUseSequence;
	XVECTOR2				m_vUVTile;
	xfloat32				m_fFPS;
	xint32					m_nActualFrameNum;
	xint32					m_nCurrentFrame;
	xfloat32				m_fTickTotalTime;
	xbool					m_bPlaySequence;

	XVECTOR2				m_vLTPercent;
	XVECTOR2				m_vBRPercent;
	XVECTOR2				m_vLTPos;
	XVECTOR2				m_vBRPos;
	xbool					m_bFlipX;

	xbool					m_bEnable9Slice;
	xfloat32				m_fSliceLeft;
	xfloat32				m_fSliceRight;
	xfloat32				m_fSliceTop;
	xfloat32				m_fSliceBottom;

	XVECTOR2				m_vTListUVLT;
	XVECTOR2				m_vTListUVBR;

	XUIImageDirtyFlag		m_eDirtyFlag;
	XUITexture*				m_pCurrentUITexture;
};

#endif
