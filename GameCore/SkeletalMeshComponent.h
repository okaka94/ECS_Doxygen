#pragma once
#include "Define.h"
#include "DXTexture.hpp"
#include "Material.h"
#include "MeshComponent.hpp"

/**
 * @class SkeletalMeshComponent
 * @brief [C] <MeshComponent> 리스트를 담고있다.
*/
class SkeletalMeshComponent
{
public:
	std::vector<MeshComponent> Meshes;

public:
	SkeletalMeshComponent() {};
};