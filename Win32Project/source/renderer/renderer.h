//=============================================================================
//
// rendere.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _RENDERER_H_
#define _RENDERER_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "app_renderer.h"

//*****************************************************************************
// クラス定義
//*****************************************************************************
class Renderer
{
public:
	//コンストラクタ
	Renderer();

	//デストラクタ
	virtual ~Renderer();

	//終了
	void Release(void);

	//描画
	virtual void Draw(void) = 0;

protected:
	//定数バッファ設定
	void ConfigConstantBuffer(UINT ByteWidth);

	//サンプラーステート設定
	void ConfigSamplerState(void);

	//シャドウサンプラーステート設定
	void ConfigShadowSamplerState(void);

	//ブレンドステート設定
	void ConfigBlendState(BOOL bBlend);

	ID3D11BlendState*					m_pBlendState;

	ID3D11SamplerState*					m_pSampleLinear;

	ID3D11SamplerState*					m_pShadowSampleLinear;

	ID3D11ShaderResourceView*			m_pTexture;

	ID3D11Buffer*						m_pVertexBuffer;

	ID3D11Buffer*						m_pConstantBuffer;

	ID3D11Buffer*						m_pIndexBuffer;
};

#endif