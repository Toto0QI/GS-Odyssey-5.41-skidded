#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: IMeleeWhileMoving

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass IMeleeWhileMoving.IMeleeWhileMoving_C
// 0x0000 (0x0028 - 0x0028)
class IIMeleeWhileMoving_C final : public IInterface
{
public:
	void GetCollisionPredictionComponent(class UShapeComponent** Collision_Prediction_Shape_Component);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"IMeleeWhileMoving_C">();
	}
	static class IIMeleeWhileMoving_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IIMeleeWhileMoving_C>();
	}
};

}
