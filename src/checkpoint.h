#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <Godot.hpp>
#include <Area.hpp>
#include "player.h"

namespace godot {
    /**
     *   A class representing a checkpoint in gameplay. 
     *   Usually occurs between major obstacles.
     **/
    class Checkpoint : public Area {
        GODOT_CLASS(Checkpoint, Area)

        private:
            // Called when this checkpoint has been entered
            // by another node.
            void checkpoint_entered(Node* node);

        public:
            // Register the methods with Godot.
            static void _register_methods();
            
            // Constructor and Destructor.
            Checkpoint();
            ~Checkpoint();

            // Godot methods.
            void _init();
            void _ready();
            void _process(float delta);

            // The current translation of this 
            // checkpoint.
            Vector3 location;
    };
}

#endif 