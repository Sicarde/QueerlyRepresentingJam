// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "SpriteManagerMusic.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpriteManagerMusic() {}
// Cross Module References
	PATAPRIDE_API UClass* Z_Construct_UClass_USpriteManagerMusic_NoRegister();
	PATAPRIDE_API UClass* Z_Construct_UClass_USpriteManagerMusic();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_Patapride();
// End Cross Module References
	void USpriteManagerMusic::StaticRegisterNativesUSpriteManagerMusic()
	{
	}
	UClass* Z_Construct_UClass_USpriteManagerMusic_NoRegister()
	{
		return USpriteManagerMusic::StaticClass();
	}
	UClass* Z_Construct_UClass_USpriteManagerMusic()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_Patapride,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "IncludePath", "SpriteManagerMusic.h" },
				{ "ModuleRelativePath", "SpriteManagerMusic.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<USpriteManagerMusic>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&USpriteManagerMusic::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USpriteManagerMusic, 364773111);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USpriteManagerMusic(Z_Construct_UClass_USpriteManagerMusic, &USpriteManagerMusic::StaticClass, TEXT("/Script/Patapride"), TEXT("USpriteManagerMusic"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USpriteManagerMusic);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
