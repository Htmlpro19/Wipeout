#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H

// All files needed for game over screen class
#include <Godot.hpp>
#include <Control.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// game over screen class defined in the godot namespace
namespace godot {
	// Definition for GameoverScreen class which extends the Control class
	class GameoverScreen : public Control {
		// Macro which identifies the game over screen class and which class it extends to godot
		GODOT_CLASS(GameoverScreen, Control)

	private:
		Node* restart_button_node;
		Node* quit_button_node;
		Button* restart_button;
		Button* quit_button;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for game over screen class
		GameoverScreen();

		// Destructor for game over screen class
		~GameoverScreen();

		void _init();

		void _ready();

		void _on_RestartButton_pressed();

		void _on_QuitButton_pressed();
	};
}

#endif