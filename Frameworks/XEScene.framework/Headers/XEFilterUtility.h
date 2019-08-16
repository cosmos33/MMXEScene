/******************************************************************************

@File         XEFilterUtility.h

@Version       1.0

@Created      2019, 6, 22

@HISTORY:    Filter node

******************************************************************************/
#ifndef _XE_FILTER_UTILITY_H_
#define _XE_FILTER_UTILITY_H_
#include "XLinkList.h"
#include "XMaterial.h"

class XEFilterInstance;
class IXVertexBuffer;
class XVertexDesc;
class XIndexBuffer16;

enum XEVertElementType
{
	XEVET_FLOAT1,
	XEVET_FLOAT2,
	XEVET_FLOAT3,
	XEVET_FLOAT4,
	XEVET_COLOR
};

enum XEVertElementUsage
{
	XEVEU_POSITION,
	XEVEU_BLENDWEIGHT,
	XEVEU_BLENDINDICES,
	XEVEU_NORMAL,
	XEVEU_PSIZE,
	XEVEU_TEXCOORD,
	XEVEU_TANGENT,
	XEVEU_BINORMAL,
	XEVEU_TESSFACTOR,
	XEVEU_POSITIONT,
	XEVEU_COLOR,
	XEVEU_FOG,
	XEVEU_DEPTH,
	XEVEU_SAMPLE
};


namespace XEFilterUtility
{
	enum FilterNodeType{ FILTER_DONTCARE, FILTER_PRE_PROCESS, FILTER_POST_PROCESS };
	typedef XLinkList<XEFilterInstance> InstanceListFilterNode;
	struct XEFilterShaderAsset
	{
		xbool IsValid()const{ return !strAssetPathMaterialDesc.IsEmpty() && strAssetPathMaterialDesc != "None"; }
		XString strAssetPathShaderVSFile;
		XString strAssetPathShaderPSFile;
		XString strAssetPathMaterialDesc;
		void UpdateAsset(const XEFilterShaderAsset& rh)
		{
			strAssetPathShaderVSFile = rh.strAssetPathShaderVSFile;
			strAssetPathShaderPSFile = rh.strAssetPathShaderPSFile;
			strAssetPathMaterialDesc = rh.strAssetPathMaterialDesc;
		}
		xbool operator==(const XEFilterShaderAsset& rh) const
		{
			return strAssetPathShaderVSFile.Compare(rh.strAssetPathShaderVSFile) == 0 &&
				strAssetPathShaderPSFile.Compare(rh.strAssetPathShaderPSFile) == 0 &&
				strAssetPathMaterialDesc.Compare(rh.strAssetPathMaterialDesc) == 0;
		}
	};

	struct XEFacePointOffset
	{
		xint32 nKeypointIndex;//face point index
		xbool  bIsLockd;//whether it was Lock
	};

	struct XEZoomKeypoint
	{
		enum ZoomArea{ ZA_FREE_HAND, ZA_LEFT_EYE, ZA_RIGHT_EYE, ZA_FACE};
		XArray<xint32> arrKeypointIndices;
		XArray<xfloat32> arrKeypointWeights;//will be multiplied by the intensity
		xint32 nPivotIndex;//-1 means the center of the keypoints
		xfloat32 fIntensity;
		xbool bEnable;
		ZoomArea eZoomAreaType;
		xbool IsValid()const{ return arrKeypointIndices.Num() > 0 && arrKeypointWeights.Num() == arrKeypointIndices.Num(); }
		void Clear(){ arrKeypointIndices.Clear(); arrKeypointWeights.Clear();  nPivotIndex = -1, fIntensity = 1.f; eZoomAreaType = ZA_FREE_HAND; bEnable = xfalse; }
		XEZoomKeypoint() :eZoomAreaType(ZA_FREE_HAND), nPivotIndex(-1), fIntensity(1.f), bEnable(xtrue){}
	};
	typedef XArray<XEZoomKeypoint> ZoomKeyPointList;

	xbool ZoomKeyPointByIntensityAndPivot(xfloat32 fZoomIntensity, XEZoomKeypoint* pZoomKeyPoint, xfloat32* pOriginFaceKeypoint, xint32 nKeyPointNum);

	ZoomKeyPointList& GetZoomKeyPoint96List();
	ZoomKeyPointList& GetZoomKeyPoint137List();
	XEZoomKeypoint*   GetZoomKeyPoint(XEZoomKeypoint::ZoomArea eZAType, xint32 nKeypointNum);


	struct XEEyeShapeInfo
	{
		xint32 nLeftIndexEyeA;// left eye's left index
		xint32 nRightIndexEyeA; // left eye's right index
		xint32 nLeftIndexEyeB; // right eye's left index
		xint32 nRightIndexEyeB; // right eye's right index
		XEEyeShapeInfo(){}
		XEEyeShapeInfo(xint32 nLeftEyeA, xint32 nRightEyeA, xint32 nLeftEyeB, xint32 nRightEyeB)
			:nLeftIndexEyeA(nLeftEyeA)
			, nRightIndexEyeA(nRightEyeA)
			, nLeftIndexEyeB(nLeftEyeB)
			, nRightIndexEyeB(nRightEyeB)
		{}
	};

	XEEyeShapeInfo  GetEyeShapeInfoFor96();
	XEEyeShapeInfo  GetEyeShapeInfoFor137();

	void DoShapeEyeProcess(XEZoomKeypoint* Zkp,XArray<xfloat32>& aLandMarks);
	//all for conveniently useing for lua.
	//all index is start from 1
	class XEVaraintVertex
	{
	public:
		XEVaraintVertex();
		~XEVaraintVertex();
	public:
		struct ElementDesc
		{
			ElementDesc() :nIndex(0), eElementType(XEVET_FLOAT3), eElementUsage(XEVEU_POSITION){}
			ElementDesc(xint32 _i, XEVertElementType _vet, XEVertElementUsage _veu,xint32 nUsageIndex)
				:nIndex(0), eElementType(_vet), eElementUsage(_veu), nUsageIdx(nUsageIndex){}

			xint32 GetFloatNum()const;
			xint32 GetSize()const;
			xint32 nIndex;
			XEVertElementType  eElementType ;//enum XVertElementType
			XEVertElementUsage eElementUsage;//enum XVertElementUsage
			xint32			   nUsageIdx;
		};
	public:
		xint32               AddVertexElementDesc(XEVertElementType eleType, XEVertElementUsage eleUsage, xint32 nUsageIdx = 0);
		xint32               GetVertexElementsCount() const;
		xint32               CalculateCurrentDescFloatCount() const;
		xint32               SizeofOneVertex()const;
		xbool                RemoveVertexElementDesc(xint32 nVertexDescIndex);//start from 1, please
	public:
		void                 Release();
		xbool                RebulidVertexDesc();//warning! all vertex data will be cleared!
	public:
		//buffer operation
		//should be used as a group
		void                 ClearFloatTempBuffer();
		void                 SetFloatTempBufferVal(xint32 nIndex, xfloat32 fVal);//start from 1, please
		xfloat32             GetFloatTempBufferVal(xint32 nIndex);//start from 1, pleas
		xint32               GetFloatTempBufferNum();
	public:
		xbool                AddVertWithCurrentFloatTempBuffer(xbool bClearTempBufferAfterUsed = xtrue);
		xbool                UpdateElementWithCurrentFloatTempBuffer(xint32 nVertexIndex, xbool bClearTempBufferAfterUsed = xtrue);//start from 1, please
		xbool                Update();//update to the vertex.
	public:
		//indices
		void                 AddIndex(xint32 nIndex);//start from 1, please
		void                 ClearIndices();
	public:
		IXVertexBuffer*      GetVertexBuffer();
		XVertexDesc*         GetVertexDesc();
		XIndexBuffer16*      GetIndexBuffer();
	private:
		XArray<ElementDesc>  m_aVertexDesc;
		XIndexBuffer16*      m_pIndexBuffer;
		IXVertexBuffer*      m_pVertexBuffer;
		XVertexDesc*         m_pVertexDesc;
		XArray<xfloat32>     m_aTempFloatBuffer;
	};
}


#endif // _XE_FILTER_UTILITY_H_
