#include "gui.h"

using namespace godot;

void Gui::_register_methods() {
    register_method((char*) "_process", &Gui::_process);
    register_method((char*) "_ready", &Gui::_ready);
    register_method((char*) "life_loss", &Gui::life_loss);
    register_method((char*) "reset_life", &Gui::reset_life);
    register_property<Gui, int>((char*) "id", &Gui::id, 0);
}

Gui::Gui() {}

Gui::~Gui() {}

void Gui::_init() {}

void Gui::_ready() {
    times = 0;
    ResourceLoader* reLo = ResourceLoader::get_singleton();
    (Ref<Texture>) full_heart = (Ref<Texture>) 
        ResourceLoader::get_singleton()->load("res://.import/hud-heart.png-3c13af327c336a93f1ea037324294796.stex", "", true);
    Ref<Texture> empty = 
        reLo->load("res://.import/hud-heart-outline.png-bbb0456d064f5b3f2138429cf6dbb0fe.stex", "", true);
    //empty_heart = empty->instance();
    //empty->instance();
    //bool valid = empty_heart.is_null();
    //godot::String valid_s = valid ? "null" : "not null";
    //godot::Godot::print("The stex is " + valid_s);
}

void Gui::_process(float delta) {
    //if (InputEventKey)
    //times++;
    //if (times % 100 == 0)
    //    life_loss();
}

void Gui::life_loss() {
    //Ref<Texture> curr_texture = (Ref<Texture>) get_texture();
    //curr_texture->get
    //new_texture
    //empty_heart.is_valid();
    //set_texture(empty_heart);
    //Ref<Texture> curr_texture = (Ref<Texture>) get_texture();
    //bool valid = curr_texture.is_valid();
    //godot::String valid_s = valid == true ? "true" : "false";
    //godot::Godot::print(valid_s);
    set_visible(false);
}

void Gui::reset_life() {
    set_visible(true);
}

