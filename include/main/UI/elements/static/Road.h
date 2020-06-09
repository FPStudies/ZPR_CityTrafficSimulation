/*
 * Road.h
 *
 *      Author: Przybysz Filip
 */

#ifndef TRAFFIC_SIM_ROAD_H
#define TRAFFIC_SIM_ROAD_H

#include "StaticElement.h"
#include "RoadConnector.h"

namespace Element {

    class RoadConnector;

    class Road : public StaticElement {

        std::deque<std::shared_ptr<RoadConnector>> connectors_;

    public:

        Road(sf::Window& window, const Texture_ptr& texture);
        ~Road();

    };

}

#endif
