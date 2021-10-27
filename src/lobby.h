#ifndef LOBBY_H
#define LOBBY_H

#include <Godot.hpp>
#include <Control.hpp>
#include <Viewport.hpp>
#include <ItemList.hpp>
#include <Texture.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>
#include "game_manager.h"

// Lobby class defined in the godot namespace
namespace godot {
	// Definition for Lobby class which extends the Control class
	class Lobby : public Control {
		GODOT_CLASS(Lobby, Control)

	private:
		// Pointers for ItemList functionality
		Node* item_list_node;
		ItemList* item_list;

		// Pointers for button start functionality
		Node* start_game_button_node;
		Button* start_game_button;

		// Pointers for game manager functionality
		Node* game_manager_node;
		GameManager* game_manager;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for Lobby class
		Lobby();

		// Destructor for Lobby class
		~Lobby();

		void _init();

		void _ready();

		void _refresh_players();

		void _onButton_pressed();
	};
}

#endif