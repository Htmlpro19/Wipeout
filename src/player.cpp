#include "player.h"

using namespace godot;

void Player::_register_methods() {
	register_method("_process", &Player::_process);
	register_method("_physics_process", &Player::_physics_process);
	register_method("_play_anim", &Player::_play_anim);
	register_method("_input", &Player::_input);
}

Player::Player() {

}

Player::~Player() {

}

void Player::_init() {
	input = Input::get_singleton();
}

void Player::_process(float delta) {

}

void Player::_physics_process(float delta) {
	// Initializing vector for calculating movement
	Vector3 move_vec;

	// Detects forward movement
	if (input->is_action_pressed("move_forwards")) {
		move_vec += Vector3(0, 0, -1);
	}
	// Detects backward movement
	if (input->is_action_pressed("move_backwards")) {
		move_vec += Vector3(0, 0, 1);
	}
	// Detects right movement
	if (input->is_action_pressed("move_right")) {
		move_vec += Vector3(1, 0, 0);
	}
	// Detects left movement
	if (input->is_action_pressed("move_left")) {
		move_vec += Vector3(-1, 0, 0);
	}

	// Normalize movement vector
	move_vec.normalize();

	// Sets movement speed
	move_vec *= MOVE_SPEED;

	// Rotates the movement vector relative to camera and player rotation
	move_vec = move_vec.rotated(Vector3(0, 1, 0), get_rotation().y);




	// Assigns the vertical velocity from last fram
	move_vec.y = vertical_velocity;

	// Moves the player parallel to the platforms
	move_and_slide(move_vec, Vector3(0, 1, 0));

	// Checks if player is on floor or if just jumped
	bool is_grounded = is_on_floor();
	//bool is_just_jumped = false;

	// Gravity decreases the vertical velocity
	vertical_velocity -= GRAVITY;

	// Checks if player can jump
	if (is_grounded && input->is_action_just_pressed("jump")) {
		//is_just_jumped = true;
		vertical_velocity = JUMP_FORCE;
	}
	
	// Makes sure player is always grounded when on floor
	if (is_grounded && (vertical_velocity <= 0)) {
		vertical_velocity = -0.1;
	}

	// Checks if fall speed is going over the maximum
	if (vertical_velocity < -MAX_FALL_SPEED) {
		vertical_velocity = -MAX_FALL_SPEED;
	}

	// Checks if jump animation should play
	/*
	if (is_just_jumped) {
		_play_anim("jump");
	}
	else if (is_grounded) {
		// Checks if idle animation should play
		if (move_vec.x == 0 && move_vec.z == 0) {
			_play_anim("idle");
		}
		// Checks if walk animation should play
		else {
			_play_anim("walk");
		}
	}
	*/

}

void Player::_play_anim(String name) {
	/*
	Node* node = get_node("../Graphics/AnimationPlayer");
	AnimationPlayer* anim = godot::Object::cast_to<AnimationPlayer>(node);

	if (anim) {
		if (anim->get_current_animation() != name) {
			anim->play(name);
		}
	}
	*/
}

void Player::_input(Variant event) {
	Node* node = get_node("CamBase");
	Spatial* cam_base = godot::Object::cast_to<Spatial>(node);
	InputEventMouseMotion* input = godot::Object::cast_to<InputEventMouseMotion>(event);

	if (input) {
		// Handles verical camera rotation
		cam_base->rotate_x((input->get_relative()).y * -V_LOOK_SENS);
		if ((cam_base->get_rotation_degrees()).x < -60) {
			Vector3 new_rotation = Vector3(-60, (cam_base->get_rotation_degrees()).y, (cam_base->get_rotation_degrees()).z);
			cam_base->set_rotation_degrees(new_rotation);
		}
		else if ((cam_base->get_rotation_degrees()).x > 20) {
			Vector3 new_rotation = Vector3(20, (cam_base->get_rotation_degrees()).y, (cam_base->get_rotation_degrees()).z);
			cam_base->set_rotation_degrees(new_rotation);
		}

		// Handle horizontal camera and player rotation
		this->rotate_y((input->get_relative()).x * -H_LOOK_SENS);

		// Handles weird camera rotation
		Vector3 new_rotation = Vector3((cam_base->get_rotation_degrees()).x, (cam_base->get_rotation_degrees()).y, 0);
		cam_base->set_rotation_degrees(new_rotation);
	}
}