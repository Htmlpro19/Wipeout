#include "host_input.h"

void godot::HostInput::_register_methods()
{
	register_method("_ready", &HostInput::_ready);
	register_method("_onButton_pressed", &HostInput::_onButton_pressed);
}

godot::HostInput::HostInput()
{
}

godot::HostInput::~HostInput()
{
}

void godot::HostInput::_init()
{
}

void godot::HostInput::_ready()
{
	host_input_node = get_node("HostInput");
	host_input = godot::Object::cast_to<LineEdit>(host_input_node);

	button_node = get_parent()->get_node("Button");
	button = godot::Object::cast_to<Button>(button_node);

	if (host_input)
	{
		host_input->grab_focus();
	}
	else
	{
		Godot::print("Host Input is NULL");
	}

	if (button)
	{
		button->connect("pressed", this, "_onButton_pressed");
	}


}

void godot::HostInput::_onButton_pressed()
{
	/*if (game_manager && host_input)
	{
		game_manager->current_player_name = host_input->get_text();

		game_manager->_host_start();

		get_tree()->change_scene("res://main_scenes/Lobby.tscn");
	}*/
}
