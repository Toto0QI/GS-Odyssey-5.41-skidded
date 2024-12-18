#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ItemDetailsHeaderTagListText

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "FortniteGame_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass ItemDetailsHeaderTagListText.ItemDetailsHeaderTagListText_C
// 0x0010 (0x0268 - 0x0258)
class UItemDetailsHeaderTagListText_C final : public UFortItemDetailElementWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0258(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       TagListTextBlock;                                  // 0x0260(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_ItemDetailsHeaderTagListText(int32 EntryPoint);
	void HandlePostDifferentItemToCompareWithSet();
	void HandlePostDifferentItemToDetailSet();
	void FormatItemDisplayTags(TArray<class FText>& TagTexts, class FText* FormatedText);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ItemDetailsHeaderTagListText_C">();
	}
	static class UItemDetailsHeaderTagListText_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UItemDetailsHeaderTagListText_C>();
	}
};

}

