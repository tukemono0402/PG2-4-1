#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize() {
	// 初期化時にシーン番号を設定（任意）
	sceneNo = CLEAR;
}

void ClearScene::Update(char* keys, char* preKeys) {
	// スペースキーでタイトルシーンへ遷移
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "Current Scene : Clear");
	Novice::ScreenPrintf(0, 30, "Push Space : Next Scene");
}