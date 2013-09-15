#ifndef ATMACTION_H
#define ATMACTION_H

#include <string>

class Command;
class ATMAction
{
public:
    explicit ATMAction(const std::string &actionName,
                       Command* aCommand = 0);

    ~ATMAction();

    void onClick(double amount);
    
private:
    std::string m_actionName;
    Command* m_aCommand;

    ATMAction(const ATMAction& other);
    ATMAction &operator=(const ATMAction& rhs);
};

#endif // ATMACTION_H
