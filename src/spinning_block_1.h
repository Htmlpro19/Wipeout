#ifndef SPINNING_BLOCK_1_H
#define SPINNING_BLOCK_1_H

// All files needed for spinning block class
#include <Godot.hpp>
#include <MeshInstance.hpp>

// Spinning block class defined in the godot namespace
namespace godot {
	// Definition for SpinningBlock class which extends the KinematicBody class
	class SpinningBlock1 : public MeshInstance {
		// Macro which identifies the spinning block class and which class it extends to godot
		GODOT_CLASS(SpinningBlock1, MeshInstance)

	private:
		float time_passed = 0;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for spinning block class
		SpinningBlock1();

		// Destructor for spinning block class
		~SpinningBlock1();

		// Function that's called when spinning block class is spawned
		void _init();

		// Function that's called every frame
		void _process(float delta);
	};
}

#endif