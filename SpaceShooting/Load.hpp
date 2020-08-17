//Load.hpp
//読み込み画面のクラス（Sceneクラスから派生）

#pragma once

//################### ヘッダファイル読み込み #################
#include "Scene.hpp"
#include "Animation.hpp"

//################### マクロ定義 ###################
#define LOAD_TEXT	"NowLoading…"		//ロード画面のテキスト
#define PUSH_TEXT	"Click"				//クリックのテキスト

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
