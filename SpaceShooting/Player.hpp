//Player.hpp
//プレイヤーを管理するクラス

#pragma once

//############# ヘッダファイル読み込み ###########
#include "Global.hpp"
#include "Charactor.hpp"

//############# マクロ定義 ############

//############# クラス定義 ############
class Player : public Charactor	//Charactor継承
{
private:

	//Image* img;		//画像
	//RECT collision;	//当たり判定

	int SpawnX;		//弾発射地点X
	int SpawnY;		//弾発射地点Y
	//int Hp;			//HP

	void Move();	//移動

public:

	Player(Image*);			//コンストラクタ
	~Player();				//デストラクタ

	void UpDate(Charactor*) override;	//毎回行う処理
	void Draw() override;	//描画
	void SetInit() override;//初期設定
	RECT GetBulletCol(int);	//弾の当たり判定取得
	int GetBulleMax();		//現在の玉の数を取得

};
