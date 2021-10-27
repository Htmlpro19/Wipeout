#include "client_input.h"

void godot::ClientInput::_register_methods()
{
	register_method("_ready", &ClientInput::_ready);
	register_method("_on_Button_pressed", &ClientInput::_on_Button_pressed);
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
	game_manager_node = get_tree()->get_root()->get_node("GameManager");
	game_manager = godot::Object::cast_to<GameManager>(game_manager_node);


	client_input_node = get_parent()->get_node("ClientInput");
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
		button->connect("pressed", this, "_on_Button_pressed");
	}
	else
	{
		Godot::print("Button is null in Client Input");
	}
}

void godot::ClientInput::_on_Button_pressed()
{
	if (game_manager != NULL && client_input != NULL)
	{
		game_manager->current_player_name = client_input->get_text();
		game_manager->_client_start();

		//Test print
		Godot::print("Client start called successfully");
	}
	else
	{
		Godot::print("Game Manager is null in client or Client Input is null");
	}
}
