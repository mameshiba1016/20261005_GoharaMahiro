#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
    constexpr int MAX_HP = 100;
    constexpr int MIN_HP = 0;

    constexpr int STAT_MIN = 1;
    constexpr int STAT_MAX = 20;

    constexpr int ROLL_MIN = 1;
    constexpr int ROLL_MAX = 12;

    constexpr int DAMAGE_NONE = 0;
}

// 行動は名前で扱う
enum class Action
{
    Attack = 1,
    Heal = 2
};

#endif#pragma once
