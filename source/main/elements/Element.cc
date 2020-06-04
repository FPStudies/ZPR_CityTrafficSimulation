/*
 * Element.cc
 *
 *      Author: Przybysz Filip, Kordowski Mateusz
 */

#include "Element.h"

using namespace Elements;

Element::Element(sf::Window& window, const Texture_ptr& texture)
:   texture_(texture), 
    states_(&texture->getTexture()), 
    can_be_drawn_(true)
{}

Element::~Element() = default;

void Element::draw(sf::RenderTarget& target) const{
    target.draw(*this, states_);
}

sf::FloatRect Element::getLocalBounds() const{
    return this->getLocalBounds();
}

sf::FloatRect Element::getGlobalBounds() const{
    return this->getGlobalBounds();
}

bool Element::canBeDrawn() const{
    return can_be_drawn_;
}