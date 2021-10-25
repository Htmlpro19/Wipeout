extends Control

onready var player_list = $TextureRect/VBoxContainer/ItemList
onready var start_game_button = $TextureRect/VBoxContainer/Button

func _ready():
	if (GameManager.local_player_id != 1):
		start_game_button.visible = false
		
	_refresh_players()
	
func _refresh_players():
	player_list.clear()
	
	for i in (GameManager.player_names).keys():
		player_list.add_item((GameManager.player_names)[i], null, false)


func _on_Button_pressed():
	GameManager._setup_game_start()
