#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H

// All files needed for multiplayer screen class
#include <Godot.hpp>
#include <Control.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// Multiplayer screen class defined in the godot namespace
namespace godot {
	// Definition for MultiplayerScreen class which extends the Control class
	class GameoverScreen : public Control {
		// Macro which identifies the multiplayer screen class and which class it extends to godot
		GODOT_CLASS(GameoverScreen, Control)

	private:
		Node* restart_button_node;
		Node* quit_button_node;
		Button* restart_button;
		Button* quit_button;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for multiplayer screen class
		GameoverScreen();

		// Destructor for multiplayer screen class
		~GameoverScreen();

		// Function that's called when title screen class is spawned
		void _init();

		// Function that's called when the title_screen and all of its children are spawned
		void _ready();

		void _on_RestartButton_pressed();

		void _on_QuitButton_pressed();
	};
}

#endif