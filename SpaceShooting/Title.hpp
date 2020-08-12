//Title.hpp
//タイトル画面の処理

#pragma once

//################### ヘッダファイル読み込み ################
#include "Scene.hpp"

//################### マクロ定義 #####################

//################### クラス定義 #####################
class Title : public Scene	//Sceneクラスを継承
{
private:

public:

	Title();		//コンストラクタ 
	~Title();		//デストラクタ

	void SetInit() override;	//初期設定
	bool DataLoad() override;	//データ読込
	void PlayScene() override;	//タイトル画面の処理

};
