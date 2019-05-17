#ifndef _IX2DPHYSICALMANAGER_H_
#define _IX2DPHYSICALMANAGER_H_

#include "XMath3D.h"

class IX2DPhysicalScene;
class IX2DPhysicalManager : public XMemBase
{
public:
	virtual						~IX2DPhysicalManager() {};

	/**
	* 初始化
	*/
	virtual xbool				Init() = 0;

	/**
	* 释放
	* 会自动销毁所有未销毁的场景
	*/
	virtual void				Release() = 0;

	/**
	* 创建一个2D物理场景
	* @note 销毁时调用DestroyScene
	*
	* @param szSceneName 场景名称
	* @return 场景指针，创建失败返回NULL
	*/
	virtual IX2DPhysicalScene*	CreateScene(const xchar* szSceneName, const XVECTOR2& vGravity = XVECTOR2(0.0f, -9.8f)) = 0;
	
	/**
	* 获取一个2D物理场景
	* @param szSceneName 场景名称
	* @return 场景指针，不存在返回NULL
	*/
	virtual IX2DPhysicalScene*	GetScene(const xchar* szSceneName) = 0;
	/**
	* 销毁一个2D物理场景
	* @note 调用者delete
	*
	* @param szSceneName 场景名称
	* @param pScene 场景指针
	*/
	virtual void				DestroyScene(const xchar* szSceneName) = 0;
	virtual void				DestroyScene(IX2DPhysicalScene* pScene) = 0;
};

extern IX2DPhysicalManager* g_pIX2DPhysicalManager;

#endif

