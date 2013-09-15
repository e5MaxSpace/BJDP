#include "atmaction.h"
#include "command.h"

ATMAction::ATMAction(const std::string &actionName,
                     Command *aCommand) :
    m_actionName(actionName),
    m_aCommand(aCommand)
{
}

ATMAction::~ATMAction()
{
}

void ATMAction::onClick(double amount)
{
    if (m_aCommand)
        (*m_aCommand)(amount);
}
