//Player.hpp
//プレイヤーを管理するクラス

#pragma once

//############# ヘッダファイル読み込み ###########
#include "Charactor.hpp"

//############# マクロ定義 ############

//############# クラス定義 ############
class Player : public Charactor	//Charactorを継承
{
private:

public:

	Player(Image*);		//コンストラクタ
	~Player();			//デストラクタ

	void SetInit() override;	//初期設定

};
