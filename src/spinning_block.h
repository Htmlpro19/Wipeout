#ifndef SPINNING_BLOCK_H
#define SPINNING_BLOCK_H

// All files needed for spinning block class
#include <Godot.hpp>
#include <MeshInstance.hpp>

// Spinning block class defined in the godot namespace
namespace godot {
	// Definition for SpinningBlock class which extends the KinematicBody class
	class SpinningBlock : public MeshInstance {
		// Macro which identifies the spinning block class and which class it extends to godot
		GODOT_CLASS(SpinningBlock, MeshInstance)

	private:
		float time_passed = 0;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for spinning block class
		SpinningBlock();

		// Destructor for spinning block class
		~SpinningBlock();

		// Function that's called when spinning block class is spawned
		void _init();

		// Function that's called every frame
		void _process(float delta);
	};
}

#endif