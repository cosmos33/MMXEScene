﻿#ifndef _FXGLOBAL_H_
#define _FXGLOBAL_H_

#include "XArray.h"
#include "XHashTable.h"
#include "XString.h"

// FIXME by hd, add namespace to prevent name conflict

#define FX_FILE_VERSION		2
#define FX_FILE_VERSION_PROPERTY_2SIDE 2

enum FxElementType
{
	FXET_PARTICLESYSTEM_SPRITE = 0,
	FXET_PARTICLESYSTEM_MODEL,
	FXET_PARTICLESYSTEM_RIBBON,
};

enum FxParticleFacing
{
	PF_FACING_CAMERA_POS = 1,
	PF_SQUARE = 2,
	PF_VELOCITY,
	PF_RECTANGLE
};

enum FxParticleLockAxis
{
	PLA_NONE,
	PLA_X,
	PLA_Y,
	PLA_Z,
	PLA_NEGATIVE_X,
	PLA_NEGATIVE_Y,
	PLA_NEGATIVE_Z,
	PLA_RANDOM
};
enum FxParticleBlendMode
{
	PBM_ALPHA,
	PBM_HIGHLIGHT,
	PBM_SHIGHLIGHT,
	PBM_COLORLIGHT,
};

enum FxTrailAxis
{
	TA_CAMERAUP,
	TA_SOURCEUP,
	TA_WORLDUP 
};

enum FxLocationEmitterSelectionMethod
{
	LESM_RANDOM,
	LESM_SEQUENTIAL,
};

enum FxEventType
{
	ET_ANY,
	ET_SPAWN,
	ET_DEATH
};

enum FxParticleLocationCylinderAxis
{
	FPLCA_X,
	FPLCA_Y,
	FPLCA_Z
};

enum FxModuleCategory
{
	FMC_ACCELERATION,
	FMC_ATTRACTION,
	FMC_COLOR,
	FMC_EVENT,
	FMC_LIFETIME,
	FMC_LOCATION,
	FMC_ORIENTATION,
	FMC_ROTATION,
	FMR_ROTATION_MODEL,
	FMC_SIZE,
	FMC_SUBUV,
	FMC_VELOCITY,	
	FMC_TRAIL,
	FMC_NUM
};
// 序列化,不能改变位置
enum FxModuleType
{
	FMT_REQUIRED,
	FMT_SPAWN,
	FMT_LIFETIME,
	FMT_INITIALVELOCITY,
	FMT_INITIALSIZE,
	FMT_INITIALPOSITION,
	FMT_INITIALCOLOR,
	FMT_INITIALROTATION,
	FMT_INITIALROTATIONRATE,
	FMT_ROTATIONRATEBYLIFE,
	FMT_VELOCITYCONE,
	FMT_COLORBYLIFE,
	FMT_LOCATION_SPHERE,
	FMT_CONST_ACCELERATION,
	FMT_SIZEBYLIFE,
	FMT_SUBUV,
	FMT_VELOCITYBYLIFE,
	FMT_LOCATION_EMITTER,
	FMT_UVPANNER,
	FMT_TYPEDATA_MODEL,
	FMT_INITIALROTATION_MODEL,
	FMT_INITIALROTATIONRATE_MODEL,
	FMT_ROTATIONRATEBYLIFE_MODEL,
	FMT_SIZEBYSPEED,
	FMT_DRAGBYLIFE,
	FMT_ATTRACTOR_POINT,
	FMT_EVENT_GENERATOR,
	FMT_EVENT_RECEIVERSPAWN,
	FMT_LOCATION_DIRECT,
	FMT_COLORSCALEBYTIME,
	FMT_TYPEDATA_RIBBON,
	FMT_TRAIL_SOURCE,
	FMT_ACCELERATION,
	FMT_LOCATION_CYLINDER,
	FMT_MODULETYPENUM
};

enum FxRenderLayerOrder
{
	LO_BeforeUI,
	LO_BetweenUI,
	LO_AfterUI
};

struct ModuleFlag
{
	ModuleFlag(){}
	ModuleFlag(FxModuleType type, const XString& str)
		: eType(type)
		, strModuleName(str)
	{}
	FxModuleType eType;
	XString		 strModuleName;
};

struct ModuleAnnotation
{
	XString					strCategoryName;
	XArray<ModuleFlag>	aModuleFlags;
};

extern XHashTable<FxModuleCategory, ModuleAnnotation> g_FXModuleAnnotations;
extern XHashTable<FxModuleType, XString> g_FXModuleName;

#endif
