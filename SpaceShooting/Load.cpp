//Load.cpp
//ロード画面のクラス

//############## ヘッダファイル読み込み #################
#include "Load.hpp"

//############## クラス定義 ################

//コンストラクタ
Load::Load()
{
	IsLoad = Animation::CreateList();	//アニメーションリスト作成
}

//デストラクタ
Load::~Load(){}

//初期設定
void Load::SetInit()
{

}

//読み込み画面の処理
void Load::PlayScene()
{

	if (IsGameStart)	//ゲームスタートできるなら
	{
		if (Mouse::OnLeftClick())	//左クリックされたら
		{
			NowScene = SCENE_TITLE;	//タイトル画面へ
		}
	}

	if (GetASyncLoadNum() == 0)	//非同期で読み込んでいる処理が終わったら
	{

		SetUseASyncLoadFlag(FALSE);	//同期読み込みに設定

		IsGameStart = true;		//ゲームスタートできる
	}

	if (IsGameStart)	//ゲームスタートできるなら
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, PUSH_TEXT, COLOR_WHITE);	//プッシュ、のテキストを描画
	}
	else		//できないなら
	{
		DrawString(TEST_TEXT_X, TEST_TEXT_Y, LOAD_TEXT, COLOR_WHITE);	//読み込み中のテキストを描画
	}


}
