#include "NPC.h"

void NPC::GetInfo() {
    cout << "имя: " << name << "\nздоровье: " << health << "\nурон: " << damage << "\nуровень: " << lvl << "\nброня: " << armor << endl;
}
void NPC::LvlUp() {
    cout << name << " получил новый уровень" << endl;
    lvl++;
    Relaculate();
}
void NPC::Relaculate() {
    damage += (1 + lvl * 0.1);
    health += (1 + lvl * 0.1);
    armor += (1 + lvl * 0.1);
}