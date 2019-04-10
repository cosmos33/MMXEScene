/******************************************************************************

@File         XEPropertyObjectUINode.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef XEPROPERTYOBJECTUINODE_H
#define XEPROPERTYOBJECTUINODE_H
#include "XEFactoryPropertyObjectUtil.h"
#include "XEPropertyObjectBase.h"
#include "XELocalization.h"

#define UINODE_SetPropValue(S, G) pNode->Set##S(pValueProperty->Get##G());
#define UINODE_GetPropValue(G, S) pValueProperty->Set##S(pNode->Get##G()); 

class XUINode;
class XEPropertyObjectUINode 
	:public XEPropertyObjectBase
{
public:
	class Listener
	{
	public:
		virtual void PropertyNameChanged(XUINode* _pNode, const XString& _name) = 0;
		virtual void PropertyCanvasResize(const int& _width, const int& _height){};
		virtual void PropertyRefreshContentSize(){};
	};

public:
	void AddListener(Listener *pListener);
	
protected:
	XArray<Listener*> m_vListener;

public:
	XEPropertyObjectUINode();
	~XEPropertyObjectUINode(){};
	enum{ 
		PROPERTY_NODE = XEPropertyTree::USER_PROPRETY_INDEX,
		PROPERTY_NAME,
		PROPERTY_POSITION,
		PROPERTY_ROTATION,
		PROPERTY_SCALE ,
		PROPERTY_LOCALZORDER,
		PROPERTY_GLOBALZORDER,
		PROPERTY_ANCHORPOINT,
		PROPERTY_CONTENTSIZE,
		PROPERTY_VISIBLE,

		PROPERTY_UINODE_END
	};
public:
	virtual xbool	GetPropertyTree(xint32 nFilter, XEPropertyTree &PropTree) override;
	virtual	xbool	SetPropertyValue(const XEProperty &Node, xbool bNotifyPropertyChanged = xtrue) override;
	virtual	xbool	GetPropertyValue(XEProperty &Node) override;

};

#endif // XEPROPERTYOBJECTWORLD_H
