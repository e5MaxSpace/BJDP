#include "atm.h"

#include "account.h"
#include "electricitycard.h"
#include "depositecommand.h"
#include "withdrawcommand.h"
#include "buyelectricitycommand.h"
#include "atmaction.h"

ATM::ATM()
    : m_aAccount(0),
      m_aElectricityCard(0)
{
    std::string balanceActionName("balance");
    m_actions[balanceActionName] = new ATMAction(balanceActionName);

    std::string depositeActionName("deposite");
    m_commands[depositeActionName] = new DepositeCommand();
    m_actions[depositeActionName]  = new ATMAction(depositeActionName, m_commands[depositeActionName]);

    std::string withdrawActionName("withdraw");
    m_commands[withdrawActionName] = new WithdrawCommand();
    m_actions[withdrawActionName]  = new ATMAction(withdrawActionName, m_commands[withdrawActionName]);

    std::string rechargeActionName("recharge");
    m_commands[rechargeActionName] = new BuyElectricityCommand();
    m_actions[rechargeActionName]  = new ATMAction(rechargeActionName, m_commands[rechargeActionName]);
}

ATM::~ATM()
{
    logout();

    std::map<std::string, ATMAction*>::iterator it = m_actions.begin();
    for (; it != m_actions.end(); ++it)
    {
        delete (*it).second;
    }
    m_actions.clear();
}

void ATM::login(const std::string &userId)
{
    // 根据 userId 构建一个特定的账户，此处略
    m_aAccount = new Account(0.0);
    m_aElectricityCard = new ElectricityCard(0);

    std::map<std::string, Command*>::iterator it = m_commands.begin();
    for (; it != m_commands.end(); ++it)
    {
        (*it).second->setAccount(m_aAccount);
        if ((*it).first == std::string("recharge"))
        {
            BuyElectricityCommand *buyElectricityCommand = static_cast<BuyElectricityCommand*>((*it).second);
            buyElectricityCommand->setElectricityCardAccount(m_aElectricityCard);
        }
    }
}

void ATM::logout()
{
    delete m_aAccount;
    m_aAccount = 0;
    delete m_aElectricityCard;
    m_aElectricityCard = 0;
}

void ATM::doSelfService(const std::string &actionName, double amount)
{
    if (m_actions.find(actionName) != m_actions.end())
        m_actions[actionName]->onClick(amount);
}

double ATM::getBalance() const
{
    if (m_aAccount == 0)
    {
        // 提示未登录
        return 0.0;
    }

    return m_aAccount->balance();
}

int ATM::getStockOfElectricity() const
{
    if (m_aElectricityCard == 0)
    {
        // 提示未登录
        return 0;
    }

    return m_aElectricityCard->stock();
}
