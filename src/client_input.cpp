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
}

void godot::ClientInput::_onButton_pressed()
{
}
