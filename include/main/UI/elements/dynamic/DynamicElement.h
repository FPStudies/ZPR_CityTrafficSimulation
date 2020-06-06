/*
 * DynamicElement.h
 *
 *      Author: Przybysz Filip
 */

#ifndef TRAFFIC_SIM_DYNAMIC_ELEMENT_H
#define TRAFFIC_SIM_DYNAMIC_ELEMENT_H

#include "../Element.h"

namespace Element {

    class DynamicElement : public Element {

    public:

        DynamicElement(sf::Window& window, const Texture_ptr& texture);
        ~DynamicElement();

    };

}

#endif
