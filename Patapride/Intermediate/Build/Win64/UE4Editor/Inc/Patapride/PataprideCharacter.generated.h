// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PATAPRIDE_PataprideCharacter_generated_h
#error "PataprideCharacter.generated.h already included, missing '#pragma once' in PataprideCharacter.h"
#endif
#define PATAPRIDE_PataprideCharacter_generated_h

#define Patapride_Source_Patapride_PataprideCharacter_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrentFlag) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetCurrentFlag(); \
		P_NATIVE_END; \
	}


#define Patapride_Source_Patapride_PataprideCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentFlag) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetCurrentFlag(); \
		P_NATIVE_END; \
	}


#define Patapride_Source_Patapride_PataprideCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPataprideCharacter(); \
	friend PATAPRIDE_API class UClass* Z_Construct_UClass_APataprideCharacter(); \
public: \
	DECLARE_CLASS(APataprideCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Patapride"), NO_API) \
	DECLARE_SERIALIZER(APataprideCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Patapride_Source_Patapride_PataprideCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPataprideCharacter(); \
	friend PATAPRIDE_API class UClass* Z_Construct_UClass_APataprideCharacter(); \
public: \
	DECLARE_CLASS(APataprideCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Patapride"), NO_API) \
	DECLARE_SERIALIZER(APataprideCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Patapride_Source_Patapride_PataprideCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APataprideCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APataprideCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APataprideCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APataprideCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APataprideCharacter(APataprideCharacter&&); \
	NO_API APataprideCharacter(const APataprideCharacter&); \
public:


#define Patapride_Source_Patapride_PataprideCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APataprideCharacter(APataprideCharacter&&); \
	NO_API APataprideCharacter(const APataprideCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APataprideCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APataprideCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APataprideCharacter)


#define Patapride_Source_Patapride_PataprideCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(APataprideCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(APataprideCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__SpriteTriangle() { return STRUCT_OFFSET(APataprideCharacter, SpriteTriangle); } \
	FORCEINLINE static uint32 __PPO__SpriteSquare() { return STRUCT_OFFSET(APataprideCharacter, SpriteSquare); } \
	FORCEINLINE static uint32 __PPO__SpriteCircle() { return STRUCT_OFFSET(APataprideCharacter, SpriteCircle); } \
	FORCEINLINE static uint32 __PPO__SpriteCross() { return STRUCT_OFFSET(APataprideCharacter, SpriteCross); } \
	FORCEINLINE static uint32 __PPO__TriangleEnd() { return STRUCT_OFFSET(APataprideCharacter, TriangleEnd); } \
	FORCEINLINE static uint32 __PPO__CircleEnd() { return STRUCT_OFFSET(APataprideCharacter, CircleEnd); } \
	FORCEINLINE static uint32 __PPO__CrossEnd() { return STRUCT_OFFSET(APataprideCharacter, CrossEnd); } \
	FORCEINLINE static uint32 __PPO__SquareEnd() { return STRUCT_OFFSET(APataprideCharacter, SquareEnd); }


#define Patapride_Source_Patapride_PataprideCharacter_h_12_PROLOG
#define Patapride_Source_Patapride_PataprideCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Patapride_Source_Patapride_PataprideCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	Patapride_Source_Patapride_PataprideCharacter_h_15_RPC_WRAPPERS \
	Patapride_Source_Patapride_PataprideCharacter_h_15_INCLASS \
	Patapride_Source_Patapride_PataprideCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Patapride_Source_Patapride_PataprideCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Patapride_Source_Patapride_PataprideCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	Patapride_Source_Patapride_PataprideCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Patapride_Source_Patapride_PataprideCharacter_h_15_INCLASS_NO_PURE_DECLS \
	Patapride_Source_Patapride_PataprideCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Patapride_Source_Patapride_PataprideCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
