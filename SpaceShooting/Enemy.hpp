//Enemy.hpp
//敵キャラを管理するクラス

#pragma once

//############ ヘッダファイル読み込み ###############
#include "Global.hpp"
#include "Image.hpp"
#include "Player.hpp"
#include "Effect.hpp"

//############ マクロ定義 ################
#define ENEMY_SPD	3	//敵の移動速度

//############ クラス定義 ################
class Enemy
{

private:

	Effect* explosion;	//爆発エフェクト
	Music* exp_se;		//爆発音
	Image* img;		//画像
	RECT collision;	//当たり判定

	int Hp;			//HP
	int Speed;		//速さ

	bool Hit;		//当たった
	bool IsLoad;	//読み込めた
	bool IsMove;	//移動しているか

	bool OnCollision(RECT);	//当たり判定の処理

public:

	Enemy(Image*);			//コンストラクタ
	~Enemy();				//デストラクタ

	void UpDate(Player*);	//毎回行う処理
	void SetInit();			//初期設定
	void Draw();			//描画
	bool GetIsLoad();		//読み込めたか取得
	void Move();			//移動

};
