/******************************************************************************/
/*! @file       Button.cpp
    @brief      ボタンクラス実装ファイル
*******************************************************************************/

#include <DxLib.h>
#include "Button.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]      l    左
    @param[in]      t    上
    @param[in]      r    右
    @param[in]      b    下
*******************************************************************************/
CButton::CButton(MyFloat l, MyFloat t, MyFloat r, MyFloat b)
    : m_Top(t)
    , m_Bottom(b)
    , m_Left(l)
    , m_Right(r)
    , m_bHold(false)
    , m_PrevX(-1)
    , m_PrevY(-1)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CButton::~CButton()
{
}

/******************************************************************************/
/*! このフレーム押しているか
    @return         true 押してる, false 押してない
*******************************************************************************/
MyBool CButton::IsPress() noexcept
{
#if defined PLATFORM_WINDOWS

    bool isMouseLeftPress = ((DxLib::GetMouseInput() & MOUSE_INPUT_LEFT) != 0);
    if (!isMouseLeftPress) { return false; }
    MyInt posX = 0, posY = 0;
    MyS32 result = DxLib::GetMousePoint(&posX, &posY);
    if (result == -1) { return false; }
    m_PrevX = posX; m_PrevY = posY;
    return (m_Left <= posX && m_Top <= posY && m_Right >= posX && m_Bottom >= posY);

#elif defined PLATFORM_LINUX
    MyS32 touchNum = DxLib::GetTouchInputNum();
    if (touchNum <= 0) { return false; }
    MyInt posX = 0, posY = 0;
    MyS32 result = DxLib::GetTouchInput(touchNum - 1, &posX, &posY, nullptr, nullptr);
    if (result == -1) { return false; }
    m_PrevX = posX; m_PrevY = posY;
    return (m_Left <= posX && m_Top <= posY && m_Right >= posX && m_Bottom >= posY);
#endif
}

/******************************************************************************/
/*! ボタンから離れたか
    @return         true 離れた, false 押してないor押してる
*******************************************************************************/
MyBool CButton::IsPull() noexcept
{
    if (IsPress())
    {
        m_bHold = true;
    }
    else if (m_bHold)
    {
        m_bHold = false;
        return (m_Left <= m_PrevX && m_Top <= m_PrevY && m_Right >= m_PrevX && m_Bottom >= m_PrevY);
    }
    return false;
}