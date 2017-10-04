#include "mainwindow.h"

#include <QApplication>
#define ButtonWitdth 30
#define ButtonLength 100

bool compilationFinished = false;
bool compilationStarted = false;
bool isRestart =false;
const std::string filePath ("../../Weather/WeatherForecast/prog");
std::unique_ptr<WeatherAPI> yahooWeatherForecast;
std::unique_ptr<WeatherAPI> owmWeatherForecast;
class myThread: public QThread
{
public:
    QString cityName;
    void run()
    {qDebug() << "RUN";
        owmWeatherForecast->printTemperature(cityName.toStdString());
        yahooWeatherForecast->printTemperature(cityName.toStdString());

        /*compilationStarted = true;
        ProgramHandler::runMakefile();
        std::cout <<"Compilation completed\n" <<std::flush;
        compilationFinished = true;
        compilationStarted = false;*/
    }
};
void MainWindow::setOwmWeatherForecast(WeatherAPI * owm)
{
    owmWeatherForecast.reset(owm);
}

void MainWindow::setYahooWeatherForecast(WeatherAPI * yahoo)
{
    yahooWeatherForecast.reset(yahoo);
}

void MainWindow::setMessageHandler(MessagingHandler * msgHandler)
{
    messagingHandler.reset(msgHandler);
}

void MainWindow::setProgramHandler(ProgramHandler * prgHandler)
{
    progHandler.reset(prgHandler);
}

MainWindow::MainWindow()
{
    QTextCodec::codecForName ("UTF-8");

    //createMenus();
    // createStatusBar();
    label = new QLabel(tr("Weather forecast"), this);
    label->setGeometry(5, 15, 150, 30);

    compileButton = new QPushButton(tr("&Compile"), this);
    compileButton->setGeometry(0, 0, ButtonLength, ButtonWitdth);

    okButton = new QPushButton(tr("&Ok"), this);
    okButton->setGeometry(300, 210, ButtonLength, ButtonWitdth);

    cleanButton= new QPushButton(tr("&Clean"), this);
    cleanButton->setGeometry(0, 60, ButtonLength, ButtonWitdth);

    restartButton = new QPushButton(tr("&Restart"), this);
    restartButton->setGeometry(0, 90, ButtonLength, ButtonWitdth);

    exitButton = new QPushButton(tr("&Exit"), this);
    exitButton->setGeometry(0, 120, ButtonLength, ButtonWitdth);

    startButton = new QPushButton(tr("&Start"), this);
    startButton->setGeometry(0, 150, ButtonLength, ButtonWitdth);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);

    t = new myThread;
    lnEdit = new QLineEdit(this);
    lnEdit->setGeometry(200,200,100,50);
    lnEdit->setText("lodz");
    connect(restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(getData()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(runApp()));
    connect(compileButton, SIGNAL(clicked()), this, SLOT(compile()));
    connect(shortcut, SIGNAL(activated()), this, SLOT(getData()));
    connect(cleanButton, SIGNAL(clicked()), this, SLOT(clean()));

    //connect(lnEdit, SIGNAL(textChanged( const QString &)), this, SLOT(lineChanged(const QString &)));

    std::ofstream myfile;
    myfile.open ("temperature.txt", std::ios::out | std::ios::app);

    setMinimumSize(200, 200);
    resize(480, 320);
}
void MainWindow::exit()
{
    /* mq_close(messageQueueHandler);
  mq_unlink("/myqueue");*/
    progHandler->stop();
    qApp->quit();
}

void MainWindow::restart()
{
    if(progHandler->performRestart() == -1)
    {
        std::cout <<"Restart went wrong" << std::endl;
    }
    else
    {
        //mq_close(messageQueueHandler);
        //mq_unlink("/myqueue");
        isRestart = true;
        this->runApp();
        std::cout <<"Restart was successful" << std::endl;
    }
}

void MainWindow::getData()
{
   // cityName = lnEdit->text().toStdString();
    qDebug() << "getdata";
    t->cityName = lnEdit->text();
    t->start();
  //  messagingHandler->sendMessage(cityName,0);
}

void MainWindow::clean()
{
    std::cout <<"Make clean\n" <<std::flush;
    compilationFinished = false;
    ProgramHandler::cleanMakefile();
}

void MainWindow::compile()
{
    std::cout <<"Compilation started\n" <<std::flush;

 //   t->start();
}

void MainWindow::runApp()
{
    if(compilationFinished || FileHandler::doesFileExist(filePath, 0))
    {
        std::cout <<"RunApp\n" <<std::flush;
        if(!isRestart) progHandler->startApp();
        isRestart = false;

    }else
    {
        if(compilationStarted) std::cout <<"Compilation started but not finished.\n" <<std::flush;
        else std::cout <<"Press compile button.\n" <<std::flush;
    }
}

void MainWindow::createMenus()
{
    menu = menuBar()->addMenu(tr("&Plik"));

    quitAction = new QAction(tr("&Wyjście"), this);
    quitAction->setStatusTip(tr("Wyjdź z programu."));
    connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    menu->addAction(quitAction);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Gotowy"));
}
