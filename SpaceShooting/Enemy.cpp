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
	Hit = false;		//当たってない
	IsLoad = false;		//読み込めたか

	exp_se = new Music(MUSIC_DIR_EFFECT, SE_NAME_EFFECT_EXPLOSION);	//爆発効果音読み込み
	IsLoad = exp_se->GetIsLoad();	//読み込めたか
	explosion = new Effect(new Animation(ANIM_EXPLOSION, ANIM_EXPLOSION_SPEED, false), exp_se);	//爆発エフェクト生成

}

//デストラクタ
Enemy::~Enemy() 
{
	delete img;			//img破棄
	delete explosion;	//explosion破棄
}

//毎回行う処理
void Enemy::UpDate(Player* player)
{

	if (img->GetIsDraw())	//表示中なら
	{
		//当たり判定
		if (OnCollision(player->GetCol()))	//プレイヤーと当たっていたら
		{
			Hit = true;	//当たった
		}


		Draw();	//描画

	}

	if (Hit)	//当たったら
	{
		explosion->DrawCenter(collision);	//爆発
		if (explosion->GetIsEffectEnd())	//エフェクト描画終了したら
		{
			explosion->Reset();		//エフェクトリセット
			img->SetIsDraw(false);	//非表示
			Hit = false;
		}
	}

}


//初期設定
void Enemy::SetInit()
{
	img->SetInit();			//画像
	explosion->SetInit();	//エフェクト

	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_TOP;										//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y

}

//描画
void Enemy::Draw()
{
	img->Draw(collision.left, collision.top);	//描画
}

//当たり判定
bool Enemy::OnCollision(RECT col)
{
	if (collision.left < col.right &&
		collision.right > col.left &&
		collision.top < col.bottom &&
		collision.bottom > col.top)
		return true;	//当たってる
	else
		return false;	//当たってない
}

//読み込めたか取得
bool Enemy::GetIsLoad()
{
	return IsLoad;
}
