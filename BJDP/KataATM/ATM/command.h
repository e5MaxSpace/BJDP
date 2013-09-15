#ifndef COMMAND_H
#define COMMAND_H

class Account;
class Command
{
public:
    Command();
    virtual ~Command();

    void setAccount(Account *account);

    virtual void operator() (double amount) = 0;

protected:
    Account* account() const;

private:
    Account *m_account;

    Command(const Command &other);
    Command &operator=(const Command &rhs);
};

#endif // COMMAND_H
