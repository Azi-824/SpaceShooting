//Enemy.cpp

//########### ヘッダファイル読み込み #############
#include "Enemy.hpp"

//########### クラス定義 ###############

//コンストラクタ
//引数：Image *：キャラクターの画像
Enemy::Enemy(Image* img)
{
	//メンバー初期化
	collision = { 0 };	//当たり判定
	Hp = 0;				//HP
	this->img = img;	//画像

}

//デストラクタ
Enemy::~Enemy() 
{
	delete img;	//img破棄
}

//毎回行う処理
void Enemy::UpDate()
{
	Draw();	//描画
}


//初期設定
void Enemy::SetInit()
{
	img->SetInit();		//画像初期設定

	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_TOP;										//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y

}

//当たり判定取得
RECT Enemy::GetCol()
{
	return collision;
}

//描画
void Enemy::Draw()
{
	img->Draw(collision.left, collision.top);	//描画
}
