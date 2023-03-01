#pragma once
#include "Define.h"

// Direct X -> Texture Tool Kit
#include "DXTK/WICTextureLoader.h"
#include "DXTK/DDSTextureLoader.h"

#ifdef _DEBUG
#pragma comment(lib, "DirectXTK_d.lib")
#else
#pragma comment(lib, "DirectXTK_r.lib")
#endif

/**
 * @class DXTexture
 * @brief �ؽ�ó�� �ε��ϰ� ������ �����ϴ� Ŭ�����̴�.
*/
class DXTexture
{
private:
	ID3D11Device*				m_pd3dDevice = nullptr;
	ID3D11DeviceContext*		m_pImmediateContext = nullptr;
	
private:
	// Texture
	ID3D11ShaderResourceView*	m_pTextureResourceView;
	//ID3D11Resource*			m_pTextureResource;
	ID3D11Texture2D*			m_pTextureResource;
	D3D11_TEXTURE2D_DESC		m_Desc;

private:
	std::wstring				m_wstrFileName;

private:
	std::vector<UINT>			MappedResourceData;

public:

	/**
	 * @brief ����̽��� ���ؽ�Ʈ�� ����� �Ҵ����ش�.
	 * @param[in] _device ����̽�
	 * @param[in] _context ����̽� ���ؽ�Ʈ
	*/
	void						setDevice(ID3D11Device* _device, ID3D11DeviceContext* _context);

public:

	/**
	 * @brief �ؽ�ó�� �ε��Ѵ�.
	 * @detail tga �����̸� dds�� �̸��� �ٲ� �ε��ϰ�, WICTexture�� �ε��� �� �����ϸ� DDSTexture�� �ε��Ѵ�.
	 * ���Ŀ� m_Desc ����� �ؽ�ó�� ������ �����Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return ������ ���ٸ� TRUE�� �����Ѵ�.
	*/
	HRESULT						Load(std::wstring _filename);

	/**
	 * @brief ���� �̻��
	*/
	HRESULT						LoadEX(std::wstring _filename);
	
public:

	/**
	 * @brief ��ü�� �ؽ�ó ���ҽ��� �����Ѵ�.
	 * @return m_pTextureResource
	*/
	ID3D11Resource*				getResource();

	/**
	 * @brief ��ü�� �ؽ�ó ���ҽ� �並 �����Ѵ�.
	 * @return m_pTextureResourceView
	*/
	ID3D11ShaderResourceView*	getResourceView();

public:

	/**
	 * @brief �ؽ�ó�� ���̸� �����Ѵ�.
	 * @return m_Desc.Width
	*/
	float						getWidth();

	/**
	 * @brief �ؽ�ó�� ���̸� �����Ѵ�.
	 * @return m_Desc.Height
	*/
	float						getHeight();

	/**
	 * @brief ���ϸ��� �����Ѵ�.
	 * @return m_wstrFileName
	*/
	std::wstring				getFileName();

	/**
	 * @brief �̻��
	*/
	std::vector<UINT>&			getMappedResource();

public:

	/**
	  * @brief �ؽ�ó Ŭ������ Release �۾��� �����Ѵ�.
	  * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool						Release();
	
public:

	/**
	 * @brief ������ ũ��� ����Ÿ������ ����� SRV�� �����Ѵ�.
	 * @detail ����Ÿ��, ���̴����ҽ� ���ε� �÷��װ� ������ �ؽ�ó2D (m_pTextureResource)�� ������ ��
	 * �̸� ����� SRV (m_pTextureResourceView)�� �����Ѵ�.
	 * @param[in] _width ����
	 * @param[in] _height ����
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool						CreateRenderTarget(float _width, float _height);
};

