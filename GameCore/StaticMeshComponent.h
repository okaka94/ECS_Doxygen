#pragma once
#include "Define.h"
#include "DXTexture.hpp"
#include "Material.h"
#include "MeshComponent.hpp"
#include "DXShaderManager.h"
#include "TransformComponent.h"

/**
 * @class StaticMeshComponent
 * @brief [C] <MeshComponent> 리스트와 렌더링에 필요한 정보를 담고있다.
*/
class StaticMeshComponent
{
private:
	ID3D11DeviceContext* Context;

public:
	std::vector<MeshComponent> Meshes;
	ID3D11InputLayout*		VertexLayout = nullptr;
	ID3D11VertexShader*		VertexShader = nullptr;
	ID3D11HullShader*		HullShader = nullptr;
	ID3D11DomainShader*		DomainShader = nullptr;
	ID3D11GeometryShader*	GeometryShader = nullptr;
	ID3D11Buffer*			TransformBuffer = nullptr;
	TransformMatrix			TransformData;

	bool isCreated = false;

public:
	StaticMeshComponent() 
	{
		Initialize(); 
	};

public:

	/**
	 * @brief Meshes 리스트를 돌며 Render() 작업을 수행한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Render();

	/**
	 * @brief isCreated가 false라면 인풋 레이아웃, 정점 셰이더, 상수 버퍼를 생성하고 isCreated를 true로 설정한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Initialize();

public:

	/**
	 * @brief 인자로 행렬을 받아 메시의 TransformData를 아핀 변환한다.
	 * @param[in] transform T R S 값을 가진 구조체
	*/
	void UpdateTransformMatrix(const TransformComponent& transform);

	/**
	 * @brief 컨텍스트를 할당한다.
	 * @param[in] context 디바이스 컨텍스트
	*/
	void SetContext(ID3D11DeviceContext* context);
};

inline bool StaticMeshComponent::Render()
{
	/*if (!isCreated)
	{
		Initialize();
	}*/

	Context->IASetInputLayout(VertexLayout);
	Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	Context->VSSetShader(VertexShader, NULL, 0);
	Context->HSSetShader(HullShader, NULL, 0);
	Context->DSSetShader(DomainShader, NULL, 0);
	Context->GSSetShader(GeometryShader, NULL, 0);
	Context->UpdateSubresource(TransformBuffer, 0, NULL, &TransformData, 0, 0);
	Context->VSSetConstantBuffers(0, 1, &TransformBuffer);
	
	for (auto& it : Meshes)
	{
		it.Render();
	}

	return true;
}

inline bool StaticMeshComponent::Initialize()
{
	if (isCreated)
	{
		return true;
	}

	VertexLayout = DXShaderManager::getInstance()->GetInputLayout(InputLayoutType::StaticMesh);
	VertexShader = DXShaderManager::getInstance()->GetVertexShader(L"../include/Core/HLSL/VS_StaticMesh.hlsl");
	TransformBuffer = DXShaderManager::getInstance()->CreateConstantBuffer<TransformMatrix>(TransformData);
	isCreated = true;

	return true;
}

inline void StaticMeshComponent::UpdateTransformMatrix(const TransformComponent& transform)
{
	DirectX::FXMVECTOR q = DirectX::XMQuaternionRotationRollPitchYawFromVector(transform.Rotation);
	TransformData.Mat = DirectX::XMMatrixAffineTransformation(transform.Scale, transform.Translation, q, transform.Translation);
	TransformData.Mat = TransformData.Mat.Transpose();
}

inline void StaticMeshComponent::SetContext(ID3D11DeviceContext* context)
{
	Context = context;
}
