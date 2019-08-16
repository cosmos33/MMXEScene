/******************************************************************************

@File         XEInstanceManager.h

@Version       1.0

@Created      2018,4, 27

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_INSTANCE_MANAGER_H
#define _XE_INSTANCE_MANAGER_H
#include "XMemBase.h"
#include "XHashTable.h"
#include "XArray.h"
#include "XEUserNode.h"
#include "XEWorld.h"

//template-nodes now will be managed by the world,  deleted by world when it is destroyed.
class XEInstanceManagerBase
	:public XMemBase
{
public:
	XEInstanceManagerBase();
	virtual ~XEInstanceManagerBase();
	typedef XArray<XEUserNodeInstance*> InstanceList;
	typedef XHashTable<XEUserNode*, InstanceList> TemplateInstanceMap;
	typedef XArray<XEInstanceManagerBase*> InstanceManagers;
public:
	virtual XEUserNode*         CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) = 0;//may have owner world.
	virtual XEUserNode*         GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) = 0;// get the template belong to the owner world.
	virtual void                Reload(const xchar* szAssetFile = NULL) = 0;//if no specific asset file, will reload all.
	virtual XEUserNodeInstance* CreateInstance(const xchar* szAssetFile, XEWorld* pOwnerWorld);
	virtual xbool               RemoveInstance(XEUserNodeInstance* pInsToRemove, xbool bReleaseMem = xtrue);
	virtual xbool               RemoveTemplate(XEUserNode* pTemplateToRemove);
	virtual void                Release();
	virtual void                SaveImpl() const{}
	virtual void                SaveAsImpl(const xchar* szPath) const{}
	virtual xbool               IsNodesModifiedImpl()const{ return xfalse; }
	virtual xbool				IsMatchFileType(const XString& szPath){ return xfalse; }
	static void					ReloadResource(const XArray<XString>& pathList);
	static xint32               RemoveAllTemplateInWorld(XEWorld* pWorld);//both in editor and runtime
	static void                 ReleaseAllTemplate();//both in editor and runtime
	static InstanceManagers&    GetRuntimeInstanceManagers();
	static InstanceManagers&    GetEditingInstanceManagers();

#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	//editor only.
	static void                 Save();
	static void                 SaveAs(const xchar* szPath);
	static xbool                IsNodesModified();
#endif
public:
	//convenient using...
	template<typename T> 
	T*     CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld);
	template<typename T>
	T*     GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse);
	template<typename T>
	T*     CreateInstance(const xchar* szAssetFile, XEWorld* pOwnerWorld);
	template<typename T>
	static T*&                             GetInstance();
	template<typename T>				   
	static void                            RegisterManager(T* pMgr,xbool bRuntime);
	template<typename T>				   
	static void                            UnregisterManager(xbool bRuntime);

	InstanceList*                          GetInstanceList(XEUserNode* pTemplateNode);
	InstanceList                           GetAllInstances();
	X_FORCEINLINE TemplateInstanceMap&     GetTemplateInstanceMap(){ return m_mapTemplateInstance; }
	xint32                                 RemoveTemplateInWorld(XEWorld* pWorld);
	xbool                                  HasTemplate(XEUserNode* pTemplate);
	xbool                                  HasInstance(XEUserNodeInstance* pInstance);
	void								   SetNeedEditForRuntime(xbool bEdit){ m_bNeedEditForRuntime = bEdit; }
	xbool								   IsNeedEditForRuntime(){ return m_bNeedEditForRuntime; }//如果当前管理器只有编辑或运行一种类型时，需要设置此值
protected:
	TemplateInstanceMap					   m_mapTemplateInstance;
	xbool								   m_bNeedEditForRuntime;
	static InstanceManagers                s_runtimeInstanceManagers;
	static InstanceManagers                s_editInstanceManagers;
};

template<typename T>
void XEInstanceManagerBase::UnregisterManager(xbool bRuntime)
{
	T*& mgr = GetInstance<T>();
	InstanceManagers& instanceMgrs = bRuntime ? GetRuntimeInstanceManagers() : GetEditingInstanceManagers();
	instanceMgrs.Remove(mgr);
	mgr = NULL;
}

template<typename T>
void XEInstanceManagerBase::RegisterManager(T* pMgr, xbool bRuntime)
{
	InstanceManagers& instanceMgrs = bRuntime ? GetRuntimeInstanceManagers() : GetEditingInstanceManagers();
	T*& mgr = GetInstance<T>();
	ASSERT(NULL == mgr);//check your manager instance,please.
	if (mgr) return;//ensure again.
	mgr = pMgr;
	instanceMgrs.AddUnique(mgr);//ensure again.
}

template<typename T>
T*& XEInstanceManagerBase::GetInstance()
{
	static T* instance = NULL;
	return instance;
}

template<typename T>
T* XEInstanceManagerBase::CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld)
{
	if (XEUserNode* pUserNode = CreateTemplate(szAssetFile, pOwnerWorld))
		return pUserNode->CastToUserNode<T>();
	return NULL;
}

template<typename T>
T* XEInstanceManagerBase::GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload /*= xfalse*/)
{
	if (XEUserNode* pUserNode = GetTemplate(szAssetFile, pOwnerWorld, bReload))
		return pUserNode->CastToUserNode<T>();
	return NULL;
}


template<typename T>
T* XEInstanceManagerBase::CreateInstance(const xchar* szAssetFile, XEWorld* pOwnerWorld)
{
	if (XEUserNodeInstance* pUserNodeIns = CreateInstance(szAssetFile,pOwnerWorld))
		return pUserNodeIns->CastToUserNode<T>();
	return NULL;
}

template<typename T>
class XEInstanceManagerRuntimeAutoRegisterWorker
{
public:
	XEInstanceManagerRuntimeAutoRegisterWorker()
	{
		XEInstanceManagerBase::RegisterManager<T>(&factoryManager_, xtrue);
	}
	~XEInstanceManagerRuntimeAutoRegisterWorker()
	{
		XEInstanceManagerBase::UnregisterManager<T>(xtrue);
	}
	T factoryManager_;
};

template<typename T>
class XEInstanceManagerEditingAutoRegisterWorker
{
public:
	XEInstanceManagerEditingAutoRegisterWorker()
	{
		XEInstanceManagerBase::RegisterManager<T>(&factoryManager_, xfalse);
	}
	~XEInstanceManagerEditingAutoRegisterWorker()
	{
		XEInstanceManagerBase::UnregisterManager<T>(xfalse);
	}
	T factoryManager_;
};

#define INSTANCE_MANAGER_IMPL(T) static T* GetInstance(){ if(T* pIns = XEInstanceManagerBase::GetInstance<T>()) return pIns; ASSERT("#T::GetInstance() Is NULL"&&0);return NULL; }
#define INSTANCE_MANAGER_RUNTIME_MGR_GENERATE(T) static XEInstanceManagerRuntimeAutoRegisterWorker<T> s_ManagerRuntimeAutoRegWorker##T;
#define INSTANCE_MANAGER_EDITING_MGR_GENERATE(T) static XEInstanceManagerEditingAutoRegisterWorker<T> s_ManagerEditingAutoRegWorker##T;
#define SET_EDIT_FOR_RUNTIME(T,B) if(T* pIns = XEInstanceManagerBase::GetInstance<T>()){ pIns->SetNeedEditForRuntime(B);}

#endif // _XE_INSTANCE_MANAGER_H
