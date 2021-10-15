#include "spinning_block.h"

using namespace godot;

void SpinningBlock::_register_methods() {
	register_method("_process", &SpinningBlock::_process);
}

SpinningBlock::SpinningBlock() {

}

SpinningBlock::~SpinningBlock() {

}

void SpinningBlock::_init() {

}

void SpinningBlock::_process(float delta) {
	time_passed += delta;
	set_rotation(Vector3(0, 5 * time_passed, 0));
}