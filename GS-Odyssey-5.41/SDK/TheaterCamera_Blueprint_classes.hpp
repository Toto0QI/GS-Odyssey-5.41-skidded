#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TheaterCamera_Blueprint

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "CommonInput_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass TheaterCamera_Blueprint.TheaterCamera_Blueprint_C
// 0x01A0 (0x0A20 - 0x0880)
class ATheaterCamera_Blueprint_C final : public AFortTheaterCamera
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0880(0x0008)(Transient, DuplicateTransient)
	float                                         FocusTimeline_Float_Curve_ADC98EA5D14E24EC78DD4F80C5102578; // 0x0888(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            FocusTimeline__Direction_ADC98EA5D14E24EC78DD4F80C5102578; // 0x088C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5E14[0x3];                                     // 0x088D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     FocusTimeline;                                     // 0x0890(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_CameraRotLevelMax_41B63CEF445574B1F9D6F489004E4238; // 0x0898(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_CameraRotLevelZero_41B63CEF445574B1F9D6F489004E4238; // 0x089C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_CameraOffsetX___LevelMax_41B63CEF445574B1F9D6F489004E4238; // 0x08A0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_CameraOffsetX___LevelZero_41B63CEF445574B1F9D6F489004E4238; // 0x08A4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_TotalNumberOfZoomLevels_41B63CEF445574B1F9D6F489004E4238; // 0x08A8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_CameraHeight_LevelMax_41B63CEF445574B1F9D6F489004E4238; // 0x08AC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_CameraHeight_LevelZero_41B63CEF445574B1F9D6F489004E4238; // 0x08B0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_FOV_In_41B63CEF445574B1F9D6F489004E4238; // 0x08B4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DebugZoomTL_FOV_Out_41B63CEF445574B1F9D6F489004E4238; // 0x08B8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            DebugZoomTL__Direction_41B63CEF445574B1F9D6F489004E4238; // 0x08BC(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5E15[0x3];                                     // 0x08BD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     DebugZoomTL;                                       // 0x08C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         WorldLocSnapSize;                                  // 0x08C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CameraZHeightLevelZero;                            // 0x08CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CameraXOffsetLevelZero;                            // 0x08D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_5E16[0x4];                                     // 0x08D4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortTheaterMapTile*                    TargetTile;                                        // 0x08D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CurrentZoomPercentage;                             // 0x08E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         NumberOfZoomLevels;                                // 0x08E4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ZoomDistanceUnitZ;                                 // 0x08E8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CurrentZoomLevel;                                  // 0x08EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                FocusedTileLocWithOffset;                          // 0x08F0(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          MouseDown;                                         // 0x08FC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E17[0x3];                                     // 0x08FD(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CurrentOffsetAmountX;                              // 0x0900(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CameraXOffsetLevelMax;                             // 0x0904(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         InitialZoomLevels;                                 // 0x0908(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ForwardVector;                                     // 0x090C(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CameraYRotationLevelZero;                          // 0x0918(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                TargetTileLoc;                                     // 0x091C(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         OldOffsetAmountX;                                  // 0x0928(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CurrentFOV;                                        // 0x092C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FOVLevelZero;                                      // 0x0930(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FOVLevelMax;                                       // 0x0934(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CameraZHeightLevelMax;                             // 0x0938(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ZoomDistanceUnitX;                                 // 0x093C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DebugCameraZoom;                                   // 0x0940(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E18[0x3];                                     // 0x0941(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CameraYRotationLevelMax;                           // 0x0944(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          SnapCameraToFocusedTile;                           // 0x0948(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E19[0x7];                                     // 0x0949(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FVector2D>                      CloudMaskLocations;                                // 0x0950(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	float                                         CloudMaskScale;                                    // 0x0960(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ReadyForPings;                                     // 0x0964(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E1A[0x3];                                     // 0x0965(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class ABP_Hex_PARENT_C*>               AllHexesArray;                                     // 0x0968(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance)
	TArray<uint8>                                 HexesPinged;                                       // 0x0978(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                          AllHexesHavePingedOnce;                            // 0x0988(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          WaitForForceFocus;                                 // 0x0989(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          AQuestIsPinned;                                    // 0x098A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E1B[0x5];                                     // 0x098B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<bool>                                  PinnedQuestsArray;                                 // 0x0990(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                          WaitForPinned;                                     // 0x09A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E1C[0x3];                                     // 0x09A1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                HexWorldLocFromBP_Hex_PARENT;                      // 0x09A4(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxCameraDistance;                                 // 0x09B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HighestXMinusValue;                                // 0x09B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HighestYMinusValue;                                // 0x09B8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TotalWidthOfHexPlane;                              // 0x09BC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         HexPlaneBufferSize;                                // 0x09C0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CenterLocOfAllHexes;                               // 0x09C4(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<struct FVector2D>                      RoadMaskLocations;                                 // 0x09D0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FVector2D>                      TileType0MinusLocs;                                // 0x09E0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FVector2D>                      TileType1MinusLocs;                                // 0x09F0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FVector2D>                      TileType2MinusLocs;                                // 0x0A00(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	float                                         TileTypeMaskScale;                                 // 0x0A10(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bSuspendInput;                                     // 0x0A14(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5E1D[0x3];                                     // 0x0A15(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         LastZoomButtonHeldTime;                            // 0x0A18(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_TheaterCamera_Blueprint(int32 EntryPoint);
	void PinnedPing();
	void MaskFinished();
	void RefreshCloudMask();
	void PingFromHex();
	void ForceTileFocus(const struct FVector& HexWorldLoc);
	void StopFocusTimeline();
	void OnDragEnd();
	void OnDragBegin();
	void ReceiveTick(float DeltaSeconds);
	void SetTileFocus(class AFortTheaterMapTile* Param_TargetTile);
	void OnDeactivated();
	void OnActivated();
	void InpActEvt_MouseScrollDown_K2Node_InputKeyEvent_0(const struct FKey& Key);
	void InpActEvt_MouseScrollUp_K2Node_InputKeyEvent_1(const struct FKey& Key);
	void DebugZoomTL__UpdateFunc();
	void DebugZoomTL__FinishedFunc();
	void FocusTimeline__UpdateFunc();
	void FocusTimeline__FinishedFunc();
	void UserConstructionScript();
	void ZoomCameraStep(bool Forward);
	void HandleTheaterSelected(const class FString& TheaterId);
	void PanCamera(float DeltaX, float DeltaY);
	struct FVector2D NewFunction_0(class AActor* Self2);
	bool IsInputSuspended();
	void SetSuspendInput(bool SuspendInput);
	void ZoomCameraWithHeldGamepadInput();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TheaterCamera_Blueprint_C">();
	}
	static class ATheaterCamera_Blueprint_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATheaterCamera_Blueprint_C>();
	}
};

}
