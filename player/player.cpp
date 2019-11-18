#include "player.h"



#include "scene/2d/physics_body_2d.h"


void player::_bind_methods(){


	ClassDB::bind_method(D_METHOD("_physics_process","value"), &player::_physics_process);
	ClassDB::bind_method(D_METHOD("_ready"), &player::_ready);
    
}








player::player(){


}



player::~player(){



}

void player::_init(){



}


void player::_ready(){



}
inline float sign(float f) {
    if (f > 0) return 1;
    return (f == 0) ? 0 : -1;
    // or some permutation of the order of the 3 cases
}
void player::_physics_process(float delta){

	
	
	Vector2 force = Vector2(0, GRAVITY);
	
	bool walk_left = Input::get_singleton()->is_action_pressed("move_left");
	bool walk_right =  Input::get_singleton()->is_action_pressed("move_right");
	bool jump =  Input::get_singleton()->is_action_pressed("jump");
	
	bool stop = true;

	if (walk_left){
		if (velocity.x <= WALK_MIN_SPEED and velocity.x > -WALK_MAX_SPEED){
			force.x -= WALK_FORCE;
			stop = false;
		}
	}else if(walk_right){
		if (velocity.x >= -WALK_MIN_SPEED and velocity.x < WALK_MAX_SPEED){
			force.x += WALK_FORCE;
			stop = false;
		}
	}


	if (stop){
		float vsign = sign(velocity.x);
		float vlen = abs(velocity.x);
		
		vlen -= STOP_FORCE * delta;
		if (vlen < 0){
			vlen = 0;
		}
		
		velocity.x = vlen * vsign;
	}

	
	velocity += force * delta;
	
//por algum motivo isso buga 
	velocity = KinematicBody2D::move_and_slide(velocity, Vector2(0, -1));
	
	if (KinematicBody2D::is_on_floor()){
		on_air_time = 0;
	}
		
	if (jumping and velocity.y > 0){
		jumping = false;
	}
	
	if (on_air_time < JUMP_MAX_AIRBORNE_TIME and jump and not prev_jump_pressed and not jumping){
		velocity.y = -JUMP_SPEED;
		jumping = true;
	}
	
	on_air_time += delta;
	prev_jump_pressed = jump;

}



