//Collision.cpp

//################## ヘッダファイル読み込み ###############
#include "Collision.hpp"

//################## クラス定義 ##################

//コンストラクタ
/*
引数：int：左(X)
引数：int：左(Y)
引数：int：右(X)
引数：int：右(Y)
*/
Collision::Collision(int left, int top, int right, int bottom)
{

	//座標設定
	Coordinate LeftTop = { left,top };		//左上
	Coordinate RightTop = { right,top };	//右上
	Coordinate RightBottom{ right,bottom };	//右下
	Coordinate LeftBottom{ left,bottom };	//左下

	Pos.push_back(LeftTop);		//左上
	Pos.push_back(RightTop);	//右上
	Pos.push_back(RightBottom);	//右下
	Pos.push_back(LeftBottom);	//左下

	CenterX = (left + right) / 2;
	CenterY = (top + bottom) / 2;
}

//コンストラクタ
Collision::Collision()
{
	//初期化
	CenterX = 0;
	CenterY = 0;
}

//デストラクタ
Collision::~Collision(){}

//設定
/*
引数：int：左(X)
引数：int：左(Y)
引数：int：右(X)
引数：int：右(Y)
*/
void Collision::Set(int left, int top, int right, int bottom)
{
	//座標設定
	Coordinate LeftTop = { left,top };		//左上
	Coordinate RightTop = { right,top };	//右上
	Coordinate RightBottom{ right,bottom };	//右下
	Coordinate LeftBottom{ left,bottom };	//左下

	Pos.push_back(LeftTop);		//左上
	Pos.push_back(RightTop);	//右上
	Pos.push_back(RightBottom);	//右下
	Pos.push_back(LeftBottom);	//左下

	CenterX = (left + right) / 2;
	CenterY = (top + bottom) / 2;

}

//描画
void Collision::Draw()
{

	//当たり判定の領域を四角形で描画(後で修正するかも)
	for (int i = 0; i < Pos.size(); ++i)
	{
		if (i == Pos.size() - 1)	//最後の場合
		{
			DrawLine(Pos.at(i).X, Pos.at(i).Y, Pos.front().X, Pos.front().Y, COLOR_RED);
		}
		else //それ以外
		{
			DrawLine(Pos.at(i).X, Pos.at(i).Y, Pos.at(i + 1).X, Pos.at(i + 1).Y, COLOR_RED);
		}
	}

}

//回転
void Collision::Rota(int rota)
{

	double cos_value = cos(rota);	//cos
	double sin_value = sin(rota);	//sin

}