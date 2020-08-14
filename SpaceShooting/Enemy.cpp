//Enemy.cpp

//########### ヘッダファイル読み込み #############
#include "Enemy.hpp"

//########### クラス定義 ###############

//コンストラクタ
//引数：Image *：キャラクターの画像
Enemy::Enemy(Image* img)
{
	this->img = img;

	//弾
	b_anim = new Animation(ANIM_DIR, ANIM_NAME_E_BULLET, ANIM_BULLET_ALL_CNT, ANIM_BULLET_YOKO_CNT, ANIM_BULLET_TATE_CNT,
		ANIM_BULLET_WIDTH, ANIM_BULLET_HEIGHT, ANIM_BULLET_SPEED, true);	//弾アニメーション
	bullet = new Bullet(b_anim);	//弾生成

}

//デストラクタ
Enemy::~Enemy() {}

//初期設定
void Enemy::SetInit()
{
	img->SetInit();		//画像初期設定

	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_TOP + img->GetHeight();					//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y

	bullet->SetInit(GAME_WIDTH / 2, collision.top);	//弾初期設定

}

//描画
void Enemy::Draw()
{
	img->Draw(collision.left, collision.top);	//描画(キャラ)
	bullet->Draw();								//描画(弾)
}

//弾を撃つ
void Enemy::Shot()
{
	bullet->SetIsDraw(true);	//弾の描画をオンに
}