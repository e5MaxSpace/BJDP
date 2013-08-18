#ifndef ATM_H
#define ATM_H

class ATM
{
public:
    ATM();

    double getBalance() const;
    void deposite(double money);
    void withdraw(double money);
    void rechargeElectricity(double unit);

private:
    double m_balance;
    const double m_pricePerKwh;
};

#endif // ATM_H
