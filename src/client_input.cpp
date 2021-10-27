#include "client_input.h"

void godot::ClientInput::_register_methods()
{
	register_method("_ready", &ClientInput::_ready);
	register_method("_onButton_pressed", &ClientInput::_onButton_pressed);
}

godot::ClientInput::ClientInput()
{
}

godot::ClientInput::~ClientInput()
{
}

void godot::ClientInput::_init()
{
}

void godot::ClientInput::_ready()
{
	client_input_node = get_node("ClientInput");
	client_input = godot::Object::cast_to<LineEdit>(client_input_node);

	button_node = get_parent()->get_node("Button");
	button = godot::Object::cast_to<Button>(button_node);

	if (client_input)
	{
		client_input->grab_focus();
	}
	else
	{
		Godot::print("Client Input is NULL");
	}

	if (button)
	{
		button->connect("pressed", this, "_onButton_pressed");
	}
}

void godot::ClientInput::_onButton_pressed()
{
	/*if (game_manager && client_input)
	{
		game_manager->current_player_name = client_input->get_text();

		game_manager->_client_start();
	}
	else
	{
		Godot::print("Game Manager is null in client or Client Input is null");
	}*/
}
