/*
 * Drawable.h
 *
 *      Author: Kordowski Mateusz
 */

#ifndef TRAFFIC_SIM_DRAWABLE_H
#define TRAFFIC_SIM_DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "DrawingID.h"

class Drawable{
    DrawingID ID_;
    std::unique_ptr<sf::RenderTarget> target; // it must be assigned later in inherit class

public:
    Drawable()
    : ID_(DrawingID::newID()), target(nullptr)
    {}

    virtual ~Drawable() = default;


    virtual void draw() = 0;
    virtual sf::FloatRect boundingBox() = 0;
    virtual bool canBeDrawn() = 0;

    DrawingID getID() const{
        return ID_;
    }
};

#endif
