//=============================================================================
//
// texture_manager.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

//*****************************************************************************
// ヘッダファイル
//*****************************************************************************
#include "texture.h"
#include <list>

//*****************************************************************************
// クラス定義
//*****************************************************************************
class TextureManager
{
	std::list<Texture*>  m_list;
public:

	//テクスチャ追加
	void AddTexture(Texture* tex);

	//テクスチャ削除
	void DeleteTexture(Texture* tex);

	//テクスチャ解放
	void ReleaseAll(void);

	//テクスチャ取得
	Texture *GetTexture(Texture* tex);
};

#endif
