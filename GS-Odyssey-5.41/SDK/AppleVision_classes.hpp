#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AppleVision

#include "Basic.hpp"

#include "AppleVision_structs.hpp"
#include "CoreUObject_classes.hpp"


namespace SDK
{

// Class AppleVision.AppleVisionDetectFacesAsyncTaskBlueprintProxy
// 0x0050 (0x0078 - 0x0028)
class UAppleVisionDetectFacesAsyncTaskBlueprintProxy final : public UObject
{
public:
	uint8                                         Pad_1217[0x8];                                     // 0x0028(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	UMulticastDelegateProperty_                   OnSuccess;                                         // 0x0030(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	UMulticastDelegateProperty_                   OnFailure;                                         // 0x0040(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	uint8                                         Pad_1218[0x10];                                    // 0x0050(0x0010)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFaceDetectionResult                   FaceDetectionResult;                               // 0x0060(0x0010)(BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	uint8                                         Pad_1219[0x8];                                     // 0x0070(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UAppleVisionDetectFacesAsyncTaskBlueprintProxy* CreateProxyObjectForDetectFaces(class UTexture* SourceImage);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"AppleVisionDetectFacesAsyncTaskBlueprintProxy">();
	}
	static class UAppleVisionDetectFacesAsyncTaskBlueprintProxy* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAppleVisionDetectFacesAsyncTaskBlueprintProxy>();
	}
};

}
