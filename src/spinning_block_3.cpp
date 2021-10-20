#include "spinning_block_3.h"

using namespace godot;

void SpinningBlock3::_register_methods() {
	register_method("_process", &SpinningBlock3::_process);
}

SpinningBlock3::SpinningBlock3() {

}

SpinningBlock3::~SpinningBlock3() {

}

void SpinningBlock3::_init() {

}

void SpinningBlock3::_process(float delta) {
	time_passed += delta;
	set_rotation(Vector3(0, 0.5 * time_passed, 0));
}