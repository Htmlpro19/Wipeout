#include "water_bottom.h"

using namespace godot;

void WaterBottom::_register_methods() {
	register_method("_ready", &WaterBottom::_ready);
	register_method("_area_entered", &WaterBottom::_area_entered);
}

WaterBottom::WaterBottom() {

}

WaterBottom::~WaterBottom() {

}

void WaterBottom::_init() {

}

void WaterBottom::_ready() {
	area_node = get_node("Area");
	if (area_node) {
		area = godot::Object::cast_to<Area>(area_node);
		area->connect("body_entered", this, "_area_entered");
	}

	/*
	player_node = get_parent()->get_node("Player");
	if (player_node) {
		player = godot::Object::cast_to<KinematicBody>(player_node);
	}
	*/
}

void WaterBottom::_area_entered() {
	Godot::print("Respawn");
	Basis respawn_basis = Basis(1, 0, 0, 0, 1, 0, 0, 0, 1);
	Vector3 respawn_origin = Vector3(0, 0, 0);
	Transform respawn_transform = Transform(respawn_basis, respawn_origin);

	//player->set_global_transform(respawn_transform);
}