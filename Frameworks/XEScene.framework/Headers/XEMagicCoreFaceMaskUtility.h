/******************************************************************************

@File         XEMagicCoreFaceMaskUtility.h

@Version       1.0

@Created      2019, 3, 26

@Description

@HISTORY:

******************************************************************************/
#ifndef XE_MAGCI_CORE_FACE_MASK_UTILITY_H
#define XE_MAGCI_CORE_FACE_MASK_UTILITY_H

#include "XTypes.h"
#include "XArray.h"
#include "XMath3D.h"

namespace XEMagicCoreFaceMaskUtility
{
	//人脸关键点转换：将96个关键点转换为104个关键点
	xbool						FDKExtend96PtLandmarksTo104PtLandmarks(const XArray<xfloat32>& aLandmarks96, XArray<xfloat32>& aLandmarks104);
	//获取人脸关键点三角剖分后的关键点索引数组(104点的索引)
	XArray<xint32>&				GetFDKFacialMaskTriangulationIndexes();
	//获取人脸关键点三角剖分后的关键点索引数组(137点的索引)
	XArray<xint32>&				GetFDKFacialMaskTriangulationIndexes_137();
	//获取标准96个人脸关键点对应的UV(x1,x2...y1,y2..)
	const XArray<XVECTOR2>&		GetStandandFacialMaskUV();
	//获取标准137个人脸关键点对应的UV(x1,y1,x2,y2..)
	const XArray<XVECTOR2>&		GetStandandFacialMaskUV_137();
	//从metadata.xml读取UV数据
	xbool						LoadMetadataFromXml(const xchar* pUVAssetFullPath, XArray<XVECTOR2>& aUV);
	xbool						SaveMetadataToXml(const xchar* pUVAssetFullPath, const XArray<XVECTOR2>& aUV);
	//根据人脸关键点数量获取三角剖分后的顶点索引列表
	XArray<xint32>&             GetFDKFacialMaskTriangulationIndexesForPointNum(xint32 nPointNum);
	//将96点的UV转为104点
	xbool					    ConvertLandmarkUV96To104(const XArray<XVECTOR2>& vUpdateUV96, XArray<XVECTOR2>& vUpdateUV104);

	//脸部区域
	enum EFacePartType
	{
		EFPT_FULL_SCREEN,
		EFPT_FULL_FACE,
// 		EFPT_LEFT_EYE,
// 		EFPT_RIGHT_EYE,
// 		EFPT_LEFT_PUPIL,//瞳孔
// 		EFPT_RIGHT_PUPIL,
// 		EFPT_TEETH,
// 		EFPT_LIP,
// 		EFPT_LEFT_EYE_BROW,
// 		EFPT_RIGHT_EYE_BROW,
		EFPT_NUM
	};

	XArray<XString>&			GetFacePartTypes();
	XString						GetFacePartTypeName(EFacePartType eType);
	EFacePartType				GetFacePartType(const XString& strName);

// 	//137点的左眼区域索引
// 	const XArray<xint32>&		GetLeftEyeIndexs_137();
// 	//137点的右眼区域索引
// 	const XArray<xint32>&		GetRightEyeIndexs_137();


};

#endif
