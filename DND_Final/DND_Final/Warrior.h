#pragma once
#include <vector>
#include "NPC.h"

struct Weapon {
    string name{ "weapon" };
    unsigned int damage{ 1 };
};

class Warrior : virtual public NPC {
protected:
    short strength{ 21 };
    vector<Weapon> weapons;
public:
    Warrior();
    Warrior(string name, unsigned int lvl);
    void Create() override;
    void GetInfo() override;
    void Relaculate() override;
    void GetWeapon();
    ~Warrior() override;

    // Позволим Паладину видеть силу
    friend class Paladin;
};