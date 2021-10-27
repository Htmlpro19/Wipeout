#include "lobby.h"

void godot::Lobby::_register_methods() {
	register_method("_ready", &Lobby::_ready);
	register_method("_refresh_players", &Lobby::_refresh_players);
	register_method("_onButton_pressed", &Lobby::_onButton_pressed);
}

godot::Lobby::Lobby() {

}

godot::Lobby::~Lobby() {

}

void godot::Lobby::_init() {

}

void godot::Lobby::_ready() {
	// Get startgame button node
	start_game_button_node = get_node("TextureRect/VBoxContainer/Button");
	if (start_game_button_node) {
		start_game_button = godot::Object::cast_to<Button>(start_game_button_node);
		start_game_button->connect("pressed", this, "_onButton_pressed");
	}

	// Gets the game manager
	game_manager_node = (get_tree()->get_root())->get_node("GameManager");
	if (game_manager_node) {
		game_manager = godot::Object::cast_to<GameManager>(game_manager_node);
	}

	// Makes the start game button only visible to the host
	if ((game_manager->local_player_id) != 1) {
		start_game_button->set_visible(false);
	}

	// Refreshes the player list
	_refresh_players();
}

void godot::Lobby::_refresh_players() {
	// Get item list node
	item_list_node = get_node("TextureRect/VBoxContainer/ItemList");
	if (item_list_node) {
		item_list = godot::Object::cast_to<ItemList>(item_list_node);
		item_list->set_item_text(0, (game_manager->player_names)[0]);
		item_list->set_item_text(1, (game_manager->player_names)[1]);
	}
	else {
		Godot::print("Can't find list");
	}
}

void godot::Lobby::_onButton_pressed() {
	// Sets up the initiation of the game for all players
	game_manager->_setup_game_start();
}
