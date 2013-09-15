#include "electricitycard.h"

ElectricityCard::ElectricityCard(int initValue) :
    m_unitPrice(2.0),
    m_stock(initValue)
{
}

double ElectricityCard::unitPrice() const
{
    return m_unitPrice;
}

void ElectricityCard::setUnitPrice(double unitPrice)
{
    m_unitPrice = unitPrice;
}

void ElectricityCard::rechargeElectricity(int numberOfElectricity)
{
    m_stock += numberOfElectricity;
}

int ElectricityCard::stock() const
{
    return m_stock;
}
