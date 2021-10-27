#include "lobby.h"

void godot::Lobby::_register_methods()
{
	register_method("_ready", &Lobby::_ready);
	register_method("_refresh_players", &Lobby::_refresh_players);
	register_method("_onButton_pressed", &Lobby::_onButton_pressed);
}

godot::Lobby::Lobby()
{
}

godot::Lobby::~Lobby()
{
}

void godot::Lobby::_init()
{
}

void godot::Lobby::_ready()
{
	//Get the nodes for the player list and start game button
	player_list_node = get_node("/TextureRect/VBoxContainer/ItemList");
	start_game_button_node = get_node("/TextureRect/VBoxContainer/Button");

	//Try and cast nodes to their respective types
	if (player_list_node)
	{
		player_list = godot::Object::cast_to<ItemList>(player_list_node);
	}
	else
	{
		Godot::print("Player List Node is NULL in Lobby");
	}

	if (start_game_button_node)
	{
		start_game_button = godot::Object::cast_to<Button>(start_game_button_node);
		start_game_button->connect("pressed", this, "_onButton_pressed");
	}
	else
	{
		Godot::print("Start game button Node is NULL in Lobby");
	}
}

void godot::Lobby::_refresh_players()
{
	
	if (player_list)
	{
		player_list->clear();
	}
	else
	{
		Godot::print("Player List is NULL in Lobby");
	}

	//if (game_manager)
	//{
	//	for i in (game_manager->player_names)->keys()
	//	{
	//		player_list->add_item((game_manager->player_names)[i], null, false);
	//	}
	//}
	//else
	//{
	//	Godot::print("Game manager is NULL in Lobby")
	//}


}

void godot::Lobby::_onButton_pressed()
{
	/*if (game_manager)
	{
		game_manager->_setup_game_start();
	}
	else
	{
		Godot::print("Game manager is NULL in Lobby")
	}*/
}
