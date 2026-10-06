#include "Character.h"
#include "Constants.h"
#include <cstdlib>

Character::Character()
{
    hp = Constants::MAX_HP;

    attackPower = GetRandomValue(Constants::STATUS_MIN,Constants::STATUS_MAX);

    defensePower = GetRandomValue(Constants::STATUS_MIN,Constants::STATUS_MAX);

    evasionPower = GetRandomValue(Constants::STATUS_MIN,Constants::STATUS_MAX);
}

int Character::GetHp() const
{
    return hp;
}

int Character::GetAttackPower() const
{
    return attackPower;
}

int Character::GetDefensePower() const
{
    return defensePower;
}

int Character::GetEvasionPower() const
{
    return evasionPower;
}

bool Character::IsAlive() const
{
    return hp > Constants::MIN_HP;
}

int Character::Attack(Character* target)
{
    if (target == nullptr)
    {
        return Constants::MIN_HP;
    }

    const int randomValue = GetRandomValue(Constants::ACTION_VALUE_MIN,Constants::ACTION_VALUE_MAX);

    const int attackValue = attackPower + randomValue;

    if (attackValue <= target->evasionPower)
    {
        return Constants::MIN_HP;
    }

    int damage = attackPower + randomValue - target->defensePower;

    if (damage < Constants::MIN_HP)
    {
        damage = Constants::MIN_HP;
    }

    target->hp -= damage;

    if (target->hp < Constants::MIN_HP)
    {
        target->hp = Constants::MIN_HP;
    }

    return damage;
}

int Character::Heal()
{
    const int healValue = GetRandomValue(Constants::ACTION_VALUE_MIN,Constants::ACTION_VALUE_MAX);

    const int beforeHp = hp;

    hp += healValue;

    if (hp > Constants::MAX_HP)
    {
        hp = Constants::MAX_HP;
    }

    return hp - beforeHp;
}

int Character::GetRandomValue(int min, int max) const
{
    return std::rand() % (max - min + Constants::STATUS_MIN) + min;
}