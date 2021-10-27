#include "multiplayer_screen.h"

using namespace godot;

void MultiplayerScreen::_register_methods() {
	register_method("_ready", &MultiplayerScreen::_ready);
	register_method("_on_HostButton_pressed", &MultiplayerScreen::_on_HostButton_pressed);
	register_method("_on_JoinButton_pressed", &MultiplayerScreen::_on_JoinButton_pressed);
	register_method("_on_BackButton_pressed", &MultiplayerScreen::_on_BackButton_pressed);
}

MultiplayerScreen::MultiplayerScreen() {

}

MultiplayerScreen::~MultiplayerScreen() {

}

void MultiplayerScreen::_init() {

}

void MultiplayerScreen::_ready() {
	host_button_node = get_node("HostButton");
	if (host_button_node) {
		host_button = godot::Object::cast_to<Button>(host_button_node);
		host_button->connect("pressed", this, "_on_HostButton_pressed");
	}

	join_button_node = get_node("JoinButton");
	if (join_button_node) {
		join_button = godot::Object::cast_to<Button>(join_button_node);
		join_button->connect("pressed", this, "_on_JoinButton_pressed");
	}

	back_button_node = get_node("BackButton");
	if (back_button_node) {
		back_button = godot::Object::cast_to<Button>(back_button_node);
		back_button->connect("pressed", this, "_on_BackButton_pressed");
	}
}

void MultiplayerScreen::_on_HostButton_pressed() {
	Godot::print("Host Button pressed");
	get_tree()->change_scene("res://main_scenes/HostNameInputScreen.tscn");
}

void MultiplayerScreen::_on_JoinButton_pressed() {
	Godot::print("Join Button pressed");
	get_tree()->change_scene("res://main_scenes/ClientNameInputScreen.tscn");
}

void MultiplayerScreen::_on_BackButton_pressed() {
	Godot::print("Back Button pressed");
	get_tree()->change_scene("res://main_scenes/TitleScreen.tscn");
}