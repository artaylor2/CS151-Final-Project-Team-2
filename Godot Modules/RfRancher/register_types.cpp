/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "rfRancher.h"
#include "monsterBase.h"
#include "fireType.h"

void register_rfrancher_types() 
{
    ClassDB::register_class<RfRancher>();
    ClassDB::register_class<MonsterBase>();
	ClassDB::register_class<FireType>();
}

void unregister_rfrancher_types() 
{
   // Nothing to do here in this example.
}