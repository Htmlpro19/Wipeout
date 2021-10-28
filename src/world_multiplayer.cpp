#include "world_multiplayer.h"

void godot::WorldMultiplayer::_register_methods()
{
	register_method("_ready", &WorldMultiplayer::_ready);
}

godot::WorldMultiplayer::WorldMultiplayer()
{
}

godot::WorldMultiplayer::~WorldMultiplayer()
{
}

void godot::WorldMultiplayer::_init()
{
}

void godot::WorldMultiplayer::_ready()
{
	// Gets the game manager
	game_manager_node = (get_tree()->get_root())->get_node("GameManager");
	if (game_manager_node) {
		game_manager = godot::Object::cast_to<GameManager>(game_manager_node);
	}

	if (game_manager)
	{
		game_manager->set_scene_node(get_parent()->get_node("WorldMultiplayer"));
	}

	player1pos_node = get_node("Player1Start");
	player2pos_node = get_node("Player2Start");

	player1pos = godot::Object::cast_to<Position3D>(player1pos_node);
	player2pos = godot::Object::cast_to<Position3D>(player2pos_node);

	if (!player1pos || !player2pos)
	{
		Godot::print("Player1pos or player2pos is NULL in world_multiplayer");
	}

	ResourceLoader* rloader = ResourceLoader::get_singleton();
	Ref<PackedScene> res = rloader->load("res://sub_scenes/Player.tscn");
	
	KinematicBody* player1 = godot::Object::cast_to<KinematicBody>(res->instance());
	player1->set_name("Player1");
	player1->set_network_master(game_manager->player_ids[0]);
	player1->set_translation(player1pos->get_transform().origin);
	get_tree()->get_root()->add_child(player1);
		
	
	KinematicBody* player2 = godot::Object::cast_to<KinematicBody>(res->instance());
	player2->set_name("Player2");
	player2->set_network_master(game_manager->player_ids[1]);
	player2->set_translation(player2pos->get_transform().origin);
	get_tree()->get_root()->add_child(player2);

}
