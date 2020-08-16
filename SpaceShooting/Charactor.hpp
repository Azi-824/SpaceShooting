//Charactor.hpp
//敵、味方の基になるクラス

#pragma once

//##################### ヘッダファイル読み込み #####################
#include "Global.hpp"
#include "Image.hpp"
#include "Bullet.hpp"

//##################### マクロ定義 ##################


//##################### クラス定義 ##################
class Charactor
{

protected:

	Image* img;		//画像
	RECT collision;	//当たり判定
	vector<Bullet*> bullet;	//弾

	int Hp;			//HP

public:

	Charactor();	//コンストラクタ
	~Charactor();	//デストラクタ

	virtual void UpDate(Charactor*);	//毎回行う処理

	virtual void Draw();	//描画
	virtual void SetInit();	//初期設定

	RECT GetCol();			//当たり判定取得

};
