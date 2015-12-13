#include <QString>
#include <QtTest>

class TranslatorTest : public QObject
{
    Q_OBJECT

public:
    TranslatorTest();

private Q_SLOTS:
    void testCase1();
};

TranslatorTest::TranslatorTest()
{
}

void TranslatorTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TranslatorTest)

#include "tst_translatortest.moc"
