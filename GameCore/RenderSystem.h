#pragma once
#include "Define.h"
#include "System.hpp"

/**
 * @class RenderSystem
 * @brief [S]렌더링 시스템
*/
class RenderSystem : public ECS::System
{
private:
	ID3D11DeviceContext* Context;

public:
	/**
	 * @brief <Landscape> , <SkeletalMeshComponent> , <StaticMeshComponent>를 가진 각 엔티티들을 동작시킨다. 
	 * @param[in] world 월드
	 * @param[in] time 시간
	*/
	virtual void Tick(ECS::World* world, float time) override;
	/*{
		ID3D11RasterizerState* pOldRSState;
		CONTEXT->RSGetState(&pOldRSState);
		CONTEXT->RSSetState(DXSamplerState::pDefaultRSSolid);
		CONTEXT->OMSetBlendState(DXSamplerState::pBlendSamplerState, 0, -1);
		CONTEXT->PSSetSamplers(0, 1, &DXSamplerState::pDefaultSamplerState);
		for (auto& entity : world->GetEntities<SkeletalMeshComponent>())
		{
			auto skeletalMesh = entity.get()->GetComponent<SkeletalMeshComponent>();
			
		}

		for (auto& entity : world->GetEntities<StaticMeshComponent>())
		{
			auto staticMesh = entity.get()->GetComponent<StaticMeshComponent>();
			auto transform = entity.get()->GetComponent<TransformComponent
			staticMesh->Render();
		}

		CONTEXT->RSSetState(pOldRSState);
		if (pOldRSState != nullptr)
		{
			pOldRSState->Release();
		}
	}*/


	/**
	 * @brief Context 멤버에 디바이스 컨텍스트를 할당해준다.
	*/
	void SetContext(ID3D11DeviceContext* context);
};