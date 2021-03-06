/*
 * Font.cc
 *
 *      Author: Kordowski Mateusz
 */

#include "font/Font.h"


using namespace Draw::Font;


Font::Font(const std::string& path)
: ::SharedResource::Resource<sf::Font>()
{
    sf::Font font;
    if(!font.loadFromFile(path)){
        std::cerr << "Could not load font file: " << path << "\n";
    }

    object_ = std::move(font);
}

Font::Font(const sf::Font& font)
: ::SharedResource::Resource<sf::Font>(font)
{}
