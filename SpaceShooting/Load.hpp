//Load.hpp
//読み込み画面のクラス（Sceneクラスから派生）

#pragma once

//################### ヘッダファイル読み込み #################
#include "Scene.hpp"

//################### マクロ定義 ###################

//################### クラス定義 ###################
class Load : public Scene	//Sceneクラスを継承
{
private:

public:

	Load();		//コンストラクタ 
	~Load();	//デストラクタ

	void SetInit() override;	//初期設定
	void PlayScene() override;	//ロード画面の処理

};
