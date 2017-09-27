#include "mainwindow.h"
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QtCharts>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE
int main(int argc, char *argv[])
{
   /* QApplication a(argc, argv);

       QLineSeries *series = new QLineSeries();

       series->append(0, 6);
       series->append(2, 4);
       series->append(3, 8);
       series->append(7, 4);
       series->append(10, 5);
       *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

       QChart *chart = new QChart();
       chart->legend()->hide();
       chart->addSeries(series);
       chart->createDefaultAxes();
       chart->setTitle("Simple line chart example");

       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       QMainWindow window;
       window.setCentralWidget(chartView);
       window.resize(400, 300);
       window.show();

       return a.exec();*/

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
/*QProgressBar *progressBar = new QProgressBar(&w);
progressBar->setRange(0, 100);
progressBar->setValue(0);
progressBar->setGeometry(10, 10, 180, 30);


QSlider *slider = new QSlider(&w);
slider->setOrientation(Qt::Horizontal);
slider->setRange(0, 100);
slider->setValue(0);
slider->setGeometry(10, 40, 180, 30);
QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));
*/
