#include "checkpoint.h"

using namespace godot;

void Checkpoint::_register_methods() {
    register_method((char*) "_ready", &Checkpoint::_ready);
    register_method((char*) "_process", &Checkpoint::_process);
    register_method((char*) "checkpoint_entered", &Checkpoint::checkpoint_entered);
    register_signal<Checkpoint>((char*) "area_entered", "node", GODOT_VARIANT_TYPE_OBJECT);
}

Checkpoint::Checkpoint() {}
Checkpoint::~Checkpoint() {}

void Checkpoint::_init() {}


void Checkpoint::_ready() {
    location = get_translation();
    // Connect this checkpoint's Area to the signal 
    this->connect("area_entered", this, "checkpoint_enetered");
}

void Checkpoint::_process(float delta)  {}

/**
 *  Called when another node enters this Area (checkpoint).
 *  Verifies that the node is a player and updates the player's
 *  checkpoint coordinates if so.
 * 
 *  @param node the node that entered the Area.
 */
void Checkpoint::checkpoint_entered(Node* node) {
    Player* player;
    // If the cast is successful, a player entered the area. 
    if ((player = cast_to<Player>(node)) != nullptr)
        //Update player's checkpoint value.
        player->_set_checkpoint(location);
}