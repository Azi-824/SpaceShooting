//Play.cpp
//プレイ画面の処理

//################# ヘッダファイル読み込み #################
#include "Play.hpp"

//################ クラス定義 ################

//コンストラクタ
Play::Play()
{

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
}

//データ読込
bool Play::DataLoad()
{

	//画像関係
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { return false; }	//背景画像読み込み

	//BGM
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY)) { return false; }	//BGM読み込み

	return true;
}

//プレイ画面の処理
void Play::PlayScene()
{

	bgm->Play();	//BGMを流す

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm->Stop();			//BGMを止める
		NowScene = SCENE_END;	//エンド画面へ
	}

}
