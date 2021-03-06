/*
 * Factory.h
 *
 *      Author: Kordowski Mateusz
 */

#ifndef TRAFFIC_SIM_MAIN_UI_BUTTON_FACTORY_H
#define TRAFFIC_SIM_MAIN_UI_BUTTON_FACTORY_H

#include "Interface.h"

namespace Button{

enum Type{
    Exit,

};

enum class Properties{
    Normal,
    Draw,
    DrawTrans
};


// TODO, do not use
class Factory{
    

public:
    Factory();
    ~Factory();

    std::shared_ptr<Interface> create(Properties prop, Type type, const std::string& name);
    std::shared_ptr<Interface> createNormal(Type type, const std::string& name);
    std::shared_ptr<InterfaceDraw> createDraw(Type type, const std::string& name);
    std::shared_ptr<InterfaceDrawTrans> createDrawTrans(Type type, const std::string& name);
};


}




#endif