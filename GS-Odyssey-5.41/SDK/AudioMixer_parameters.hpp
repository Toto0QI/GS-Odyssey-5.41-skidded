#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AudioMixer

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AudioMixer_structs.hpp"


namespace SDK::Params
{

// Function AudioMixer.SynthComponent.SetSubmixSend
// 0x0010 (0x0010 - 0x0000)
struct SynthComponent_SetSubmixSend final
{
public:
	class USoundSubmix*                           Submix;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SendLevel;                                         // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F3F[0x4];                                      // 0x000C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function AudioMixer.SynthComponent.SetVolumeMultiplier
// 0x0004 (0x0004 - 0x0000)
struct SynthComponent_SetVolumeMultiplier final
{
public:
	float                                         VolumeMultiplier;                                  // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.SynthComponent.IsPlaying
// 0x0001 (0x0001 - 0x0000)
struct SynthComponent_IsPlaying final
{
public:
	bool                                          ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.AudioMixerBlueprintLibrary.AddMasterSubmixEffect
// 0x0010 (0x0010 - 0x0000)
struct AudioMixerBlueprintLibrary_AddMasterSubmixEffect final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundEffectSubmixPreset*               SubmixEffectPreset;                                // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.AudioMixerBlueprintLibrary.AddSourceEffectToPresetChain
// 0x0020 (0x0020 - 0x0000)
struct AudioMixerBlueprintLibrary_AddSourceEffectToPresetChain final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundEffectSourcePresetChain*          PresetChain;                                       // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSourceEffectChainEntry                Entry;                                             // 0x0010(0x0010)(Parm, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
};

// Function AudioMixer.AudioMixerBlueprintLibrary.ClearMasterSubmixEffects
// 0x0008 (0x0008 - 0x0000)
struct AudioMixerBlueprintLibrary_ClearMasterSubmixEffects final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.AudioMixerBlueprintLibrary.GetNumberOfEntriesInSourceEffectChain
// 0x0018 (0x0018 - 0x0000)
struct AudioMixerBlueprintLibrary_GetNumberOfEntriesInSourceEffectChain final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundEffectSourcePresetChain*          PresetChain;                                       // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ReturnValue;                                       // 0x0010(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F40[0x4];                                      // 0x0014(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function AudioMixer.AudioMixerBlueprintLibrary.RemoveMasterSubmixEffect
// 0x0010 (0x0010 - 0x0000)
struct AudioMixerBlueprintLibrary_RemoveMasterSubmixEffect final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundEffectSubmixPreset*               SubmixEffectPreset;                                // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.AudioMixerBlueprintLibrary.RemoveSourceEffectFromPresetChain
// 0x0018 (0x0018 - 0x0000)
struct AudioMixerBlueprintLibrary_RemoveSourceEffectFromPresetChain final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundEffectSourcePresetChain*          PresetChain;                                       // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         EntryIndex;                                        // 0x0010(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F41[0x4];                                      // 0x0014(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function AudioMixer.AudioMixerBlueprintLibrary.SetBypassSourceEffectChainEntry
// 0x0018 (0x0018 - 0x0000)
struct AudioMixerBlueprintLibrary_SetBypassSourceEffectChainEntry final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundEffectSourcePresetChain*          PresetChain;                                       // 0x0008(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         EntryIndex;                                        // 0x0010(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bBypassed;                                         // 0x0014(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F42[0x3];                                      // 0x0015(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// Function AudioMixer.AudioMixerBlueprintLibrary.StartRecordingOutput
// 0x0018 (0x0018 - 0x0000)
struct AudioMixerBlueprintLibrary_StartRecordingOutput final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ExpectedDuration;                                  // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F43[0x4];                                      // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundSubmix*                           SubmixToRecord;                                    // 0x0010(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.AudioMixerBlueprintLibrary.StopRecordingOutput
// 0x0048 (0x0048 - 0x0000)
struct AudioMixerBlueprintLibrary_StopRecordingOutput final
{
public:
	const class UObject*                          WorldContextObject;                                // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EAudioRecordingExportType                     ExportType;                                        // 0x0008(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F44[0x7];                                      // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 Param_Name;                                        // 0x0010(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Path;                                              // 0x0020(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundSubmix*                           SubmixToRecord;                                    // 0x0030(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundWave*                             ExistingSoundWaveToOverwrite;                      // 0x0038(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class USoundWave*                             ReturnValue;                                       // 0x0040(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// Function AudioMixer.SubmixEffectDynamicsProcessorPreset.SetSettings
// 0x0028 (0x0028 - 0x0000)
struct SubmixEffectDynamicsProcessorPreset_SetSettings final
{
public:
	struct FSubmixEffectDynamicsProcessorSettings InSettings;                                        // 0x0000(0x0028)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
};

// Function AudioMixer.SubmixEffectSubmixEQPreset.SetSettings
// 0x0010 (0x0010 - 0x0000)
struct SubmixEffectSubmixEQPreset_SetSettings final
{
public:
	struct FSubmixEffectSubmixEQSettings          InSettings;                                        // 0x0000(0x0010)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
};

// Function AudioMixer.SubmixEffectReverbPreset.SetSettings
// 0x0030 (0x0030 - 0x0000)
struct SubmixEffectReverbPreset_SetSettings final
{
public:
	struct FSubmixEffectReverbSettings            InSettings;                                        // 0x0000(0x0030)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
};

// Function AudioMixer.SubmixEffectReverbPreset.SetSettingsWithReverbEffect
// 0x0010 (0x0010 - 0x0000)
struct SubmixEffectReverbPreset_SetSettingsWithReverbEffect final
{
public:
	const class UReverbEffect*                    InReverbEffect;                                    // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         WetLevel;                                          // 0x0008(0x0004)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F48[0x4];                                      // 0x000C(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}
