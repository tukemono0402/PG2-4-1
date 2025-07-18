#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Initialize() {
	// 初期化時にシーン番号を設定（オプション）
	sceneNo = TITLE;
}

void TitleScene::Update(char* keys, char* preKeys) {
	// スペースキーでステージシーンに遷移
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Current Scene : Title");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
}