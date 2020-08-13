//Play.hpp
//プレイ画面の処理

#pragma once

//############### ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Player.hpp"

//############### マクロ定義 #################

//############### クラス定義 #################
class Play : public Scene	//Sceneクラスを継承
{
private:

	vector<Image*> chara_img;	//キャラの画像
	vector<Charactor*> chara;	//キャラ

public:

	Play();		//コンストラクタ
	~Play();	//デストラクタ

	void SetInit() override;	//初期設定
	void PlayScene() override;	//プレイ画面の処理

};
