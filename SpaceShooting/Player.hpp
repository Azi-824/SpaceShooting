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


	int SpawnX;		//弾発射地点X
	int SpawnY;		//弾発射地点Y

	void Move();	//移動

public:

	Player(Image*);			//コンストラクタ
	~Player();				//デストラクタ

	void UpDate(Charactor*) override;	//毎回行う処理
	void Draw() override;	//描画
	void SetInit() override;//初期設定

};
