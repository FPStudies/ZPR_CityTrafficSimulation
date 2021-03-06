/*
 * CollisionID.h
 *
 *      Author: Kordowski Mateusz
 */

#ifndef TRAFFIC_SIM_COLLISION_ID_H
#define TRAFFIC_SIM_COLLISION_ID_H

#include "../utility/ID.hpp"

class CollisionID: virtual public Utils::ID<CollisionID>{

    friend class CollisionInterface;

    CollisionID(const ID<CollisionID> id)
    : ID<CollisionID>(id)
    {}

public:

};


#endif
