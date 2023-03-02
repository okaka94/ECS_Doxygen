#pragma once
#include "Define.h"
#include "DXTexture.hpp"
#include "Material.h"
#include "MeshComponent.hpp"

/**
 * @class SkeletalMeshComponent
 * @brief [C] <MeshComponent> ����Ʈ�� ����ִ�.
*/
class SkeletalMeshComponent
{
public:
	std::vector<MeshComponent> Meshes;

public:
	SkeletalMeshComponent() {};
};