#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <SceneTree.hpp>
#include <NetworkedMultiplayerENet.hpp>
#include <NetworkedMultiplayerPeer.hpp>

// Title screen class defined in the godot namespace
namespace godot {
	// Definition for TitleScreen class which extends the Control class
	class GameManager : public Node {
		GODOT_CLASS(GameManager, Node)

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for title screen class
		GameManager();

		// Destructor for title screen class
		~GameManager();

		// Function that's called when title screen class is spawned
		void _init();

		// Function that implements host functionality
		void _host_start();

		// Function that is called when a client connects to the server
		void _player_connected(int player_id);

		// Function that is called when a client disconnects from the server
		void _player_disconnected(int player_id);

		// Function that allows clients to send player info to host
		void _send_player_info(int client_id, String client_name);

		// Function that implements client functionality
		void _client_start();

		// Function that's called when client failed to connect to server
		void _connected_fail();

		// Function that's called when server shutsdown
		void _server_disconnected();

		// Function that's called when client successlly connects to the server
		void _connected_ok();

		// Function for updating player name dictionary across host and client
		void _update_player_names(String new_player_name1, String new_player_name2);

		// Function for updating the lobby screen
		void _update_waiting_room();

		// Function that starts the game for everyone connected to the server
		void _setup_game_start();

		// Function that changes scenes to multiplayer world
		void _game_start();

		// Declaring and initializing global variables
		NetworkedMultiplayerENet* network = new NetworkedMultiplayerENet;
		String current_player_name = "";            // Defines the name of the current player
		String player_names[2] = {"", ""};          // Defines a dictionary with a mapping from player id to player name
		int local_player_id = 1;                    // Defines id for local player
		int port = 3234;                            // Defines port number used for server connection
		int max_players = 2;                        // Defines the max number of players

	};
}

#endif