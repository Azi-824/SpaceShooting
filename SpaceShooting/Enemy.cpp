//Enemy.cpp

//########### ヘッダファイル読み込み #############
#include "Enemy.hpp"

//########### クラス定義 ###############

//コンストラクタ
//引数：Image *：キャラクターの画像
Enemy::Enemy(Image* img)
{
	this->img = img;
}

//デストラクタ
Enemy::~Enemy() {}

//毎回行う処理
//void Enemy::UpDate()
//{
//
//}


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
