/*register_types.cpp*/


#include "register_types.h"
#include "core/class_db.h"
#include "player.h"

void register_player_types(){
ClassDB::register_class<player>();

}

void unregister_player_types(){}

