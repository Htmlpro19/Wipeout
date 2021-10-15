#include "wipeout_fist.h"

using namespace godot;

void WipeoutFist::_register_methods() {
	register_method("_process", &WipeoutFist::_process);
}

WipeoutFist::WipeoutFist() {

}

WipeoutFist::~WipeoutFist() {

}

void WipeoutFist::_init() {
	old_translation = get_translation();
	new_translation = old_translation + Vector3(-1.9, 0, 0);
}

void WipeoutFist::_process(float delta) {
	time_left -= delta;

	if (time_left <= 0) {
		set_translation(new_translation);

		if (time_left <= -1) {
			time_left = 1;
		}
	}
	else {
		set_translation(old_translation);
	}
}