extends Node

# Stores current player name
var current_player_name

# Dictionary which contains (playerID : playerName)
var player_names = {}

# Creates a new networking object
var network = NetworkedMultiplayerENet.new()

# Defines the IP address used for network connection
var ip_address = "127.0.0.1"

# Defines the port number to be used for network connection
var port = 3234

# Defines the max number of players
var max_players = 2

# Function that implements host functionality
func _host_start():
	# Creates and sets the server
	network.create_server(port, max_players)
	get_tree().set_network_peer(network)
	
	# Connects network signals to defined functions
	network.connect("peer_connected", self, "_player_connected")
	network.connect("peer_disconnected", self, "_player_disconnected")
	
	# Stores clients name with network ID in the dictionary
	var local_player_id = get_tree().get_network_unique_id()
	player_names[local_player_id] = current_player_name
	
	#TEST Print statement
	print("Server started!")

# Function that is called when a client connects to the server
func _player_connected(player_id):
	print("Player: " + str(player_id) + " connected!")

# Function that is called when a client disconnects from the server
func _player_disconnected(player_id):
	print("Player: " + str(player_id) + " disconnected!")
	
remote func _send_player_info(client_id, client_name):
	player_names[client_id] = client_name
	rset("player_names", player_names)
	rpc("_update_waiting_room")




# Function that implements client functionality
func _client_start():
	# Creates and sets the client
	network.create_client(ip_address, port)
	get_tree().set_network_peer(network)
	
	# Connects network signals to defined functions
	get_tree().connect("connection_failed", self, "_connected_fail")
	get_tree().connect("server_disconnected", self, "_server_disconnected")
	get_tree().connect("connected_to_server", self, "_connected_ok")
	
	#TEST Print statement
	print("...Attempting to join server...")

# Function called when client failed to connect to server
func _connected_fail():
	print("Failed to connect!")

# Function called when server shutsdown
func _server_disconnected():
	print("Server disconnected!")

# Function called when client successfully connects to the server
func _connected_ok():
	# Stores clients name with network ID in the dictionary
	var local_player_id = get_tree().get_network_unique_id()
	
	# Sends local_player_id and current_player_name to the host
	rpc_id(1, "_send_player_info", local_player_id, current_player_name)
	
	#TEST Print statement
	print("Successfully connected to server")
	
# Function for updating the lobby screen
