#ifndef PLAYER_H
#define PLAYER_H

// All files needed for player class
#include <Godot.hpp>
#include <KinematicBody.hpp>
#include <Input.hpp>
#include <Vector3.hpp>
#include <Animation.hpp>
#include <AnimationPlayer.hpp>
#include <Camera.hpp>
#include <Node.hpp>
#include <Spatial.hpp>
#include <InputEventMouseMotion.hpp>

// Player class defined in the godot namespace
namespace godot {
	// Definition for player class which extends the KinematicBody class
	class Player : public KinematicBody {
		// Macro which identifies the player class and which class it extends to godot
		GODOT_CLASS(Player, KinematicBody)

	private:
		// Constants for player movement
		const int MOVE_SPEED = 12;
		const int JUMP_FORCE = 30;
		const float GRAVITY = 0.98;
		const int MAX_FALL_SPEED = 30;

		// Constants for camera movement
		const float H_LOOK_SENS = 0.01;
		const float V_LOOK_SENS = 0.01;

		// Current vertical velocity of the player
		float vertical_velocity = 0;

		// Pointer to input functionality
		Input* input;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for player class
		Player();

		// Destructor for player class
		~Player();

		// Function that's called when player class is spawned
		void _init();

		// Function that's called every frame
		void _process(float delta);

		// Function used for processing framerate independent functionality
		void _physics_process(float delta);

		// Function used for playing animations
		void _play_anim(String name);

		// Function used for handling camera input
		void _input(Variant event);
	};
}

#endif