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
}

void godot::HostInput::_onButton_pressed()
{
}
