/******************************************************************************/
/*! @file       main.cpp
    @brief      エントリポイント
*******************************************************************************/
#include <DxLib.h>
#include "GameApplication.h"
#include "GameDefine.h"

using namespace Shooting2D;

/******************************************************************************/
/*! @brief android始まりの関数
    @return         成功 0, 失敗 -1
******************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    // WINDOWMODE
    DxLib::ChangeWindowMode(TRUE);

    // 画面サイズの設定
    DxLib::SetGraphMode(k_SceneWidth, k_SceneHeight, k_ColorBitNum);

    // ＤＸライブラリ初期化処理
    if (DxLib::DxLib_Init() == -1)
    {
        // エラーが起きたら直ちに終了
        MyLOGE("lib init error : %ld\n", (MyS32)-1);
        return -1;
    }

    // リソースフォルダの指定
    SetCurrentDirectory("../../app/src/main/assets");

    // 描画先を裏画面にする(ダブルバッファリング)
    DxLib::SetDrawScreen(DX_SCREEN_BACK);

    // ゲームアプリケーションの作成
    CGameApplication gameApplication;

    // ゲームの初期化
    MyS32 result = gameApplication.Initialize();
    if (result != k_Success)
    {
        MyLOGE("init error : %ld\n", result);
        return -1;
    }

    // ゲームループ
    while (DxLib::ProcessMessage() == 0)
    {
        // ゲームの更新
        result = gameApplication.Update();
        if (result != k_Success)
        {
            MyLOGE("update error : %ld\n", result);
            break;
        }

        // 画面に描かれているものを一回全部消す
        DxLib::ClearDrawScreen();
        // ゲームの描画
        result = gameApplication.Draw();
        if (result != k_Success)
        {
            MyLOGE("draw error : %ld\n", result);
            break;
        }
        // 裏画面の内容を表画面に反映させる
        DxLib::ScreenFlip();
    }

    // ゲームの解放
    result = gameApplication.Release();
    if (result != k_Success)
    {
        MyLOGE("release error : %ld\n", result);
    }

    // ＤＸライブラリ使用の終了処理
    DxLib::DxLib_End();

    // ソフトの終了
    return 0;
}
