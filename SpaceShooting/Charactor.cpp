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
