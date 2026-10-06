#include "Battle.h"
#include "Constants.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Battle::Battle()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Battle::Start()
{
    std::cout << "     バトル開始\n";

    ShowCharacterStatus();

    while (player.IsAlive() && enemy.IsAlive())
    {
        ShowStatus();

        PlayerTurn();

        if (!enemy.IsAlive())
        {
            break;
        }

        EnemyTurn();

        if (!player.IsAlive())
        {
            break;
        }
    }

    ShowStatus();
    ShowResult();
}

void Battle::PlayerTurn()
{
    int action;

    std::cout << "\n【プレイヤーのターン】\n";

    while (true)
    {
        std::cout << "1：攻撃\n";
        std::cout << "2：回復\n";
        std::cout << "行動を選択してください：";

        std::cin >> action;

        if (action == Constants::ACTION_ATTACK)
        {
            const int damage = player.Attack(&enemy);

            if (damage > Constants::MIN_HP)
            {
                std::cout << "\nプレイヤーの攻撃！\n";
                std::cout<< "敵に "<< damage<< " ダメージ！\n";
            }
            else
            {
                std::cout<< "\nプレイヤーの攻撃は失敗した！\n";
            }

            break;
        }

        if (action == Constants::ACTION_HEAL)
        {
            const int healValue = player.Heal();

            std::cout<< "\nプレイヤーは "<< healValue<< " HP回復した！\n";

            break;
        }

        std::cout<< "\n正しい数字を入力してください。\n\n";
    }
}

void Battle::EnemyTurn()
{
    std::cout << "\n【敵のターン】\n";

    const int action = GetEnemyAction();

    if (action == Constants::ACTION_ATTACK)
    {
        const int damage = enemy.Attack(&player);

        if (damage > Constants::MIN_HP)
        {
            std::cout << "敵の攻撃！\n";
            std::cout<< "プレイヤーに "<< damage<< " ダメージ！\n";
        }
        else
        {
            std::cout<< "敵の攻撃は失敗した！\n";
        }
    }
    else if (action == Constants::ACTION_HEAL)
    {
        const int healValue = enemy.Heal();

        std::cout<< "敵は "<< healValue<< " HP回復した！\n";
    }
}

void Battle::ShowStatus() const
{
    std::cout<< "プレイヤー HP："<< player.GetHp()<< "\n";

    std::cout<< "敵 HP："<< enemy.GetHp()<< "\n";
}

void Battle::ShowCharacterStatus() const
{
    std::cout << "【プレイヤー能力値】\n";

    std::cout<< "HP："<< player.GetHp()<< "\n";

    std::cout<< "攻撃力："<< player.GetAttackPower()<< "\n";

    std::cout<< "防御力："<< player.GetDefensePower()<< "\n";

    std::cout<< "回避力："<< player.GetEvasionPower()<< "\n\n";

    std::cout << "【敵能力値】\n";

    std::cout<< "HP："<< enemy.GetHp()<< "\n";

    std::cout<< "攻撃力："<< enemy.GetAttackPower()<< "\n";

    std::cout<< "防御力："<< enemy.GetDefensePower()<< "\n";

    std::cout<< "回避力："<< enemy.GetEvasionPower()<< "\n";
}

void Battle::ShowResult() const
{
    std::cout << "     バトル終了\n";

    if (player.IsAlive())
    {
        std::cout << "プレイヤーの勝利！\n";
    }
    else
    {
        std::cout << "敵の勝利！\n";
    }
}

int Battle::GetEnemyAction() const
{
    return std::rand()% (Constants::ENEMY_ACTION_MAX - Constants::ENEMY_ACTION_MIN + Constants::STATUS_MIN) + Constants::ENEMY_ACTION_MIN;
}