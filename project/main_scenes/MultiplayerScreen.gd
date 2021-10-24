extends Control

func _ready():
	pass

func _on_HostButton_pressed():
	print("Host button pressed")
	get_tree().change_scene("res://main_scenes/HostNameInputScreen.tscn")

func _on_JoinButton_pressed():
	print("Join button pressed")
	get_tree().change_scene("res://main_scenes/ClientNameInputScreen.tscn")
