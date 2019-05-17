//
// Created by momo783 on 2019/3/31.
//

#ifndef PODS_XESMAGICCORECVBRIDGE_H
#define PODS_XESMAGICCORECVBRIDGE_H

#include "core/XESDefine.h"
#include "XEMagicCore/XEDecorationEnvBridgeBase.h"

XESCENE_NAMESPACE_BEGIN

class MagicCoreCVBridge : public XEDecorationEnvBridgeBase {
public:
    MagicCoreCVBridge();

    ~MagicCoreCVBridge() override;

    void  SetSegmentationMaskBuffer(xuint8 *pMaskBuffer, xint32 &nSegmentationType, xint32 &nMaskSize, xint32 &nMaskWidth, xint32 &nMaskHeight);
    xbool GetSegmentationMaskBuffer(const xuint8 *&pMaskBuffer, xint32 &nSegmentationType, xint32 &nMaskSize, xint32 &nMaskWidth, xint32 &nMaskHeight) override;

    XVECTOR4 GetSegmentationMaskRect() const override;

    void Initialize() override;

    xbool IsMMCVDetectValid() const override;

protected:
    xbool OnFaceLandmarkModified(const XEMagicCore::XEFaceEntity &modifyFace, xint32 nLandmarkIndex) override;

    void OnSegmentationProcessed() override;
    
private:
    xuint8 * m_bufferData;
    xint32 m_segmationType;
    xint32 m_bufferWidth;
    xint32 m_bufferHeight;
    xint32 m_bufferLength;
};

XESCENE_NAMESPACE_END

#endif //PODS_XESMAGICCORECVBRIDGE_H
