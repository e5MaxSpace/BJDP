#include "atm.h"

ATM::ATM()
    : m_balance(0.0),
      m_pricePerKwh(2.0)
{
}

double ATM::getBalance() const
{
    return m_balance;
}

void ATM::deposite(double money)
{
    m_balance += money;
}

void ATM::withdraw(double money)
{
    if (m_balance < money)
    {
        return;
    }

    m_balance -= money;
}

void ATM::rechargeElectricity(double unit)
{
    if (m_balance < unit*m_pricePerKwh)
    {
        return;
    }

    m_balance -= unit*m_pricePerKwh;
}
