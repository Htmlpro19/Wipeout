#ifndef HEART_H
#define HEART_H

#include <Godot.hpp>
#include <Texture.hpp>
#include <TextureRect.hpp>
#include <Ref.hpp>
#include <Image.hpp>
#include <ResourceLoader.hpp>
#include <InputEventKey.hpp>

namespace godot {
    class Heart : public TextureRect {
        GODOT_CLASS(Heart, TextureRect);

        private:
            int id;

        public :
            static void _register_methods();

            Heart();
            ~Heart();

            void _init();
            void _ready();
            void _process(float delta);
            void lose_life();
            void reset_life();
            int get_id();
    };
}

#endif