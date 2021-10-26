#ifndef HOST_INPUT_H
#define HOST_INPUT_H

// All files needed for HostInput class
#include <Godot.hpp>
#include <LineEdit.hpp>
#include <Viewport.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// HostInput class defined in the godot namespace
namespace godot {
	// Definition for HostInput class which extends the LineEdit class
	class HostInput : public LineEdit {
		// Macro which identifies the multiplayer screen class and which class it extends to godot
		GODOT_CLASS(HostInput, LineEdit)
	
	public:
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