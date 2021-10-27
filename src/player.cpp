#include "player.h"

using namespace godot;

void Player::_register_methods() {
	register_method((char*) "_ready", &Player::_ready);
	register_method("_process", &Player::_process);
	register_method("_physics_process", &Player::_physics_process);
	register_method("_play_anim", &Player::_play_anim);
	register_method("_input", &Player::_input);
	register_method("_ready", &Player::_ready);
	register_method("_area_entered_ball", &Player::_area_entered_ball);
	register_method("_set_position", &Player::_set_position, GODOT_METHOD_RPC_MODE_REMOTE);
}

Player::Player() {

}

Player::~Player() {

}

void Player::_init() {
	input = Input::get_singleton();
}

void Player::_process(float delta) {
	//godot::Godot::print(get_translation());
	if (get_translation().y < 0 && 
		can_lose_life && 
		has_life_loss_mechanics && 
		curr_lives > 0)
		lose_life();
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
	if (move_vec != Vector3())
	{
		if (is_network_master())
		{
			Node* camera_node = get_node("CamBase/Camera");
			Camera* camera = godot::Object::cast_to<Camera>(camera_node);
			camera->make_current();
			rpc_unreliable("_set_position", player->get_transform().origin);
		}

		move_and_slide(move_vec, Vector3(0, 1, 0), false, 4, 0.0, true);
	}

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

void Player::_ready() {
	area_node = get_parent()->get_node("WipeoutBall/Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered_ball");
	}

	area_node = get_parent()->get_node("WipeoutBall2/Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered_ball");
	}

	area_node = get_parent()->get_node("WipeoutBall3/Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered_ball");
	}

	area_node = get_parent()->get_node("WipeoutBall4/Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered_ball");
	}

	area_node = get_parent()->get_node("WipeoutBall5/Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered_ball");
	}

	Node* camNode = get_node("CamBase");
	playerNode = camNode->get_parent();

	if (!playerNode)
	{
		Godot::print("PLAYER NODE IS NULL");
	}
	player = godot::Object::cast_to<KinematicBody>(playerNode);
	if (!player)
	{
		Godot::print("PLAYER IS NULL");
	}

	// Set references to life gui.
	// Get GUI heart nodes
	Node* n_heart_1 = get_node("../HealthGui/HBoxContainer/NinePatchRect/TextureRect");
	Node* n_heart_2 = get_node("../HealthGui/HBoxContainer/NinePatchRect2/TextureRect");
	Node* n_heart_3 = get_node("../HealthGui/HBoxContainer/NinePatchRect3/TextureRect");

	// Cast to "Heart" objects
	Heart* heart_1 = cast_to<Heart>(n_heart_1);
	Heart* heart_2 = cast_to<Heart>(n_heart_2);
	Heart* heart_3 = cast_to<Heart>(n_heart_3);

	// Store in array.
	lives[0] = heart_1;
	lives[1] = heart_2;
	lives[2] = heart_3;

	has_life_loss_mechanics = n_heart_1 && n_heart_2 && n_heart_3;
}

void Player::_area_entered_ball() {
	if (can_bounce >= 5 ) {
		Godot::print("Bounce");
		vertical_velocity = JUMP_FORCE * 1.5;
	}

	can_bounce += 1;
}

void Player::_set_position(Vector3 pos)
{
	if (player)
	{
		player->set_translation(pos);
	}
	else
	{
		Godot::print("ERROR");
	}

}

/**
 *  Decrement the player's life by one and change the GUI
 *  accordingly. If player loses all three lives, trigger
 *  game over screen. Respawn player at last known checkpoint.
 **/
void Player::lose_life() {
	//godot::Godot::print("life lost!");
	can_lose_life = 0;
	curr_lives--;
	lives[curr_lives]->lose_life();
	if (curr_lives == 0) {
		for (int i = 0; i < 3; i++)
			lives[i]->reset_life();
		get_tree()->change_scene("res://main_scenes/GameoverScreen.tscn");
	}
}

void Player::set_can_lose_life(int lose_life) {
	can_lose_life = lose_life;
}

/**
 * 	Set the player's current checkpoint position.
 * 
 *  @param pos the position of the new checkpoint at which
 * 			   the player will respawn upon loss of life. 
 **/
void Player::_set_checkpoint(Vector3 pos) {
	curr_checkpoint = pos;
}