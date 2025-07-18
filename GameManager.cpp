#include "GameManager.h"
#include "ClearScene.h"
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include <Novice.h>

GameManager::GameManager() {
	// シーン配列の初期化
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	// 初期シーンをタイトルに設定
	currentSceneNo_ = TITLE;
	prevSceneNo_ = currentSceneNo_;
}

GameManager::~GameManager() {}

int GameManager::Run() {
	char keys[256] = {0};
	char preKeys[256] = {0};

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		// キー入力を取得
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		// シーン番号の更新
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		// シーンが変わったら初期化
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}

		// 現在のシーンの更新・描画
		sceneArr_[currentSceneNo_]->Update(keys, preKeys);
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		// ESCキーで終了
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	return 0;
}