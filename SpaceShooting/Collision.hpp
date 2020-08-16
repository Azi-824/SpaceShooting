//Collision.hpp
//当たり判定のクラス

#pragma once

//################### ヘッダファイル読み込み ##################
#include "Global.hpp"

//################### マクロ定義 ####################

//################### 構造体 #######################
struct Coordinate
{
	int X;	//X
	int Y;	//Y
};	//座標

//################### クラス定義 ####################
class Collision
{
private:

	Coordinate LeftTop;		//左上
	Coordinate RightTop;	//右上
	Coordinate LeftBottom;	//左下
	Coordinate RightBottom;	//右下

public:

	Collision(int, int, int, int);	//コンストラクタ
	Collision(	);					//コンストラクタ
	~Collision();					//デストラクタ

	void Set(int, int, int, int);	//設定
	void Draw();					//描画

};
