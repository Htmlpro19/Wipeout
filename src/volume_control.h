#ifndef VOLUME_CONTROL_H
#define VOLUME_CONTROL_H

#include <Godot.hpp>
#include <TextureButton.hpp>
#include <AudioStreamPlayer.hpp>

namespace godot {
    class VolumeControl : public TextureButton {
        GODOT_CLASS(VolumeControl, TextureButton);

        public:
            static void _register_methods();

            VolumeControl();
            ~VolumeControl();

            void _init();
            void _ready();

            void _on_mute_pressed();

            enum state {
                UNMUTED,
                MUTED
            };

            state current_state;

        private: 
            AudioStreamPlayer* audio_player;
            const int MUTE = 50;
    };
}

#endif