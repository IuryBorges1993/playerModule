
#ifndef PLAYER_H
#define PLAYER_H


#include "scene/2d/physics_body_2d.h"
#include "core/os/input.h"


class player: public KinematicBody2D {

GDCLASS(player, KinematicBody2D);

public:
const float GRAVITY = 500.0;


const int FLOOR_ANGLE_TOLERANCE = 40;
const int WALK_FORCE = 600;
const int WALK_MIN_SPEED = 10;
const int WALK_MAX_SPEED = 200;
const int STOP_FORCE = 1300;
const int JUMP_SPEED = 200;
const float JUMP_MAX_AIRBORNE_TIME = 0.2;

const float SLIDE_STOP_VELOCITY = 1.0;
const float SLIDE_STOP_MIN_TRAVEL = 1.0;
Vector2 velocity = Vector2();
int on_air_time = 100;
bool jumping = false;


bool prev_jump_pressed = false;




void _ready();
void _physics_process(float delta);
void _init();


player();
~player();


protected:
	static void _bind_methods();








};

#endif
