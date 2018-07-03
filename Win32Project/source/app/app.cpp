//=============================================================================
//
// app.cpp
// Author : SHOTA FUKUOKA
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "app.h"
#include "app_renderer.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"

///////////////////////////////////////////////////////////////////////////////
//コンストラクタ
///////////////////////////////////////////////////////////////////////////////
App::App():
	m_pAppRenderer(NULL)
{
	;
}

///////////////////////////////////////////////////////////////////////////////
//デストラクタ
///////////////////////////////////////////////////////////////////////////////
App::~App()
{
	Release();
}

///////////////////////////////////////////////////////////////////////////////
//初期化
///////////////////////////////////////////////////////////////////////////////
HRESULT App::Init(const HWND hWnd, HINSTANCE hInstance)
{
	AppRenderer::CreateInstance();
	m_pAppRenderer = AppRenderer::GetInstance();
	m_pAppRenderer->Init(hWnd);

	ImGui_ImplDX11_Init(hWnd, m_pAppRenderer->GetDevice(), m_pAppRenderer->GetDeviceContex());

	return S_OK;
}

///////////////////////////////////////////////////////////////////////////////
//終了
///////////////////////////////////////////////////////////////////////////////
void App::Release(void)
{
	ImGui_ImplDX11_Shutdown();

	SAFE_RELEASE(m_pAppRenderer);
}

///////////////////////////////////////////////////////////////////////////////
//更新
///////////////////////////////////////////////////////////////////////////////
void App::Update(void)
{
	ImGui_ImplDX11_NewFrame();
}

///////////////////////////////////////////////////////////////////////////////
//描画
///////////////////////////////////////////////////////////////////////////////
void App::Draw(int nCountFPS)
{
	ImGui::Begin("debug");
	{
		static float f = 0.0f;
		ImGui::Text("fps:%d", nCountFPS);
	}
	ImGui::End();

	m_pAppRenderer->Draw(NULL);
}

///////////////////////////////////////////////////////////////////////////////
//シーン入れ替え
///////////////////////////////////////////////////////////////////////////////
void App::SceneChange(void)
{
}
