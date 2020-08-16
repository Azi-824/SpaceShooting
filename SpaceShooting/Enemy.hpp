//Enemy.hpp
//敵キャラを管理するクラス

#pragma once

//############ ヘッダファイル読み込み ###############
#include "Global.hpp"
#include "Charactor.hpp"
#include "Player.hpp"
#include "Effect.hpp"

//############ マクロ定義 ################

//############ クラス定義 ################
class Enemy : public Charactor	//Charactor継承
{

private:

	Effect* explosion;	//爆発エフェクト
	Music* exp_se;		//爆発音

	bool Hit;		//当たった
	bool IsLoad;	//読み込めた

	bool OnCollision(RECT);	//当たり判定の処理

public:

	Enemy(Image*);			//コンストラクタ
	~Enemy();				//デストラクタ

	void UpDate(Charactor*) override;	//毎回行う処理
	void SetInit() override;			//初期設定
	void Draw() override;			//描画
	bool GetIsLoad();		//読み込めたか取得

};
