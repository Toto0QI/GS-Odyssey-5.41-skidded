#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GameplayTags

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK
{

// Enum GameplayTags.EGameplayTagQueryExprType
// NumValues: 0x0008
enum class EGameplayTagQueryExprType : uint8
{
	Undefined                                = 0,
	AnyTagsMatch                             = 1,
	AllTagsMatch                             = 2,
	NoTagsMatch                              = 3,
	AnyExprMatch                             = 4,
	AllExprMatch                             = 5,
	NoExprMatch                              = 6,
	EGameplayTagQueryExprType_MAX            = 7,
};

// Enum GameplayTags.EGameplayContainerMatchType
// NumValues: 0x0003
enum class EGameplayContainerMatchType : uint8
{
	Any                                      = 0,
	All                                      = 1,
	EGameplayContainerMatchType_MAX          = 2,
};

// Enum GameplayTags.EGameplayTagMatchType
// NumValues: 0x0003
enum class EGameplayTagMatchType : uint8
{
	Explicit                                 = 0,
	IncludeParentTags                        = 1,
	EGameplayTagMatchType_MAX                = 2,
};

// Enum GameplayTags.EGameplayTagSourceType
// NumValues: 0x0007
enum class EGameplayTagSourceType : uint8
{
	Native                                   = 0,
	DefaultTagList                           = 1,
	TagList                                  = 2,
	RestrictedTagList                        = 3,
	DataTable                                = 4,
	Invalid                                  = 5,
	EGameplayTagSourceType_MAX               = 6,
};

// ScriptStruct GameplayTags.GameplayTagReferenceHelper
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FGameplayTagReferenceHelper final
{
public:
	uint8                                         Pad_2478[0x10];                                    // 0x0000(0x0010)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GameplayTags.GameplayTag
// 0x0008 (0x0008 - 0x0000)
struct alignas(0x08) FGameplayTag
{
public:
	class FName                                   TagName;                                           // 0x0000(0x0008)(Edit, ZeroConstructor, EditConst, SaveGame, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
};

// ScriptStruct GameplayTags.GameplayTagContainer
// 0x0020 (0x0020 - 0x0000)
struct FGameplayTagContainer final
{
public:
	TArray<struct FGameplayTag>                   GameplayTags;                                      // 0x0000(0x0010)(BlueprintVisible, ZeroConstructor, SaveGame, Protected, NativeAccessSpecifierProtected)
	TArray<struct FGameplayTag>                   ParentTags;                                        // 0x0010(0x0010)(ZeroConstructor, Transient, Protected, NativeAccessSpecifierProtected)
};

// ScriptStruct GameplayTags.GameplayTagSource
// 0x0020 (0x0020 - 0x0000)
struct FGameplayTagSource final
{
public:
	class FName                                   SourceName;                                        // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGameplayTagSourceType                        SourceType;                                        // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2479[0x7];                                     // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameplayTagsList*                      SourceTagList;                                     // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class URestrictedGameplayTagsList*            SourceRestrictedTagList;                           // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct GameplayTags.GameplayTagTableRow
// 0x0018 (0x0020 - 0x0008)
struct FGameplayTagTableRow : public FTableRowBase
{
public:
	class FName                                   Tag;                                               // 0x0008(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 DevComment;                                        // 0x0010(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct GameplayTags.GameplayTagCreationWidgetHelper
// 0x0001 (0x0001 - 0x0000)
struct FGameplayTagCreationWidgetHelper final
{
public:
	uint8                                         Pad_247A[0x1];                                     // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GameplayTags.GameplayTagQuery
// 0x0048 (0x0048 - 0x0000)
struct FGameplayTagQuery final
{
public:
	int32                                         TokenStreamVersion;                                // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	uint8                                         Pad_247B[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FGameplayTag>                   TagDictionary;                                     // 0x0008(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	TArray<uint8>                                 QueryTokenStream;                                  // 0x0018(0x0010)(ZeroConstructor, NativeAccessSpecifierPrivate)
	class FString                                 UserDescription;                                   // 0x0028(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class FString                                 AutoDescription;                                   // 0x0038(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
};

// ScriptStruct GameplayTags.GameplayTagNode
// 0x0050 (0x0050 - 0x0000)
struct alignas(0x08) FGameplayTagNode final
{
public:
	uint8                                         Pad_247C[0x50];                                    // 0x0000(0x0050)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GameplayTags.RestrictedGameplayTagTableRow
// 0x0008 (0x0028 - 0x0020)
struct FRestrictedGameplayTagTableRow final : public FGameplayTagTableRow
{
public:
	bool                                          bAllowNonRestrictedChildren;                       // 0x0020(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_247D[0x7];                                     // 0x0021(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct GameplayTags.RestrictedConfigInfo
// 0x0020 (0x0020 - 0x0000)
struct FRestrictedConfigInfo final
{
public:
	class FString                                 RestrictedConfigName;                              // 0x0000(0x0010)(Edit, ZeroConstructor, Config, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class FString>                         Owners;                                            // 0x0010(0x0010)(Edit, ZeroConstructor, Config, AdvancedDisplay, NativeAccessSpecifierPublic)
};

// ScriptStruct GameplayTags.GameplayTagCategoryRemap
// 0x0020 (0x0020 - 0x0000)
struct FGameplayTagCategoryRemap final
{
public:
	class FString                                 BaseCategory;                                      // 0x0000(0x0010)(Edit, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class FString>                         RemapCategories;                                   // 0x0010(0x0010)(Edit, ZeroConstructor, NativeAccessSpecifierPublic)
};

// ScriptStruct GameplayTags.GameplayTagRedirect
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) FGameplayTagRedirect final
{
public:
	class FName                                   OldTagName;                                        // 0x0000(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   NewTagName;                                        // 0x0008(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}
