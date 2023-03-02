#pragma once
#include "Define.h"
#include "DXTexture.hpp"
#include "DXDevice.hpp"

/**
 * @class Material
 * @brief [C] 텍스처 리스트와 픽셀 셰이더로 구성되어있다.
*/
class Material
{
private:
	ID3D11DeviceContext*			Context;
	ID3D11PixelShader*				PixelShader;
	std::vector<DXTexture*>			Textures;

public:
	Material();
	~Material();

public:
	/**
	 * @brief 텍스처 리스트에 있는 텍스처들에 픽셀 셰이더를 적용한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Apply();

public:

	/**
	 * @brief 텍스처 리스트에 텍스처를 추가한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool AddTexture(DXTexture* texture);

	/**
	 * @brief 픽셀 셰이더를 설정한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool SetPixelShader(ID3D11PixelShader* pixelShader);

	/**
	 * @brief 컨텍스트를 할당한다.
	 * @param[in] context 디바이스 컨텍스트
	*/
	void SetContext(ID3D11DeviceContext* context);
};

inline Material::Material()
{
	
}

inline Material::~Material()
{
	Textures.clear();
}

inline bool Material::Apply()
{
	Context->PSSetShader(PixelShader, NULL, 0);
	for (size_t idx = 0; idx < Textures.size(); idx++)
	{
		ID3D11ShaderResourceView* resourceView = Textures[idx]->getResourceView();
		Context->PSSetShaderResources(idx, 1, &resourceView);
	}
	return true;
}

inline bool Material::AddTexture(DXTexture* texture)
{
	Textures.push_back(texture);
	return true;
}

inline bool Material::SetPixelShader(ID3D11PixelShader* pixelShader)
{
	PixelShader = pixelShader;
	return true;
}

inline void Material::SetContext(ID3D11DeviceContext* context)
{
	Context = context;
}
