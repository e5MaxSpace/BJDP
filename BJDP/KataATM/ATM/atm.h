#ifndef ATM_H
#define ATM_H

#include <map>
#include <string>

class Account;
class ElectricityCard;
class Command;
class ATMAction;

class ATM
{
public:
    ATM();
    ~ATM();

    void login(const std::string &userId);
    void logout();

    void doSelfService(const std::string &actionName, double amount);
    double getBalance() const;
    int getStockOfElectricity() const;

private:
    Account *m_aAccount;
    ElectricityCard *m_aElectricityCard;

    std::map<std::string, Command*> m_commands;
    std::map<std::string, ATMAction*> m_actions;

    ATM(const ATM &other);
    ATM &operator=(const ATM &rhs);
};

#endif // ATM_H
