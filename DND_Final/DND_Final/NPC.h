#pragma once
#include <string>
#include <iostream>
using namespace std;

class NPC {
protected:
    string name{ "npc" };
    unsigned int damage{ 2 };
    unsigned int health{ 5 };
    short lvl = 1;
    unsigned int armor = 2;
public:
    bool isEnemy = true;
    unsigned int GetDamage() { return damage; }
    unsigned int GetHealth() { return health; }
    void SetHealth(unsigned int health) { this->health = health; }

    virtual void GetInfo();
    virtual void Create() {}
    void LvlUp();
    virtual void Relaculate();
    virtual ~NPC() = default;
};