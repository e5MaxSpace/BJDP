#include "withdrawcommand.h"
#include "account.h"

WithdrawCommand::WithdrawCommand()
{
}

void WithdrawCommand::operator ()(double amount)
{
    if (account())
        account()->withdraw(amount);
}
