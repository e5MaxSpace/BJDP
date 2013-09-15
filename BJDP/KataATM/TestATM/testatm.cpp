#include <QString>
#include <QtTest>

#include "../ATM/atm.h"

class TestAtmTest : public QObject
{
    Q_OBJECT
    
public:
    TestAtmTest();
    
private Q_SLOTS:
    void testCase();
};

TestAtmTest::TestAtmTest()
{
}

void TestAtmTest::testCase()
{
    ATM atm;

    atm.login("liucz");

    QVERIFY2(qFuzzyCompare(atm.getBalance(), 0), "ATM::getBalance failed.");

    double depositeMount = 1000.0;
    atm.doSelfService("deposite", depositeMount);
    QVERIFY2(qFuzzyCompare(atm.getBalance(), depositeMount), "ATM::deposite failed.");

    double withdrawMount = 300.0;
    atm.doSelfService("withdraw", withdrawMount);
    QVERIFY2(qFuzzyCompare(atm.getBalance(), 700.0), "ATM::withdraw failed.");

    double elecKWh = 100.0;
    atm.doSelfService("recharge", elecKWh);
    QVERIFY2(qFuzzyCompare(atm.getBalance(), 500.0), "ATM::rechargeElectricity failed.");
    QVERIFY2((atm.getStockOfElectricity() == 100), "ATM::rechargeElectricity failed.");
}

QTEST_APPLESS_MAIN(TestAtmTest)

#include "testatm.moc"
