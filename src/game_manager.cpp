#include "game_manager.h"

using namespace godot;

void GameManager::_register_methods() {
	register_method("_host_start", &GameManager::_host_start);
	register_method("_player_connected", &GameManager::_player_connected);
	register_method("_player_disconnected", &GameManager::_player_disconnected);
	register_method("_send_player_info", &GameManager::_send_player_info, GODOT_METHOD_RPC_MODE_REMOTE);
	register_method("_client_start", &GameManager::_client_start);
	register_method("_connected_fail", &GameManager::_connected_fail);
	register_method("_server_disconnected", &GameManager::_server_disconnected);
	register_method("_connected_ok", &GameManager::_connected_ok);
	register_method("_update_player_names", &GameManager::_update_player_names, GODOT_METHOD_RPC_MODE_SYNC);
	register_method("_update_waiting_room", &GameManager::_update_waiting_room, GODOT_METHOD_RPC_MODE_SYNC);
	register_method("_setup_game_start", &GameManager::_setup_game_start);
	register_method("_game_start", &GameManager::_game_start, GODOT_METHOD_RPC_MODE_SYNC);
}

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::_init() {

}

void GameManager::_host_start() {
	// Creates and sets the server
	network = NetworkedMultiplayerENet::_new();
	network->create_server(port, max_players);
	get_tree()->set_network_peer(network);

	// Connects network signals to defined functions
	network->connect("peer_connected", this, "_player_connected");
	network->connect("peer_disconnected", this, "_player_disconnected");

	// Stores clients name with network ID in the dictionary
	local_player_id = get_tree()->get_network_unique_id();
	player_names[0] = current_player_name;

	//TEST Print statement
	Godot::print("Server started!");
}

void GameManager::_player_connected(int player_id) {
	Godot::print("Player connected!");
}

void GameManager::_player_disconnected(int player_id) {
	Godot::print("Player disconnected!");
	Node* player2 = get_tree()->get_root()->get_node("Player2");
	if (player2)
	{
		get_tree()->get_root()->remove_child(player2);
	}
	else
	{
		Godot::print("Player2 node is null in game manager");
	}
	
}

void GameManager::_send_player_info(int client_id, String client_name) {
	player_names[1] = client_name;
	rpc("_update_player_names", player_names[0], player_names[1]);
	rpc("_update_waiting_room");
}

void GameManager::_client_start() {
	// Creates and sets the client
	network = NetworkedMultiplayerENet::_new();
	network->create_client("127.0.0.1", port);
	get_tree()->set_network_peer(network);
	player_ids[1] = get_tree()->get_network_unique_id();

	// Connects network signals to defined functions
	get_tree()->connect("connection_failed", this, "_connected_fail");
	get_tree()->connect("server_disconnected", this, "_server_disconnected");
	get_tree()->connect("connected_to_server", this, "_connected_ok");

	//TEST Print statement
	Godot::print("...Attempting to join server...");
}

void GameManager::_connected_fail() {
	Godot::print("Failed to connect!");
}

void GameManager::_server_disconnected() {
	Godot::print("Server disconnected!");
	get_tree()->change_scene("res://main_scenes/TitleScreen.tscn");
	
}

void GameManager::_connected_ok() {
	// Stores clients name with network ID in the dictionary
	local_player_id = get_tree()->get_network_unique_id();

	// Sends local_player_id and current_player_name to the host
	rpc_id(1, "_send_player_info", local_player_id, current_player_name);

	//TEST Print statement
	Godot::print("Successfully connected to server");
}

void GameManager::_update_player_names(String new_player_name1, String new_player_name2) {
	player_names[0] = new_player_name1;
	player_names[1] = new_player_name2;
}

void GameManager::_update_waiting_room() {
	get_tree()->change_scene("res://main_scenes/Lobby.tscn");
}

void GameManager::_setup_game_start() {
	rpc("_game_start");
}

void GameManager::_game_start() {
	get_tree()->change_scene("res://main_scenes/WorldMultiplayer.tscn");
}

//Node* GameManager::get_scene_node()
//{
//	Node* scene = get_tree()->get_root()->get_node("WorldMultiplayer");
//
//	if (!scene)
//	{
//		Godot::print("Scene is NULL in game manager");
//	}
//
//	return scene;
//
//}