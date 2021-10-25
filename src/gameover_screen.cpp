#include "gameover_screen.h"

using namespace godot;

void GameoverScreen::_register_methods() {
	register_method("_ready", &GameoverScreen::_ready);
	register_method("_on_RestartButton_pressed", &GameoverScreen::_on_RestartButton_pressed);
	register_method("_on_QuitButton_pressed", &GameoverScreen::_on_QuitButton_pressed);
}

GameoverScreen::GameoverScreen() {

}

GameoverScreen::~GameoverScreen() {

}

void GameoverScreen::_init() {

}

void GameoverScreen::_ready() {
	restart_button_node = get_node("RestartButton");
	if (restart_button_node) {
		restart_button = godot::Object::cast_to<Button>(restart_button_node);
		restart_button->connect("pressed", this, "_on_RestartButton_pressed");
	}

	quit_button_node = get_node("QuitButton");
	if (quit_button_node) {
		quit_button = godot::Object::cast_to<Button>(quit_button_node);
		quit_button->connect("pressed", this, "_on_QuitButton_pressed");
	}
}

void GameoverScreen::_on_RestartButton_pressed() {
	Godot::print("Restart Button pressed");
	get_tree()->change_scene("res://main_scenes/MultiplayerScreen.tscn");
}

void GameoverScreen::_on_QuitButton_pressed() {
	Godot::print("Quit Button pressed");
	get_tree()->quit();
}
