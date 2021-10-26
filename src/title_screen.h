#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <Button.hpp>
#include <Control.hpp>
#include <Godot.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>

// Title screen class defined in the godot namespace
namespace godot {
	// Definition for TitleScreen class which extends the Control class
	class TitleScreen : public Control {
		GODOT_CLASS(TitleScreen, Control)

	private:
		// Pointers for singleplayer button functionality
		Node* singleplayer_button_node;
		Button* singleplayer_button;

		// Pointers for multiplayer button functionality
		Node* multiplayer_button_node;
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

		// Function that's called when the singleplayer button is pressed
		void _on_SingleplayerButton_pressed();

		// Function that's called when the multiplayer button is pressed
		void _on_MultiplayerButton_pressed();
	};
}

#endif