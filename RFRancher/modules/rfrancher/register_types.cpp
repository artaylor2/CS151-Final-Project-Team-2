/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"

#include "rfRancher.h"
#include "monsterBase.h"
#include "fireType.h"
#include "forestType.h"
#include "ghostType.h"
#include "iceType.h"
#include "waterType.h"
#include "rockType.h"

void register_rfrancher_types() 
{
    ClassDB::register_class<RfRancher>();
    ClassDB::register_class<MonsterBase>();
	ClassDB::register_class<FireType>();
    ClassDB::register_class<ForestType>();
    ClassDB::register_class<GhostType>();
    ClassDB::register_class<IceType>();
    ClassDB::register_class<WaterType>();
    ClassDB::register_class<RockType>();
}

void unregister_rfrancher_types() 
{
   // Nothing to do here in this example.
}