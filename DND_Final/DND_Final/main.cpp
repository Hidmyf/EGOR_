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

enum class Сharacters {
    Warrior = 1,  // Можно явно задать начальное число,
    Wizard, //  будет 2
    Paladin, // будет 3
    NPC
};

enum class Rarity {
    Common,
    Unusual,
    Rare,
    Epic,
    Legendary
};

// Добавим простейшую функцию TakeDamage, чтобы main не ругался
void TakeDamage(NPC* character) {
    if (character) {
        cout << "\nПерсонаж " << character->GetHealth() << " хп проверяет урон..." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Player player;
    cout << "Присядь путник у костра и расскажи, кто ты: " << endl;
    cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;

    int choise = 0;
    cin >> choise;

    Сharacters selectedClass = Сharacters::NPC;
    Сharacters myClass = Сharacters::Wizard;

    switch (choise) {
    case 1:
        selectedClass = Сharacters::Warrior;
        cout << "Воин, сила и защита\n";
        break;
    case 2:
        selectedClass = Сharacters::Wizard;
        cout << "Маг, магия и интеллект\n";
        break;
    case 3:
        selectedClass = Сharacters::Paladin;
        cout << "Паладин, среднее между воином и магом\n";
        break;

        int characterNumber = static_cast<int>(myClass);
        cout << "Числовое значение класса: " << characterNumber << "\n";  // Выведет 11

        cout << "Выбери редкость оружия " << endl;
        cout << "\t1 - обычная\n\t2 - необычная\n\t3 - редкая\n\t4 - эпическая\n\t5 - легендарная" << endl;

    //switch (selectedClass) {
    //case Warrior:
    //    player.Create(make_unique<Warrior>());
    //    break;
    //case Wizard:
    //    player.Create(make_unique<Wizard>());
    //    break;
    //case Paladin:
    //    player.Create(make_unique<Paladin>());
    //    break;
    //default:
    //    cout << "Таких героев еще не было в наших краях.\nПопытай удачу позже\n";
    //    return 0;
    //}

    Rarity selectedClass = Rarity::Common;

    switch (selectedClass) {
    case Rarity::Common:
        std::cout << "Обычное\n";
        break;
    case Rarity::Unusual:
        std::cout << "Необычное\n";
        break;
    case Rarity::Rare:
        std::cout << "Редкое\n";
        break;
    case Rarity::Epic:
        std::cout << "Эпическое\n";
        break;
    case Rarity::Legendary:
        std::cout << "Легендарное\n";
        break;
    }

    //TakeDamage(player.GetCharacter());

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