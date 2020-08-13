//Charactor.hpp
//敵、味方の基になるクラス

#pragma once

//##################### ヘッダファイル読み込み #####################
#include "Global.hpp"
#include "Image.hpp"

//##################### マクロ定義 ##################
#define CHAR_IMG_DIR	R"(.\Image\Charactor)"		//キャラの画像ファイルのディレクトリ

#define PLAYER_IMG_NAME	R"(\player.png)"			//プレイヤーの画像ファイルの名前

//##################### 列挙型 ##################
enum CHARA_KIND
{
	CHARA_KIND_PLAYER	//プレイヤー
};

//##################### クラス定義 ##################
class Charactor
{

protected:

	Image* img;		//画像
	RECT collision;	//当たり判定

	int Hp;			//HP

public:

	Charactor();	//コンストラクタ
	~Charactor();	//デストラクタ

	void Draw();	//描画
	virtual void SetInit() = 0;	//初期設定

};
