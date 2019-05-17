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
	//获取人脸关键点三角剖分后的关键点索引数组
	XArray<xint32>&				GetFDKFacialMaskTriangulationIndexes();
	//获取标准人脸UV(x1,x2...y1,y2..)
	const XArray<XVECTOR2>&		GetStandandFacialMaskUV();
	//从metadata.xml读取UV数据
	xbool						LoadMetadataFromXml(const xchar* pUVAssetFullPath, XArray<XVECTOR2>& aUV);
	xbool						SaveMetadataToXml(const xchar* pUVAssetFullPath, const XArray<XVECTOR2>& aUV);
};

#endif
