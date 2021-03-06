#ifndef HOST_INPUT_H
#define HOST_INPUT_H

#include <Godot.hpp>
#include <LineEdit.hpp>
#include <Viewport.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>
#include "game_manager.h"

// HostInput class defined in the godot namespace
namespace godot {
	// Definition for HostInput class which extends the LineEdit class
	class HostInput : public LineEdit {
		GODOT_CLASS(HostInput, LineEdit)
	private:
		// Pointers for GameManager functionality
		Node* game_manager_node;
		GameManager* game_manager;

		// Pointers for Button functionality
		Node* button_node;
		Button* button;
	
	public:
		
		/*	Node* game_manager_node(get_tree()->get_root())->get_node("GameManager");
		GameManager* game_manager = godot::Object::cast_to<GameManager>(game_manager_node);*/

		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for HostInput class
		HostInput();

		// Destructor for HostInput class
		~HostInput();

		void _init();

		void _ready();

		void _onButton_pressed();
	};
}

#endif