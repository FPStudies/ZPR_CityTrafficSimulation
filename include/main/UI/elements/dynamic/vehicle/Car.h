/*
 * Car.h
 *
 *      Author: Przybysz Filip
 */

#ifndef TRAFFIC_SIM_CAR_H
#define TRAFFIC_SIM_CAR_H

#include "Vehicle.h"

namespace Elements::Vehicle {

    /**
     * @brief smaller, faster vehicle
     * 
     */
    class Car : public Vehicle {

    public:

        Car(sf::Window& window, const Texture_ptr& texture);
        ~Car();

    };

}

#endif
