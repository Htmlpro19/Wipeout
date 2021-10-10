#ifndef GUI_H
#define GUI_H

#include <Godot.hpp>
#include <Texture.hpp>
#include <TextureRect.hpp>
#include <Ref.hpp>
#include <Image.hpp>
#include <ResourceLoader.hpp>
#include <InputEventKey.hpp>

namespace godot {
    class Gui : public TextureRect {
        GODOT_CLASS(Gui, TextureRect);

        private:
            int id;
            //Texture curr_texture;
            const Ref<Texture> full_heart;
            const Ref<Texture> empty_heart;
            int times;

        public :
            static void _register_methods();

            Gui();
            ~Gui();

            void _init();
            void _ready();
            void _process(float delta);
            void life_loss();
            void reset_life();
    };
}

#endif