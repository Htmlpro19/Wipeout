#ifndef LOBBY_H
#define LOBBY_H

// All files needed for Lobby class
#include <Godot.hpp>
#include <Control.hpp>
#include <Viewport.hpp>
#include <ItemList.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// Lobby class defined in the godot namespace
namespace godot {
	// Definition for MultiplayerScreen class which extends the Control class
	class Lobby : public Control {
		// Macro which identifies the multiplayer screen class and which class it extends to godot
		GODOT_CLASS(Lobby, Control)

	private:
		Node* player_list_node;
		Node* start_game_button_node;
		ItemList* player_list;
		Button* start_game_button;
	

	public:
		/*	Node* game_manager_node(get_tree()->get_root())->get_node("GameManager");
		GameManager* game_manager = godot::Object::cast_to<GameManager>(game_manager_node);*/

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