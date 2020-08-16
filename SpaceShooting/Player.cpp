//Player.cpp

//########### ヘッダファイル読み込み #############
#include "Player.hpp"

//########### クラス定義 ############

//コンストラクタ
//引数：Image *：キャラクターの画像
Player::Player(Image* img)
{
	//メンバー初期化
	collision = { 0 };	//当たり判定
	Hp = 0;				//HP
	rota = 0.0;			//角度
	col = new Collision();	//当たり判定作成

	this->img = img;
	bullet.push_back(new Bullet());
}

//デストラクタ
Player::~Player()
{
	for (auto b : bullet) { delete b; }
	vector<Bullet*> v;
	bullet.swap(v);

	delete img;	//img破棄
}

//毎回行う処理
void Player::UpDate()
{

	//角度計算
	CalcRota();

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
	img->SetPos((GAME_WIDTH / 2) - (img->GetWidth() / 2), GAME_HEIGHT - img->GetHeight());	//描画位置設定

	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_HEIGHT - img->GetHeight();					//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y
	
	col->Set((GAME_WIDTH / 2) - (img->GetWidth() / 2), GAME_HEIGHT - img->GetHeight(), collision.left + img->GetWidth(), collision.top + img->GetHeight());


	for (auto b : bullet) { b->SetInit(GAME_WIDTH / 2, collision.top); }	//弾の初期化

}

//描画
void Player::Draw()
{
	img->DrawRota(rota);	//描画(キャラ)
	//img->Draw(collision.left, collision.top);
	//DrawBox(collision.left, collision.top, collision.right, collision.bottom,COLOR_RED,FALSE);
	col->Draw();
	DrawFormatString(0, 150, COLOR_WHITE, "left:%d\ntop:%d\nright:%d\nbottom:%d", collision.left, collision.top, collision.right, collision.bottom);
	for (auto b : bullet) { b->Draw(); }		//弾描画
}

//弾を撃つ
void Player::Shot()
{
	bullet.back()->SetIsDraw(true);
}

//当たり判定取得
RECT Player::GetCol()
{
	return collision;
}

//弾の当たり判定取得
RECT Player::GetBulletCol(int element)
{
	return bullet.at(element)->GetCol();
}

//現在の弾の数を取得
int Player::GetBulleMax()
{
	return Bullet::GetElementMax();
}

//角度計算
void Player::CalcRota()
{
	int x = 0, y = 0;		//マウス位置取得用
	Mouse::GetPos(&x, &y);	//マウス位置取得

	if (x < GAME_LEFT || x > GAME_WIDTH)	//画面外の場合
		return;			//計算しない

	x -= ROTA_BASE;			//基準値からの距離を測定

	if (rota == (double)x / ROTA_BASE)
		return;

	//角度計算処理
	rota = (double)x / ROTA_BASE;

	int center_x = img->GetCenterX();
	int center_y = img->GetCenterY();

	int left = (collision.left - center_x) * cos(rota) - (collision.top - center_y) * sin(rota) + center_x;
	int top = (collision.left - center_x) * sin(rota) + (collision.top - center_y) * cos(rota) + center_y;
	int right = (collision.right - center_x) * cos(rota) - (collision.bottom - center_y) * sin(rota) + center_x;
	int bottom = (collision.right - center_x) * sin(rota) + (collision.bottom - center_y) * cos(rota) + center_y;

	collision.left = left;
	collision.top = top;
	collision.right = right;
	collision.bottom = bottom;

}