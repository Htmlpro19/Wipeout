#include "wipeout_fist_opposite.h"

using namespace godot;

void WipeoutFistOpposite::_register_methods() {
	register_method("_process", &WipeoutFistOpposite::_process);
}

WipeoutFistOpposite::WipeoutFistOpposite() {

}

WipeoutFistOpposite::~WipeoutFistOpposite() {

}

void WipeoutFistOpposite::_init() {
	old_translation = get_translation();
	new_translation = old_translation + Vector3(1.9, 0, 0);
}

void WipeoutFistOpposite::_process(float delta) {
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