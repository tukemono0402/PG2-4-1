#include "StageScene.h"
#include <Novice.h>

void StageScene::Initialize() {
	sceneNo = STAGE; // 現在のシーン番号を設定
}

void StageScene::Update(char* keys, char* preKeys) {
	// スペースキーで次のシーンへ
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		sceneNo = CLEAR; // クリアシーンに遷移
	}
}

void StageScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Current Scene : Stage");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
}