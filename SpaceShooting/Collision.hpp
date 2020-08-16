//Collision.hpp
//当たり判定のクラス(四角形)

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

//################### 列挙型 #################
enum POS_POINT
{
	LEFT_TOP,		//左上
	RIGHT_TOP,		//右上
	RIGHT_BOTTOM,	//右下
	LEFT_BOTTOM		//左下
};

using std::vector;

//################### クラス定義 ####################
class Collision
{
private:

	vector<Coordinate> Pos;	//座標

	int CenterX;			//中央X
	int CenterY;			//中央Y

public:

	Collision(int, int, int, int);	//コンストラクタ
	Collision(	);					//コンストラクタ
	~Collision();					//デストラクタ

	void Set(int, int, int, int);	//設定
	void Draw();					//描画
	void Rota(int);					//回転

};
