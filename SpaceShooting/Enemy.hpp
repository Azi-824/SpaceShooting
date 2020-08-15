//Enemy.hpp
//敵キャラを管理するクラス

#pragma once

//############ ヘッダファイル読み込み ###############
#include "Global.hpp"
#include "Image.hpp"
#include "Player.hpp"

//############ マクロ定義 ################

//############ クラス定義 ################
class Enemy
{

private:

	Image* img;		//画像
	RECT collision;	//当たり判定

	int Hp;			//HP
	bool Hit;		//当たった

	bool OnCollision(RECT);	//当たり判定の処理

public:

	Enemy(Image*);			//コンストラクタ
	~Enemy();				//デストラクタ

	void UpDate(Player*);	//毎回行う処理
	void SetInit();			//初期設定
	void Draw();			//描画

};
