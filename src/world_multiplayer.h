#ifndef WORLD_MULTIPLAYER_H
#define WORLD_MULTIPLAYER_H

// All files needed for WorldMultiplayer class
#include <Godot.hpp>
#include <Spatial.hpp>
#include <Viewport.hpp>
#include <Node.hpp>
#include <Button.hpp>
#include <SceneTree.hpp>

// WorldMultiplayer class defined in the godot namespace
namespace godot {
	// Definition for WorldMultiplayer class which extends the Spatial class
	class WorldMultiplayer : public Spatial {
		// Macro which identifies the multiplayer screen class and which class it extends to godot
		GODOT_CLASS(WorldMultiplayer, Spatial)

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for WorldMultiplayer class
		WorldMultiplayer();

		// Destructor for WorldMultiplayer class
		~WorldMultiplayer();

		void _init();

		void _ready();

	};
}

#endif