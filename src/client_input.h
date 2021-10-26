#ifndef CLIENT_INPUT_H
#define CLIENT_INPUT_H

// All files needed for ClientInput class
#include <Godot.hpp>
#include <LineEdit.hpp>
#include <Viewport.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// ClientInput class defined in the godot namespace
namespace godot {
	// Definition for ClientInput class which extends the LineEdit class
	class ClientInput : public LineEdit {
		// Macro which identifies the multiplayer screen class and which class it extends to godot
		GODOT_CLASS(ClientInput, LineEdit)

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for ClientInput class
		ClientInput();

		// Destructor for ClientInput class
		~ClientInput();

		void _init();

		void _ready();

		void _onButton_pressed();
	};
}

#endif