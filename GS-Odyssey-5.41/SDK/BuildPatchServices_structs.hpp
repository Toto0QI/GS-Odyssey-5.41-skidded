#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BuildPatchServices

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// ScriptStruct BuildPatchServices.SHAHashData
// 0x0014 (0x0014 - 0x0000)
struct FSHAHashData final
{
public:
	uint8                                         Hash[0x14];                                        // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct BuildPatchServices.ChunkPartData
// 0x0018 (0x0018 - 0x0000)
struct FChunkPartData final
{
public:
	struct FGuid                                  Guid;                                              // 0x0000(0x0010)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint32                                        Offset;                                            // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint32                                        Size;                                              // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct BuildPatchServices.FileManifestData
// 0x0068 (0x0068 - 0x0000)
struct FFileManifestData final
{
public:
	class FString                                 Filename;                                          // 0x0000(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSHAHashData                           FileHash;                                          // 0x0010(0x0014)(NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2406[0x4];                                     // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FChunkPartData>                 FileChunkParts;                                    // 0x0028(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<class FString>                         InstallTags;                                       // 0x0038(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	bool                                          bIsUnixExecutable;                                 // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2407[0x7];                                     // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 SymlinkTarget;                                     // 0x0050(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIsReadOnly;                                       // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIsCompressed;                                     // 0x0061(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2408[0x6];                                     // 0x0062(0x0006)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct BuildPatchServices.ChunkInfoData
// 0x0040 (0x0040 - 0x0000)
struct FChunkInfoData final
{
public:
	struct FGuid                                  Guid;                                              // 0x0000(0x0010)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint64                                        Hash;                                              // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FSHAHashData                           ShaHash;                                           // 0x0018(0x0014)(NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2409[0x4];                                     // 0x002C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	int64                                         FileSize;                                          // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         GroupNumber;                                       // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_240A[0x7];                                     // 0x0039(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct BuildPatchServices.CustomFieldData
// 0x0020 (0x0020 - 0x0000)
struct FCustomFieldData final
{
public:
	class FString                                 Key;                                               // 0x0000(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Value;                                             // 0x0010(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}
