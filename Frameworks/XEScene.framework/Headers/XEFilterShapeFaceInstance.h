/******************************************************************************

@File         XEFilterShapeFaceInstance.h

@Version       1.0

@Created      2019, 6, 27

@HISTORY:    Filter node instance

******************************************************************************/
#ifndef _XE_FILTER_SHAPE_FACE_INSTANCE_H_
#define _XE_FILTER_SHAPE_FACE_INSTANCE_H_

#include "XEFilterInstance.h"

class XEFilterShapeFace;
class XEFilterShapeFaceInstance 
	: public XEFilterInstance
{
public:
	XEFilterShapeFaceInstance(XEFilter* pNodeTl);
	virtual ~XEFilterShapeFaceInstance();
public:
	virtual void                                  Release() override;
	virtual void                                  Apply() override;//apply parameters from node-template.
	virtual void								  Tick(xfloat32 fInterval) override;
	XEFilterShapeFace*                            GetFilterShapeFaceTemplate() const;
	virtual void                                  SetVertexDesc(IXVertexDesc* pVertexDesc) override;
	virtual void                                  SetVertexBuffer(IXVertexBuffer* pVertexBuffer) override;
	virtual void                                  SetIndexBuffer(IXIndexBuffer* pIndexBuffer) override;
	virtual void								  SetEnabled(xbool bEnabled) override;//may be rebuild-material
	virtual xbool                                 IsValidForRender() override;
#if X_PLATFORM_WIN_DESKTOP | X_PLATFORM_MAC
	virtual XEPropertyObjectSet                   GetPropertyObjectSet(XEPropertyObjectProxy* pPropertyObjectProxy)override;
#endif
public:                      
	xbool                                         ReShapeKeypoint();
public:
	XE_USER_NODE_CAST(XEFilterShapeFaceInstance)
	XE_USER_NODE_TYPE_DEF(NODE_TYPENAME)
	static const XString  NODE_TYPENAME;
};



#endif // _XE_FILTER_SHAPE_FACE_INSTANCE_H_
