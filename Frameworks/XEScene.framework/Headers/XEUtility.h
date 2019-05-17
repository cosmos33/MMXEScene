/******************************************************************************

@File         XEUtility.h

@Version       1.0

@Created      2017, 10, 12

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/

#ifndef _XE_UTILITY_H_
#define _XE_UTILITY_H_
#include "XEHitResult.h"
#include "XCustomGeometry.h"
#include "XArray.h"
#include "XHashTable.h"
#include "XMaterial.h"
#include "XModel.h"
#include "XModelInstance.h"
#include "tinyxml2_XEngine.h"
#include "XPlatform.h"
#include <string>
#include "IXPhysicsRes.h"
#include "XClass.h"
#include "XEViewport.h"

class XEWorld;
class XEAnimatableModelComponent;
class XEActorComponent;
class XEModelComponent;
class XEViewport;
class XViewport;
class XBaseCamera;
class XESceneARAdsVideoComponent;
class XEAnimCurveFlyController;

struct XEMacroRelationParamInfo
{
	XString strMacro;
	XArray<XString> vRelationParam;
	XArray<XString> vEliminateParam;
};

namespace XEUtility
{
	xbool								  GetTriangleFaceInfoByUV(IXModelInstance* pModelIns, const xchar* szMeshName, const xchar* szSkinName, XVECTOR2 uv, xint32& nOutTriIndex, XSkinMeshVertex outVertices[3],xint32 outVerIndices[3]);
	xbool                                 GetVertexPositionFromIndex(IXModelInstance* pModelIns, const xchar* szMeshName, const xchar* szSkinName, xint32 nVertexIndex, XVECTOR3& vOutPos);
	xbool                                 GetVertexIndexFromUV(IXModelInstance* pModelIns, const xchar* szMeshName, const xchar* szSkinName, XVECTOR2 uv, xint32& vOutVertexIndex);
	xbool                                 GetVertexPositionFromUV(IXModelInstance* pModelIns, const xchar* szMeshName, const xchar* szSkinName, XVECTOR2 uv, XVECTOR3& vOutPos);
	xbool                                 GetHitResultAtScreenPosition(const XVECTOR2& ScreenPosition, XEWorld* pWorld, XEHitResult& HitResult, XArray<XEActor*>* pActorsExclude = NULL);//deprecated  Do not use this function - it is deprecated in release 1.2.17. Instead, use XEWorld::RayPick instead[collision channel supported]
	xbool                                 LookAtActorWithCurrentCameraRotation(const XEActor* pActor, const xfloat32 fMultiNum = 1.f);
	xbool                                 LookAtComponentWithCurrentCameraRotation(const XEActorComponent* pComponent, const XEWorld* pWorld, const xfloat32 fMultiNum = 1.f);
	xbool                                 LookAtBoundBoxWithCurrentCameraRotation(const XCusAABB& box, const XEWorld* pWorld, const xfloat32 fMultiNum = 1.f);
	xbool                                 LookAtBoundSphereWithCurrentCameraRotation(const XCusSphere& sphere, const XEWorld* pWorld, const xfloat32 fMultiNum = 1.f);
	XArray<XString>&                      GetMaterialTemplate();
	XHashTable<XString, XEMacroRelationParamInfo>& GetMaterialShaderParamMacroRelation();
	xbool                                 IsShaderParamRelatedToMacro(const XString& strParamName, const XString& strMacroName);
	xbool								  IsShaderParamEliminateByMacro(const XString& strParamName, const XString& strMacroName);
	void                                  MakeNameLegalForLua(std::string& szName);
	XEAnimCurveFlyController*             GetCameraFlyAnimCurveController();
	XEAnimCurveFlyController*             GetActorFlyAnimCurveController();
	XEAnimCurveFlyController*             GetActorComponentFlyAnimCurveController();    
    template<typename T>
    void                                  GetRealPositionOfWindow(XEViewport* viewport, T& pos) { pos = pos * viewport->GetWindowScale(); }
    
    
    //canvas & cast ray, etc.
    //may consider the different platforms also.
	void                                  CastRay(XViewport* pViewport, const XVECTOR3& vecScreenPoint, XVECTOR3& vecStart, XVECTOR3& vecDir);
    xfloat32                              PointToLineDistance(const XVECTOR3& vecPoint, const XVECTOR3& vecLinePoint, const XVECTOR3& vecLineDirection, xfloat32* pFraction = NULL);
    void			                      DrawString(xint32 x, xint32 y, const xchar* szString, const XCOLORBASE& clr);
    void                                  DrawQuad(xint32 x, xint32 y, xint32 nWidth, xint32 nHeight, const XCOLORBASE& clr, xbool bSolid = xfalse, XMATRIX3 *pMat = NULL);
    void                                  Render2DLine(xint32 xBegin, xint32 yBegin, xint32 xEnd, xint32 yEnd, const XCOLORBASE& clr, XMATRIX3 *pMat = NULL);
    void                                  Render2DCircle(const XVECTOR2& vPos, xfloat32 fRadius, const XVECTOR2& vStartNormalizedDir,const XVECTOR2& vEndNormalizedDir, const XCOLORBASE& color, xbool bClockWise = xtrue, xbool bSolid = xfalse, XMATRIX3 *pMat = NULL);

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	xbool                                 GetActorAnimationSequenceResources(const XEActor* pAnimationActor, XArray<XString>& arrSeqRes);
	xbool                                 GetComponentAnimationSequenceResources(const XEAnimatableModelComponent* pAnimatableComponent, XArray<XString>& arrSeqRes);
	xbool                                 GetClothResources(const XEAnimatableModelComponent* pAnimatableComponent, XArray<XString>& arrClothRes);
	xbool                                 GetResourcesWithSuffix(XArray<XString>& arrResource, const xchar* pDirPath, const xchar* pSuffix, xbool bRelativeToResourcePath = xtrue);//suffix is with the format of "*.xxx", if bRelativeToResourcePath is set to true, will auto append the relative to the resource path.
	xbool                                 GetComponentVideoResources(const XESceneARAdsVideoComponent* pAnimatableComponent, XArray<XString>& arrVideoRes);
	xbool                                 GetComponentARAdsResources(const XEModelComponent* pSkinModelComponent, XArray<XString>& arrARAdsRes);
	xbool                                 GetComponentMontageAnimationResources(const XEModelComponent* pSkinModelComponent, XArray<XString>& arrMontageAnimRes);
	xbool                                 GetComponentMounterResources(const XEModelComponent* pSkinModelComponent, XArray<XString>& arrMounters);
	xbool                                 GetComponentBlendAnimationResources(const XEModelComponent* pSkinModelComponent, XArray<XString>& arrBlendAnimRes);
#endif
	XQUATERNION                           GetCameraQuaternion(XBaseCamera* pCamera);
	XMATRIX4                              GetCameraWorldMatrix(XBaseCamera* pCamera);
	XArray<XVECTOR3>                      GetCircleTrackPoint(const XVECTOR3 vCenter = XVECTOR3(0.f), const xfloat32 fRadius = 1.f, const xint32 nSegment = 32);
	XArray<XVECTOR3>                      GetCrossRectTrackPoint(const XVECTOR3 vCenter = XVECTOR3(0.f), const xfloat32 fRadius = 1.f);
	XArray<XVECTOR3>                      GetSinTrackPoint(const XVECTOR3 vCenter = XVECTOR3(0.f), const xfloat32 fAmplitude = 1.f, const xfloat32 fPeriod = 1.f);
	XArray<XVECTOR2>                      GetDrawPointOfLookingLocationAtScreen(XEWorld* pWorld, const XVECTOR3& vLocation, const xint32 nInnerPixel = 128);//0 is the location projecting in the screen. others will be the intersecting points.
	xbool                                 GetViewPointOfLookingLocationAtScreen(XEWorld* pWorld, XVECTOR2& vOutPointStart, XVECTOR2& vOutPointEnd, const XVECTOR3& vLocation, const xint32 nInnerPixel = 128);//if location is can be seen, return 0,else 1. output the direction(vOutPointStart,vOutPointEnd)
	void                                  MakePathSimple(XArray<XString>& fullPaths);
	XString                               GetAssetPackageValidPath(const xchar* pFullRelativeAssetPackagePath, const xchar* pEvalAssetPath, xbool bNoRepeatPortionPath = xfalse);//evaluate the input asset path for the relative package(usually come from worlds).
	//create mesh applique
	xbool								  GetSkinNames(IXModelInstance* pModelIns, XArray<XString>& aSkinNames);
	xbool								  GetMeshNames(IXModelInstance* pModelIns, XArray<XString>& aMeshNames);
	xbool								  IsExistActorInActorList(const XEActor* pActor, const XArray<XEActor*>& aActorList);

	template<typename T>
	XString                               GetArrayValidName(const XArray<T*>& arrData, const xchar* pPrefix = "ArrayValidName", const xint32 nMaxIndex = 0xffff)
	{
		XString validName;
		if (NULL != pPrefix)
		{
			for (xint32 i = 1; i < nMaxIndex; i++)
			{
				validName.Format("%s_%d", pPrefix, i);
				xbool bExist = xfalse;
				for (xint32 i = 0; i < arrData.Num(); ++i)
				{
					if (T* pData = arrData[i])
					{
						if (0 == pData->GetName().CompareNoCase(validName.CStr()))
						{
							bExist = xtrue;
							break;
						}
					}
				}
				if (xfalse == bExist)
					return validName;
			}
		}
		validName.Empty();
		return validName;//empty
	}
	
	//go through material in a model instance.
	struct MaterialKey{
		xint32 skinId;
		xint32 lodId;
		xint32 meshId;
		xint32 macroId;
		xint32 parameterId;
		MaterialKey() :skinId(0),lodId(0),meshId(0),macroId(-1),parameterId(0){}
		MaterialKey(xint32 _sid, xint32 _lid, xint32 _meid, xint32 _maid, xint32 _pid) :skinId(_sid), lodId(_lid), meshId(_meid), macroId(_maid), parameterId(_pid){}
		xbool operator == (const MaterialKey& mk)const{ return skinId == mk.skinId && lodId == mk.lodId && meshId == mk.meshId && parameterId == mk.parameterId; }//NOTE:(2018/11/7)unnecessary for macroId comparing.
	};

	struct MaterialInfo{
		MaterialKey key;
		XSkin* pSkin;
		IXMaterialInstance* pIns;
		XMaterialSupportMacro*  pMacro;
		XMaterialParamDescInfo* pParamDescInfo;
		XMaterialParamTypeValue paramTypeValue;
		xbool                   bValid;
		MaterialInfo() :pSkin(NULL), pIns(NULL), pMacro(NULL), pParamDescInfo(NULL), bValid(xfalse){}
	};

X_EEB_BEGIN
	typedef xbool(*checkItemMatch)(void* holder, MaterialInfo& materialInfo);
	void									TravelMaterialParameter(IXModelInstance* pModelIns,void*  pHolder, checkItemMatch checkFunc);
X_EEB_END

	//apply the specific value for the parameter.
	xbool									ApplyMaterialParameter(IXModelInstance* pModelIns, const MaterialKey& mk, xint32 nParamIndex, xfloat32 fParamVal);
	xbool									ApplyMaterialParameter(IXModelInstance* pModelIns, const MaterialKey& mk, const xchar* pTexPath);
	//szMTPath/szTexPath full relative path to the engine root
	//will match to the name
	xbool									ApplyMaterialType(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName, const xchar* szMTPath);
	xbool									ApplyMaterialTextureParameterValue(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName, const xchar* szParamDesc, const xchar* szTexPath);
	xbool									ApplyMaterialVectorParameterValue(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName, const xchar* szParamDesc, const XVECTOR4& valueSlot);//as max as xvector4
	xbool									ApplyMaterialVectorParameterValue(IXMaterialInstance *pMaterialIns, const xchar* szParamDesc, const XVECTOR4& valueSlot);
	//get method
	const xchar*							GetMaterailType(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName);
	const xchar*							GetMaterailTextureParameterValue(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName, const xchar* szParamDesc);
	XVECTOR4								GetMaterialVectorParameterValue(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName, const xchar* szParamDesc);
	MaterialInfo							GetMaterialParamTypeValue(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar* szMaterialInsName, const xchar* szParamDesc);

	xbool									ApplyMaterailInsParamToOther(const IXMaterialInstance *pSourceMaterialIns, IXMaterialInstance *pDestMaterialIns);
	xbool									GetRawMeshNameByMaterialInsName(IXModelInstance* pModelIns, const xchar* szSkinName, const xchar *szMaterialInsName, xint32 nLod, XArray<XString> &vRawMeshName);
		
	EConstraintMotion						GetConstraintMotionTypeByName(const XString& str);
	const XArray<XString>&					GetConstraintMotionNameList();

	IXSkeletalPhysicsRes::EPhysResFitVertWeight		GetPhysResFitVertWeightTypeByName(const XString& str);
	const XArray<XString>&					GetAllPhysResFitVertWeightType();
	const XArray<XString>&					GetAllShapeMaterialParams();



	class XEBinaryString
	{
	public:
		XEBinaryString();
		~XEBinaryString();
	public:
		const xchar*            BinaryToString(void * pData, xint32 nlen );
		xbool		            StringToBinary(const xchar * pString, void * pData, xint32 iDataBufSize);
		xbool		            IsChar(xchar ch);
	protected:
		xchar*      m_pBuffer;
		xuint32		m_dwBufferSize;
	};

	//TemporalObject, usually for delay-destroying...
	class XETemporalObject
	{
	public:
		XETemporalObject(){}
		virtual ~XETemporalObject(){}
		//functions that should be override.
		virtual xbool ShouldBeDeleted() = 0;
		virtual void  Release() = 0;
		virtual void  Tick(xfloat32 fDel){}//in milliseconds.
		virtual void  Render(XEViewport* pViewport){}
	};
	typedef XArray<XETemporalObject*> TemporalObjectList;
	//vectors.
	template<typename T, int n>
	class XEVector
	{
	public:
		XEVector(){ Clear(); }
		XEVector(const T& t){ for (xint32 i = 0; i < n; ++i) m[i] = t; }
		XEVector(const T& t1, const T& t2){ if (1 <= n) m[0] = t1; if (2 <= n) m[1] = t2; }
		XEVector(const T& t1, const T& t2, const T& t3){ if (1 <= n) m[0] = t1; if (2 <= n) m[1] = t2; if (3 <= n) m[2] = t3; }
		XEVector(const T& t1, const T& t2, const T& t3, const T& t4){ if (1 <= n) m[0] = t1; if (2 <= n) m[1] = t2; if (3 <= n) m[2] = t3; if (4 <= n) m[3] = t4; }
		void Clear(){ memset(m, 0, n * sizeof(T)); }
		T m[n];
		T* X(){ return 1 <= n ? &m[0] : NULL; }
		T* Y(){ return 2 <= n ? &m[1] : NULL;  }
		T* Z(){ return 3 <= n ? &m[2] : NULL;  }
		T* W(){ return 4 <= n ? &m[3] : NULL;  }
		const T* X()const{ return 1 <= n ? &m[0] : NULL; }
		const T* Y()const{ return 2 <= n ? &m[1] : NULL; }
		const T* Z()const{ return 3 <= n ? &m[2] : NULL; }
		const T* W()const{ return 4 <= n ? &m[3] : NULL; }
	};

	template<typename T, int n>
	class XEVectorM
	{
	public:
        XEVectorM(){ Clear(); }
        XEVectorM(const T& t){ for (xint32 i = 0; i < n; ++i) m[i] = t; }
        XEVectorM(const T& t1, const T& t2){ if (1 <= n) m[0] = t1; if (2 <= n) m[1] = t2; }
        XEVectorM(const T& t1, const T& t2, const T& t3){ if (1 <= n) m[0] = t1; if (2 <= n) m[1] = t2; if (3 <= n) m[2] = t3; }
        XEVectorM(const T& t1, const T& t2, const T& t3, const T& t4){ if (1 <= n) m[0] = t1; if (2 <= n) m[1] = t2; if (3 <= n) m[2] = t3; if (4 <= n) m[3] = t4; }
        void Clear(){ memset(m, 0, n * sizeof(T)); }
        T m[n];
        T* X(){ return 1 <= n ? &m[0] : NULL; }
        T* Y(){ return 2 <= n ? &m[1] : NULL;  }
        T* Z(){ return 3 <= n ? &m[2] : NULL;  }
        T* W(){ return 4 <= n ? &m[3] : NULL;  }
        const T* X()const{ return 1 <= n ? &m[0] : NULL; }
        const T* Y()const{ return 2 <= n ? &m[1] : NULL; }
        const T* Z()const{ return 3 <= n ? &m[2] : NULL; }
        const T* W()const{ return 4 <= n ? &m[3] : NULL; }
        
		const XEVectorM& operator += (const XEVectorM& vec)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] += vec.m[i];
			return *this;
		}
		const XEVectorM& operator -= (const XEVectorM& vec)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] -= vec.m[i];
			return *this;
		}
		const XEVectorM& operator *= (const XEVectorM& vec)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] *= vec.m[i];
			return *this;
		}
		const XEVectorM& operator /= (const XEVectorM& vec)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] /= vec.m[i];
			return *this;
		}
		template<typename V = T>
		const XEVectorM& operator *= (V v)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] *= v;
			return *this;
		}
		template<typename V = T>
		const XEVectorM& operator /= (V v)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] /= v;
			return *this;
		}
		const XEVectorM& operator = (const XEVectorM& vec)
		{
			for (xint32 i = 0; i < n; ++i)
				m[i] = vec.m[i];
			return *this;
		}
		XEVectorM operator + () const
		{
			XEVectorM<T, n> val = *this;
			return val;
		}
		XEVectorM operator - () const
		{
			XEVectorM<T, n> val = *this;
			for (xint32 i = 0; i < n; ++i)
				m[i] *= -1.f;
			return val;
		}
	};

	template<typename T, int n>
	XEVectorM<T, n> operator + (const XEVectorM<T, n>& vec1, const XEVectorM<T, n>& vec2)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = vec1.m[i] + vec2.m[i];
		return val;
	}
	template<typename T, int n>
	XEVectorM<T, n> operator - (const XEVectorM<T, n>& vec1, const XEVectorM<T, n>& vec2)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = vec1.m[i] - vec2.m[i];
		return val;
	}
	template<typename T, int n>
	XEVectorM<T, n> operator * (const XEVectorM<T, n>& vec1, const XEVectorM<T, n>& vec2)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = vec1.m[i] * vec2.m[i];
		return val;
	}
	template<typename T, typename V, int n>
	XEVectorM<T, n> operator * (const V& v, const XEVectorM<T, n>& vec)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = v * vec.m[i];
		return val;
	}
	template<typename T, typename V, int n>
	XEVectorM<T, n> operator * (const XEVectorM<T, n>& vec, const V& v)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = vec.m[i] * v;
		return val;
	}

	template<typename T, int n>
	XEVectorM<T, n> operator / (const XEVectorM<T, n>& vec1, const XEVectorM<T, n>& vec2)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = vec1.m[i] / vec2.m[i];
		return val;
	}
	template<typename T, typename V, int n>
	XEVectorM<T, n> operator / (const XEVectorM<T, n>& vec, const V& v)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = vec.m[i] / v;
		return val;
	}
	template<typename T, typename V, int n>
	XEVector<T, n> operator / (const V& v, const XEVector<T, n>& vec)
	{
		XEVectorM<T, n> val;
		for (xint32 i = 0; i < n; ++i)
			val.m[i] = v / vec.m[i];
		return val;
	}
	template<typename T, int n>
	xbool operator == (const XEVectorM<T, n>& vec1, const XEVectorM<T, n>& vec2)
	{
		for (xint32 i = 0; i < n; ++i)
			if (vec1.m[i] != vec2.m[i])
				return xfalse;
		return xtrue;
	}
	template<typename T, int n>
	xbool operator != (const XEVectorM<T, n>& vec1, const XEVectorM<T, n>& vec2)
	{
		for (xint32 i = 0; i < n; ++i)
			if (vec1.m[i] != vec2.m[i])
				return xtrue;
		return xfalse;
	}
X_EEB_BEGIN
	extern const xfloat32            c_StanderCameraDis;
	extern const xfloat32            c_StanderDirScale;
	extern const xfloat32            c_StanderFadeDis;
	extern const xfloat32            c_StanderOrthSize;
    extern const xfloat32            c_ScreenResolutionDPIRatio;
	extern const xint32              c_MaxParticleSystemFadingTime;//ms.
	extern const xchar*	             c_PhyBodySuffix;
	extern const xchar*	             c_PhyConstraintSuffix;
	extern const xchar*              c_szMacro_DEFAULTENABLE;
X_EEB_END	

	
	//load skeletal phy res from file
	IXPhysicsRes*								LoadPhysicsResFromPhy(const xchar* szPhyPath, xbool bReload = xfalse);
	IXPhysicsRes*								CreatePhysicsRes(PhysicsResourceType eType, const xchar* szName, const xchar* szMdlPath, const IXSkeletalPhysicsRes::XPhysResCreateParams& Params); 


	//////////////////////////////////////////////////////////////////////////
	// version function
	// conver version string to int, Condition: Maximum four segments of the number, the maximum number of each is 99.
	xint32										ConverVersionStringToValue(const XString &strVersion);

};

typedef XEUtility::XEVectorM<xint32, 2> XEVector2i;
typedef XEUtility::XEVectorM<xint32, 4> XEVector4i;
typedef XEUtility::XEVector<std::string, 2> XEVector2s;

#define ASSERT_ERROR(V,I) ASSERT(0&&V&&I)
#endif
