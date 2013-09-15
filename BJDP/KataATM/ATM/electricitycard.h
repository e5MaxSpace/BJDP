#ifndef ELECTRICITYCARD_H
#define ELECTRICITYCARD_H

class ElectricityCard
{
public:
    explicit ElectricityCard(int initValue);

    double unitPrice() const;
    void setUnitPrice(double unitPrice);

    void rechargeElectricity(int numberOfElectricity);
    int stock() const;

private:
    double m_unitPrice;
    int m_stock;
};

#endif // ELECTRICITYCARD_H
