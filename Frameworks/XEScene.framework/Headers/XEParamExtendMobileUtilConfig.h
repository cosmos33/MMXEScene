/******************************************************************************

@File         XEParamExtendMobileUtilConfig.h

@Version       1.0

@Created      2018, 3, 23

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/


#ifndef _XE_PARAMEXTENDMOBILEUTILCONFIG_H_
#define _XE_PARAMEXTENDMOBILEUTILCONFIG_H_

#include "XEActor.h"
#include "XEUserNode.h"

static XArray<XString>  MobileActionDictionary;
#define REGISTER_MOBILE_ACTION_TYPE(N) static xint32 __s_n##N = MobileActionDictionary.Add(#N);\
template<>\
XString MobileActionCfgBase::GetActionConfigTypeName<N>()\
{\
	return #N;\
}

class MobileActionCfgBase
{
public:
	MobileActionCfgBase() : m_bEditable(xtrue){}
	virtual ~MobileActionCfgBase(){}
public:
	virtual XString     GetTypeName() = 0;
	template<typename T>
	static XString      GetActionConfigTypeName();
protected:
	xbool m_bEditable;
};


typedef XArray<MobileActionCfgBase*> MobileActionConfigArray;

//several Action config for the mobile platforms.
class FaceTracking :public MobileActionCfgBase
{
public:
	FaceTracking() :m_szShowAction("position"){ m_bEditable = xfalse; }
	virtual XString     GetTypeName() override;
public:
	XString m_szShowAction;//tracking or position
};


class XEAnimComponentPlayList;
class StandbyAnimation :public MobileActionCfgBase
{
public:
	StandbyAnimation(){}
	virtual XString     GetTypeName() override;
	xint32 GetUnUsedAnimation(XArray<XString>& animList, XEAnimComponentPlayList* pPlayList);
public:
	XArray<XString> m_StandbyAnimation;
};

class FaceExpression :public MobileActionCfgBase
{
public:
	FaceExpression() :m_nTriggerType(0), m_nAnimationIndex(0), m_nAnimPlayMode(0){ m_bEditable = xfalse; }
	virtual XString     GetTypeName() override;
public:
	xint32 m_nTriggerType;//the face-expression code.
	xint32 m_nAnimationIndex;//animation-expression binding.
	xint32 m_nAnimPlayMode;//动画播放模式
};

class GestureExpression :public MobileActionCfgBase
{
public:
	GestureExpression() :m_nIndex(0), m_fScroeThread(0.9f), m_nAnimationIndex(0), m_nAnimPlayMode(0){ }
	virtual XString     GetTypeName() override;
public:
	xfloat32 m_fScroeThread;
	xint32   m_nIndex;//may be multi?
	XString  m_strGestureName;
	xint32	 m_nAnimationIndex;//animation-expression binding.
	xint32   m_nAnimPlayMode;//动画播放模式
};


class SpinchToScale :public MobileActionCfgBase
{
public:
	SpinchToScale() :m_fMaxScale(3.f), m_fMinScale(0.01f){}
	virtual XString     GetTypeName() override;
public:
	xfloat32 m_fMaxScale;
	xfloat32 m_fMinScale;
};

class PressToDrag :public MobileActionCfgBase
{
public:
	PressToDrag() :m_fdistance(0.3f){}
	virtual XString     GetTypeName() override;
public:
	xfloat32 m_fdistance;
};

class TapToPlace :public MobileActionCfgBase
{
public:
	TapToPlace() :m_fdistance(0.3f){}
	virtual XString     GetTypeName() override;
public:
	xfloat32 m_fdistance;
};

class TapToPlay :public MobileActionCfgBase
{
public:
	TapToPlay() :m_nAnimationIndex(0){}
	virtual XString     GetTypeName() override;
public:
	xint32 m_nAnimationIndex;
};

class XEParamExtendMobileUtilConfig
	:public IXEExtendParam
{
public:
	enum
	{
		PARAM_MOBILE_ACTION_ADD, 
		PARAM_MOBILE_ACTION_ITEM_START
	};
	                            XEParamExtendMobileUtilConfig();
	virtual                    ~XEParamExtendMobileUtilConfig();
	XE_EXT_PARAM_TYPE_DEF(EXTEND_PARAM_NAME)
	virtual void				Tick(xfloat32 fDelMs) override;
	virtual XMLElement*         Serialize(XMLElement* pEleParent) override;
	virtual void                Deserialize(const XMLElement* pEleExtendParam) override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual xbool               SetValueProperty(xint32 nMemberIndex, const XEValueProperty* pValueProperty, XEPropertyObject* pPropertyObject) override;
	virtual void                GetValueProperty(xint32 nMemberIndex, XEValueProperty* pValueProperty, XEPropertyObject* pPropertyObject) override;
	virtual XEProperty*         CreateProperty(xint32 nParamIndex,xint32 nMemberIndex,   XEProperty* pParent, XEPropertyObject* pPropertyObject) override;
	virtual xint32              GetParamMemberCount() override;
	virtual XString             GetParamMemberName(xint32 nIndex) override;
#endif
	xbool                       HasActionCfg(const XString& szActionType);
	xbool                       AddActionCfg(const XString& szActionType);
	xbool                       RemoveActionCfg(const XString& szActionType);
	MobileActionCfgBase*        GetActionCfg(const XString& szActionType);
	
	xint32                      GetRestValidActionCfgType(XArray<XString>& aType);
	xint32                      GetUseActionCftType(XArray<XString>& aType);
	static MobileActionCfgBase* NewActionCfgBaseForType(const XString& szActionType);
	static XArray<XString>&     GetFaceCandidateEmotion();
	static XString*             GetFaceEmotionForExpressionIndex(xint32 nEmotionIndex);
	static xint32*              GetExpressionIndexForFaceEmotion(const XString& szEmotionName);
	static XArray<XString>&     GetObjectCandidateGestrue();
	static xint32*              GetExpressionIndexForObjectGesture(const XString& szGestureName);
	static XString*             GetObjectGestureForExpressionIndex(xint32 nGestureIndex);
	static XArray<XString>&		GetAnimationCandidatePlayMode();
	static XString*				GetAnimationPlayModeByIndex(const xint32& nPlayModeIndex);
	static xint32*				GetAnimationPlayModeIndexByName(const XString& strPlayModeName);
protected:
	//driving methods.
	void                        ActOnFaceExpression();
	void                        ActOnGesture();
public:
	static XString EXTEND_PARAM_NAME;
	MobileActionConfigArray     m_aMobileActionCfg;
private:
	xint32                      m_nCurEmotionType;
	xint32                      m_nCurGestureType;
};


#endif //_XE_PARAMEXTENDMOBILEUTILCONFIG_H_
