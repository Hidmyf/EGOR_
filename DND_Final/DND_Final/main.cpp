#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <windows.h>

#include "NPC.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"
#include "Player.h"
#include "Evil.h"

using namespace std;

// Добавим простейшую функцию TakeDamage, чтобы main не ругался
void TakeDamage(NPC* character) {
    if (character) {
        cout << "\nПерсонаж " << character->GetHealth() << " хп проверяет урон..." << endl;
    }
}

int main() {
    // Надежная русификация консоли Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Player player;
    cout << "Присядь путник у костра и расскажи, кто ты: " << endl;
    cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;

    short choise = 0;
    cin >> choise;

    switch (choise) {
    case 1:
        player.Create(make_unique<Warrior>());
        break;
    case 2:
        player.Create(make_unique<Wizard>());
        break;
    case 3:
        player.Create(make_unique<Paladin>());
        break;
    default:
        cout << "Таких героев еще не было в наших краях.\nПопытай удачу позже\n";
        return 0;
    }

    TakeDamage(player.GetCharacter());

    cout << "\n--- Проверка кастомных объектов ---\n";
    Warrior* warrior = new Warrior("друг воина", 5);
    warrior->GetInfo();
    cout << "Метод публичный, вот значение здоровья - " << warrior->GetHealth() << endl;
    delete warrior;
    warrior = nullptr;

    // Раскомментированное задание 3 со зловещими вектором
    vector<Evil*> evils;
    evils.push_back(new Evil());
    evils.push_back(new Evil("Кабанчик"));
    evils.push_back(new Evil("Гнолл", 12));
    evils.push_back(new Evil("Гнолл Дробитель", 15, 20));
    evils.push_back(new Evil("Дракон", 50, 100, 200));

    cout << "\n--- Появление злодеев в игре ---\n";
    for (size_t i = 0; i < evils.size(); i++) {
        evils[i]->GetInfo();
        cout << "---------------------\n";
    }

    cout << "\n--- Уничтожение злодеев ---\n";
    for (size_t i = 0; i < evils.size(); i++) {
        delete evils[i];
    }
    evils.clear();

    system("pause"); // Чтобы консоль не закрывалась сразу
    return 0;
}