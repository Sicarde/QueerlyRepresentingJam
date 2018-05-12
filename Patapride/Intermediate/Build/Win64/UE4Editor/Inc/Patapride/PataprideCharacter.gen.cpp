// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "PataprideCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePataprideCharacter() {}
// Cross Module References
	PATAPRIDE_API UClass* Z_Construct_UClass_APataprideCharacter_NoRegister();
	PATAPRIDE_API UClass* Z_Construct_UClass_APataprideCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Patapride();
	PATAPRIDE_API UFunction* Z_Construct_UFunction_APataprideCharacter_GetCurrentFlag();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void APataprideCharacter::StaticRegisterNativesAPataprideCharacter()
	{
		UClass* Class = APataprideCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCurrentFlag", (Native)&APataprideCharacter::execGetCurrentFlag },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_APataprideCharacter_GetCurrentFlag()
	{
		struct PataprideCharacter_eventGetCurrentFlag_Parms
		{
			int32 ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(PataprideCharacter_eventGetCurrentFlag_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Widgets" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_APataprideCharacter, "GetCurrentFlag", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(PataprideCharacter_eventGetCurrentFlag_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APataprideCharacter_NoRegister()
	{
		return APataprideCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_APataprideCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_Patapride,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_APataprideCharacter_GetCurrentFlag, "GetCurrentFlag" }, // 2624948761
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "PataprideCharacter.h" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col8_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col8 = { UE4CodeGen_Private::EPropertyClass::Struct, "col8", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col8), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col8_MetaData, ARRAY_COUNT(NewProp_col8_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col7_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col7 = { UE4CodeGen_Private::EPropertyClass::Struct, "col7", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col7), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col7_MetaData, ARRAY_COUNT(NewProp_col7_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col6_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col6 = { UE4CodeGen_Private::EPropertyClass::Struct, "col6", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col6), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col6_MetaData, ARRAY_COUNT(NewProp_col6_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col5_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col5 = { UE4CodeGen_Private::EPropertyClass::Struct, "col5", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col5), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col5_MetaData, ARRAY_COUNT(NewProp_col5_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col4_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col4 = { UE4CodeGen_Private::EPropertyClass::Struct, "col4", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col4), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col4_MetaData, ARRAY_COUNT(NewProp_col4_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col3_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col3 = { UE4CodeGen_Private::EPropertyClass::Struct, "col3", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col3), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col3_MetaData, ARRAY_COUNT(NewProp_col3_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col2_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col2 = { UE4CodeGen_Private::EPropertyClass::Struct, "col2", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col2), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col2_MetaData, ARRAY_COUNT(NewProp_col2_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_col1_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_col1 = { UE4CodeGen_Private::EPropertyClass::Struct, "col1", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, col1), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_col1_MetaData, ARRAY_COUNT(NewProp_col1_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_protestersNumber_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_protestersNumber = { UE4CodeGen_Private::EPropertyClass::Int, "protestersNumber", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, protestersNumber), METADATA_PARAMS(NewProp_protestersNumber_MetaData, ARRAY_COUNT(NewProp_protestersNumber_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_currentStrike_MetaData[] = {
				{ "Category", "PataprideCharacter" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_currentStrike = { UE4CodeGen_Private::EPropertyClass::Int, "currentStrike", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, currentStrike), METADATA_PARAMS(NewProp_currentStrike_MetaData, ARRAY_COUNT(NewProp_currentStrike_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SquareEnd_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SquareEnd = { UE4CodeGen_Private::EPropertyClass::Object, "SquareEnd", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, SquareEnd), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_SquareEnd_MetaData, ARRAY_COUNT(NewProp_SquareEnd_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrossEnd_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CrossEnd = { UE4CodeGen_Private::EPropertyClass::Object, "CrossEnd", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, CrossEnd), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_CrossEnd_MetaData, ARRAY_COUNT(NewProp_CrossEnd_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CircleEnd_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CircleEnd = { UE4CodeGen_Private::EPropertyClass::Object, "CircleEnd", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, CircleEnd), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_CircleEnd_MetaData, ARRAY_COUNT(NewProp_CircleEnd_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TriangleEnd_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TriangleEnd = { UE4CodeGen_Private::EPropertyClass::Object, "TriangleEnd", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, TriangleEnd), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_TriangleEnd_MetaData, ARRAY_COUNT(NewProp_TriangleEnd_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpriteCross_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpriteCross = { UE4CodeGen_Private::EPropertyClass::Object, "SpriteCross", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, SpriteCross), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_SpriteCross_MetaData, ARRAY_COUNT(NewProp_SpriteCross_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpriteCircle_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpriteCircle = { UE4CodeGen_Private::EPropertyClass::Object, "SpriteCircle", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, SpriteCircle), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_SpriteCircle_MetaData, ARRAY_COUNT(NewProp_SpriteCircle_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpriteSquare_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpriteSquare = { UE4CodeGen_Private::EPropertyClass::Object, "SpriteSquare", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, SpriteSquare), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_SpriteSquare_MetaData, ARRAY_COUNT(NewProp_SpriteSquare_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpriteTriangle_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpriteTriangle = { UE4CodeGen_Private::EPropertyClass::Object, "SpriteTriangle", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, SpriteTriangle), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(NewProp_SpriteTriangle_MetaData, ARRAY_COUNT(NewProp_SpriteTriangle_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_CameraBoom_MetaData, ARRAY_COUNT(NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideViewCameraComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PataprideCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideViewCameraComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SideViewCameraComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x004000000008000d, 1, nullptr, STRUCT_OFFSET(APataprideCharacter, SideViewCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_SideViewCameraComponent_MetaData, ARRAY_COUNT(NewProp_SideViewCameraComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col8,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col7,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col6,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col5,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col4,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col3,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col2,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_col1,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_protestersNumber,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_currentStrike,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SquareEnd,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CrossEnd,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CircleEnd,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TriangleEnd,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpriteCross,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpriteCircle,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpriteSquare,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpriteTriangle,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CameraBoom,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SideViewCameraComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<APataprideCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&APataprideCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APataprideCharacter, 1546962614);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APataprideCharacter(Z_Construct_UClass_APataprideCharacter, &APataprideCharacter::StaticClass, TEXT("/Script/Patapride"), TEXT("APataprideCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APataprideCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
