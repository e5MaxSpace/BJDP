#include "depositecommand.h"

#include "account.h"

DepositeCommand::DepositeCommand()
{
}

void DepositeCommand::operator ()(double amount)
{
    if (account())
        account()->deposite(amount);
}
