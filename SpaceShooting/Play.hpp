//Play.hpp
//プレイ画面の処理

#pragma once

//############### ヘッダファイル読み込み ##############
#include "Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

//############### マクロ定義 #################

//##################### 列挙型 ##################
enum CHARA_KIND
{
	CHARA_KIND_PLAYER,	//プレイヤー
	CHARA_KIND_ENEMY1	//敵1
};

//############### クラス定義 #################
class Play : public Scene	//Sceneクラスを継承
{
private:

	vector<Image*> chara_img;	//キャラの画像
	vector<Enemy*> enemy;		//敵
	Player* player;				//プレイヤー

public:

	Play();		//コンストラクタ
	~Play();	//デストラクタ

	void SetInit() override;	//初期設定
	void PlayScene() override;	//プレイ画面の処理

};
