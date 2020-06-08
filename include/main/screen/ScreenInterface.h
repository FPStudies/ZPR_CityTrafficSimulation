/*
 * ScreenInterface.h
 *
 *      Author: Kordowski Mateusz
 */

#ifndef TRAFFIC_SIM_SCREEN_INTERFACE_H
#define TRAFFIC_SIM_SCREEN_INTERFACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <mutex>

#include "ScreenID.h"
#include "../utility/Singleton.hpp"


// TODO correct name to ScreenInterface
class ScreenInteface{

    ScreenID ID_;

protected:
    static std::mutex lock_loopback_data_;

    struct LoopbackData{
        std::vector<ScreenID> request_for_next_screen_;
    };

    static std::unique_ptr<LoopbackData> received_data_;

    void resetLoopbackData();

    bool isAnyoneWaiting();

    void clearAll();

public:
    /**
     * @brief It is used to implement the rendering loops or other kind of tasks. Main channel to implement the program actions.
     * @details Main program will nearly always be in the state of screen. The loop will run this method
     * and return the next screen that should be used. If the returned screen ID will be invalid then it will 
     * break loop and starts to end an program.
     * 
     * @param window 
     * @return ScreenID The next identifier of screen that should be used.
     */
    virtual ScreenID run(std::shared_ptr<sf::RenderWindow> & window) = 0;    // it wll return the next screen that should be used

    ScreenInteface();

    virtual ~ScreenInteface();

    ScreenID getID() const;

    static void requestForNextScreen(const ScreenID& ID);
};


#endif
