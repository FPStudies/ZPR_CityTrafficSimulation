#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screenInterface.h"

class GameScreen: public ScreenInteface{
    
public:
    ScreenID run(sf::RenderWindow & window);
};


#endif