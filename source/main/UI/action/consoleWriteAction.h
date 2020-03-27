#ifndef CONSOLE_WRITE_ACTION_H
#define CONSOLE_WRITE_ACTION_H

#include <string>

#include "actionInterface.h"

class ConsoleWriteAction: public ActionInterface{
    std::string lastCommand;

    void writeToConsole();

public:
    virtual void update();
};

#endif