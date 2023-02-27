#pragma once
#include "DXShaderManager.h"
#include "DXTexture.hpp"
#include "DXSamplerState.hpp"

/**
 * @class DXRenderTarget
 * @brief 텍스처 렌더링을 위한 클래스이다.
*/
class DXRenderTarget
{
private:
	// Device
	ID3D11Device*			m_pd3dDevice = nullptr;
	ID3D11DeviceContext*	m_pImmediateContext = nullptr;

	// Texture Render Target View
	D3D11_VIEWPORT					m_viewPort = D3D11_VIEWPORT();

	ComPtr<ID3D11RenderTargetView>	m_pRenderTargetView = nullptr;
	DXTexture*						m_pTexture = nullptr;
	
	ComPtr<ID3D11DepthStencilView>	m_pDepthStencilView = nullptr;
	ComPtr<ID3D11Texture2D>			m_pDSTexture = nullptr;

	
	ID3D11RenderTargetView*			m_pOldRenderTargetView = nullptr;								///< For Save Prev View Infomation.
	ID3D11DepthStencilView*			m_pOldDepthStencilView = nullptr;								///< For Save Prev View Infomation.
	D3D11_VIEWPORT					m_OldViewPort[D3D11_VIEWPORT_AND_SCISSORRECT_MAX_INDEX] = {};	///< For Save Prev View Infomation.

	// For Render
	ID3D11InputLayout*				InputLayout = nullptr;

	ID3D11VertexShader*				VertexShader = nullptr;
	ID3D11PixelShader*				PixelShader = nullptr;

	ID3D11SamplerState*				SamplerState = nullptr;
	ID3D11RasterizerState*			RSState = nullptr;

	ID3D11Buffer*					VertexBuffer = nullptr;
	ID3D11Buffer*					IndexBuffer = nullptr;
	ID3D11Buffer*					TransformBuffer = nullptr;
	ID3D11Buffer*					CameraProjectionBuffer = nullptr;

	std::vector<Vertex>				VertexList;
	std::vector<DWORD>				IndexList;
	TransformMatrix					TransformData;
	CameraMatrix					ProjectionData;

public:
	DXRenderTarget();

public:

	/**
	 * @brief 디바이스와 컨텍스트를 멤버에 할당해준다.
	 * @param[in] device 디바이스
	 * @param[in] context 디바이스 컨텍스트
	*/
	void SetDevice(ID3D11Device* device, ID3D11DeviceContext* context);

	/**
	 * @brief 텍스처 렌더 타겟 뷰를 생성한다.
	 * @detail 뷰포트 사이즈 설정 -> 텍스처 생성 -> RTV & DSV 생성 -> 셰이더 생성 & States 설정을 한다.
	 * @param[in] x 뷰포트의 TopLeftX
	 * @param[in] y 뷰포트의 TopLeftY
	 * @param[in] width 뷰포트의 넓이
	 * @param[in] height 뷰포트의 높이
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Create(float x, float y, float width, float height);

	/**
	 * @brief 이전의 RTV & DSV를 저장하고 새로운 RTV & DSV와 뷰포트로 교체한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Begin();

	/**
	 * @brief 텍스처로부터 SRV를 받아와 Draw() 한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Render();

	/**
	 * @brief 이전에 저장해둔 뷰포트로 설정을 복원한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool End();

	/**
	 * @brief DXRenderTaget 클래스의 Release 함수이다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Release();
};