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
		Node* player_node;
		Area* area;
		KinematicBody* player_body;
		Player* player;

	public:
		static void _register_methods();

		// Constructor for Trophy class
		WaterBottom();

		// Destructor for Trophy class
		~WaterBottom();

		void _init();

		void _ready();

		void _area_entered();
	};
}

#endif