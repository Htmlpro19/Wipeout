extends Spatial


onready var player1pos = $Player1Start
onready var player2pos = $Player2Start

var player1name
var player2name

var player1id
var player2id

# Called when the node enters the scene tree for the first time.
func _ready():
	for i in (GameManager.player_names).keys():
		if (i == 1):
			player1name = GameManager.player_names[i]
			player1id = i
		else:
			player2name = GameManager.player_names[i]
			player2id = i
	
	var player1 = preload("res://sub_scenes/Player.tscn").instance()
	player1.set_name(player1name)
	player1.set_network_master(player1id)
	player1.global_transform = player1pos.global_transform
	add_child(player1)
	
	var player2 = preload("res://sub_scenes/Player.tscn").instance()
	player2.set_name(player2name)
	player2.set_network_master(player2id)
	player2.global_transform = player2pos.global_transform
	add_child(player2)
