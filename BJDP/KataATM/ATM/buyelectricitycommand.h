#ifndef BUYELECTRICITYCOMMAND_H
#define BUYELECTRICITYCOMMAND_H

#include "command.h"

class ElectricityCard;
class BuyElectricityCommand : public Command
{
public:
    explicit BuyElectricityCommand();

    void setElectricityCardAccount(ElectricityCard *electricityCard);
    virtual void operator ()(double numberOfElectricity);

private:
    ElectricityCard *m_aElectricityCard;
};

#endif // BUYELECTRICITYCOMMAND_H
