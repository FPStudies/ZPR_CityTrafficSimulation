#ifndef ZPR_TRAFFIC_SIM_RENDER_LOOP_CPP
#define ZPR_TRAFFIC_SIM_RENDER_LOOP_CPP

#include <memory>

#include "renderLoop.h"

using namespace sf;

RenderLoop::RenderLoop(const uint& width, const uint& height, const char* name, const uint& modeBitsPerPixel)
: window(sf::VideoMode(width, height, modeBitsPerPixel), name)
{}

RenderLoop::~RenderLoop(){}

const int RenderLoop::render(){
    EventManager eventManager;
    std::shared_ptr<BasicEvents> ev = std::make_shared<BasicEvents>();
    

    eventManager.add("test", EventManager::State::Active, ev);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            eventManager.checkEvents(window, event);
        }

        window.clear();
        window.display();    
    }

    return EXIT_SUCCESS;
}




static const std::vector<sf::VideoMode> getFullscreenVideoModes() {
    return std::vector<sf::VideoMode>(sf::VideoMode::getFullscreenModes());
}

#endif
