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

    QVERIFY2(qFuzzyCompare(atm.getBalance(), 0), "ATM::getBalance failed.");

    double depositeMount = 1000.0;
    atm.deposite(depositeMount);
    QVERIFY2(qFuzzyCompare(atm.getBalance(), depositeMount), "ATM::deposite failed.");

    double withdrawMount = 300.0;
    atm.withdraw(withdrawMount);
    QVERIFY2(qFuzzyCompare(atm.getBalance(), 700.0), "ATM::withdraw failed.");

    double elecKWh = 100.0;
    atm.rechargeElectricity(elecKWh);
    QVERIFY2(qFuzzyCompare(atm.getBalance(), 500.0), "ATM::rechargeElectricity failed.");
}

QTEST_APPLESS_MAIN(TestAtmTest)

#include "testatm.moc"
