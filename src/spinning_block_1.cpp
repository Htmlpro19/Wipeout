#include "spinning_block_1.h"

using namespace godot;

void SpinningBlock1::_register_methods() {
	register_method("_process", &SpinningBlock1::_process);
}

SpinningBlock1::SpinningBlock1() {

}

SpinningBlock1::~SpinningBlock1() {

}

void SpinningBlock1::_init() {

}

void SpinningBlock1::_process(float delta) {
	time_passed += delta;
	set_rotation(Vector3(0, 0.75 * time_passed, 0));
}