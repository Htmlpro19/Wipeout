#ifndef WATER_BOTTOM_H
#define WATER_BOTTOM_H

// All files needed for WaterBottom class
#include <Godot.hpp>
#include <Spatial.hpp>
#include <Node.hpp>
#include <KinematicBody.hpp>
#include <Area.hpp>
#include "player.h"

// WaterBottom class defined in the godot namespace
namespace godot {
	// Definition for WaterBottom class which extends the Spatial class
	class WaterBottom : public Spatial {
		GODOT_CLASS(WaterBottom, Spatial)

	private:
		Node* area_node;
		Area* area;

		Node* n_player1;
		KinematicBody* player1_body;
		Player* player1;

		Node* n_player2;
		KinematicBody* player2_body;

	public:
		static void _register_methods();

		// Constructor for Trophy class
		WaterBottom();

		// Destructor for Trophy class
		~WaterBottom();

		void _init();

		void _ready();

		void _area_entered();

		void respawn(KinematicBody* body);
	};
}

#endif