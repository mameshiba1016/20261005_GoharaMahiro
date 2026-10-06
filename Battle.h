#pragma once

#include "Player.h"
#include "Enemy.h"

class Battle
{
private:
    Player player;
    Enemy enemy;

public:
    Battle();

    void Start();

private:
    void PlayerTurn();
    void EnemyTurn();

    void ShowStatus() const;
    void ShowCharacterStatus() const;
    void ShowResult() const;

    int GetEnemyAction() const;
};