#pragma once
#include "NPC.h"

class Evil : public NPC {
public:
    Evil();
    Evil(string name);
    Evil(string name, unsigned int damage);
    Evil(string name, unsigned int damage, unsigned int health);
    Evil(string name, unsigned int damage, unsigned int health, unsigned int armor);
    ~Evil() override;
};