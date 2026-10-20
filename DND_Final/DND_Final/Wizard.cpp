#include "Wizard.h"

Wizard::Wizard() {
    damage = 27; health = 21; armor = 10;
}
void Wizard::Create() {
    cout << "Вы создали волшебника\nЗадайте имя игрока\n";
    cin >> name;
    GetInfo();
    LearnSpell();
}
void Wizard::GetInfo() {
    NPC::GetInfo();
    cout << "интеллект: " << intellect << endl;
}
void Wizard::LearnSpell() {
    Spell defaultSpell{ "Огненный шар", 15 };
    spells.push_back(defaultSpell);
    cout << name << " выучил заклинание: " << defaultSpell.name << endl;
}
void Wizard::Relaculate() {
    damage += (unsigned int)((1 + lvl * 0.1) + (intellect * 0.5));
    health += (unsigned int)(1 + lvl * 0.1);
    armor += (unsigned int)(1 + lvl * 0.1);
}
Wizard::~Wizard() {
    cout << name << " испускает дух" << endl;
}