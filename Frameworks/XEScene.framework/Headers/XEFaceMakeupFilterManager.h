/******************************************************************************

@File         XEFaceMakeupFilterManager.h

@Version       1.0

@Created      2019, 6, 22

@Description

@HISTORY:

******************************************************************************/
#ifndef XE_MAGCI_CORE_MAKEUP_UTILITY_H
#define XE_MAGCI_CORE_MAKEUP_UTILITY_H

#include "XESingleton.h"
#include "XHashTable.h"
#include "XFileReadMem.h"
#include "XFileBase.h"

/*
* 对应bin\FilterFaceDecoration\FilterFaceDecoration.xml
*/
class XEFaceMakeupFilterManager 
	: public XESingleton<XEFaceMakeupFilterManager>
{
public:
	XEFaceMakeupFilterManager();
	~XEFaceMakeupFilterManager();
	xbool		                 LoadFaceMakeupFilterConfig(const XString& strConfigPath);
	xbool		                 SaveFaceMakeupFilterConfig();
	xbool		                 RegisterMakeupBlendInfo(const XString& strModeName,const XString& strMaterialDesPath);
	xbool		                 UnRegisterMakeupBlendInfo(const XString& strModeName);
	void                         Clear();
	void						 GetAllBlendMode(XArray<XString>& aBlendModeList); 
	xbool						 GetMaterialDescPath(const XString& strBlendMode, XString& strMaterialDescPath);
private:		                 
	void		                 LoadInfos(XFileReadMem* pFile);
	void		                 SaveInfos(XFileBase* pFile);
private:		             
	XString						 m_strConfigFilePath;
	XHashTable<XString, XString> m_htModeToMaterialPath;//blend mode => material desc path
};

#endif
