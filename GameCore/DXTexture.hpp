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
 * @brief 텍스처를 로드하고 정보를 관리하는 클래스이다.
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
	 * @brief 디바이스와 컨텍스트를 멤버에 할당해준다.
	 * @param[in] _device 디바이스
	 * @param[in] _context 디바이스 컨텍스트
	*/
	void						setDevice(ID3D11Device* _device, ID3D11DeviceContext* _context);

public:

	/**
	 * @brief 텍스처를 로드한다.
	 * @detail tga 파일이면 dds로 이름을 바꿔 로드하고, WICTexture로 로드한 뒤 실패하면 DDSTexture로 로드한다.
	 * 이후에 m_Desc 멤버에 텍스처의 정보를 저장한다.
	 * 
	 * @param[in] _filename 파일명
	 * @return 오류가 없다면 TRUE를 리턴한다.
	*/
	HRESULT						Load(std::wstring _filename);
	HRESULT						LoadEX(std::wstring _filename);
	
public:
	ID3D11Resource*				getResource();
	ID3D11ShaderResourceView*	getResourceView();

public:
	float						getWidth();
	float						getHeight();
	std::wstring				getFileName();
	std::vector<UINT>&			getMappedResource();

public:
	bool						Release();
	
public:
	bool						CreateRenderTarget(float _width, float _height);
};

