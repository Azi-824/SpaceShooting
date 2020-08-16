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
	LeftTop.X = left;		//左上(X)
	LeftTop.Y = top;		//左上(Y)
	RightTop.X = right;		//右上(X)
	RightTop.Y = top;		//右上(Y)
	LeftBottom.X = left;	//左下(X)
	LeftBottom.Y = bottom;	//左下(Y)
	RightBottom.X = right;	//右下(X)
	RightBottom.Y = bottom;	//右下(Y)
}

//コンストラクタ
Collision::Collision()
{
	//初期化
	LeftTop = { 0 };
	RightTop = { 0 };
	LeftBottom = { 0 };
	RightBottom = { 0 };
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
	LeftTop.X = left;		//左上(X)
	LeftTop.Y = top;		//左上(Y)
	RightTop.X = right;		//右上(X)
	RightTop.Y = top;		//右上(Y)
	LeftBottom.X = left;	//左下(X)
	LeftBottom.Y = bottom;	//左下(Y)
	RightBottom.X = right;	//右下(X)
	RightBottom.Y = bottom;	//右下(Y)
}

//描画
void Collision::Draw()
{

	//当たり判定の領域を四角形で描画(後で修正するかも)
	DrawLine(LeftTop.X, LeftTop.Y, RightTop.X, RightTop.Y, COLOR_RED);
	DrawLine(RightTop.X, RightTop.Y, RightBottom.X, RightBottom.Y, COLOR_RED);
	DrawLine(RightBottom.X, RightBottom.Y, LeftBottom.X, LeftBottom.Y, COLOR_RED);
	DrawLine(LeftBottom.X, LeftBottom.Y, LeftTop.X, LeftTop.Y, COLOR_RED);

}