#include "spinning_block_2.h"

using namespace godot;

void SpinningBlock2::_register_methods() {
	register_method("_process", &SpinningBlock2::_process);
}

SpinningBlock2::SpinningBlock2() {

}

SpinningBlock2::~SpinningBlock2() {

}

void SpinningBlock2::_init() {

}

void SpinningBlock2::_process(float delta) {
	time_passed += delta;
	set_rotation(Vector3(0, -0.25 * time_passed, 0));
}