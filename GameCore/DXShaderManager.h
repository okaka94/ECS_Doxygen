#pragma once
#include "Define.h"

/**
	* @class InputLayoutType
	* @brief 스태틱 메시와 스켈레탈 메시로 구분되는 열거형 클래스이다. 
	*/
enum class InputLayoutType
{
	StaticMesh,
	SkeletalMesh
};

/**
 * @class DXShaderManager
 * @brief [싱글톤]셰이더를 관리하는 매니저 클래스이다.
*/
class DXShaderManager : public Singleton<DXShaderManager>
{
private:
	friend class Singleton<DXShaderManager>;

private:
	ID3D11Device*									m_pd3dDevice = nullptr;
	ID3D11DeviceContext*							m_pImmediateContext = nullptr;

	std::map<InputLayoutType, ID3D11InputLayout*>	InputLayoutMap;

	std::map<std::wstring, ID3DBlob*>				VertexShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				HullShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				DomainShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				GeometryShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				PixelShaderCodeMap;

	std::map<std::wstring, ID3D11VertexShader*>		VertexShaderMap;
	std::map<std::wstring, ID3D11HullShader*>		HullShaderMap;
	std::map<std::wstring, ID3D11DomainShader*>		DomainShaderMap;
	std::map<std::wstring, ID3D11GeometryShader*>	GeometryShaderMap;
	std::map<std::wstring, ID3D11PixelShader*>		PixelShaderMap;

	std::vector<ID3D11Buffer*>						BufferList;

private:
	DXShaderManager() {};
	virtual ~DXShaderManager() { Release(); };

public:
	/**
		* @brief 기존에 생성된 정점 셰이더 코드가 없다면 새롭게 생성 후 코드 맵에 삽입한다.
		* @param filename 파일명
		* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool LoadVSCode(std::wstring filename);

	/**
	* @brief 기존에 생성된 헐 셰이더 코드가 없다면 새롭게 생성 후 코드 맵에 삽입한다.
	* @param filename 파일명
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool LoadHSCode(std::wstring filename);

	/**
	* @brief 기존에 생성된 도메인 셰이더 코드가 없다면 새롭게 생성 후 코드 맵에 삽입한다.
	* @param filename 파일명
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool LoadDSCode(std::wstring filename);

	/**
	* @brief 기존에 생성된 기하 셰이더 코드가 없다면 새롭게 생성 후 코드 맵에 삽입한다.
	* @param filename 파일명
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool LoadGSCode(std::wstring filename);

	/**
	* @brief 기존에 생성된 픽셀 셰이더 코드가 없다면 새롭게 생성 후 코드 맵에 삽입한다.
	* @param filename 파일명
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool LoadPSCode(std::wstring filename);

	/**
	* @brief 코드 맵에 있는 모든 셰이더 코드를 불러와 셰이더를 생성 후 셰이더 맵에 삽입한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CreateVertexShader();

	/**
	* @brief 코드 맵에 있는 모든 셰이더 코드를 불러와 셰이더를 생성 후 셰이더 맵에 삽입한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CreatePixelShader();

	/**
	* @brief 코드 맵에 있는 모든 셰이더 코드를 불러와 셰이더를 생성 후 셰이더 맵에 삽입한다.
	* @param decl ????
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CreateGeometryShader(D3D11_SO_DECLARATION_ENTRY* decl);

	/**
	* @brief 스태틱 메시 인풋 레이아웃 생성 함수 호출 후 스켈레탈 메시 인풋 레이아웃 생성 함수를 호출한다.
	* @return 스태틱 메시와 스켈레탈 메시 레이아웃이 모두 생성되면 true 값을 리턴한다.
	*/
	bool CreateInputLayout();

	/**
	* @brief "VS_StaticMesh.hlsl" 파일의 정점 셰이더 코드가 있다면 PNCT 형태의 인풋 레이아웃 생성 후 맵에 삽입한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CreateStaticMeshInputLayout();

	/**
	* @brief "VS_SkeletalMesh.hlsl" 파일의 정점 셰이더 코드가 있다면 PNCT 형태의 인풋 레이아웃 생성 후 맵에 삽입한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CreateSkeletalMeshInputLayout();

public:

	/**
	* @brief 정점 버퍼를 생성한다.
	* @param vertices 정점의 PNCT 정보가 담긴 벡터 컨테이너
	* @return 버퍼 생성 실패시 nullptr을 리턴, 성공시 버퍼 포인터를 BufferList에 추가 후 리턴한다.
	*/
	ID3D11Buffer* CreateVertexBuffer(const std::vector<Vertex>& vertices);

	/**
	* @brief indices가 비어있지 않다면 인덱스 버퍼를 생성한다.
	* @param indices DWORD 값이 담긴 벡터 컨테이너
	* @return 버퍼 생성 실패시 nullptr을 리턴, 성공시 버퍼 포인터를 BufferList에 추가 후 리턴한다.
	*/
	ID3D11Buffer* CreateIndexBuffer(const std::vector<DWORD>& indices);

	/**
	* @brief 상수 버퍼를 생성한다.
	* @param constantData [템플릿 인자]
	* @return 버퍼 생성 실패시 nullptr을 리턴, 성공시 버퍼 포인터를 BufferList에 추가 후 리턴한다.
	*/
	template <typename T>
	ID3D11Buffer* CreateConstantBuffer(const T& constantData);

	/**
	* @brief 아웃풋 버퍼를 생성한다.
	* @param size 버퍼 사이즈
	* @return 버퍼 생성 실패시 nullptr을 리턴, 성공시 버퍼 포인터를 BufferList에 추가 후 리턴한다.
	*/
	ID3D11Buffer* CreateStreamOutputBuffer(UINT size);

	/**
	* @brief 현재 미사용
	* @param size 버퍼 사이즈
	* @return nullptr
	*/
	ID3D11Buffer* CreateMappedBuffer(UINT size);

public:
	/**
	 * @brief 디바이스와 컨텍스트를 멤버에 할당해준다.
	 * @param[in] device 디바이스
	 * @param[in] context 디바이스 컨텍스트
	*/
	void SetDevice(ID3D11Device* device, ID3D11DeviceContext* context);

public:
	/**
	 * @brief 인풋 레이아웃 맵에서 지정한 타입의 인풋 레이아웃을 받아온다.
	 * @param[in] type 인풋 레이아웃 타입
	 * @return 맵에 찾는 타입이 없다면 nullptr을 리턴하고, 존재하면 인풋 레이아웃 포인터를 리턴한다.
	*/
	ID3D11InputLayout* GetInputLayout(InputLayoutType type);

	/**
	 * @brief 셰이더 코드 맵을 검색해 셰이더 코드를 얻기위한 ID3DBlob 포인터를 받아온다.
	 * @param[in] key 파일명
	 * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3DBlob* GetVSCode(std::wstring key);

	/**
	 * @brief 셰이더 코드 맵을 검색해 셰이더 코드를 얻기위한 ID3DBlob 포인터를 받아온다.
	 * @param[in] key 파일명
	 * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3DBlob* GetHSCode(std::wstring key);

	/**
	 * @brief 셰이더 코드 맵을 검색해 셰이더 코드를 얻기위한 ID3DBlob 포인터를 받아온다.
	 * @param[in] key 파일명
	 * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3DBlob* GetDSCode(std::wstring key);

	/**
	 * @brief 셰이더 코드 맵을 검색해 셰이더 코드를 얻기위한 ID3DBlob 포인터를 받아온다.
	 * @param[in] key 파일명
	 * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3DBlob* GetGSCode(std::wstring key);

	/**
	 * @brief 셰이더 코드 맵을 검색해 셰이더 코드를 얻기위한 ID3DBlob 포인터를 받아온다.
	 * @param[in] key 파일명
	 * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3DBlob* GetPSCode(std::wstring key);


	/**
	 * @brief 셰이더 맵을 검색해 셰이더 포인터를 받아온다.
	 * @param[in] key 파일명
	 * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3D11VertexShader*		GetVertexShader(std::wstring key);

	/**
	  * @brief 셰이더 맵을 검색해 셰이더 포인터를 받아온다.
	  * @param[in] key 파일명
	  * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3D11HullShader*		GetHullShader(std::wstring key);

	/**
	  * @brief 셰이더 맵을 검색해 셰이더 포인터를 받아온다.
	  * @param[in] key 파일명
	  * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3D11DomainShader*		GetDomainShader(std::wstring key);

	/**
	  * @brief 셰이더 맵을 검색해 셰이더 포인터를 받아온다.
	  * @param[in] key 파일명
	  * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3D11GeometryShader*	GetGeometryShader(std::wstring key);

	/**
	  * @brief 셰이더 맵을 검색해 셰이더 포인터를 받아온다.
	  * @param[in] key 파일명
	  * @return 검색 결과가 존재하면 포인터를 리턴한다.
	*/
	ID3D11PixelShader*		GetPixelShader(std::wstring key);
	
public:
	/**
	  * @brief 셰이더 매니저 클래스의 초기화 작업을 수행한다.
	  * @detail 정점 셰이더 파일(VS_StaticMesh , VS_SkeletalMesh)을 컴파일하고
	  * 픽셀 셰이더 파일(PS_Default , PS_Light)을 컴파일 한 후 정점 셰이더와 픽셀 셰이더, 인풋 레이아웃을 생성한다.
	  * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Initialize();

	/**
	  * @brief 셰이더 매니저 클래스의 Release 작업을 수행한다.
	  * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Release();
};

template<typename T>
inline ID3D11Buffer* DXShaderManager::CreateConstantBuffer(const T& constantData)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.ByteWidth = sizeof(T) * 1; // 바이트 용량
	desc.Usage = D3D11_USAGE_DEFAULT; // 버퍼의 할당 장소 내지는 버퍼 용도, D3D11_USAGE_DEFAULT == GPU 메모리에 할당. D3D11_USAGE_DYNAMIC; //
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // Constant 버퍼를 사용하겠다는 플래그
	//desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; // Test
	//desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initialData;
	ZeroMemory(&initialData, sizeof(initialData));
	initialData.pSysMem = &constantData; // 배열이 아니면 시스템 메모리에 들어 갈 수 없음. 그래서 그냥 배열보다 편한 vector 사용.

	//ID3D11Buffer* pConstantBuffer;
	//HRESULT result = m_pd3dDevice->CreateBuffer(
	//	&desc, // 버퍼 할당 
	//	&initialData, // 초기 할당된 버퍼를 체우는 CPU 메모리, NULL로 넣으면 생성만 해 놓는 것.
	//	&pConstantBuffer);

	ID3D11Buffer* pConstantBuffer;
	HRESULT result = m_pd3dDevice->CreateBuffer(
		&desc, // 버퍼 할당 
		&initialData, // 초기 할당된 버퍼를 체우는 CPU 메모리, NULL로 넣으면 생성만 해 놓는 것.
		&pConstantBuffer);

	if (FAILED(result))
	{
		return nullptr;
	}
	else
	{
		BufferList.push_back(pConstantBuffer);
		return pConstantBuffer;
	}
}
