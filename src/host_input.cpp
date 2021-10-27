#include "host_input.h"

void godot::HostInput::_register_methods()
{
	register_method("_ready", &HostInput::_ready);
	register_method("_onButton_pressed", &HostInput::_onButton_pressed);
}

godot::HostInput::HostInput() {

}

godot::HostInput::~HostInput() {

}

void godot::HostInput::_init() {

}

void godot::HostInput::_ready() {
	// Gets the button node
	button_node = get_parent()->get_node("Button");
	if (button_node) {
		button = godot::Object::cast_to<Button>(button_node);
		button->connect("pressed", this, "_onButton_pressed");
	}

	// Gets the game manager
	game_manager_node = (get_tree()->get_root())->get_node("GameManager");
	if (game_manager_node) {
		game_manager = godot::Object::cast_to<GameManager>(game_manager_node);
	}

	// Highlights text field when scene starts
	grab_focus();
}

void godot::HostInput::_onButton_pressed() {
	game_manager->current_player_name = get_text();

	game_manager->_host_start();

	get_tree()->change_scene("res://main_scenes/Lobby.tscn");
}
