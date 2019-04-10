/******************************************************************************

@File         XEPhysicsSkeletalRoot.h

@Version       1.0

@Created      2018,8, 29

@HISTORY:

******************************************************************************/

#ifndef XE_PHYSICS_SKELETAL_ROOT_H
#define XE_PHYSICS_SKELETAL_ROOT_H

#include "XEUserNode.h"
#include "IXSkeletalBody.h"
/*
* XEPhysicsSkeletalRoot:����һ��phy ��Դ������ײ��У�phy��Դ·����IXSkeletalPhysicsRes*��һһ��Ӧ�ġ�
* ��˲��ܼ���XEPhysicsSkeletalRoot*��ֻҪ���ص�phy��Դ·��һ�£�������XEPhysicsSkeletalRoot*����ͬһ��IXSkeletalPhysicsRes*��
* //һ��ģ�Ϳ��ܼ����˶��phy��Դ����ͬʱ�����õ����ҽ���һ��phy��Ҳ����XEPhysicsSkeletalRootָ�룩
*/
class XEPhysicsConstraint;
class XEPhysicsSkeletalBody;
class IXSkeletalPhysicsRes;

class XEPhysicsSkeletalRoot : public XEUserNode
{
public:
											XEPhysicsSkeletalRoot();
	virtual								    ~XEPhysicsSkeletalRoot();
	virtual void                            Release() override;
	virtual Manager*						GetNodeManager() override{ return m_pNodeManager; }
	XString&								GetSkeAssetPath(){ return m_strSkeAssetPath; }
	XString									GetPhyAssetPath();//phy asset

	//phy asset
	xbool									LoadSkeletalPhyAsset(const xchar* szPhyResPath, const xchar* szSkePath);//forbidden to reload! As the phys resource will be mapped to the same file.
	IXSkeletalPhysicsRes*					GetXSkeletalPhysicsRes(){ return m_pSkeletalPhyRes; }
	xbool									GetIsModify(){ return m_bIsModify; }
	void									SetIsModify(xbool bIsModify){ m_bIsModify = bIsModify; }
	xbool									Save();
public:
	//create or remove body in physics world
	xbool									CreateSkeletalBodyInPhysicsWorld(const xchar* szBoneName);
	xbool									CreateConstraintInPhysicsWorld(const xchar* szBone1Name, const xchar* szBone2Name);
	void									RemovePhysicsSkeletalBodyFromPhysicsWorld(XEPhysicsSkeletalBody* pBodyTemp);
	void									RemoveConstraintFromPhysicsWorld(const xchar* szBone1Name,const xchar* szBone2Name);
	//create or remove node
	XEPhysicsSkeletalBody*					CreatePhysicsSkeletalBodyNode(const xchar* szBoneName);
	XEPhysicsConstraint*					CreateConstraintNode(const xchar* szBone2Name, const xchar* szBone1Name);
	//remove body node or constraint node
	void									RemoveNodeTempate(XEUserNode* pNode, xbool bIncludeChild = xfalse, xbool bReleaseMemory = xtrue, xbool bReleaseNodes = xtrue);

private:
	XEPhysicsSkeletalBody*					IsExistPhysicsSkeletalBodyNode(const xchar* szNodeName);
	XEPhysicsConstraint*					IsExistXEPhysicsConstraint(XString strConstraintNodeName);
	void									RemoveAllSkeletalNode();
	XEPhysicsSkeletalBody*					GetSkeletalBodyNode(const xchar* szNodeName);
	void									RemoveBodyRefConstraintNode(XEPhysicsSkeletalBody* pBodyTemp);
public:
	XE_USER_NODE_CAST(XEPhysicsSkeletalRoot)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
	static const XString  SUFFIX;
private:
	XString									m_strSkeAssetPath;//ske asset path
	Manager*								m_pNodeManager;
	IXSkeletalPhysicsRes*					m_pSkeletalPhyRes;
	xbool									m_bIsModify;
};

#endif