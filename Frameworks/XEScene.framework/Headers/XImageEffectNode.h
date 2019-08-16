#ifndef _X_IMAGE_EFFECT_NODE_H_
#define _X_IMAGE_EFFECT_NODE_H_

#include "XTypes.h"
#include "XResource.h"
#include "XImageEffectNodeFactory.h"

enum ENodeInputId
{
	ePId_Input0,
	ePId_Input1,
	ePId_Input2,
	ePId_Input3,
	ePId_Input4,
	ePId_Input5,
	ePId_Input6,
	ePId_Input_MAX
};

enum ENodeOutputId
{
	ePId_Output0,
	ePId_Output1,
	ePId_Output2,
	ePId_Output3,
	ePId_Output4,
	ePId_Output5,
	ePId_Output6,
	ePID_Output_MAX
};

struct XRenderTargetDesc
{
	XTexFormat	format;
	xint32		width;
	xint32		height;

	XRenderTargetDesc(XTexFormat _format = XTF_R8G8B8A8, xint32 _width = 1, xint32 _height = 1)
		: format(_format), width(_width), height(_height) {}

	xbool		IsValid() const
	{
		return ((format == XTF_R8G8B8 || format == XTF_R8G8B8A8) && width > 0 && height > 0);
	}

	// Check if equals to another desc
	xbool		Compare(const XRenderTargetDesc& rhs) const
	{
		return (format == rhs.format && width == rhs.width && height == rhs.height);
	}
};

//-------------------------------------------------------------------------------------
//
//	XImageEffectOutput
//
//-------------------------------------------------------------------------------------
class IXRenderTarget;
class IXPooledRenderTarget;
class XImageEffectOutput
{
public:
	XImageEffectOutput();
	~XImageEffectOutput() {}

	void							AddDependency();
	void							ResolveDependency();
	xint32							GetDependencyNum() const { return m_nDependencyNum; }

	// Get the texture to read from
	IXPooledRenderTarget*			RequestInput();

	// Get the surface to write to
	IXRenderTarget*					RequestSurface();

	const XRenderTargetDesc&		GetRenderTargetDesc() const { return m_RenderTargetDesc; }
	void							SetRenderTargetDesc(const XRenderTargetDesc& desc);

private:
	XRenderTargetDesc				m_RenderTargetDesc;
	IXPooledRenderTarget*			m_pRenderTarget;
	xint32							m_nDependencyNum;
};

//-------------------------------------------------------------------------------------
//
//	XImageEffectOutputRef
//
//-------------------------------------------------------------------------------------
class XImageEffectNode;
class XImageEffectOutputRef
{
public:
	XImageEffectOutputRef(XImageEffectNode* pOutputNode = NULL, ENodeOutputId eOutputId = ePId_Output0)
		: m_pOutputNode(pOutputNode), m_eOutputId(eOutputId) {}

	XImageEffectOutput*			GetOutput() const;
	XImageEffectNode*			GetNode() const;

	xbool						IsValid() const;

private:
	XImageEffectNode*			m_pOutputNode;
	ENodeOutputId				m_eOutputId;
};

//-------------------------------------------------------------------------------------
//
//	XImageEffectNode
//
//-------------------------------------------------------------------------------------
class IXMaterialInstance;
class XImageEffectNode
{
public:
	XImageEffectNode() : m_bComputeOutputDescWasCalled(xfalse), m_bProcessWasCalled(xfalse) {}
	virtual							~XImageEffectNode() {}

	virtual	void					SetInput(ENodeInputId eInputId, const XImageEffectOutputRef& outputRef) = 0;
	virtual XImageEffectOutput*		GetOutput(ENodeOutputId eOutputId) = 0;
	virtual XImageEffectOutputRef*	GetDependency(xuint32 nIndex) = 0;

	// Functions below need implementation in sub-class
	virtual XRenderTargetDesc		ComputeOutputDesc(ENodeOutputId eOutputId) const = 0;
	virtual void					Process() = 0;
	virtual IXMaterialInstance*		GetParameterSet() = 0;
	virtual const xchar*			GetTypeName() const = 0;

protected:
	xbool							m_bComputeOutputDescWasCalled;
	xbool							m_bProcessWasCalled;

	friend class XImageEffectGraph;
};

//-------------------------------------------------------------------------------------
//
//	XImageEffectNodeBase: custom image effect inherits from this class
//
//-------------------------------------------------------------------------------------
template<xint32 nInputNum, xint32 nOutputNum>
class XImageEffectNodeBase : public XImageEffectNode
{
public:
	XImageEffectNodeBase() {}
	virtual ~XImageEffectNodeBase() {}

	virtual void							SetInput(ENodeInputId eInputId, const XImageEffectOutputRef& outputRef) override
	{
		if ((xint32)eInputId < nInputNum)
		{
			m_aNodeInputs[eInputId] = outputRef;
		}
		else
		{
			ASSERT(xfalse);
		}
	}

	virtual XImageEffectOutputRef*			GetInput(ENodeInputId eInputId)
	{
		if ((xint32)eInputId < nInputNum)
		{
			return &m_aNodeInputs[eInputId];
		}

		return NULL;
	}

	virtual const XImageEffectOutputRef*	GetInput(ENodeInputId eInputId) const
	{
		if ((xint32)eInputId < nInputNum)
		{
			return &m_aNodeInputs[eInputId];
		}

		return NULL;
	}

	virtual XImageEffectOutput*				GetOutput(ENodeOutputId eOutputId) override
	{
		if ((xint32)eOutputId < nOutputNum)
		{
			return &m_aNodeOutputs[eOutputId];
		}

		return NULL;
	}

	virtual XImageEffectOutputRef*			GetDependency(xuint32 nIndex) override
	{
		if (nIndex < nInputNum)
		{
			return &m_aNodeInputs[nIndex];
		}

		return NULL;
	}


private:
	XImageEffectOutput						m_aNodeOutputs[nOutputNum];
	XImageEffectOutputRef					m_aNodeInputs[nInputNum == 0 ? 1 : nInputNum];
};

#endif