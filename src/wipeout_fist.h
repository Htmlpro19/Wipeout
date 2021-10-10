#ifndef WIPEOUT_FIST_H
#define WIPEOUT_FIST_H

// All files needed for world class
#include <Godot.hpp>
#include <Spatial.hpp>

// World class defined in the godot namespace
namespace godot {
	// Definition for World class which extends the Spatial class
	class WipeoutFist : public Spatial {
		// Macro which identifies the world class and which class it extends to godot
		GODOT_CLASS(WipeoutFist, Spatial)

	private:
		Vector3 old_translation;
		Vector3 new_translation;
		float time_left = 1;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for world class
		WipeoutFist();

		// Destructor for world class
		~WipeoutFist();

		// Function that's called when world class is spawned
		void _init();

		// Function that's called every frame
		void _process(float delta);
	};
}

#endif