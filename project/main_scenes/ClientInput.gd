extends LineEdit

func _ready():
	grab_focus()
	

func _on_Button_pressed():
	#Gets text from input field and puts it into the game manager
	GameManager.current_player_name = get_text()
	
	# Starts the server
	GameManager._client_start();
	
	# Change the scene to the lobby
	#get_tree().change_scene("res://main_scenes/Lobby.tscn")
