﻿/******************************************************************************

@File         XEPhysicsSkeletalBody.h

@Version       1.0

@Created      2018,8, 29

@HISTORY:

******************************************************************************/

#ifndef XE_PHYSICS_SKELETAL_BODY_H
#define XE_PHYSICS_SKELETAL_BODY_H

#include "XEUserNode.h"
#include "XString.h"
#include "XEPhysicsShapeElem.h"
#include "IXSkeletalBody.h"
#include "IXPhysicsRes.h"

class XEBone;
class XEPhysicsConstraint;
class IXSkeletalPhysicsRes;
class XEPhysicsSkeletalRoot;
class XEPhysicsSkeletalBody : public XEUserNode
{
public:
	XEPhysicsSkeletalBody();
	virtual								    ~XEPhysicsSkeletalBody();
	virtual void                            Release() override;
	const char*								GetBoneNameWithBody();
	void									SetIXSkeletalBody(IXSkeletalBody* pBody);
	IXSkeletalBody*							GetIXSkeletalBody(){return m_pSkeletalBody; }
	void									CreateShapeElem();
	void									UpdateShapeElem(IXSkeletalBody* pBody);
	XEPhysicsShapeElem*						IsExistXEPhysicsShapeElemNode(XString strShapeNodeName);
	XEPhysicsSkeletalRoot*					GetPhysicsSkeletalRoot();
	XArray<IXSkeletalPhysicsRes::XPhyConstraintBoneNames>&	GetBindConstraintNamePair(){ return m_aConstraintNamePair; }

	void									AddBindConstraintNamePair(const xchar* szBone1Name,const xchar* szBone2Name);
	void									RemoveBindConstraintNamePair(const xchar* szBone1Name, const xchar* szBone2Name);
	void									ClearBindConstraintNamePair();
	void									RemoveConstraintTemplate(XEUserNode* pConstraintTemp);

	//当前刚体节点关联的约束节点，例如根据BodyNode1和BodyNode2创建了一个约束，则不包含约束节点的刚体节点下会记录关节节点名称
	void									AddRefConstraintNodeName(const XString& strConstraintNodeName);
	XArray<XString>&						GetAllRefConstraintNodeNames(){ return m_aRefConstraintNodeName; }
	xbool									GetAllRefConstraintNodeNames(XArray<XString>& aRefConstraintNodeNames);
	void									ClearRefConstraintNodeName(const XString& strConstraintNodeName);
	void									ClearAllRefConstraintNodeNames();
public:
	XE_USER_NODE_CAST(XEPhysicsSkeletalBody)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;

protected:
	XArray<IXSkeletalPhysicsRes::XPhyConstraintBoneNames>			m_aConstraintNamePair;
	IXSkeletalBody*													m_pSkeletalBody;
	XArray<XString>													m_aRefConstraintNodeName;
};

#endif