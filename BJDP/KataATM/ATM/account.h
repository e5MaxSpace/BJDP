#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    explicit Account(double balance);

    double balance() const;
    void deposite(double amount);
    bool withdraw(double amount);

private:
    double m_balance;
};

#endif // ACCOUNT_H
