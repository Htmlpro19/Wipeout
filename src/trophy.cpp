#include "trophy.h"
#include <SceneTree.hpp>

using namespace godot;

void Trophy::_register_methods() {
	register_method("_area_entered", &Trophy::_area_entered);
	register_method("_ready", &Trophy::_ready);
}

void Trophy::_init() {
	start = 0;
	//trophyNode = get_node("Trophy");

   // trophy = godot::Object::cast_to<Spatial>(trophyNode);
}

Trophy::Trophy() {

}

Trophy::~Trophy() {

}

void Trophy::_ready()
{
	audioNode = get_node("VictorySoundPlayer");
	areaNode = get_node("Area");
	area = godot::Object::cast_to<Area>(areaNode);
	audioPlayer = godot::Object::cast_to<AudioStreamPlayer>(audioNode);
	area->connect("body_entered", this, "_area_entered");
}

void Trophy::_area_entered() {

	Godot::print("CollisionDetected");

	if (start == 1)
	{
		if (audioPlayer)
		{
			audioPlayer->play();
		}

		get_tree()->change_scene("res://main_scenes/GameoverScreen.tscn");
	}

	start += 1;
}
