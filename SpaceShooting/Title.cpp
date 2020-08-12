//Title.cpp
//タイトル画面の処理

//############# ヘッダファイル読み込み ##################
#include "Title.hpp"

//############ クラス定義 ################

//コンストラクタ
Title::Title()
{

}

//デストラクタ
Title::~Title()
{

}

//初期設定
void Title::SetInit()
{
	back->SetInit();	//背景画像初期設定
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM初期設定
}

//データ読込
bool Title::DataLoad()
{
	if (!back->Load(IMG_DIR_BACK, IMG_NAME_TITLE)) { return false; }	//背景画像読み込み
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_TITLE)) { return false; }	//BGM読み込み

	return true;
}

//タイトル画面の処理
void Title::PlayScene()
{
	bgm->Play();	//BGMを流す

	back->Draw(GAME_LEFT, GAME_TOP);	//背景描画

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, TITLE_TEXT, GetColor(255, 255, 255));	//テスト用のテキストを描画

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm->Stop();			//BGMを止める
		NowScene = SCENE_PLAY;	//プレイ画面へ
	}

}