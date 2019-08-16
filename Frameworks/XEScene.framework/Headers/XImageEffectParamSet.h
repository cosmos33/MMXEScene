#ifndef _X_IMAGE_EFFECT_PARAMETER_SET_H_
#define _X_IMAGE_EFFECT_PARAMETER_SET_H_

#include "XMaterial.h"

class XImageEffectParamSet : public IXMaterialInstance
{
public:
	XImageEffectParamSet() : m_aParamDescs(4, 4), m_aParams(4, 4) {}
	virtual ~XImageEffectParamSet() {}

	// IXResource interface
	virtual XResType							Type() const override { return XRES_MATERIAL_INSTANCE; }
	virtual xint32								GetResourceIdx() const { return -1; }
	virtual void								SetResourceIdx(xint32 nIdx) {}
	virtual xbool								IsDynamic() const { return xfalse; }
	virtual void								Update() {}

	// IXMaterialInstance interface
	virtual void								Release() override {}

	virtual IXMaterial*							GetMaterialPtr() const override { return NULL; }
	virtual const xchar*						GetMaterialInsFile() const override { return NULL; }

	virtual xint32								GetParameterCount() const override { return m_aParams.Num(); }

	virtual const XMaterialParamDescInfo*		GetParameterDescInfoByParamName(const xchar* szName) const override;
	virtual const XMaterialParamDescInfo*		GetParameterDescInfoByParamId(xint32 id) const override;

	virtual const xint32						GetParameterIdByParamName(const xchar* szName) const override;

	virtual const XMaterialParamTypeValue&		GetParameterByParamId(xint32 iId) const override;
	virtual const XMaterialParamTypeValue&		GetParameterByParamName(const xchar* szName) const override;

	virtual void								SetParameterByParamName(const xchar* szName, const XMaterialParamTypeValue& val) override;
	virtual void								SetParameterByParamId(xint32 id, const XMaterialParamTypeValue& val) override;

	virtual void								SetTextureParameterByParamName(const xchar* szName, IXTexture* pTexture) override;
	virtual void								SetTextureParameterByParamId(xint32 id, IXTexture* pTexture) override;

	virtual xbool								IsMacroEnabled(xint32 id) override { return xfalse; }
	virtual void								EnabledMacro(xint32 id, xbool bEnable) override {}

	virtual xbool								ChangeMtl(const xchar* szMaterialFile) override { return xfalse; }
	virtual xbool								ApplyAndUpdateMaterial(const IXMaterialInstance* pSrcMtlIns) override { return xfalse; }

	virtual xbool								IsCastShadow() const override { return xfalse; }

	virtual void								AddParameter(const XMaterialParamDescInfo& desc, const XMaterialParamTypeValue& val);


protected:
	XArray<XMaterialParamDescInfo>				m_aParamDescs;
	XArray<XMaterialParamTypeValue>				m_aParams;
};

#endif // !_X_IMAGE_EFFECT_PARAMETER_H_
