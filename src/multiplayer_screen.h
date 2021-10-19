#ifndef MULTIPLAYER_SCREEN_H
#define MULTIPLAYER_SCREEN_H

// All files needed for multiplayer screen class
#include <Godot.hpp>
#include <Control.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// Multiplayer screen class defined in the godot namespace
namespace godot {
	// Definition for MultiplayerScreen class which extends the Control class
	class MultiplayerScreen : public Control {
		// Macro which identifies the multiplayer screen class and which class it extends to godot
		GODOT_CLASS(MultiplayerScreen, Control)

	private:
		Node* host_button_node;
		Node* join_button_node;
		Node* back_button_node;
		Button* host_button;
		Button* join_button;
		Button* back_button;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for multiplayer screen class
		MultiplayerScreen();

		// Destructor for multiplayer screen class
		~MultiplayerScreen();

		// Function that's called when title screen class is spawned
		void _init();

		// Function that's called when the title_screen and all of its children are spawned
		void _ready();

		void _on_HostButton_pressed();

		void _on_JoinButton_pressed();

		void _on_BackButton_pressed();
	};
}

#endif