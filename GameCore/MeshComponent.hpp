#pragma once
#include "Define.h"
#include "DXTextureManager.hpp"
#include "Material.h"
#include "DXDevice.hpp"
#include "DXShaderManager.h"


/**
 * @struct Face
 * @brief 정점 3개로 구성된 페이스 구조체이다.
*/
struct Face
{
	Vertex V0;
	Vertex V1;
	Vertex V2;

	Face() : V0(Vertex()), V1(Vertex()), V2(Vertex()) {};
	Face(const Vertex& v0, const Vertex& v1, const Vertex& v2)
		: V0(v0), V1(v1), V2(v2)
	{

	}

	Vector3 GetNormal()
	{

	}
};


/**
 * @class MeshComponent
 * @brief [C] 정점, 페이스, 인덱스 정보 등 렌더링을 위한 데이터를 담고있다.
*/
class MeshComponent
{
public:
	ID3D11DeviceContext* Context;
	std::vector<Vertex> Vertices;
	std::vector<Face>	Faces;
	std::vector<DWORD>	Indices;

	int VertexCount = 0;
	int FaceCount = 0;
	int IndexCount = 0;

	ID3D11Buffer*	VertexBuffer = nullptr;
	ID3D11Buffer*	IndexBuffer = nullptr;
	Material*		MaterialSlot = nullptr;

	bool isCreated = false;

public:
	MeshComponent() {};
	~MeshComponent()
	{
		if (MaterialSlot != nullptr)
		{
			delete MaterialSlot;
			MaterialSlot = nullptr;
		}
	}

public:
	/**
	 * @brief isCreated가 false라면 초기화 후 렌더링 작업을 수행한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Render();

	/**
	 * @brief isCreated가 false라면 정점 버퍼와 인덱스 버퍼 생성하고 MaterialSlot을 채운 뒤 isCreated를 true로 설정한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Initialize();

public:
	/**
	 * @brief 컨텍스트를 할당한다.
	 * @param[in] context 디바이스 컨텍스트
	*/
	void SetContext(ID3D11DeviceContext* context) { Context = context; };
};

inline bool MeshComponent::Render()
{
	if (!isCreated)
	{
		Initialize();
	}

	UINT Strides = sizeof(Vertex); // 정점 1개의 바이트 용량
	UINT Offsets = 0; // 정점 버퍼에서 출발 지점(바이트)
	Context->IASetVertexBuffers(0, 1, &VertexBuffer, &Strides, &Offsets);
	Context->UpdateSubresource(VertexBuffer, 0, NULL, &Vertices.at(0), 0, 0);

	MaterialSlot->Apply();

	if (IndexBuffer == nullptr)
	{
		Context->Draw(static_cast<UINT>(Vertices.size()), 0);
	}
	else
	{
		Context->IASetIndexBuffer(IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
		Context->UpdateSubresource(IndexBuffer, 0, NULL, &Indices.at(0), 0, 0);
		Context->DrawIndexed(static_cast<UINT>(Indices.size()), 0, 0);
	}
	
	//ID3D11ShaderResourceView* resourceView = NULL;
	//CONTEXT->PSSetShaderResources(0, 1, &resourceView);

	return true;
}

inline bool MeshComponent::Initialize()
{
	if (isCreated)
	{
		return true;
	}

	VertexBuffer = DXShaderManager::getInstance()->CreateVertexBuffer(Vertices);
	IndexBuffer = DXShaderManager::getInstance()->CreateIndexBuffer(Indices);

	if (MaterialSlot == nullptr)
	{
		MaterialSlot = new Material;
		MaterialSlot->SetContext(Context);
		DXTextureManager::getInstance()->Load(L"../resource/Default.bmp");
		DXTexture* DefaultTexture = DXTextureManager::getInstance()->getTexture(L"../resource/Default.bmp");
		MaterialSlot->AddTexture(DefaultTexture);
		MaterialSlot->SetPixelShader(DXShaderManager::getInstance()->GetPixelShader(L"../include/Core/HLSL/PS_Light.hlsl"));
	}

	isCreated = true;

	return true;
}
