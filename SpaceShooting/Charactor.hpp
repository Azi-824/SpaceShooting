//Charactor.hpp
//敵、味方の基になるクラス

#pragma once

//##################### ヘッダファイル読み込み #####################
#include "Global.hpp"
#include "Image.hpp"

//##################### マクロ定義 ##################
#define CHAR_IMG_DIR	R"(.\Image\Charactor)"		//キャラの画像ファイルのディレクトリ

#define PLAYER_IMG_NAME	R"(\player.png)"			//プレイヤーの画像ファイルの名前
#define ENEMY1_IMG_NAME	R"(\enemy1.png)"			//敵キャラ1の画像ファイルの名前

//##################### 列挙型 ##################
enum CHARA_KIND
{
	CHARA_KIND_PLAYER,	//プレイヤー
	CHARA_KIND_ENEMY1	//敵1
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

	virtual void UpDate();	//毎回行う処理

	virtual void Draw();	//描画
	virtual void SetInit();	//初期設定

};
