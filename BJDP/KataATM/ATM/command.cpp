#include "command.h"

Command::Command() : m_account(0)
{
}

Command::~Command()
{
}

void Command::setAccount(Account *account)
{
    m_account = account;
}

Account *Command::account() const
{
    return m_account;
}
