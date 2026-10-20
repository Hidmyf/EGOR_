#include "Paladin.h"

Paladin::Paladin() : Warrior(), Wizard() {
    strength = 19;
    intellect = 25;
    health = 25;
    damage = 25;
}
void Paladin::Create() {
    cout << "Вы создали паладина\nЗадайте имя игрока\n";
    cin >> name;
    GetInfo();
    LearnSpell();
    GetWeapon();
}
void Paladin::GetInfo() {
    Warrior::GetInfo();
    cout << "интеллект: " << intellect << endl;
}
void Paladin::Relaculate() {
    Warrior::Relaculate();
    damage += (unsigned int)(Wizard::intellect * 0.5);
}
Paladin::~Paladin() {
    cout << "Отправляется к праотцам" << endl;
}