#include "buyelectricitycommand.h"

#include "account.h"
#include "electricitycard.h"

#include <assert.h>

BuyElectricityCommand::BuyElectricityCommand()
    : m_aElectricityCard(0)
{
}

void BuyElectricityCommand::setElectricityCardAccount(ElectricityCard *electricityCard)
{
    m_aElectricityCard = electricityCard;
}

void BuyElectricityCommand::operator ()(double numberOfElectricity)
{
    assert(m_aElectricityCard);
    double chargeOfElectricity = numberOfElectricity*m_aElectricityCard->unitPrice();
    if (account() && account()->withdraw(chargeOfElectricity))
    {
        m_aElectricityCard->rechargeElectricity(numberOfElectricity);
    }
    else
    {
        // ±®¥ÌÃ· æ£° ....
    }
}
