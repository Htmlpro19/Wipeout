#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// All files needed for GameManager screen class
#include <Godot.hpp>
#include <Control.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// GameManager  class defined in the godot namespace
namespace godot {
	// Definition for GameManager class which extends the Control class
	class GameManager : public Node {
		// Macro which identifies the GameManager  class and which class it extends to godot
		GODOT_CLASS(GameManager, Node)

	private:
		

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for GameManager class
		GameManager();

		// Destructor for GameManager class
		~GameManager();

		void _init();

		void _ready();

	};
}

#endif