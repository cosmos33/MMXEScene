//
//  XESWorld.h
//  XEScene
//
//  Created by momo783 on 05/02/2018.
//

#ifndef XESWORLD_H_
#define XESWORLD_H_

#include "core/XESDefine.h"
#include "XECore/XEWorld.h"

XESCENE_NAMESPACE_BEGIN

class World : public XEWorld, public XClass {

public:
    class WorldListener {

    public:
        virtual void OnWorldAddActor(XEActor *aActor) = 0;

        virtual void OnWorldWillRemoveActor(XEActor *aActor) = 0;

        virtual void OnWorldUpdateActor(XEActor *aActor, XString strNewActorName) = 0;

        virtual void OnWorldTick(xfloat32 fDel) = 0;

        virtual void OnWorldTickComplete(xfloat32 fDel) = 0;

    };

public:
    X_CLASS_DEF(xes::World);

    World();

    virtual ~World();

    virtual void Tick(xfloat32 fDel) override;

    virtual xbool LoadScene(const xchar *pRelativePath, xbool bUseRelPathAsHome = xtrue) override;

    virtual XEActor *CreateActor(const XString &strActorType) override;//With the type of Actor.

    virtual XEActor *CreateActor(const XString &strActorType, const XString &strActorName) override;

    virtual void DeleteActor(XEActor *pActor) override;

    virtual XEActor *UpdateNameOfActor(const XString &strActorOldName, const XString &strActorNewName) override;

public:

    XESS_IGNORE void AddWorldListener(WorldListener *mWorldListener);

    XESS_IGNORE void RemoveWorldListener(WorldListener *mWorldListener);

public:

    /**
     * @deprecated
     * 等价于@IsTickable
     * @return
     */
    inline xbool IsHaveTick() {
        return m_bTickable;
    }

public:

    /**
     * 克隆Actor
     * @param pActor
     * @return
     */
    XEActor *CloneActor(XEActor *pActor);

    /**
     * 克隆Actor
     * @param pActor
     * @param strCloneActorName
     * @return
     */
    XEActor *CloneActor(XEActor *pActor, XString strCloneActorName);

private:
    WorldListener *m_lWorldListener;
};

XESCENE_NAMESPACE_END

//typedef XESCENE_NAMESPACE::World XEControllerRootWorld;

#endif /* XESWORLD_H_ */
