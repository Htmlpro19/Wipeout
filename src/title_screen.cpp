#include "title_screen.h"

using namespace godot;

void TitleScreen::_register_methods() {
	register_method("_ready", &TitleScreen::_ready);
	register_method("_on_SingleplayerButton_pressed", &TitleScreen::_on_SingleplayerButton_pressed);
	register_method("_on_MultiplayerButton_pressed", &TitleScreen::_on_MultiplayerButton_pressed);
}

TitleScreen::TitleScreen() {

}

TitleScreen::~TitleScreen() {

}

void TitleScreen::_init() {

}

void TitleScreen::_ready() {
	singleplayer_button_node = get_node("SingleplayerButton");
	if (singleplayer_button_node) {
		singleplayer_button = godot::Object::cast_to<Button>(singleplayer_button_node);
		singleplayer_button->connect("pressed", this, "_on_SingleplayerButton_pressed");
	}

	multiplayer_button_node = get_node("MultiplayerButton");
	if (multiplayer_button_node) {
		multiplayer_button = godot::Object::cast_to<Button>(multiplayer_button_node);
		multiplayer_button->connect("pressed", this, "_on_MultiplayerButton_pressed");
	}
}

void TitleScreen::_on_SingleplayerButton_pressed() {
	get_tree()->change_scene("res://main_scenes/WorldSingleplayer.tscn");
}

void TitleScreen::_on_MultiplayerButton_pressed() {
	get_tree()->change_scene("res://main_scenes/MultiplayerScreen.tscn");
}