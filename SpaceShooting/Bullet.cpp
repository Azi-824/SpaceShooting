//Bullet.cpp

//############## ヘッダファイル読み込み ####################
#include "Bullet.hpp"

//############## クラス定義 ################

//コンストラクタ
/*
引数：Animation *：弾のアニメーション
*/
Bullet::Bullet(Animation* anim)
{
	//メンバー初期化
	this->anim = anim;		//弾のアニメーション
	collision = { 0 };		//当たり判定
	Speed = 0;				//速さ
	IsDraw = false;			//最初は描画しない
}

//デストラクタ
Bullet::~Bullet()
{
	delete anim;	//anim破棄
}

//初期設定
void Bullet::SetInit(int x, int y)
{
	Speed = BULLET_SPEED;
	//当たり判定設定
	collision.left = x;
	collision.top = y;
	collision.right = x + anim->GetWidth();
	collision.bottom = y + anim->GetHeight();
	IsDraw = false;	//最初は描画しない
}

//描画するか設定
void Bullet::SetIsDraw(bool draw)
{
	IsDraw = draw;
}

//描画
void Bullet::Draw()
{
	if (IsDraw)	//描画するとき
	{
		anim->Draw(collision.left,collision.top);	//描画
		//弾を移動
		collision.top -= Speed;
		collision.bottom -= Speed;
	}
}
