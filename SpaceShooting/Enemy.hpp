//Enemy.hpp
//敵キャラを管理するクラス

#pragma once

//############ ヘッダファイル読み込み ###############
#include "Charactor.hpp"

//############ マクロ定義 ################

//############ クラス定義 ################
class Enemy : public Charactor	//Charactorクラス継承
{

private:

public:

	Enemy(Image*);		//コンストラクタ
	~Enemy();			//デストラクタ

	void SetInit() override;	//初期設定
	void Shot() override;		//弾を撃つ	

};
