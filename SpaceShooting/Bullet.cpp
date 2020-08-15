//Bullet.cpp

//############## ヘッダファイル読み込み ####################
#include "Bullet.hpp"

//############## クラス定義 ################

int Bullet::ElementCnt = 0;	//要素数

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
	++ElementCnt;			//要素数カウント
}

//コンストラクタ
Bullet::Bullet()
{
	//メンバー初期化
	anim = new Animation(ANIM_BULLET, ANIM_BULLET_SPEED,true);		//弾のアニメーション
	collision = { 0 };		//当たり判定
	Speed = 0;				//速さ
	IsDraw = false;			//最初は描画しない
	++ElementCnt;			//要素数カウント
}

//デストラクタ
Bullet::~Bullet()
{
	delete anim;	//anim破棄
	--ElementCnt;	//カウントダウン
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

//画面内か
bool Bullet::InScreen()
{
	if (collision.top < GAME_TOP ||
		collision.left < GAME_LEFT ||
		collision.right > GAME_WIDTH)
		return false;
	else
		return true;

}

//当たり判定取得
RECT Bullet::GetCol()
{
	return collision;
}

//要素数取得
int Bullet::GetElementMax()
{
	return ElementCnt;
}
