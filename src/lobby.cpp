#include "lobby.h"

void godot::Lobby::_register_methods()
{
	register_method("_ready", &Lobby::_ready);
	register_method("_refresh_players", &Lobby::_refresh_players);
	register_method("_onButton_pressed", &Lobby::_onButton_pressed);
}

godot::Lobby::Lobby()
{
}

godot::Lobby::~Lobby()
{
}

void godot::Lobby::_init()
{
}

void godot::Lobby::_ready()
{

}

void godot::Lobby::_refresh_players()
{
}

void godot::Lobby::_onButton_pressed()
{
}
