#include "audio_player.h"

using namespace godot;

void AudioPlayer::_register_methods() {
	register_method("_ready", &AudioPlayer::_ready);
}

AudioPlayer::AudioPlayer() {

}

AudioPlayer::~AudioPlayer() {

}

void AudioPlayer::_init() {

}

void AudioPlayer::_ready() {
	this->play();
}