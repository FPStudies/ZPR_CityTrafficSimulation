/*
 * ScreenTests.cc
 *
 *      Author: Kordowski Mateusz
 */

#ifndef TRAFFIC_SIM_BOOST_TEST_EVENTS_CPP
#define TRAFFIC_SIM_BOOST_TEST_EVENTS_CPP

#define BOOST_TEST_MODULE Events

#include <boost/test/included/unit_test.hpp>

#include "BasicEvents.h"
#include "EventManager.h"
#include "EventSet.h"
#include "UIEvents.h"


BOOST_AUTO_TEST_CASE(basic_events_methods){
    BasicEvents event;
    auto copy = event.clone();

    BOOST_CHECK(event.equals(*copy) == true);

    auto copy2 = copy->clone();

    BOOST_CHECK(copy2->equals(event) == true);
}

BOOST_AUTO_TEST_CASE(UI_events_check){
    UIEvents event;
    auto copy = event.clone();

    BOOST_CHECK(event.equals(*copy) == true);

    auto copy2 = copy->clone();

    BOOST_CHECK(copy2->equals(event) == true);
}

BOOST_AUTO_TEST_CASE(event_manager_methods){
    EventManager manager;
    std::shared_ptr<BasicEvents> bEvent = std::make_shared<BasicEvents>();
    std::shared_ptr<UIEvents> uiEvent = std::make_shared<UIEvents>();

    manager.add("test1", EventManager::State::ACTIVE, bEvent);
    manager.add("test2", EventManager::State::INACTIVE, uiEvent);
    manager.add("test3", EventManager::State::INACTIVE, bEvent);

    BOOST_CHECK(manager.remove("test1") == false);
    BOOST_CHECK(manager.remove("test1") == true);

    BOOST_CHECK(manager.addNew("test1", EventManager::State::ACTIVE, bEvent) == true);

    manager.add("test4", EventManager::State::INACTIVE, bEvent);
    manager.add("test4", EventManager::State::INACTIVE, uiEvent);

     BOOST_CHECK(manager.remove("test4") == false);
     BOOST_CHECK(manager.remove("test4") == true);
}   


#endif