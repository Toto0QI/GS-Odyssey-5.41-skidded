#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Landscape

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// Enum Landscape.ELandscapeSetupErrors
// NumValues: 0x0005
enum class ELandscapeSetupErrors : uint8
{
	LSE_None                                 = 0,
	LSE_NoLandscapeInfo                      = 1,
	LSE_CollsionXY                           = 2,
	LSE_NoLayerInfo                          = 3,
	LSE_MAX                                  = 4,
};

// Enum Landscape.ELandscapeGizmoType
// NumValues: 0x0004
enum class ELandscapeGizmoType : uint8
{
	LGT_None                                 = 0,
	LGT_Height                               = 1,
	LGT_Weight                               = 2,
	LGT_MAX                                  = 3,
};

// Enum Landscape.EGrassScaling
// NumValues: 0x0004
enum class EGrassScaling : uint8
{
	Uniform                                  = 0,
	Free                                     = 1,
	LockXY                                   = 2,
	EGrassScaling_MAX                        = 3,
};

// Enum Landscape.ELandscapeLODFalloff
// NumValues: 0x0003
enum class ELandscapeLODFalloff : uint8
{
	Linear                                   = 0,
	SquareRoot                               = 1,
	ELandscapeLODFalloff_MAX                 = 2,
};

// Enum Landscape.ELandscapeLayerDisplayMode
// NumValues: 0x0004
enum class ELandscapeLayerDisplayMode : uint8
{
	Default                                  = 0,
	Alphabetical                             = 1,
	UserSpecific                             = 2,
	ELandscapeLayerDisplayMode_MAX           = 3,
};

// Enum Landscape.ELandscapeLayerPaintingRestriction
// NumValues: 0x0005
enum class ELandscapeLayerPaintingRestriction : uint8
{
	None                                     = 0,
	UseMaxLayers                             = 1,
	ExistingOnly                             = 2,
	UseComponentWhitelist                    = 3,
	ELandscapeLayerPaintingRestriction_MAX   = 4,
};

// Enum Landscape.ELandscapeImportAlphamapType
// NumValues: 0x0003
enum class ELandscapeImportAlphamapType : uint8
{
	Additive                                 = 0,
	Layered                                  = 1,
	ELandscapeImportAlphamapType_MAX         = 2,
};

// Enum Landscape.LandscapeSplineMeshOrientation
// NumValues: 0x0003
enum class ELandscapeSplineMeshOrientation : uint8
{
	LSMO_XUp                                 = 0,
	LSMO_YUp                                 = 1,
	LSMO_MAX                                 = 2,
};

// Enum Landscape.ELandscapeLayerBlendType
// NumValues: 0x0004
enum class ELandscapeLayerBlendType : uint8
{
	LB_WeightBlend                           = 0,
	LB_AlphaBlend                            = 1,
	LB_HeightBlend                           = 2,
	LB_MAX                                   = 3,
};

// Enum Landscape.ELandscapeCustomizedCoordType
// NumValues: 0x0006
enum class ELandscapeCustomizedCoordType : uint8
{
	LCCT_None                                = 0,
	LCCT_CustomUV0                           = 1,
	LCCT_CustomUV1                           = 2,
	LCCT_CustomUV2                           = 3,
	LCCT_WeightMapUV                         = 4,
	LCCT_MAX                                 = 5,
};

// Enum Landscape.ETerrainCoordMappingType
// NumValues: 0x0005
enum class ETerrainCoordMappingType : uint8
{
	TCMT_Auto                                = 0,
	TCMT_XY                                  = 1,
	TCMT_XZ                                  = 2,
	TCMT_YZ                                  = 3,
	TCMT_MAX                                 = 4,
};

// ScriptStruct Landscape.LandscapeProxyMaterialOverride
// 0x0010 (0x0010 - 0x0000)
struct FLandscapeProxyMaterialOverride final
{
public:
	struct FPerPlatformInt                        LODIndex;                                          // 0x0000(0x0004)(Edit, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2412[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     Material;                                          // 0x0008(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.LandscapeComponentMaterialOverride
// 0x0010 (0x0010 - 0x0000)
struct FLandscapeComponentMaterialOverride final
{
public:
	struct FPerPlatformInt                        LODIndex;                                          // 0x0000(0x0004)(Edit, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2413[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     Material;                                          // 0x0008(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.LandscapeSplineMeshEntry
// 0x0038 (0x0038 - 0x0000)
struct FLandscapeSplineMeshEntry final
{
public:
	class UStaticMesh*                            Mesh;                                              // 0x0000(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class UMaterialInterface*>             MaterialOverrides;                                 // 0x0008(0x0010)(Edit, ZeroConstructor, AdvancedDisplay, NativeAccessSpecifierPublic)
	uint8                                         bCenterH : 1;                                      // 0x0018(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_2414[0x3];                                     // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector2D                              CenterAdjust;                                      // 0x001C(0x0008)(Edit, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         bScaleToWidth : 1;                                 // 0x0024(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_2415[0x3];                                     // 0x0025(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                Scale;                                             // 0x0028(0x000C)(Edit, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ELandscapeSplineMeshOrientation               Orientation;                                       // 0x0034(0x0001)(ZeroConstructor, Deprecated, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESplineMeshAxis                               ForwardAxis;                                       // 0x0035(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESplineMeshAxis                               UpAxis;                                            // 0x0036(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2416[0x1];                                     // 0x0037(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.WeightmapLayerAllocationInfo
// 0x0010 (0x0010 - 0x0000)
struct FWeightmapLayerAllocationInfo final
{
public:
	class ULandscapeLayerInfoObject*              LayerInfo;                                         // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         WeightmapTextureIndex;                             // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         WeightmapTextureChannel;                           // 0x0009(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2417[0x6];                                     // 0x000A(0x0006)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.LandscapeImportLayerInfo
// 0x0001 (0x0001 - 0x0000)
struct FLandscapeImportLayerInfo final
{
public:
	uint8                                         Pad_2418[0x1];                                     // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.GizmoSelectData
// 0x0050 (0x0050 - 0x0000)
struct alignas(0x08) FGizmoSelectData final
{
public:
	uint8                                         Pad_2419[0x50];                                    // 0x0000(0x0050)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.LandscapeEditToolRenderData
// 0x0028 (0x0028 - 0x0000)
struct FLandscapeEditToolRenderData final
{
public:
	class UMaterialInterface*                     ToolMaterial;                                      // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UMaterialInterface*                     GizmoMaterial;                                     // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         SelectedType;                                      // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         DebugChannelR;                                     // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         DebugChannelG;                                     // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         DebugChannelB;                                     // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             DataTexture;                                       // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.GrassVariety
// 0x0048 (0x0048 - 0x0000)
struct FGrassVariety final
{
public:
	class UStaticMesh*                            GrassMesh;                                         // 0x0000(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPerPlatformFloat                      GrassDensity;                                      // 0x0008(0x0004)(Edit, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          bUseGrid;                                          // 0x000C(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_241A[0x3];                                     // 0x000D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PlacementJitter;                                   // 0x0010(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPerPlatformInt                        StartCullDistance;                                 // 0x0014(0x0004)(Edit, NoDestructor, NativeAccessSpecifierPublic)
	struct FPerPlatformInt                        EndCullDistance;                                   // 0x0018(0x0004)(Edit, NoDestructor, NativeAccessSpecifierPublic)
	int32                                         MinLOD;                                            // 0x001C(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EGrassScaling                                 Scaling;                                           // 0x0020(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_241B[0x3];                                     // 0x0021(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFloatInterval                         ScaleX;                                            // 0x0024(0x0008)(Edit, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FFloatInterval                         ScaleY;                                            // 0x002C(0x0008)(Edit, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FFloatInterval                         ScaleZ;                                            // 0x0034(0x0008)(Edit, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          RandomRotation;                                    // 0x003C(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          AlignToSurface;                                    // 0x003D(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUseLandscapeLightmap;                             // 0x003E(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLightingChannels                      LightingChannels;                                  // 0x003F(0x0001)(Edit, NoDestructor, AdvancedDisplay, NativeAccessSpecifierPublic)
	bool                                          bReceivesDecals;                                   // 0x0040(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCastDynamicShadow;                                // 0x0041(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bKeepInstanceBufferCPUCopy;                        // 0x0042(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_241C[0x5];                                     // 0x0043(0x0005)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.LandscapeInfoLayerSettings
// 0x0010 (0x0010 - 0x0000)
struct FLandscapeInfoLayerSettings final
{
public:
	class ULandscapeLayerInfoObject*              LayerInfoObj;                                      // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   LayerName;                                         // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.LandscapeLayerStruct
// 0x0008 (0x0008 - 0x0000)
struct FLandscapeLayerStruct final
{
public:
	class ULandscapeLayerInfoObject*              LayerInfoObj;                                      // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.LandscapeEditorLayerSettings
// 0x0001 (0x0001 - 0x0000)
struct FLandscapeEditorLayerSettings final
{
public:
	uint8                                         Pad_241D[0x1];                                     // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.LandscapeWeightmapUsage
// 0x0020 (0x0020 - 0x0000)
struct FLandscapeWeightmapUsage final
{
public:
	class ULandscapeComponent*                    ChannelUsage[0x4];                                 // 0x0000(0x0008)(ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.LandscapeSplineConnection
// 0x0010 (0x0010 - 0x0000)
struct FLandscapeSplineConnection final
{
public:
	class ULandscapeSplineSegment*                Segment;                                           // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         End : 1;                                           // 0x0008(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_241E[0x7];                                     // 0x0009(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.ForeignWorldSplineData
// 0x0001 (0x0001 - 0x0000)
struct FForeignWorldSplineData final
{
public:
	uint8                                         Pad_241F[0x1];                                     // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.ForeignSplineSegmentData
// 0x0001 (0x0001 - 0x0000)
struct FForeignSplineSegmentData final
{
public:
	uint8                                         Pad_2420[0x1];                                     // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.ForeignControlPointData
// 0x0001 (0x0001 - 0x0000)
struct FForeignControlPointData final
{
public:
	uint8                                         Pad_2421[0x1];                                     // 0x0000(0x0001)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.LandscapeSplineSegmentConnection
// 0x0018 (0x0018 - 0x0000)
struct FLandscapeSplineSegmentConnection final
{
public:
	class ULandscapeSplineControlPoint*           ControlPoint;                                      // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         TangentLen;                                        // 0x0008(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2422[0x4];                                     // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   SocketName;                                        // 0x0010(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.LandscapeSplineInterpPoint
// 0x0040 (0x0040 - 0x0000)
struct FLandscapeSplineInterpPoint final
{
public:
	struct FVector                                Center;                                            // 0x0000(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                Left;                                              // 0x000C(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                Right;                                             // 0x0018(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                FalloffLeft;                                       // 0x0024(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                FalloffRight;                                      // 0x0030(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         StartEndFalloff;                                   // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// ScriptStruct Landscape.GrassInput
// 0x0028 (0x0028 - 0x0000)
struct FGrassInput final
{
public:
	class FName                                   Name;                                              // 0x0000(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class ULandscapeGrassType*                    GrassType;                                         // 0x0008(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FExpressionInput                       Input;                                             // 0x0010(0x0010)(NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2423[0x8];                                     // 0x0020(0x0008)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

// ScriptStruct Landscape.LayerBlendInput
// 0x0058 (0x0058 - 0x0000)
struct FLayerBlendInput final
{
public:
	class FName                                   LayerName;                                         // 0x0000(0x0008)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ELandscapeLayerBlendType                      BlendType;                                         // 0x0008(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2424[0x7];                                     // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FExpressionInput                       LayerInput;                                        // 0x0010(0x0010)(NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2425[0x8];                                     // 0x0020(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FExpressionInput                       HeightInput;                                       // 0x0028(0x0010)(NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_2426[0x8];                                     // 0x0038(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PreviewWeight;                                     // 0x0040(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                ConstLayerInput;                                   // 0x0044(0x000C)(Edit, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ConstHeightInput;                                  // 0x0050(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2427[0x4];                                     // 0x0054(0x0004)(Fixing Struct Size After Last Property [ Dumper-7 ])
};

}

