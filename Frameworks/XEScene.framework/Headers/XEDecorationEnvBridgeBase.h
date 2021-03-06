/******************************************************************************

@File         XEDecorationEnvBridgeBase.h

@Version       1.0

@Created      2019, 3, 13

@Description  bridge for the tex env ready. You should derived from this class

@HISTORY:

******************************************************************************/
#ifndef _XE_TEX_ENV_BRIDGE_INTERFACE_H
#define _XE_TEX_ENV_BRIDGE_INTERFACE_H

#include "XTypes.h"
#include "XMath3D.h"
#include "XEMagicCore.h"
#include "XEEngine.h"
#include "tinyxml2_XEngine.h"
using namespace tinyxml2_XEngine;

class XETexSegmentationMask;
//@implement this interface please. AT YOUR RENDERING FLOW MODULE.
class XEDecorationEnvBridgeBase
	:public XEEngine::XEFrameListener
{
public:
	XEDecorationEnvBridgeBase();
	virtual ~XEDecorationEnvBridgeBase();
public:
	//mmcv-core-detecting enable/disable
	X_EES_LINE void                                               OnMMCVDetectEnableChange(xbool bEnable);
	//will add or modify the detected face to the face list, you should call this first.
	//return ADD_NEW if there isn't the face with the specific index, otherwise return MODIFY_EXIST
	X_EES_LINE XEMagicCore::eEntityDetectStatus					  OnFaceEntityDetected(xint32 nFaceIndex, const XEMagicCore::XEFaceEntity& faceDesc);
	//may include index/matrix/landmarks/expression changing, an assemble detector.
	X_EES_LINE void                                               OnFaceEntitiesChangeDetected();
	//objects, such as hand-gesture
	X_EES_LINE XEMagicCore::eEntityDetectStatus                   OnObjectEntityDetected(xint32 nObjectIndex, const XEMagicCore::XEObjectEntity& objDesc);
	// an assemble detector.
	X_EES_LINE void                                               OnObjectEntitiesChangeDetected();

protected:
	//FACE MASK may be modified, response and process it properly in your module.
	virtual xbool                                                 OnFaceLandmarkModified(const XEMagicCore::XEFaceEntity& modifyFace, xint32 nLandmarkIndex){ return xtrue; }
	//segmentation processing...					            
	virtual void                                                  OnSegmentationProcessed();

	//render-frame processing...
	virtual void                                                  OnPreFrame() override;
	virtual void                                                  OnPostFrame() override;
public:												            
	X_FORCEINLINE XEMagicCore::FaceEntityList&                    GetFaceList(){ return m_aFaceEntityList; }
	X_EES_LINE X_FORCEINLINE const XEMagicCore::FaceEntityList&   GetFaceList()const{ return m_aFaceEntityList; }
	X_FORCEINLINE XEMagicCore::ObjectEntityList&                  GetObjectList(){ return m_aObjectEntityList; }
	X_EES_LINE X_FORCEINLINE const XEMagicCore::ObjectEntityList& GetObjectList()const{ return m_aObjectEntityList; }
	X_FORCEINLINE static XEMagicCore::DetectParams&				  GetDetectParamList(){ return s_aDetectParamList; }
	static XEMagicCore::XEDetectParam*                            GetDetectParam(const xchar* pParamDesc, xbool bAddIfNotExist = xtrue);//params can be changed.
	static xint32                                                 AddDetectParam(const XEMagicCore::XEDetectParam& pParam);
	static void													  Serialize(XMLElement* pEleScene);
	static void													  Deserialize(XMLElement* pEleScene);

	std::mutex*                                                   GetFaceMutex(xint32 nFaceIndex);//face index will start from 1
	void                                                          ClearFaceEntities();
	void                                                          ClearObjectEntities();
	void                                                          ReSetupFaceMutex();//according to the amount of max-faces. if you want to reset the face amount, please call this.
public:												              
	//you need to setup beauty params, if necessary.              
	virtual void                                                  Initialize();
	//mask segmentation buffer								      
	virtual xbool                                                 GetSegmentationMaskBuffer(const xuint8*& pMaskBuffer, xint32& nSegmentationType, xint32& nMaskSize, xint32& nMaskWidth, xint32& nMaskHeight){ return xfalse; }
	//mask segmentation mask rect, specific the mask rect correctly.
	virtual XVECTOR4                                              GetSegmentationMaskRect() const{ return XVECTOR4(0.f, 0.f, 1.f, 1.f); }
	//check mmcv detector valid or not, you need to specific and override this
	virtual xbool                                                 IsMMCVDetectValid() const = 0;
private:
	XEMagicCore::FaceEntityList									  m_aFaceEntityList;
	XEMagicCore::ObjectEntityList                                 m_aObjectEntityList;
	xbool                                                         m_bInit;
protected:											              
	//mutex for each faces							              
	XArray<std::mutex*>                                           m_aMutexes;
	//detect params - static params									              
	static XEMagicCore::DetectParams							  s_aDetectParamList;
};																  
																  
//convenient for override behaviors.							  
#define ADD_DEFAULT_DETECT_PARAM(A,P,S)							  {XEMagicCore::XEDetectParam b; b.szTypeDesc = #P; b.bShowInProperty = S; A.AddUnique(b);}
#define ADD_DEFAULT_DETECT_PARAM_WITH_FLOAT_VALUE(A,P,V,S)		  {XEMagicCore::XEDetectParam b; b.szTypeDesc = #P; b.data.SetFloat(V);b.bShowInProperty = S;	A.AddUnique(b);}
#define ADD_DEFAULT_DETECT_PARAM_WITH_INT_VALUE(A,P,V,S)		  {XEMagicCore::XEDetectParam b; b.szTypeDesc = #P; b.data.SetInt(V);b.bShowInProperty = S;		A.AddUnique(b);}
#define ADD_DEFAULT_DETECT_PARAM_WITH_BOOL_VALUE(A,P,V,S)		  {XEMagicCore::XEDetectParam b; b.szTypeDesc = #P; b.data.SetBool(V);b.bShowInProperty = S;	A.AddUnique(b);}
#define ADD_DEFAULT_DETECT_PARAM_WITH_STRING_VALUE(A,P,V,S)		  {XEMagicCore::XEDetectParam b; b.szTypeDesc = #P; b.data.SetString(V);b.bShowInProperty = S;	A.AddUnique(b);}


#endif//_XE_TEX_ENV_BRIDGE_INTERFACE_H
