#pragma once
#include "DXShaderManager.h"
#include "DXTexture.hpp"
#include "DXSamplerState.hpp"

/**
 * @class DXRenderTarget
 * @brief �ؽ�ó �������� ���� Ŭ�����̴�.
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
	 * @brief ����̽��� ���ؽ�Ʈ�� ����� �Ҵ����ش�.
	 * @param[in] device ����̽�
	 * @param[in] context ����̽� ���ؽ�Ʈ
	*/
	void SetDevice(ID3D11Device* device, ID3D11DeviceContext* context);

	/**
	 * @brief �ؽ�ó ���� Ÿ�� �並 �����Ѵ�.
	 * @detail ����Ʈ ������ ���� -> �ؽ�ó ���� -> RTV & DSV ���� -> ���̴� ���� & States ������ �Ѵ�.
	 * @param[in] x ����Ʈ�� TopLeftX
	 * @param[in] y ����Ʈ�� TopLeftY
	 * @param[in] width ����Ʈ�� ����
	 * @param[in] height ����Ʈ�� ����
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Create(float x, float y, float width, float height);

	/**
	 * @brief ������ RTV & DSV�� �����ϰ� ���ο� RTV & DSV�� ����Ʈ�� ��ü�Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Begin();

	/**
	 * @brief �ؽ�ó�κ��� SRV�� �޾ƿ� Draw() �Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Render();

	/**
	 * @brief ������ �����ص� ����Ʈ�� ������ �����Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool End();

	/**
	 * @brief DXRenderTaget Ŭ������ Release �Լ��̴�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Release();
};