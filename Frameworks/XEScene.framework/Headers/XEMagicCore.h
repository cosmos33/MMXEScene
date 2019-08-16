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
#include "XEGraphBuilderSelector.h"
#include <mutex>

class XEDecorationEnvBridgeBase;

namespace XEMagicCore
{
	xbool ModuleEntrance();//you'd better call this in your runnable module,otherwise the api may won't work.

X_EEB_BEGIN
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
X_EEB_END

	struct XEFaceEntity
	{
		XEFaceEntity() :   nFaceIndex(-1), nCurTrackingID(-1), nCurFaceExpressionCode(0), vFaceRect(0.f),matFace(XMATRIX4::IDENTITY){}
		xint32             nFaceIndex;//may be changed at each frame(not fixed for a single face. -1 will be invalid, start from 1)
		xint32             nCurTrackingID;//original tracking id
		xint32             nCurFaceExpressionCode;//may be changed at each frame. please provide this detail-meaning for the runnable module if necessary.
		XVECTOR4           vFaceRect;//you may probably use this to calculate the correct UVs.
		XMATRIX4           matFace;//indicate that the matrix for the face, need to update every frame.
		XArray<xfloat32>   arrFaceLandMarks;//indicate the landmark for the face(eg. 96,104, etc...)
		XArray<xfloat32>   arrFaceLandMarks137;//137 for makeup
		xbool              IsValid() const;
		void               Clear();
		void               AssignLandmarks(const xfloat32* pData, xint32 nSize);
		void               AssignLandmarks_137(const xfloat32* pData, xint32 nSize);
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
		XEObjectEntity() :fScore(0.f), nObjectIndex(-1){}
		void	          UpdateData(const XEObjectEntity& cpy);
		void              Clear();
		xbool             IsValid() const;
		xfloat32          fScore;
		xint32            nObjectIndex;
		XString           strClassName;
	};

	/*
	* body joint data
	*/
	struct XEBodyJoint
	{
		XEBodyJoint() :fScore(0), nPointX(0), nPointY(0){}
		void	          UpdateData(const XEBodyJoint& cpy);
		xfloat32		  fScore;
		xint32			  nPointX;
		xint32			  nPointY;
	};

	/*
	* single persion's body joints
	*/
	struct XEBodyEntity
	{
		XEBodyEntity() :nBodyIndex(-1){}
		void	               UpdateData(const XEBodyEntity& cpy);
		xbool                  IsValid() const;
		void                   Clear();
		void                   Lock() const;
		void                   Unlock() const;
X_EES_LINE XArray<XEBodyJoint> a2DJoints;
		xint32			       nBodyIndex;
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
	typedef XArray<XEBodyEntity>   BodyEntityList;
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
		//single body entity
		virtual void		   OnBodyEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, eEntityDetectStatus status, const XEBodyEntity& entity){}
		//multi body entities
		virtual void		   OnBodyEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const BodyEntityList& entities){}
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
	//single body entity
	void                       OnBodyEntityDetected(XEDecorationEnvBridgeBase* pEnvBridge, eEntityDetectStatus status, const XEBodyEntity& entity);
	//multi body entities
	void					   OnBodyEntitiesChangeDetected(XEDecorationEnvBridgeBase* pEnvBridge, const BodyEntityList& entities);
	std::mutex*                GetDataMutex(xint32 nFaceIndex);
X_EEB_END				       
						       
	void                       RegisterEnvBridge(XEDecorationEnvBridgeBase*  pEnvBridge);
	X_EES_LINE xint32          AddFxListener(FxListener* pFaceEntityListener);
	X_EES_LINE xbool           RemoveFxListener(FxListener* pFaceEntityListener);
	XEFaceEntity*              GetFaceEntityByIndex(xint32 nFaceIndex);
	XEObjectEntity*            GetObjectEntity(xint32 nObjectIndex);
	XEDecorationEnvBridgeBase* GetDecorationEnvBridge();
	XEGraphBuilderProcess&     GetGraphBuilderPostprocess();
	XEGraphBuilderProcess&     GetGraphBuilderPreprocess();
	xbool                      IsPreProcessEnabled();
	xbool                      IsPostProcessEnabled();

}

#endif//_XE_MAGIC_CORE_ENTRANCE_H
