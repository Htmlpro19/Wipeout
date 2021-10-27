#include "volume_control.h"

using namespace godot;
using std::string;

VolumeControl::VolumeControl() {}
VolumeControl::~VolumeControl() {}

void VolumeControl::_register_methods() {
    register_method((char*) "_ready", &VolumeControl::_ready);
    register_method((char*) "_on_mute_pressed", &VolumeControl::_on_mute_pressed);
}

void VolumeControl::_init() {}

/**
 *  Ready the Volume Control button.  Connect the necessary signal to the 
 *  callback method and obtain reference to audio player.
 **/
void VolumeControl::_ready() {
    Node* n_audio_player = get_node("../../../../AudioStreamPlayer");
    if (n_audio_player)
        audio_player = godot::Object::cast_to<AudioStreamPlayer>(n_audio_player);
    this->connect("toggled", this, "_on_mute_pressed");
    current_state = UNMUTED;
    this->set_focus_mode(FOCUS_NONE);
}

/**
 *  Toggles the audio stream when the mute button is pressed.
 *  If audio is playing and the button is pressed, disable the audio.
 *  Otherwise, enable the audio.
 **/
void VolumeControl::_on_mute_pressed() {
    if (audio_player) {
        float current_volume = audio_player->get_volume_db();
        if (current_state == UNMUTED) {
            audio_player->set_volume_db(current_volume - MUTE);
            current_state = MUTED;
        }
        else {
            audio_player->set_volume_db(current_volume + MUTE);
            current_state = UNMUTED;
        }
    }
}