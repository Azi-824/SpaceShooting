//End.cpp
//エンド画面の処理

//############# ヘッダファイル読み込み ###############
#include "End.hpp"

//############# クラス定義 ################

//コンストラクタ
End::End()
{

	if (!back->Load(IMG_DIR_BACK, IMG_NAME_RANKING)) { IsLoad = false; }	//背景画像読み込み
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_RANKING)) { IsLoad = false; }	//BGM読み込み

	IsLoad = true;	//読み込み成功

}

//デストラクタ
End::~End()
{

}

//初期設定
void End::SetInit()
{
	back->SetInit();	//背景画像初期設定
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM初期設定
}

//エンド画面の処理
void End::PlayScene()
{

	bgm->Play();	//BGMを流す

	back->Draw(GAME_LEFT, GAME_TOP);//背景描画

	SetFontSize(RESULT_FONT_SIZE);	//フォントサイズ変更
	DrawFormatString(0, 50, COLOR_WHITE, RESULT_TEXT, Enemy::GetDestroyNum());
	SetFontSize(DEFF_FONT_SIZE);	//フォントサイズ変更

	if (Mouse::OnLeftClick())	//左クリックされたら
	{
		bgm->Stop();			//BGMを止める
		NowScene = SCENE_TITLE;	//タイトル画面へ
	}

}