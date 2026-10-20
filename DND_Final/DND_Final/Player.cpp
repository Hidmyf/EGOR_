#include "Player.h"

void Player::Create(unique_ptr<NPC> character) {
    currentCharacter = move(character);
    currentCharacter->Create();
}
NPC* GetCharacter() { return nullptr; } // «аглушка, если метод не используетс€ в main напр€мую
NPC* Player::GetCharacter() { return currentCharacter.get(); }