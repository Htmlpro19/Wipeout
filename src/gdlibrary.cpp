#include <Godot.hpp>
#include "player.h"
#include "spinning_block_1.h"
#include "spinning_block_2.h"
#include "spinning_block_3.h"
#include "wipeout_fist.h"
#include "trophy.h"
#include "audio_player.h"
#include "title_screen.h"
#include "multiplayer_screen.h"
#include "water_bottom.h"
#include "wipeout_fist_opposite.h"
#include "checkpoint.h"
#include "heart.h"
#include "gameover_screen.h"
#include "world_multiplayer.h"
#include "client_input.h" 
#include "host_input.h"
#include "lobby.h"
#include "game_manager.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void* handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<godot::Player>();
    godot::register_class<godot::SpinningBlock1>();
    godot::register_class<godot::SpinningBlock2>();
    godot::register_class<godot::SpinningBlock3>();
    godot::register_class<godot::WipeoutFist>();
    godot::register_class<godot::Trophy>();
    godot::register_class<godot::AudioPlayer>();
    godot::register_class<godot::TitleScreen>();
    godot::register_class<godot::MultiplayerScreen>();
    godot::register_class<godot::WaterBottom>();
    godot::register_class<godot::WipeoutFistOpposite>();
    godot::register_class<godot::Checkpoint>();
    godot::register_class<godot::Heart>();
    godot::register_class<godot::GameoverScreen>();
    godot::register_class<godot::WorldMultiplayer>();
    godot::register_class<godot::ClientInput>();
    godot::register_class<godot::HostInput>();
    godot::register_class<godot::Lobby>();
    godot::register_class<godot::GameManager>();

    
}