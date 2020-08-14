//Play.cpp
//プレイ画面の処理

//################# ヘッダファイル読み込み #################
#include "Play.hpp"

//################ クラス定義 ################

//コンストラクタ
Play::Play()
{

	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { IsLoad = false; return; }	//背景画像読み込み
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY)) { IsLoad = false; return; }	//BGM読み込み

	//キャラ関係
	//画像
	chara_img.push_back(new Image(CHAR_IMG_DIR, PLAYER_IMG_NAME));	//プレイヤーの画像
	chara_img.push_back(new Image(CHAR_IMG_DIR, ENEMY1_IMG_NAME));	//敵1の画像

	for (auto c : chara_img)
	{
		if (!c->GetIsLoad()) { IsLoad = false; return; }	//読み込み失敗
	}
	//キャラ
	chara.push_back(new Player(chara_img.at(CHARA_KIND_PLAYER)));	//プレイヤー
	chara.push_back(new Enemy(chara_img.at(CHARA_KIND_ENEMY1)));	//敵1

	IsLoad = true;	//読み込み成功

}

//デストラクタ
Play::~Play()
{

}

//初期設定
void Play::SetInit()
{
	back->SetInit();	//画像初期設定
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM初期設定

	//キャラ
	for (auto c : chara) { c->SetInit(); }
}

//プレイ画面の処理
void Play::PlayScene()
{

	bgm->Play();	//BGMを流す

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	for (auto c : chara) 
	{ 
		c->UpDate();//毎回行う処理
		//c->Draw();	//キャラ描画
	}	

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, COLOR_WHITE);	//テスト用のテキストを描画

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		//bgm->Stop();			//BGMを止める
		//NowScene = SCENE_END;	//エンド画面へ
	}

}
