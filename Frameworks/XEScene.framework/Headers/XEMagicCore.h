/******************************************************************************

@File         XEImgFxCoreEntrance.h

@Version       1.0

@Created      2019, 3, 15

@Description  You should call this in your project.

@HISTORY: 

******************************************************************************/
#ifndef _XE_MAGIC_CORE_ENTRANCE_H
#define _XE_MAGIC_CORE_ENTRANCE_H
#include "XEVariant.h"
#include <mutex>

class XEDecorationEnvBridgeBase;

namespace XEMagicCore
{
	xbool ModuleEntrance();//you'd better call this in your runnable module,otherwise the api may won't work.
	struct XEAutoLock
	{
		XEAutoLock(std::mutex& lock)
			:lock_(lock)
		{
			lock_.lock();
		}
		~XEAutoLock()
		{
			lock_.unlock();
		}
		std::mutex& lock_;
	};

	struct XEFaceEntity
	{
		XEFaceEntity() :   nFaceIndex(-1), nCurTrackingID(-1), nCurFaceExpressionCode(0), vFaceRect(0.f),matFace(XMATRIX4::IDENTITY){}
		xint32             nFaceIndex;//may be changed at each frame(not fixed for a single face. -1 will be invalid, start from 1)
		xint32             nCurTrackingID;//original tracking id
		xint32             nCurFaceExpressionCode;//may be changed at each frame. please provide this detail-meaning for the runnable module if necessary.
		XVECTOR4           vFaceRect;//you may probably use this to calculate the correct UVs.
		XMATRIX4           matFace;//indicate that the matrix for the face, need to update every frame.
		XArray<xfloat32>   arrFaceLandMarks;//indicate the landmark for the face(eg. 96,104, etc...)
		xbool              IsValid() const;
		void               Clear();
		void               AssignLandmarks(const xfloat32* pData, xint32 nSize);
		void               UpdateData(const XEFaceEntity& cpy);
		xint32             LandmarkSize() const;
		xfloat32*          Landmark(xint32 nIndex);
		//warning ! if you want to lock manually , please ensure the function above is finished!
		void               Lock() const;
		void               Unlock() const;
	};

	/*
	手势触发类型:
	heart 比心 five 比5 yeah 剪刀手 one 向上指 baoquan 抱拳 bainian 百年 fingerheart 单手比心 eight 八/手枪 zan 大拇指 fist 拳头
	*/
	struct XEObjectEntity
	{
		XEObjectEntity() :fScore(0.f), nObjectIndex(0){}
		void	          UpdateData(const XEObjectEntity& cpy);
		xfloat32          fScore;
		xint32            nObjectIndex;
		XString           strClassName;
	};

	struct XEDetectParam
	{
		XEDetectParam() :data(XEVariant::PType::XVT_INT), bShowInProperty(xtrue),szTypeDesc("Unknown"){}
		XEDetectParam(const xchar* pTypeDesc) { szTypeDesc = pTypeDesc ? pTypeDesc : "Unknown"; }
		xbool     operator == (const XEDetectParam& cmp)const;//will only compare with the nBeautyType
		xbool     IsAllEqual(const XEDetectParam& cmp)const;//consider all.
		xbool     bShowInProperty;
		XEVariant data;//variant data.
		XString   szTypeDesc;//e.g, face_width_, beauty_switch_, etc.
	};

X_EEB_BEGIN	
	typedef XArray<XEFaceEntity>   FaceEntityList;
	typedef XArray<XEDetectParam>  DetectParams;
	typedef XArray<XEObjectEntity> ObjectEntityList;
	enum    eEntityDetectStatus{ EDS_UNKOWN, EDS_ADD_NEW, EDS_MODIFY_EXIST };
	class   FxListener
	{
		//warning! this may be called in the thread[DESKTOP]
	public:
		FxListener(){}
		virtual ~FxListener(){}
		//mmcv-detecting algorithm enable/disable switch
		virtual void           OnMMCVDetectEnableChange(xbool bEnable){}
		//single face entity detected.
		virtual void           OnFaceEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, eEntityDetectStatus status, const XEFaceEntity& entity){}
		//may include index/matrix/landmarks/expression changing, an assemble detector, multi face entities.
		virtual void           OnFaceEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const FaceEntityList& entities){}
		//single obect entity
		virtual void           OnObjectEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, eEntityDetectStatus status, const XEObjectEntity& entity){}
		//an assemble detector, multi object entities.
		virtual void           OnObjectEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const ObjectEntityList& entities){}
		//segmentation, nSegModelType need to be defined, may exist multi types, eg. face-only, body, hand, hair-only, etc.
		virtual void           OnSegmentationProcessed(XEDecorationEnvBridgeBase* pEnvBridge){}
	};

	//cv-enable/disable
	void					   OnMMCVDetectEnableChange(xbool bEnable);
	//single face entity
	void                       OnFaceEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, eEntityDetectStatus status, const XEFaceEntity& entity);
	//may include index/matrix/landmarks/expression changing, an assemble detector.
	void                       OnFaceEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const FaceEntityList& entities);
	//object entities, such as hand-gesture
	void					   OnObjectEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, eEntityDetectStatus status, const XEObjectEntity& entity);
	//an assemble detector, multi object entities.
	void                       OnObjectEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const ObjectEntityList& entities);
	//segmentation
	void                       OnSegmentationProcessed(XEDecorationEnvBridgeBase* pEnvBridge);
	std::mutex*                GetDataMutex(xint32 nFaceIndex);
X_EEB_END				       
						       
	void                       RegisterEnvBridge(XEDecorationEnvBridgeBase*  pEnvBridge);
	xint32                     AddFxListener(FxListener* pFaceEntityListener);
	xbool                      RemoveFxListener(FxListener* pFaceEntityListener);
	XEFaceEntity               GetFaceEntityByIndex(xint32 nFaceIndex);
	XEDecorationEnvBridgeBase* GetDecorationEnvBridge();

}

#endif//_XE_MAGIC_CORE_ENTRANCE_H
