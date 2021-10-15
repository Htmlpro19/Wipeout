#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

// All files needed for audio player class
#include <Godot.hpp>
#include <AudioStreamPlayer.hpp>

// Audio player class defined in the godot namespace
namespace godot {
	// Definition for AudioPlayer class which extends the AudioStreamPlayer class
	class AudioPlayer : public AudioStreamPlayer {
		// Macro which identifies the audio player class and which class it extends to godot
		GODOT_CLASS(AudioPlayer, AudioStreamPlayer)

	private:

	public:
		// Function required by godot to regester new methods and properties
		static void _register_methods();

		// Constructor for audio player class
		AudioPlayer();

		// Destructor for audio player class
		~AudioPlayer();

		// Function that's called when audio player class is spawned
		void _init();

		// Function that's called when the audio player and all of its children are spawned
		void _ready();
	};
}

#endif