#pragma once
#include <vector>
#include "NPC.h"

struct Spell {
    string name{ "spell" };
    unsigned int damage{ 1 };
};

class Wizard : virtual public NPC {
protected:
    short intellect{ 29 };
    vector<Spell> spells;
public:
    Wizard();
    void Create() override;
    void GetInfo() override;
    void Relaculate() override;
    void LearnSpell();
    ~Wizard() override;

    // Позволим Паладину видеть интеллект
    friend class Paladin;
};