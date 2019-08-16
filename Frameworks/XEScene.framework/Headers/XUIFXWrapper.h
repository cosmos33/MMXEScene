#ifndef _XUI_FX_WRAPPER_H_
#define _XUI_FX_WRAPPER_H_
#include "XUIWidget.h"
#include "FxInstance.h"
#include "XBaseCamera.h" 
#define  XUI_FX_PATH_     "FX_Path"
#define  XUI_FX_Layer_    "FX_Layer"

class XUIFxWrapper :public XUIWidget
{
public:
	X_CLASS_DEF(XUIFxWrapper);

	static XUIFxWrapper*		    Create(/*const XString& _fxpath*/);
	static XUIFxWrapper*		    Create(const XString& _fxpath);
	xbool                           SetFxPath(XString const& _path);
	XString                         GetFxPath(){ return m_sFxPath; }
	void                            SetLayer(xint32 type);
	xint32                          GetLayer() const { return m_elayer; }
	void                            SetEnginePath (XString const& _path){ m_strEnginepath  = _path; }
	void                            SetProjectPath(XString const& _path){ m_strProjectpath = _path; }
	void                            FxStop();
	void                            FxPause();
	void                            FxPlay();
	void		                    FxRestart();
	xbool		                    FxIsCompleted() ;
	virtual xbool				    HitTest(const XVECTOR2& vPoint, XVECTOR2* pHitPos);
	virtual void					Visit(IXWorld* pWorld, const XMATRIX4& matParentTransform, xuint32 unParentFlags) override;
	virtual void					Draw(IXWorld* pWorld, xuint32 unParentFlags) override;
	virtual void		            Tick(xfloat32 fDelta) override;
	virtual void					SetPosition(xfloat32 x, xfloat32 y) override;
	virtual void					SetPosition(const XVECTOR2& vPos)override;
	virtual void                    SetRotation(xfloat32 fRotation) override;
	/*virtual void					SetScaleX(xfloat32 fScaleX) override;
	virtual void					SetScaleY(xfloat32 fScaleY) override;
	virtual void					SetScale(xfloat32 fScaleX, xfloat32 fScaleY) override;
	virtual void					SetScale(const XVECTOR2& vScale) override;*/
	XUIFxWrapper();
	virtual ~XUIFxWrapper();
	virtual xbool			        SerilizeSelfXML(XXMLExtendTool& outXmlArchive) override;
protected:
	virtual xbool			Init() override;
	virtual xbool			Init(const XString& _fxpath);
private:
	void         ReleaseFX();
	XBaseCamera* GetOrCreateCameara();
	IFxInstance* GetOrCreateFxInstance(/*XString const& path_*/);
	XString      m_sFxPath;
	IFxInstance* m_pFxInstance = nullptr;
	XBaseCamera* m_pcamera     = nullptr;
	xint32       m_elayer      = 0;
	XMATRIX4     m_initfxmat   = XMATRIX4(XMATRIX4::IDENTITY);
	XString      m_strEnginepath;
	XString      m_strProjectpath;
};
#endif // !_XUI_FX_WRAPPER_H_
