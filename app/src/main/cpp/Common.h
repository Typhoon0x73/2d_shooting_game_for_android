/******************************************************************************/
/*! @file       Common.h
    @brief      ゲームで使用する定義ファイル
*******************************************************************************/

#ifndef COMMON_H
#define COMMON_H

# if defined(_WIN32) // Windows

#define PLATFORM_WINDOWS

# elif defined(__APPLE__) && defined(__MACH__) // macOS

#define PLATFORM_MAC

# elif defined(__linux__) // Linux

#define PLATFORM_LINUX

# endif


/*! LOG　関連 */
#if defined PLATFORM_WINDOWS

#define MyLOGE(...) ((void)0)
#define MyLOGD(...) ((void)0)

#elif defined PLATFORM_LINUX

#include <android/log.h>

#define MyLOGE(...) __android_log_print(ANDROID_LOG_ERROR, "TAG", __VA_ARGS__)
#define MyLOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "TAG", __VA_ARGS__)

#endif

#include <string>

namespace Shooting2D
{

    /*! 各型名を置き換え */
    using MyS8        = char;
    using MyS16       = short;
    using MyS32       = long;
    using MyS64       = long long;

    using LPMyS8      = char*;
    using LPMyS16     = short*;
    using LPMyS32     = long*;
    using LPMyS64     = long long*;

    using LPKMyS8     = const char*;
    using LPKMyS16    = const short*;
    using LPKMyS32    = const long*;
    using LPKMyS64    = const long long*;

    using MyU8        = unsigned char;
    using MyU16       = unsigned short;
    using MyU32       = unsigned long;
    using MyU64       = unsigned long long;

    using LPMyU8      = unsigned char*;
    using LPMyU16     = unsigned short*;
    using LPMyU32     = unsigned long*;
    using LPMyU64     = unsigned long long*;

    using LPKMyU8     = const unsigned char*;
    using LPKMyU16    = const unsigned short*;
    using LPKMyU32    = const unsigned long*;
    using LPKMyU64    = const unsigned long long*;

    using MyInt       = int;
    using MyFloat     = float;
    using MyDouble    = double;
    using LPMyInt     = int*;
    using LPMyFloat   = float*;
    using LPMyDouble  = double*;
    using LPKMyInt    = const int*;
    using LPKMyFloat  = const float*;
    using LPKMyDouble = const double*;

    using MyBool      = bool;
    using LPMyBool    = bool*;
    using LPKMyBool   = const bool*;

    using MyVoid      = void;
    using LPMyVoid    = void*;
    using LPKMyVoid   = const void*;

    #define RKMy(x) const x&

    using RKMyString  = RKMy(std::string);

    constexpr MyS32 k_Success = 1; /*!< 成功 */
    constexpr MyS32 k_failure = 0; /*!< 失敗 */

}

#endif //COMMON_H
