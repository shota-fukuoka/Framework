//=============================================================================
//
// texture.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*********************************************************
//インクルード
//*********************************************************
#include "app_renderer.h"
#include <string>

//*********************************************************
//前方宣言
//*********************************************************
class TextureManager;

//*********************************************************
//クラス
//*********************************************************
class Texture
{
public:

	//コンストラクタ
	Texture(const char* name, TextureManager* m_pTextureManager);

	//デストラクタ
	~Texture();

	//テクスチャ読み込み
	void LoadTexture(const char* name);

	//テクスチャ作成
	void CreateTextureResource(void);

	//テクスチャ名前取得
	const char *GetName();

	//テクスチャピクセル取得
	unsigned char *GetPixels();

	//テクスチャ取得
	ID3D11ShaderResourceView *GetTexture(void);

	//終了
	void Release(void);

private:

	ID3D11ShaderResourceView* m_pTexture;

	std::string	m_name;

	unsigned char* m_Pixels;

	int m_Width;

	int m_Height;
};

#endif