#pragma once
#include "Define.h"
#include "DXDevice.hpp"

/**
 * @class DXSamplerState
 * @brief ���� DX States�� �����ϴ� Ŭ�����̴�.
*/
class DXSamplerState
{
public:
	static ID3D11SamplerState* pDefaultSamplerState;				///< �ֱ��� ���͸� & �ٵ��ǽ� ���ø����� ����
	static ID3D11SamplerState* pDefaultMirrorSamplerState;			///< �ֱ��� ���͸� & �ſ��(�̹����� ������) ���ø����� ����
	static ID3D11RasterizerState* pDefaultRSWireFrame;				///< ���̾������� & Back �ø� (�ո� ����)���� ����
	static ID3D11RasterizerState* pRSWireFrame_CullNone;			///< ���̾������� & None �ø� (�յ� ��� ����)���� ����
	static ID3D11RasterizerState* pRSWireFrame_CullFront;			///< ���̾������� & Front �ø� (�޸� ����)���� ����
	static ID3D11RasterizerState* pDefaultRSSolid;					///< ����Ʈ �����Ͷ�����(�ָ���) & Back �ø� (�ո� ����)���� ����
	static ID3D11RasterizerState* pRSSolid_CullNone;				///< ����Ʈ �����Ͷ�����(�ָ���) & None �ø� (�յ� ��� ����)���� ����
	static ID3D11RasterizerState* pRSSolid_CullFront;				///< ����Ʈ �����Ͷ�����(�ָ���) & Front �ø� (�޸� ����)���� ����
	static ID3D11BlendState* pBlendSamplerState;					///< ���� ���� ����

	static ID3D11DepthStencilState* pDefaultDepthStencil;			///< ���� ���� ��� & ���� �� - Less(���� ������ �۰ų� ������ ���) ����
	static ID3D11DepthStencilState* pGreaterDepthStencil;			///< ���� ���� ��� & ���� �� - Greater(���� ������ ũ�ų� ������ ���) ����. ó������ �� ���� �����ϸ� �⺻ �� 1.0���� ū ���� ���⶧���� ��� ���� ����

public:

	/**
	 * @brief ���� ������Ʈ�� �̸� �����صΰ� ����ƽ ��� ������ �Ҵ��Ѵ�.
	 * @param[in] device ����̽�
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	static bool setState(ID3D11Device* _pd3dDevice);

	/**
	 * @brief ������ ������Ʈ���� �ʱ�ȭ�Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	static bool release();
};
