#pragma once
#include "Light.h"

/**
 * @class SpotLight
 * @brief [E]Spot Light : <Movement> + <Transform> + <SpotLightComponent>
*/
class SpotLight : public Light
{
public:

public:
	SpotLight();
	virtual ~SpotLight();
};

SpotLight::SpotLight()
{
	this->AddComponent<SpotLightComponent>();
}

SpotLight::~SpotLight()
{

}