/******************************************************************************

@File         XEInstanceManagerPhysicsSkeletal.h

@Version       1.0

@Created      2017,12, 22

@HISTORY:

******************************************************************************/
#ifndef XE_INSTANCE_MANAGER_PHYSICS_SKELTAL_H
#define XE_INSTANCE_MANAGER_PHYSICS_SKELTAL_H

#include "XESingleton.h"
#include "XTypes.h"
#include "XString.h"
#include "XEUserNode.h"
#include "XEInstanceManagerBase.h"
#include "XEPhysicsSkeletalRoot.h"

class XEPhysicsSkeletalRootInstance;
class XESkeleton;
//一个XEPhysicsSkeletalRoot 对应一个phy资源
class XEInstanceManagerPhysicsSkeletal
	: public XEInstanceManagerBase
	, public XESingleton<XEInstanceManagerPhysicsSkeletal>
{
public:
	XEInstanceManagerPhysicsSkeletal();
	~XEInstanceManagerPhysicsSkeletal(){}

public:
	virtual XEUserNode*						CreateTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld) override;
	virtual XEUserNode*						GetTemplate(const xchar* szAssetFile, XEWorld* pOwnerWorld, xbool bReload = xfalse) override;
	virtual void							Reload(const xchar* szAssetFile = NULL) override;
	virtual void							SaveImpl() const override;
	virtual xbool							IsNodesModifiedImpl()const override;
public:
	//多一个szSkePath参数，因此重载此函数
	XEUserNodeInstance*						CreateInstance(const xchar* szPhyResPath, const xchar* szSkePath, XEWorld* pOwnerWorld);
	//更新骨架模板
	void									UpdateSkeletalPhyNodeForSkeletonTemplate(XESkeleton* pSkeletonTemplate);
private:
	XEUserNode*								CreatePhyTemplate(const xchar* szPhyResPath, const xchar* szSkePath, XEWorld* pOwnerWorld);
	void									AttachPhysicsBodyTempateToSkeletonTemp(XEPhysicsSkeletalBody* pBodyTemplate,XESkeleton* pSkeletonTp);
	void									AttachPhysicsConstraintTempateToSkeletonTemp(XEPhysicsConstraint* pConstraintTemplate, XESkeleton* pSkeletonTp);
	XEPhysicsSkeletalRoot*					FindPhysicsSkeletalRootTemplate(XESkeleton* pSkeletonTemplate);
	void									RemoveBodyTemplateFromSkeletonManager(XETreeNode::NodeList& bodyNodesInSkeleton, XEPhysicsSkeletalBody* pBodyTemplate);
	void									RemoveConstraintTemplateFromSkeletonManager(XETreeNode::NodeList& listConstraintInSkeleton, XEPhysicsConstraint* pConstraintTemplate);

	void									UpdateBodyConstraintPair(XEPhysicsSkeletalBody* pSkeletalBodyTemp, XEPhysicsConstraint* pConstraint);
public:
	//for lua side
	static XEInstanceManagerPhysicsSkeletal*GetInstanceManagerPhysicsSkeletal();
};

#endif // XE_INSTANCE_MANAGER_PHYSICS_SKELTAL_H
