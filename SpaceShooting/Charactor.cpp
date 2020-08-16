//Charactor.cpp

//############ ヘッダファイル読み込み ###############
#include "Charactor.hpp"

//############ クラス定義 ############

//コンストラクタ
Charactor::Charactor()
{
	//メンバー初期化
	img = new Image();	//インスタンス生成
	collision = { 0 };	//当たり判定
	Hp = 0;				//HP
}

//デストラクタ
Charactor::~Charactor()
{
	delete img;	//img破棄
}

//毎回行う処理
void Charactor::UpDate(Charactor* chara)
{
	Draw();
}

//初期設定
void Charactor::SetInit()
{
	img->SetInit();		//画像初期設定

	//当たり判定設定
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//左上X
	collision.top = GAME_HEIGHT - img->GetHeight();					//左上Y
	collision.right = collision.left + img->GetWidth();				//右下X
	collision.bottom = collision.top + img->GetHeight();			//右下Y

}

//描画
void Charactor::Draw()
{
	img->Draw(collision.left, collision.top);	//描画
}

//当たり判定取得
RECT Charactor::GetCol()
{
	return collision;
}

