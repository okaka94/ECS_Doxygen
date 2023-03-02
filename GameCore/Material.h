#pragma once
#include "Define.h"
#include "DXTexture.hpp"
#include "DXDevice.hpp"

/**
 * @class Material
 * @brief [C] �ؽ�ó ����Ʈ�� �ȼ� ���̴��� �����Ǿ��ִ�.
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
	 * @brief �ؽ�ó ����Ʈ�� �ִ� �ؽ�ó�鿡 �ȼ� ���̴��� �����Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Apply();

public:

	/**
	 * @brief �ؽ�ó ����Ʈ�� �ؽ�ó�� �߰��Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool AddTexture(DXTexture* texture);

	/**
	 * @brief �ȼ� ���̴��� �����Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool SetPixelShader(ID3D11PixelShader* pixelShader);

	/**
	 * @brief ���ؽ�Ʈ�� �Ҵ��Ѵ�.
	 * @param[in] context ����̽� ���ؽ�Ʈ
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
