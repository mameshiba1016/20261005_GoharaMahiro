#pragma once

class Character
{
protected:
    int hp;
    int attackPower;
    int defensePower;
    int evasionPower;

public:
    Character();
    virtual ~Character() = default;

    int GetHp() const;
    int GetAttackPower() const;
    int GetDefensePower() const;
    int GetEvasionPower() const;

    bool IsAlive() const;

    int Attack(Character* target);
    int Heal();

protected:
    int GetRandomValue(int min, int max) const;
};