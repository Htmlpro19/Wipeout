#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

// All files needed for title screen class
#include <Godot.hpp>
#include <Control.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// Title screen class defined in the godot namespace
namespace godot {
	// Definition for TitleScreen class which extends the Control class
	class TitleScreen : public Control {
		// Macro which identifies the title screen class and which class it extends to godot
		GODOT_CLASS(TitleScreen, Control)

	private:
		Node* singleplayer_button_node;
		Node* multiplayer_button_node;
		Button* singleplayer_button;
		Button* multiplayer_button;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for title screen class
		TitleScreen();

		// Destructor for title screen class
		~TitleScreen();

		// Function that's called when title screen class is spawned
		void _init();

		// Function that's called when the title_screen and all of its children are spawned
		void _ready();

		void _on_SingleplayerButton_pressed();

		void _on_MultiplayerButton_pressed();
	};
}

#endif