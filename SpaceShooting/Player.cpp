//Player.cpp

//########### ヘッダファイル読み込み #############
#include "Player.hpp"

//########### クラス定義 ############

//コンストラクタ
//引数：Image *：キャラクターの画像
Player::Player(Image* img)
{
	this->img = img;
	Animation::CreateList();
	bullet.push_back(new Bullet());
}

//デストラクタ
Player::~Player()
{
	for (auto b : bullet) { delete b; }
	vector<Bullet*> v;
	bullet.swap(v);
}

//毎回行う処理
void Player::UpDate()
{
	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		Shot();	//弾を撃つ
		bullet.push_back(new Bullet());	//弾を生成
		bullet.back()->SetInit(GAME_WIDTH / 2, collision.top);	//初期設定
	}

	//画面外に出た弾を削除
	for (int i = 0; i < bullet.size(); ++i)
	{
		if (!bullet.at(i)->InScreen())
		{
			delete bullet.at(i);	//破棄
			bullet.erase(bullet.begin() + i);
		}
	}
	Draw();
}


//初期設定
void Player::SetInit()
{
	img->SetInit();		//画像初期設定
	
	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_HEIGHT - img->GetHeight();					//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y

	for (auto b : bullet) { b->SetInit(GAME_WIDTH / 2, collision.top); }

}

//描画
void Player::Draw()
{
	img->Draw(collision.left, collision.top);	//描画(キャラ)
	for (auto b : bullet) { b->Draw(); }
}

//弾を撃つ
void Player::Shot()
{
	bullet.back()->SetIsDraw(true);
}