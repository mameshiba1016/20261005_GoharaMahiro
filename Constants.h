#pragma once

namespace Constants
{
    constexpr int MAX_HP = 100;
    constexpr int MIN_HP = 0;

    constexpr int STATUS_MIN = 1;
    constexpr int STATUS_MAX = 20;

    constexpr int ACTION_VALUE_MIN = 1;
    constexpr int ACTION_VALUE_MAX = 12;

    constexpr int ACTION_ATTACK = 1;
    constexpr int ACTION_HEAL = 2;

    constexpr int ENEMY_ACTION_MIN = ACTION_ATTACK;
    constexpr int ENEMY_ACTION_MAX = ACTION_HEAL;
}