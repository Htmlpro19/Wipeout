#include "water_bottom.h"

using namespace godot;

void WaterBottom::_register_methods() {
	register_method("_ready", &WaterBottom::_ready);
	register_method("_area_entered", &WaterBottom::_area_entered);
	register_method((char*) "respawn", &WaterBottom::respawn);
}

WaterBottom::WaterBottom() {}

WaterBottom::~WaterBottom() {}

void WaterBottom::_init() {}

void WaterBottom::_ready() {
	
	game_manager_node = (get_tree()->get_root())->get_node("GameManager");
	if (game_manager_node) {
		game_manager = godot::Object::cast_to<GameManager>(game_manager_node);
	}

	if (!game_manager)
	{
		Godot::print("GAME MANAGER IS NULL IN WATER BOTTOM");
	}
	
	area_node = get_node("Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered");
	}
}

/**
 *  Callback method when player enters water area.
 **/
void WaterBottom::_area_entered(Node* body) {

	// Respawn Player1 on both single and mutliplayer.
	n_player1 = get_parent()->get_node("Player1");
	if (n_player1) {
		player1_body = godot::Object::cast_to<KinematicBody>(n_player1);
		respawn(player1_body);
		player1 = godot::Object::cast_to<Player>(n_player1);
		if (player1)
			player1->set_can_lose_life(1);
	}


	// For multiplayer -- i.e., if a Player1 exists.
	if (body->get_name() == "Player1")
	{
		n_player1 = get_tree()->get_root()->get_node("Player1");
		if (n_player1) {
			player1_body = godot::Object::cast_to<KinematicBody>(n_player1);
			respawn(player1_body);
		}
	}
	else
	{
		// For multiplayer -- i.e., if a Player2 exists.
		n_player2 = get_tree()->get_root()->get_node("Player2");
		if (n_player2) {
			player2_body = godot::Object::cast_to<KinematicBody>(n_player2);
			respawn(player2_body);
		}
	}

}

/**
 *  Executes respawn mechancis when player falls in water.
 **/
void WaterBottom::respawn(KinematicBody* body) {
	Godot::print("Respawn");
	Basis respawn_basis = Basis(1, 0, 0, 0, 1, 0, 0, 0, 1);
	Vector3 respawn_origin = Vector3(0, 0, 0);
	Transform respawn_transform = Transform(respawn_basis, respawn_origin);

	body->set_global_transform(respawn_transform);
}