//Player.cpp

//########### ヘッダファイル読み込み #############
#include "Player.hpp"

//########### クラス定義 ############

//コンストラクタ
//引数：Image *：キャラクターの画像
Player::Player(Image* img)
{
	this->img = img;
}

//デストラクタ
Player::~Player(){}

//初期設定
void Player::SetInit()
{
	img->SetInit();		//画像初期設定
	
	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_HEIGHT - img->GetHeight();					//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y

}