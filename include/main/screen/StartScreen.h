/*
 * StartScreen.h
 *
 *      Author: Kordowski Mateusz
 */

#ifndef TRAFFIC_SIM_START_SCREEN_H
#define TRAFFIC_SIM_START_SCREEN_H

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <memory>

#include "ScreenInterface.h"
#include "FixedFramerate.h"
#include "CoordinateSystem.h"

#include "../event/Basic.h"
#include "../event/Manager.h"


#include "../drawing/DrawManager.h"

class StartScreen: virtual public ScreenInteface{
    std::unique_ptr<b2World> world_;
    std::unique_ptr<Event::Manager> event_manager_;
    std::unique_ptr<sf::View> view_;

    void setBox2D();
    void setEventManager();

public:
    StartScreen();
    ~StartScreen();

    ScreenID run(std::shared_ptr<sf::RenderWindow> & window) override;
};


#endif
