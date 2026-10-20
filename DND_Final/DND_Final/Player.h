#pragma once
#include <memory>
#include "NPC.h"

class Player {
private:
    unique_ptr<NPC> currentCharacter{ nullptr };
public:
    void Create(unique_ptr<NPC> character);
    NPC* GetCharacter();
};