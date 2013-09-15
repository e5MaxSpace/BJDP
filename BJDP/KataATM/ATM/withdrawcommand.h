#ifndef WITHDRAWCOMMAND_H
#define WITHDRAWCOMMAND_H

#include "command.h"

class WithdrawCommand : public Command
{
public:
    WithdrawCommand();

    virtual void operator ()(double amount);
};

#endif // WITHDRAWCOMMAND_H
