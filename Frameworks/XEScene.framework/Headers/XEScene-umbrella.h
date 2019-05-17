#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "XESDirector.h"
#import "D_XESEventDispatcher.h"
#import "XESAction.h"
#import "XESActionManager.h"
#import "XESAnimationAction.h"
#import "XESInstantAction.h"
#import "XESIntervalAction.h"
#import "XESSpeed.h"
#import "XESSplineAction.h"
#import "XESTweenAction.h"
#import "XESTweenFunction.h"
#import "XESAccelerationEvent.h"
#import "XESAccelerationEventListener.h"
#import "XESAttitudeEvent.h"
#import "XESAttitudeEventListener.h"
#import "XESCustomEvent.h"
#import "XESCustomEventListener.h"
#import "XESCVAboutEvent.h"
#import "XESCVAboutEventListener.h"
#import "XESDataEvent.h"
#import "XESDataEventListener.h"
#import "XESEvent.h"
#import "XESEventDispatcher.h"
#import "XESEventListener.h"
#import "XESExpressionEvent.h"
#import "XESExpressionEventListener.h"
#import "XESFaceEvent.h"
#import "XESFaceEventListener.h"
#import "XESGestureEvent.h"
#import "XESGestureEventListener.h"
#import "XESGestureEventListenerV1.h"
#import "XESHandEvent.h"
#import "XESHandEventListener.h"
#import "XESTouchEvent.h"
#import "XESTouchEventListener.h"
#import "XEScheduler.h"
#import "XESCVAbout.h"
#import "XESDefine.h"
#import "XESFace.h"
#import "XESFileUtils.h"
#import "XESGeometry.h"
#import "XESHand.h"
#import "XESObject.h"
#import "XESObjectManager.h"
#import "XESPoints.h"
#import "XESSensor.h"
#import "XESSpline.h"
#import "XESSystemEventDispatcher.h"
#import "XESTouch.h"
#import "XESScriptEngine.h"
#import "XESScriptEngineManager.h"
#import "XESScene.h"
#import "XESWindow.h"
#import "XESWorld.h"
#import "XESAnimojiFaceTrack.h"
#import "XESSceneAnimojiFilter.h"
#import "XESGameMessageHandler.h"
#import "XESSceneGameExpressionFilter.h"
#import "XESSceneGameFilter.h"
#import "XESMagicCoreCVBridge.h"
#import "XESSceneMagicConfig.h"
#import "XESSceneMagicFilter.h"
#import "XESModule.h"
#import "XESModuleDetector.h"
#import "XESModuleMaker.h"
#import "XESModuleManager.h"
#import "XESModuleTrigger.h"
#import "XESModuleTriggerCV.h"
#import "XESModuleTriggerFace.h"
#import "XESModuleTriggerSensor.h"
#import "XESModuleTriggerTouch.h"
#import "XESMoodFaceTrack.h"
#import "XESSceneMoodFilter.h"
#import "XESMessageHandler.h"
#import "XESSceneADFilter.h"
#import "XESSceneFilter.h"
#import "XESSceneFilterManager.h"
#import "XESSceneLowVersionVideoConfig.h"
#import "XESSceneLowVersionVideoFilter.h"
#import "XESSceneNewADFilter.h"
#import "XESSceneVideoConfig.h"
#import "XESSceneVideoFilter.h"
#import "XESSceneVideoGameConfig.h"
#import "XESSceneVideoGameFilter.h"
#import "XESMessageAction.h"
#import "XESMessageActor.h"
#import "XESMessageDown.h"
#import "XESMessageEvent.h"
#import "XESMessageGame.h"
#import "XESMessageOld.h"
#import "XESMessageUp.h"
#import "XESMessageUpEvent.h"
#import "XESMessage.h"
#import "XESMessageManager.h"
#import "XESDevice.h"
#import "XESLogger.h"
#import "XESDisplayView.h"
#import "XEARAnchor.h"
#import "XEAREnumType.h"
#import "XEARMathUtil.h"
#import "XESARModule.h"
#import "XEAudioEngine.h"
#import "XEAudioMacros.h"
#import "XEAudioManager.h"
#import "XEDenshion.h"
#import "XEOpenALSupport.h"
#import "XESimpleAudioEngine.h"
#import "MMARElelment.h"
#import "allocators.h"
#import "cursorstreamwrapper.h"
#import "document.h"
#import "encodedstream.h"
#import "encodings.h"
#import "filereadstream.h"
#import "filewritestream.h"
#import "fwd.h"
#import "istreamwrapper.h"
#import "memorybuffer.h"
#import "memorystream.h"
#import "ostreamwrapper.h"
#import "pointer.h"
#import "prettywriter.h"
#import "rapidjson.h"
#import "reader.h"
#import "schema.h"
#import "stream.h"
#import "stringbuffer.h"
#import "writer.h"
#import "en.h"
#import "error.h"
#import "biginteger.h"
#import "diyfp.h"
#import "dtoa.h"
#import "ieee754.h"
#import "itoa.h"
#import "meta.h"
#import "pow10.h"
#import "regex.h"
#import "stack.h"
#import "strfunc.h"
#import "strtod.h"
#import "swap.h"
#import "XAnimatable.h"
#import "XAnimation.h"
#import "XAnimationSequence.h"
#import "XAnimController.h"
#import "XAnimInstanceData.h"
#import "XAnimMultiLayer.h"
#import "XAnimParameterPack.h"
#import "XAnimTrack.h"
#import "XBlendShapeAnim.h"
#import "XBoneMap.h"
#import "XFaceRigAnim.h"
#import "XPinchFaceControl.h"
#import "XPose.h"
#import "XSkelAnimController.h"
#import "XSkeletonMap.h"
#import "XSkeletonMask.h"
#import "XSkelMorphController.h"
#import "XTimeline.h"
#import "XAudioBase.h"
#import "XAudioController.h"
#import "XAudioJniHelper.h"
#import "XAudioListener.h"
#import "XAudioMacros.h"
#import "XAudioManager.h"
#import "XAudioProperties.h"
#import "XAudioSource.h"
#import "FxElement.h"
#import "FxGlobal.h"
#import "FxInstance.h"
#import "FxModule.h"
#import "FxParticleSystem.h"
#import "FxProperty.h"
#import "FxPropertyObject.h"
#import "XCurve.h"
#import "XDistribution.h"
#import "IX2DJoint.h"
#import "IX2DPhysicalManager.h"
#import "IX2DPhysicalScene.h"
#import "IX2DRigidBody.h"
#import "IX2DShape.h"
#import "IXCloth.h"
#import "IXConstraint.h"
#import "IXPhysicsRes.h"
#import "IXPhysicsScene.h"
#import "IXRigidBody.h"
#import "IXSkeletalBody.h"
#import "IXSkeletalPhysicsInstance.h"
#import "PhysicalManager.h"
#import "XEngineUI.h"
#import "XGestureManager.h"
#import "XUIAbstractCheckButton.h"
#import "XUIAction.h"
#import "XUIActionInstant.h"
#import "XUIActionInterval.h"
#import "XUIActionManager.h"
#import "XUIAssist.h"
#import "XUIButton.h"
#import "XUICallFunc.h"
#import "XUIChatView.h"
#import "XUICheckBox.h"
#import "XUIColorTo.h"
#import "XUIComboBox.h"
#import "XUIDialog.h"
#import "XUIDynamicListView.h"
#import "XUIEditBox.h"
#import "XUIEvent.h"
#import "XUIEventTouch.h"
#import "XUIFiniteTimeAction.h"
#import "XUIGeometry.h"
#import "XUIGlobalAssist.h"
#import "XUIGuidePage.h"
#import "XUIImage.h"
#import "XUIImageArray.h"
#import "XUIImeDelegate.h"
#import "XUIJniHelper.h"
#import "XUILabel.h"
#import "XUILabelCyclicRoll.h"
#import "XUILayout.h"
#import "XUILayoutParameter.h"
#import "XUIListView.h"
#import "XUIManager.h"
#import "XUIMessageBox.h"
#import "XUIMessageTip.h"
#import "XUIMoveBy.h"
#import "XUIMoveTo.h"
#import "XUINode.h"
#import "XUIPageView.h"
#import "XUIProgressBar.h"
#import "XUIRadioButton.h"
#import "XUIRichText.h"
#import "XUIRotateBy.h"
#import "XUIRotateTo.h"
#import "XUIScaleBy.h"
#import "XUIScaleTo.h"
#import "XUIScene.h"
#import "XUIScrollView.h"
#import "XUISequence.h"
#import "XUISlider.h"
#import "XUISpawn.h"
#import "XUISpeed.h"
#import "XUITabControl.h"
#import "XUITouch.h"
#import "XUITreeView.h"
#import "XUIWidget.h"
#import "XUIWidgetAlignment.h"
#import "tinyxml2_XEngine.h"
#import "XAndroidSys.h"
#import "XAndroidTypes.h"
#import "XAPKFile.h"
#import "XApplication.h"
#import "XArray.h"
#import "XBase3DTypes.h"
#import "XBaseCamera.h"
#import "XBaseCoordSpace.h"
#import "XBaseTM.h"
#import "XBitArray.h"
#import "XBlendShapeManager.h"
#import "XBlendShapeTarget.h"
#import "XBone.h"
#import "XBoneController.h"
#import "XBrush.h"
#import "XCameraViewFrustum.h"
#import "XCanvasBase.h"
#import "XClass.h"
#import "XClassReflector.h"
#import "XConsoleManager.h"
#import "XCrc.h"
#import "XCriticalSection.h"
#import "XCustomGeometry.h"
#import "XEngineRoot.h"
#import "XFileAnalyseTool.h"
#import "XFileBase.h"
#import "XFileHelper.h"
#import "XFileReadMem.h"
#import "XGlobalFuncs.h"
#import "XHashTable.h"
#import "XInternalResource.h"
#import "XJoint.h"
#import "XLightBase.h"
#import "XLinkList.h"
#import "XMaterial.h"
#import "XMath3D.h"
#import "XMemBase.h"
#import "XMemory.h"
#import "XMeshRenderBase.h"
#import "XModel.h"
#import "XModelInstance.h"
#import "XName.h"
#import "XObject.h"
#import "XOrthoCamera.h"
#import "XPerspectiveCamera.h"
#import "XPhysicalInterface.h"
#import "XPlatform.h"
#import "XPlatformWindow.h"
#import "XPoint.h"
#import "XPrimitiveBase.h"
#import "XRectangle.h"
#import "XRefCount.h"
#import "XRenderSystemBase.h"
#import "XResource.h"
#import "XScopedBufferPtr.h"
#import "XSkeleton.h"
#import "XSkin.h"
#import "XSkinData.h"
#import "XSparseArray.h"
#import "XStaticArray.h"
#import "XStats.h"
#import "XString.h"
#import "XSys.h"
#import "XTexture.h"
#import "XThread.h"
#import "XThreadComm.h"
#import "XThreadMain.h"
#import "XThreadManager.h"
#import "XTypes.h"
#import "XViewport.h"
#import "XWaterPrimitive.h"
#import "XWinSys.h"
#import "XWinTypes.h"
#import "XWorld.h"
#import "XXMLExtendTool.h"
#import "XXOSSys.h"
#import "XXOSTypes.h"
#import "IXEInterface.h"
#import "XEALPolygon.h"
#import "XEAttachDetachRules.h"
#import "XEBindUserNodeData.h"
#import "XEBroadcast.h"
#import "XECmdHelper.h"
#import "XEHitResult.h"
#import "XEIteratorWrapper.h"
#import "XELocalization.h"
#import "XEMath.h"
#import "XEPathFileTool.h"
#import "XESingleton.h"
#import "XETreeNode.h"
#import "XEUtility.h"
#import "XEVariant.h"
#import "XEActor.h"
#import "XE2DRectangleActor.h"
#import "XE3DTextureActor.h"
#import "XEAmbientSoundActor.h"
#import "XEAnimationFaceRigActor.h"
#import "XEAnimationMeshActor.h"
#import "XEAuxiliaryLineActor.h"
#import "XECameraActor.h"
#import "XEDirLightActor.h"
#import "XEDummyActor.h"
#import "XEEnvLightActor.h"
#import "XEGroundGridActor.h"
#import "XEParticleSystemActor.h"
#import "XEPointLightActor.h"
#import "XESceneARAdsActor.h"
#import "XESceneARAdsVideoActor.h"
#import "XESceneSequenceActor.h"
#import "XESkySphereActor.h"
#import "XESpotLightActor.h"
#import "XEStaticMeshActor.h"
#import "XETriggerBaseActor.h"
#import "XETriggerBoxActor.h"
#import "XETriggerSphereActor.h"
#import "XEUISceneActor.h"
#import "XEWindActor.h"
#import "XEActorComponent.h"
#import "XE2DRectangleComponent.h"
#import "XE3DTextureComponent.h"
#import "XEAnimatableFaceRigComponent.h"
#import "XEAnimatableModelComponent.h"
#import "XEAudioComponent.h"
#import "XECameraComponent.h"
#import "XEChildActorComponent.h"
#import "XELightComponent.h"
#import "XEMeshAppliqueComponent.h"
#import "XEModelComponent.h"
#import "XEOutlineComponent.h"
#import "XEParticleSystemComponent.h"
#import "XEPinchSkeletonComponent.h"
#import "XESceneARAdsComponent.h"
#import "XESceneARAdsVideoComponent.h"
#import "XESceneSequenceComponent.h"
#import "XEShapeComponent.h"
#import "XETriggerBoxComponent.h"
#import "XETriggerSphereComponent.h"
#import "XEWindComponent.h"
#import "XEActorComponentInclude.h"
#import "XEActorInclude.h"
#import "XEAnimBlend.h"
#import "XEAnimBlendBase.h"
#import "XEAnimBlendBaseInstance.h"
#import "XEAnimBlendController.h"
#import "XEAnimBlendInstance.h"
#import "XEAnimBlendLayerTrack.h"
#import "XEAnimBlendLayerTrackInstance.h"
#import "XEAnimComponentPlayList.h"
#import "XEAnimController.h"
#import "XEAnimControllerBase.h"
#import "XEAnimCurveFlyController.h"
#import "XEAnimMonBase.h"
#import "XEAnimMonBaseInstance.h"
#import "XEAnimMonController.h"
#import "XEAnimMonElement.h"
#import "XEAnimMonElementInstance.h"
#import "XEAnimMonNodeInclude.h"
#import "XEAnimMonNotify.h"
#import "XEAnimMonNotifyInstance.h"
#import "XEAnimMontage.h"
#import "XEAnimMontageInstance.h"
#import "XEAnimMonTrack.h"
#import "XEBindSocket.h"
#import "XEBindSocketInstance.h"
#import "XEBone.h"
#import "XEBoneInstance.h"
#import "XEAnimBlendEleModelAnimation.h"
#import "XEAnimBlendEleModelAnimationIns.h"
#import "XEAnimMonElementModelAnimation.h"
#import "XEAnimMonElementModelAnimationIns.h"
#import "XELayersAnimaPlay.h"
#import "XEMovementAttacher.h"
#import "XEAnimMonNotifyCloth.h"
#import "XEAnimMonNotifyParticle.h"
#import "XEAnimMonNotifyParticleIns.h"
#import "XEAnimMonNotifyPlayControl.h"
#import "XEAnimMonNotifySound.h"
#import "XEAnimMonNotifySoundIns.h"
#import "XESkeleton.h"
#import "XESkeletonInstance.h"
#import "XESocketListenerActor.h"
#import "XESocketListenerBase.h"
#import "XESocketListenerComponent.h"
#import "XESocketListenerInclude.h"
#import "XESocketListenerUserNodeIns.h"
#import "XEARAds.h"
#import "XEARAdsAnimController.h"
#import "XEARAdsBase.h"
#import "XEARAdsBinding.h"
#import "XEARAdsBindingActor.h"
#import "XEARAdsBindingActorComponent.h"
#import "XEARAdsBindingActorInstance.h"
#import "XEARAdsBindingActorParticle.h"
#import "XEARAdsBindingActorParticleInstance.h"
#import "XEARAdsBindingTransform.h"
#import "XEARAdsComponentPlayList.h"
#import "XEARAdsInstance.h"
#import "XEARAdsNodeInclude.h"
#import "XEARAdsTrackPlayRate.h"
#import "XEARAdsTrackPlayRateInstance.h"
#import "XEARAdsTrackSectionAnimation.h"
#import "XEARAdsTrackSectionAnimationInstance.h"
#import "XEARAdsTrackSectionVideo.h"
#import "XEARAdsTrackSectionVideoInstance.h"
#import "XEDressup.h"
#import "XEEngine.h"
#import "XEViewport.h"
#import "XEWin32Window.h"
#import "XEActorMovementEvent.h"
#import "XEActorVisibleEvent.h"
#import "XECustomEvent.h"
#import "XEPlayAnimationEvent.h"
#import "XESpawnParticleSystemEvent.h"
#import "XEVariantDataEvent.h"
#import "XECustomEventReceiver.h"
#import "XEGlobalReceiver.h"
#import "XEVariantDataReceiver.h"
#import "XEEventBase.h"
#import "XEEventInclude.h"
#import "XEEventList.h"
#import "XEEventManager.h"
#import "XEEventReceiver.h"
#import "XEEventUtil.h"
#import "XEFactoryActorComponentUtil.h"
#import "XEFactoryActorUtil.h"
#import "XEFactoryEventUtil.h"
#import "XEFactoryExtendParamUtil.h"
#import "XEFactoryPropertyObjectUtil.h"
#import "XEFactoryUIWidgetUtil.h"
#import "XEFactoryUserNodeUtil.h"
#import "XEFactoryUtil.h"
#import "XEGame.h"
#import "XEInstanceManagerARAds.h"
#import "XEInstanceManagerBase.h"
#import "XEInstanceManagerBlend.h"
#import "XEInstanceManagerInclude.h"
#import "XEInstanceManagerMaterialFx.h"
#import "XEInstanceManagerMontage.h"
#import "XEInstanceManagerMounter.h"
#import "XEInstanceManagerPhysicsSkeletal.h"
#import "XEInstanceManagerScript.h"
#import "XEInstanceManagerSequencer.h"
#import "XEInstanceManagerSkeleton.h"
#import "XELog.h"
#import "XEMaterialFx.h"
#import "XEMaterialFxInstance.h"
#import "XEMaterialFxNodeInclude.h"
#import "XEMatFxDistributionParameter.h"
#import "XEMatFxDistributionParameterInstance.h"
#import "XEMessageLog.h"
#import "XEModelMeshInclude.h"
#import "XEModelMeshLineColorInstance.h"
#import "XEModelMeshSkeletonNodeInstance.h"
#import "XEModelMeshVertexNodeInstance.h"
#import "XEAnimSocketMounter.h"
#import "XEAnimSocketMounterInstance.h"
#import "XEAnimSocketMounterNodeInclude.h"
#import "XEPhysicsClothConfig.h"
#import "XEPhysicsConstraint.h"
#import "XEPhysicsConstraintInstance.h"
#import "XEPhysicsNodeInclude.h"
#import "XEPhysicsShapeElem.h"
#import "XEPhysicsShapeElemInstance.h"
#import "XEPhysicsSkeletalActorNodeInstance.h"
#import "XEPhysicsSkeletalBody.h"
#import "XEPhysicsSkeletalBodyInstance.h"
#import "XEPhysicsSkeletalRoot.h"
#import "XEPhysicsSkeletalRootInstance.h"
#import "XEPrimitiveComponent.h"
#import "XEProperty.h"
#import "XEScript.h"
#import "XEScriptContainer.h"
#import "XEScriptContainerInstance.h"
#import "XEScriptInstance.h"
#import "XEScriptInterpreter.h"
#import "XEScriptNodeInclude.h"
#import "XESeqAnimController.h"
#import "XESeqBase.h"
#import "XESeqBinding.h"
#import "XESeqBindingActor.h"
#import "XESeqBindingActorCamera.h"
#import "XESeqBindingActorCameraInstance.h"
#import "XESeqBindingActorInstance.h"
#import "XESeqBindingActorLight.h"
#import "XESeqBindingActorLightInstance.h"
#import "XESeqBindingActorParticle.h"
#import "XESeqBindingActorParticleInstance.h"
#import "XESeqBindingCameraCuts.h"
#import "XESeqBindingCameraCutsInstance.h"
#import "XESeqBindingTransform.h"
#import "XESeqSingleAnimation.h"
#import "XESeqTrackEvent.h"
#import "XESeqTrackEventInstance.h"
#import "XESeqTrackMaterialInsFloatParameter.h"
#import "XESeqTrackMaterialInsFloatParameterInstance.h"
#import "XESeqTrackPlayRate.h"
#import "XESeqTrackPlayRateInstance.h"
#import "XESeqTrackSectionAnimation.h"
#import "XESeqTrackSectionAnimationInstance.h"
#import "XESequencer.h"
#import "XESequencerInstance.h"
#import "XESequencerNodeInclude.h"
#import "XEKeyframe.h"
#import "XETrackBase.h"
#import "XETrackBool.h"
#import "XETrackColor.h"
#import "XETrackFade.h"
#import "XETrackFloat.h"
#import "XETrackInt32.h"
#import "XETrackNodeInclude.h"
#import "XETrackSection.h"
#import "XETrackTransform.h"
#import "XETrackVariant.h"
#import "XETrackVirtual.h"
#import "XETrackVisibility.h"
#import "XETransform.h"
#import "XEActorMoveEventDataInstance.h"
#import "XESpawnParticleEventDataInstance.h"
#import "XETriggerUtil.h"
#import "XEUserNode.h"
#import "XEWorld.h"
#import "XEWorldParam.h"
#import "XE2DSeqFramePlayListController.h"
#import "XE2DSequenceFrameAnimController.h"
#import "XEMagicCoreParamExtendFactoryManager.h"
#import "XEParamExtendARAdsReference.h"
#import "XEParamExtendCameraShowType.h"
#import "XEParamExtendMobileUtilConfig.h"
#import "XETriggerOption.h"
#import "XEFaceTrackerActor.h"
#import "XEImg2DFaceKeyPointSequenceFrameActor.h"
#import "XEImg2DScreenSequenceFrameActor.h"
#import "XEImgSegmentationActor.h"
#import "XEMagicCoreActorBase.h"
#import "XEImg2DFaceKeyPointSequenceFrameComponent.h"
#import "XEImg2DScreenSequenceFrameComponent.h"
#import "XEImgFaceTrackerComponent.h"
#import "XEImgSegmentationComponent.h"
#import "XEImgSequenceFrameComponent.h"
#import "XEMagicCoreFactoryUtil.h"
#import "XETexCustomPrimitive.h"
#import "XETexFlexiblePrimitive.h"
#import "XETexMaterialRenderable.h"
#import "XETexSegmentationMask.h"
#import "XEMagicCoreFaceMaskUtility.h"
#import "XEMagicCoreUtility.h"
#import "XEDecorationEnvBridgeBase.h"
#import "XEMagicCore.h"
#import "XEMagicCoreActorComponentInclude.h"
#import "XEMagicCoreActorInclude.h"

FOUNDATION_EXPORT double XESceneVersionNumber;
FOUNDATION_EXPORT const unsigned char XESceneVersionString[];

