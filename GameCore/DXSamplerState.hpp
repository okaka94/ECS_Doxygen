#pragma once
#include "Define.h"
#include "DXDevice.hpp"

/**
 * @class DXSamplerState
 * @brief 여러 DX States를 관리하는 클래스이다.
*/
class DXSamplerState
{
public:
	static ID3D11SamplerState* pDefaultSamplerState;				///< 최근점 필터링 & 바둑판식 샘플링으로 설정
	static ID3D11SamplerState* pDefaultMirrorSamplerState;			///< 최근점 필터링 & 거울상(이미지축 반전식) 샘플링으로 설정
	static ID3D11RasterizerState* pDefaultRSWireFrame;				///< 와이어프레임 & Back 컬링 (앞면 렌더)으로 설정
	static ID3D11RasterizerState* pRSWireFrame_CullNone;			///< 와이어프레임 & None 컬링 (앞뒤 모두 렌더)으로 설정
	static ID3D11RasterizerState* pRSWireFrame_CullFront;			///< 와이어프레임 & Front 컬링 (뒷면 렌더)으로 설정
	static ID3D11RasterizerState* pDefaultRSSolid;					///< 디폴트 래스터라이저(솔리드) & Back 컬링 (앞면 렌더)으로 설정
	static ID3D11RasterizerState* pRSSolid_CullNone;				///< 디폴트 래스터라이저(솔리드) & None 컬링 (앞뒤 모두 렌더)으로 설정
	static ID3D11RasterizerState* pRSSolid_CullFront;				///< 디폴트 래스터라이저(솔리드) & Front 컬링 (뒷면 렌더)으로 설정
	static ID3D11BlendState* pBlendSamplerState;					///< 알파 블렌딩 설정

	static ID3D11DepthStencilState* pDefaultDepthStencil;			///< 깊이 버퍼 사용 & 버퍼 비교 - Less(원래 값보다 작거나 같으면 출력) 설정
	static ID3D11DepthStencilState* pGreaterDepthStencil;			///< 깊이 버퍼 사용 & 버퍼 비교 - Greater(원래 값보다 크거나 같으면 출력) 설정. 처음부터 이 설정 적용하면 기본 값 1.0보다 큰 값이 없기때문에 출력 오류 생김

public:

	/**
	 * @brief 여러 스테이트를 미리 생성해두고 스태틱 멤버 변수로 할당한다.
	 * @param[in] device 디바이스
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	static bool setState(ID3D11Device* _pd3dDevice);

	/**
	 * @brief 생성된 스테이트들을 초기화한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	static bool release();
};
