//Player.hpp
//プレイヤーを管理するクラス

#pragma once

//############# ヘッダファイル読み込み ###########
#include "Charactor.hpp"
#include "Bullet.hpp"

//############# マクロ定義 ############

//############# クラス定義 ############
class Player : public Charactor	//Charactorを継承
{
private:

	Animation* b_anim;	//弾のアニメーション
	Bullet* bullet;		//弾

public:

	Player(Image*);		//コンストラクタ
	~Player();			//デストラクタ

	void UpDate() override;		//毎回行う処理
	void Draw() override;		//描画
	void SetInit() override;	//初期設定
	void Shot();				//弾を打つ

};
