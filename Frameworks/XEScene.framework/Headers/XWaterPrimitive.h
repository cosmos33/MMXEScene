#ifndef _XWATERPRIMITIVE_H_
#define _XWATERPRIMITIVE_H_

#include "XPrimitiveBase.h"
#include "XObject.h"

struct XWaterDesc
{
	XWaterDesc()
		: nWidthBlock(1)
		, nLengthBlock(1)
		, fBlockSize(100.0f)
		, vCenter(XVECTOR3(0.0f))
		, fNormalScale(1.0f)
		, vNormalSpeed0(XVECTOR2(0.02f, 0.02f))
		, vNormalSpeed1(XVECTOR2(-0.02f, 0.02f))
		, colWater(XCOLORBASE(0.14, 0.31, 0.33, 0.5))
		, vLightDir(0.0f, 1.0f, 0.0f)
		, colLight(1.0f, 1.0f, 1.0f, 1.0f)
		, fSpecularPower(100.0)
		, fFresnelBase(0.1f)
		, fFresnelPower(5.0f)
		, strNormalTexture0("")
		, strNormalTexture1("")
		, strReflectTexture("")
	{}
	xint32			nWidthBlock;
	xint32			nLengthBlock;
	xfloat32		fBlockSize;
	XVECTOR3		vCenter;
	xfloat32		fNormalScale;
	XVECTOR2		vNormalSpeed0;
	XVECTOR2		vNormalSpeed1;
	XCOLORBASE		colWater;
	XVECTOR3		vLightDir;
	XCOLORBASE		colLight;
	xfloat32		fSpecularPower;
	xfloat32		fFresnelBase;
	xfloat32		fFresnelPower;
	XString			strNormalTexture0;
	XString			strNormalTexture1;
	XString			strReflectTexture;
};

class IXWater : public IXPrimitiveBase, public IXObject
{
public:
	static IXWater* CreateWater(const XWaterDesc& Desc);
	virtual void	Tick(xfloat32 fTime) = 0;

	virtual xbool				SetWaterDesc(const XWaterDesc& pWaterDesc) = 0;
	virtual const XWaterDesc&	GetWaterDesc() const = 0;

	virtual xfloat32			GetNormalScale() const = 0;
	virtual void				SetNormalScale(xfloat32 fNormalScale) = 0;

	virtual const XVECTOR2&		GetNormalSpeed0() const = 0;
	virtual void				SetNormalSpeed0(const XVECTOR2& vNormalSpeed0) = 0;

	virtual const XVECTOR2&		GetNormalSpeed1() const = 0;
	virtual void				SetNormalSpeed1(const XVECTOR2& vNormalSpeed1) = 0;

	virtual const XCOLORBASE&	GetWaterColor() const = 0;
	virtual void				SetWaterColor(const XCOLORBASE& colWater) = 0;

	virtual const XVECTOR3&		GetLightDir() const = 0;
	virtual void				SetLightDir(const XVECTOR3& vLightDir) = 0;
	
	virtual const XCOLORBASE&	GetLightColor() const = 0;
	virtual void				SetLightColor(const XCOLORBASE& colLight) = 0;
	
	virtual xfloat32			GetSpecularPower() const = 0;
	virtual void				SetSpecularPower(xfloat32 fSpecularPower) = 0;

	virtual xfloat32			GetFresnelBase() const = 0;
	virtual void				SetFresnelBase(xfloat32 fFresnelBase) = 0;

	virtual xfloat32			GetFresnelPower() const = 0;
	virtual void				SetFresnelPower(xfloat32 fFresnelPower) = 0;

	virtual const XString&		GetReflectTextureName() const = 0;
	virtual xbool				SetReflectTextureName(const XString& strReflectTexture) = 0;

	virtual const XString&		GetNormalTexture0Name() const = 0;
	virtual xbool				SetNormalTexture0Name(const XString& strNormalTexture0) = 0;

	virtual const XString&		GetNormalTexture1Name() const = 0;
	virtual xbool				SetNormalTexture1Name(const XString& strNormalTexture1) = 0;
};

#endif