#pragma once
#include "Light.h"

/**
 * @class DirectionalLight
 * @brief [E] Directional Light : <Movement> + <Transform> + <DirectionalLightComponent>
*/
class DirectionalLight : public Light
{
public:

public:
	DirectionalLight();
	virtual ~DirectionalLight();
};

DirectionalLight::DirectionalLight()
{
	this->AddComponent<DirectionalLightComponent>();
}

DirectionalLight::~DirectionalLight()
{

}