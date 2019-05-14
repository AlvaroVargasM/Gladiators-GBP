#include "statistics.h"
#include "ui_statistics.h"

#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsView>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QChartView>
#include <QGridLayout>
#include "genericlinkedlist.h"
#include <QtDebug>

QT_CHARTS_USE_NAMESPACE

Statistics::Statistics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);

    QPushButton *newGame = new QPushButton("New Game");
    QObject::connect(newGame, SIGNAL(clicked()), this, SLOT(newGame()));
    QPushButton *exit = new QPushButton("Exit");
    QObject::connect(exit, SIGNAL(clicked()), this, SLOT(exit()));

    newGame->setStyleSheet("QPushButton {background-color: #2B8B5B; color: white;}");
    exit->setStyleSheet("QPushButton {background-color: #262626; color: white;}");

    layout = new QGridLayout;
    layout->addWidget(newGame,2,0,1,1);
    layout->addWidget(exit,2,1,1,1);

    auto central = new QWidget;
    central->setLayout(layout);
    setCentralWidget(central);
}

void Statistics::setParent(QMainWindow *display)
{
    this->display=display;
}

void Statistics::generateCharts(GraphPac pack)
{
    int n = pack.get(1).getLength();
    qDebug() <<"Largo: "<<n;
    QChart *resChart = createChart("Resistance",n,
                                getSeries(pack.get(1),"AStar",QColor(138, 40, 40)),
                                getSeries(pack.get(2),"Backtracking",QColor(31,69,70)));
    QChartView *resistanceView = new QChartView(resChart);
    resistanceView->setRenderHint(QPainter::Antialiasing);

    QChart *intelChart = createChart("Intelligence",n,
                                     getSeries(pack.get(3),"AStar",QColor(138, 40, 40)),
                                     getSeries(pack.get(4),"Backtracking",QColor(31,69,70)));
    QChartView *intelView = new QChartView(intelChart);
    intelView->setRenderHint(QPainter::Antialiasing);

    QChart *condChart = createChart("Physical Condition",n,
                                    getSeries(pack.get(5),"AStar",QColor(138, 40, 40)),
                                    getSeries(pack.get(6),"Backtracking",QColor(31,69,70)));
    QChartView *conditionView = new QChartView(condChart);
    conditionView->setRenderHint(QPainter::Antialiasing);

    QChart *bodystrgChart = createChart("Strenght",n,
                                        getSeries(pack.get(7),"AStar Upper Body",QColor(203, 77, 77)),
                                        getSeries(pack.get(8),"AStar Lower Body",QColor(138, 40, 40)),
                                        getSeries(pack.get(9),"Backtracking Upper Body",QColor(70, 157, 160)),
                                        getSeries(pack.get(10),"Backtracking Lower Body",QColor(31,69,70)));
    QChartView *bodystrgView = new QChartView(bodystrgChart);
    bodystrgView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(resistanceView,0,0,1,1);
    layout->addWidget(intelView,0,1,1,1);
    layout->addWidget(conditionView,1,0,1,1);
    layout->addWidget(bodystrgView,1,1,1,1);
}

QLineSeries *Statistics::getSeries(GenericLinkedList<int> list, QString name, QColor color)
{
    QLineSeries *series = new QLineSeries();
    series->setName(name);
    QPen pen(color);
    pen.setWidth(3);
    series->setPen(pen);
    for(int i=0;i<list.getLength();i++){
        int value = list.get(i)->getData();
        series->append(QPoint(i,value));
    }
    return series;
}

QChart *Statistics::createChart(QString name, int generations, QLineSeries *data1,QLineSeries *data2)
{
    QChart *chart = new QChart();
    chart->setTitle(name);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(data1);
    chart->addSeries(data2);

    QStringList tags;
    for(int n=1;n<generations+1;n++)tags.append(QString::number(n));

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(tags);

    chart->addAxis(axisX, Qt::AlignBottom);
    data1->attachAxis(axisX);
    data2->attachAxis(axisX);

    axisX->setRange(tags.first(),tags.last());

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    data1->attachAxis(axisY);
    data2->attachAxis(axisY);

    chart->legend()->setAlignment(Qt::AlignBottom);
    return chart;
}

QChart *Statistics::createChart(QString name, int generations, QLineSeries *data1, QLineSeries *data2, QLineSeries *data3, QLineSeries *data4)
{
    QChart *chart = new QChart();
    chart->setTitle(name);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->addSeries(data1);
    chart->addSeries(data2);
    chart->addSeries(data3);
    chart->addSeries(data4);

    QStringList tags;
    for(int n=1;n<generations+1;n++)tags.append(QString::number(n));

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(tags);

    chart->addAxis(axisX, Qt::AlignBottom);
    data1->attachAxis(axisX);
    data2->attachAxis(axisX);
    data3->attachAxis(axisX);
    data4->attachAxis(axisX);

    axisX->setRange(tags.first(),tags.last());

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    data1->attachAxis(axisY);
    data2->attachAxis(axisY);
    data3->attachAxis(axisY);
    data4->attachAxis(axisY);

    chart->legend()->setAlignment(Qt::AlignBottom);
    return chart;
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::newGame()
{
    this->hide();
    display->show();
}

void Statistics::exit()
{
    this->close();
}
