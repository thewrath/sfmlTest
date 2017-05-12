#include "gameManager.hpp"

int main()
{
    GameManager& gameManager = GameManager::getInstance();
    gameManager.start();
    return 0;
}