#ifndef TROPHY_H
#define TROPHY_H

// All files needed for player class
#include <Godot.hpp>
#include <AudioStreamPlayer.hpp>
#include <Area.hpp>
#include <Vector3.hpp>
#include <Node.hpp>
#include <Spatial.hpp>

// Player class defined in the godot namespace
namespace godot {
	// Definition for player class which extends the KinematicBody class
	class Trophy : public Spatial {
		// Macro which identifies the player class and which class it extends to godot
		GODOT_CLASS(Trophy, Spatial)
	private:
		int start;
		Node trophyNode;
		Node* audioNode;
		Node* areaNode;
		Area* area;
		AudioStreamPlayer* audioPlayer;
		Spatial* trophy;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		void _init();

		void _ready();

		void _area_entered();
		
		// Constructor for Trophy class
		Trophy();

		// Destructor for Trophy class
		~Trophy();
		
		// Function that's called every frame
		void _process(float delta);
	};
}

#endif