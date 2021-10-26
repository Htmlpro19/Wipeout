#ifndef PLAYER_SINGLEPLAYER_H
#define PLAYER_SINGLEPLAYER_H

#include <Animation.hpp>
#include <AnimationPlayer.hpp>
#include <Area.hpp>
#include <Camera.hpp>
#include <Godot.hpp>
#include <Input.hpp>
#include <InputEventMouseMotion.hpp>
#include <KinematicBody.hpp>
#include <Node.hpp>
#include <Spatial.hpp>
#include <Vector3.hpp>

// Player class defined in the godot namespace
namespace godot {
	// Definition for player_singleplayer class which extends the KinematicBody class
	class PlayerSingleplayer : public KinematicBody {
		GODOT_CLASS(PlayerSingleplayer, KinematicBody)

	private:
		// Constants for player_singleplayer movement
		const int MOVE_SPEED = 12;
		const int JUMP_FORCE = 30;
		const float GRAVITY = 0.98;
		const int MAX_FALL_SPEED = 30;

		// Constants for camera movement
		const float H_LOOK_SENS = 0.01;
		const float V_LOOK_SENS = 0.01;

		// Current vertical velocity of the player_singleplayer
		float vertical_velocity = 0;

		// Pointer to input functionality
		Input* input;
		
		Node* area_node;
		Area* area;

		int can_bounce = 0;

		// Player_singleplayers's checkpoint value.
		Vector3 curr_checkpoint;

		//Reference to this player_singleplayer's node
		Node* playerNode;
		KinematicBody* player;

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for player_singleplayer class
		PlayerSingleplayer();

		// Destructor for player_singleplayer class
		~PlayerSingleplayer();

		// Function that's called when player_singleplayer class is spawned
		void _init();

		/*
		// Function that's called every frame
		void _process(float delta);

		// Function used for processing framerate independent functionality
		void _physics_process(float delta);

		// Function used for playing animations
		void _play_anim(String name);

		// Function used for handling camera input
		void _input(Variant event);

		void _ready();

		// Function for bouncing on balls
		void _area_entered_ball();

		void _set_position(Vector3 pos);

		// Set the player's current checkpoint location.
		void _set_checkpoint(Vector3 pos);
		*/
	};
}

#endif