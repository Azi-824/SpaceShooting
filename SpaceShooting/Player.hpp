//Player.hpp
//プレイヤーを管理するクラス

#pragma once

//############# ヘッダファイル読み込み ###########
#include "Global.hpp"
#include "Image.hpp"
#include "Bullet.hpp"

//############# マクロ定義 ############
#define ROTA_BASE	(GAME_WIDTH / 2)		//回転角度計算の基準値

//############# クラス定義 ############
class Player
{
private:

	Image* img;		//画像
	RECT collision;	//当たり判定
	vector<Bullet*> bullet;	//弾

	int Hp;			//HP
	double rota;	//角度

	void CalcRota();	//角度計算

public:

	Player(Image*);			//コンストラクタ
	~Player();				//デストラクタ

	void UpDate();			//毎回行う処理
	void Draw();			//描画
	void SetInit();			//初期設定
	void Shot();			//弾を打つ
	RECT GetCol();			//当たり判定取得
	RECT GetBulletCol(int);	//弾の当たり判定取得
	int GetBulleMax();		//現在の玉の数を取得

};
