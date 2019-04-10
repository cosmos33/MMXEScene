/******************************************************************************

@File         XEPropertyObjectBase.h

@Version       1.0

@Created      2017, 10, 25

@Description  The class ids of each class in X Editor

@HISTORY:

******************************************************************************/
#ifndef _XE_PROPERTYOBJECTBASE_H
#define _XE_PROPERTYOBJECTBASE_H
#include "XEProperty.h"

//parent node,tree,index,name,editable,min,max,span,listArray = P,T,I,N,E,MI,MA,S,A
//editable is false by default
#define XE_CREATE_VALUE_PROPERTY(P,T,I,N) T.CreateValueProperty(P,N,I)
#define XE_CREATE_VALUE_PROPERTY_M(P,T,I,N,MA,MI,S) T.CreateValueProperty(P,N,I,"",1U,1U,1U,MA,MI,S)
//parent node,tree,index,name = P,T,I,N
#define XE_CREATE_SET_VALUE_PROPERTY(P,T,I,N) GetPropertyValue(*T.CreateValueProperty(P,N,I))
//parent node,tree,index,name,editable = P,T,I,N,E
#define XE_CREATE_SET_VALUE_PROPERTY_E(P,T,I,N,E) GetPropertyValue(*T.CreateValueProperty(P,N,I,"",1U,1U,E))
//parent node,tree,index,name,max,min,span = P,T,I,N,MA,MI,S
#define XE_CREATE_SET_VALUE_PROPERTY_M(P,T,I,N,MA,MI,S) GetPropertyValue(*T.CreateValueProperty(P,N,I,"",1U,1U,1U,MA,MI,S))
//parent node,tree,index,name,listArray = P,T,I,N,A
#define XE_CREATE_SET_VALUE_PROPERTY_CMB(P,T,I,N,A) if(XEValueProperty* pProperty = T.CreateValueProperty(P,N,I)){pProperty->SetComboBoxStr(0, A, false); GetPropertyValue(*pProperty);}
//parent node,tree,index,name,spritePath = P,T,I,N,SP
#define XE_CREATE_SET_VALUE_PROPERTY_9S(P,T,I,N,SP) if(XEValueProperty* pProperty = T.CreateValueProperty(P,N,I,"",1U,1U,1U,1.0,0.0,0.01)){pProperty->Set9SliceSpritePath(SP); GetPropertyValue(*pProperty);}

class XEPropertyObjectProxy;
class XEPropertyObjectBase 
	:public XEPropertyObject
{
public:
	                              XEPropertyObjectBase() :m_pPropertyObjectProxy(NULL), m_nStartIndex(0), m_nEndIndex(0){};
	virtual                       ~XEPropertyObjectBase(){}
	virtual void                  ClearCache(){}
	inline void                   SetPropertyObjectProxy(XEPropertyObjectProxy* pProxy){ m_pPropertyObjectProxy = pProxy; }
	inline XEPropertyObjectProxy* GetPropertyObjectProxy(){ return m_pPropertyObjectProxy; }
	inline void                   SetStartIndex(xint32 nIndex){ m_nStartIndex = nIndex; }
	inline xint32                 GetStartIndex()const{ return m_nStartIndex; }
	inline void                   SetEndIndex(xint32 nIndex){ m_nEndIndex = nIndex; }
	inline xint32                 GetEndIndex()const{ return m_nEndIndex; }
protected:
	XEPropertyObjectProxy*        m_pPropertyObjectProxy;
	xint32                        m_nStartIndex;
	xint32                        m_nEndIndex;
};

#define XE_PROPERTY_OBJ_DEFAULT_TYPE_NAME(T) #T

//bNotify,Node = b,N
#define XE_PROPERTY_DISPATCH_CHANGED(b,N)\
if (b)\
{\
OnPropertyChangeBegin(N);\
OnPropertyChangeEnd(N);\
}\

//bNotify,Node = b,N
#define XE_PROPERTY_DISPATCH_CHANGED_BEGIN(b,N)\
if (b)\
{\
OnPropertyChangeBegin(N);\
}\

//bNotify,Node = b,N
#define XE_PROPERTY_DISPATCH_CHANGED_END(b,N)\
if (b)\
{\
OnPropertyChangeEnd(N);\
}\

#endif // _XE_PROPERTYOBJECTBASE_H
