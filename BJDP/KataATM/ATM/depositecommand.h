#ifndef DEPOSITECOMMAND_H
#define DEPOSITECOMMAND_H

#include "command.h"

class DepositeCommand : public Command
{
public:
    DepositeCommand();

    virtual void operator ()(double amount);
};

#endif // DEPOSITECOMMAND_H
