#include <QtTest>
#include <QCoreApplication>
#include "../../Weather/WeatherForecast/mainwindow.h"
// add necessary includes here

class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

test1::test1()
{
   /* QDate date( 1967, 3, 11 );
    QDateEdit dateEdit( date );

     // up-arrow should increase day by one
     QTest::keyClick( &dateEdit, Qt::Key_Up );
     QCOMPARE( dateEdit.date(), date.addDays(1) );

     // we click twice on the "reduce" arrow at the bottom RH corner
    // first we need the widget size to know where to click
     QSize editWidgetSize = dateEdit.size();
    QPoint clickPoint(editWidgetSize.rwidth()-2, editWidgetSize.rheight()-2);
    // issue two clicks
     QTest::mouseClick( &dateEdit, Qt::LeftButton, 0, clickPoint);
    QTest::mouseClick( &dateEdit, Qt::LeftButton, 0, clickPoint);
     // and we should have decreased day by two (one less than original)
     QCOMPARE( dateEdit.date(), date.addDays(-1) );

     QTest::keyClicks( &dateEdit, "25122005" );
     QCOMPARE( dateEdit.date(), QDate( 2005, 12, 25 ) );

     QTest::keyClick( &dateEdit, Qt::Key_Tab, Qt::ShiftModifier );
     QTest::keyClicks( &dateEdit, "08" );
     QCOMPARE( dateEdit.date(), QDate( 2005, 8, 25 ) );*/
}

test1::~test1()
{

}

void test1::initTestCase()
{

}

void test1::cleanupTestCase()
{

}

void test1::test_case1()
{

}

QTEST_MAIN(test1)

#include "tst_test1.moc"
