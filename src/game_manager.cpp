#include "game_manager.h

void GameManager::_register_methods() {
	register_method("_ready", &GameoverScreen::_ready);
}

GameManager::GameManager() {

}

~GameManager::GameManager() {

}

void GameManager::_ready() {
	
}