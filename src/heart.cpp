#include "heart.h"

using namespace godot;

void Heart::_register_methods() {
    register_method((char*) "_process", &Heart::_process);
    register_method((char*) "_ready", &Heart::_ready);
    register_method((char*) "lose_life", &Heart::lose_life);
    register_method((char*) "reset_life", &Heart::reset_life);
    register_property<Heart, int>((char*) "id", &Heart::id, 0);
}

Heart::Heart() {}

Heart::~Heart() {}

void Heart::_init() {}

void Heart::_ready() {}

void Heart::_process(float delta) {}

/**
 *  Hide this heart on loss of life.
 **/
void Heart::lose_life() {
    set_visible(false);
}

/**
 *  Reset the visibility of this heart.
 */
void Heart::reset_life() {
    set_visible(true);
}

/**
 *  Return the ID associated with this heart.
 **/
int Heart::get_id() {
    return id;
}

