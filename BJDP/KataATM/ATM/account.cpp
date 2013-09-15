#include "account.h"

Account::Account(double balance) :
    m_balance(balance)
{
}

double Account::balance() const
{
    return m_balance;
}

void Account::deposite(double amount)
{
    m_balance += amount;
}

bool Account::withdraw(double amount)
{
    if (m_balance < amount)
    {
        return false;
    }

    m_balance -= amount;

    return true;
}
