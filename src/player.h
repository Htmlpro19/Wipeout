#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <KinematicBody.hpp>


namespace godot {
    class Player : public KinematicBody {
        GODOT_CLASS(Player, KinematicBody)

    private:
            const int MOVE_SPEED = 12;
            const int JUMP_FORCE = 30;
            const float GRAVITY = 0.98;
            const int MAX_FALL_SPEED = 30;

            const float H_LOOK_SENS = 1.0;
            const float V_LOOK_SENS = 1.0;

    public:
        static void _register_methods();

        Player();
        ~Player();

        void _init();

        void _process(float delta);

    };
}

#endif