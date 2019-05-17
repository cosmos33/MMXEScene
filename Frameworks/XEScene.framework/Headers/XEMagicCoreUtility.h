/******************************************************************************

@File         XEMagicCoreUtility.h

@Version       1.0

@Created      2019, 3, 12

@Description

@HISTORY:

******************************************************************************/
#ifndef XE_MAGIC_CORE_UTILITY_H
#define XE_MAGIC_CORE_UTILITY_H
#include "XString.h"
#include "XEWorld.h"
#include "XEFaceTrackerActor.h"

namespace XEMagicCoreUtility
{
	//对于lua导出，过滤到此部分
X_EEB_BEGIN
	extern const xchar* c_strFaceTracking;
	extern const xchar* c_strPosition;
	extern const xchar* c_strTracking;
	extern const xchar* c_strFilterPathOfFaceMaskInTrack;///custom/ do not show in custom.
	extern xint32		g_nFacePointNum;//默认采用96点
X_EEB_END


	/*
	* 此函数为了兼容SceneVer版本低于1.3的情况！！
	* 当SceneType类型是facetrack，并且SceneVer版本小于等于1.2时，
	* (1)需要为世界创建一个XEImgFaceTrackerActor,并将fileterPath是"/FaceTracker:f/tracking:g"的actor
	* 或是"/custom/facetracker:f/tracking:g/"的actor，
	* 或是"/custom/facetracker:f/position:g/"的actor Attach 到XEImgFaceTrackerActor
	* (2)需要将SceneVer版本号设为1.3
	*
	* Note：此函数需要在XEWorld::LoadScene之后调用。
	*/
	void		ConvertSceneVersionForFaceTrackerType(XEWorld* pWorld);

	//是否是face track类型，并且低于1.3版本
	xbool		IsFaceTrackTypeDownSceneVer1_3(XEWorld* pWorld);

	//////////////////////////////////////////////////////////////////////////序列帧数据 start
	enum ETextureAssetType //纹理类型
	{
		TAT_NONE,
		TAT_MULT_TEXTURE_SINGLE_FRAME,//序列帧是由多个纹理组成，并且每个纹理代表一帧画面
		TAT_SINGLE_TEXRTURE_MULT_FRAME,//序列帧有一张纹理组成，此纹理包含m * n帧画面
		//后续支持序列帧由多张纹理组成，并且每张纹理上包含m * n帧
		//TAT_MULT_TEXTURE_MULT_FRAME
		TAT_NUM
	};

	const XString&				GetTextureAssetType(ETextureAssetType eType);
	ETextureAssetType			GetTextureTypeByName(const XString &str);

	//单张纹理信息
	struct XE2DSequenceFrameSingleInfo
	{
		XString strTexturePath;//序列帧纹理相对路径(相对于xscene文件的路径)
		xint32  nCol;//切分此纹理的列数
		xint32  nRow;//切分此纹理的行数
		xbool operator==(const XE2DSequenceFrameSingleInfo& rl);
		xbool operator==(const XE2DSequenceFrameSingleInfo& rl)const;
		XE2DSequenceFrameSingleInfo() :strTexturePath(""), nCol(1), nRow(1){}
		XE2DSequenceFrameSingleInfo(const XString& strPath) :strTexturePath(strPath), nCol(1), nRow(1){}
	};
	typedef XArray<XE2DSequenceFrameSingleInfo> Img2DSequenceFrameInfoList;
	//一组序列帧信息
	struct XE2DSequenceFrameListInfo
	{
		Img2DSequenceFrameInfoList				aTextureFrameInfo;
		XEMagicCoreUtility::ETextureAssetType	eTextureAssetType;
		xbool operator==(const XE2DSequenceFrameListInfo& rl);
		xbool operator==(const XE2DSequenceFrameListInfo& rl) const;
		XE2DSequenceFrameListInfo() :eTextureAssetType(XEMagicCoreUtility::TAT_NONE){}
	};

	//待渲染的纹理路径及UV
	struct XERenderTextureInfo
	{
		XString  strRenderTexturePath;
		XVECTOR2 vUV1;
		XVECTOR2 vUV2;
		XVECTOR2 vUV3;
		XVECTOR2 vUV4;
	};
	//////////////////////////////////////////////////////////////////////////序列帧数据 end

	//////////////////////////////////////////////////////////////////////////
	//Viewport的尺寸发生改变，同步到世界
	bool						OnFrameSizeChangedForWorld(XEWorld* pWorld);

	bool						ConvertScreenToWorld(XViewport* pViewPort, const XVECTOR3& vScreenPos, XVECTOR3& vWorld);
	bool						ConvertWorldToScreen(XViewport* pViewPort, const XVECTOR3& vWorld, XVECTOR2& vScreenPos);
	XVECTOR2                    ConvertToViewportPixelCenter(const XVECTOR2& vRectSize, const XVECTOR2& vNormalizeCenter);//convert pixel center to the viewport one.(viewport center is in the viewport space, which origin point is left, top )
	XVECTOR2                    ConvertToNormalizePixelCenter(const XVECTOR2& vRectSize, const XVECTOR2& vViewportPixelCenter);
	void                        OnActorAttachToFaceTracker(XEActor* pActor);

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	extern xfloat32             g_fDeviceWHRate;
	extern xfloat32             g_fDeviceScaleRate;
	extern XVECTOR2				g_vDeviceWH;
	void                        SetDeviceRate(xfloat32 fWHRate, xfloat32 fDeviceScaleRate, xfloat32 fDeviceWidth, xfloat32 fDeviceHeight);//for editor
	void                        UpdateFrameSequenceDeviceWH(XEWorld* pWorld);//for editor
#endif
};

#endif
