#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newAgentColor->addItem("Red");
    ui->newAgentColor->addItem("Yellow");
    ui->newAgentColor->addItem("Green");
    ui->newAgentColor->addItem("Blue");
    ui->newProductUserColor->addItem("Red");
    ui->newProductUserColor->addItem("Yellow");
    ui->newProductUserColor->addItem("Green");
    ui->newProductUserColor->addItem("Blue");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    potentialBuyersSet = new QBarSet("Потенциальные покупатели");
    productUsersSet = new QBarSet("Покупатели");

    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(potentialBuyersSet);
    barSeries->append(productUsersSet);

    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Рост потребителей");
    barChart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (int i = 0; i < 30; ++i) {
        categories << QString::number(i);
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 500);
    axisY->setTickCount(11);
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    ui->chartView->setChart(barChart);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScene(int numberOfPeople) {
    int day = ui->numberOfIterations->value();
    int currentDay = environment->getCurrentDay();
    environment->updateEnvironment(day);

    int productUsers = 0;
    int potentialBuyers = 0;

    QString agentColorName = ui->newAgentColor->currentText();
    QString productUserColorName = ui->newProductUserColor->currentText();


    QColor agentColor(agentColorName);
    QColor productUserColor(productUserColorName);

    for (int i = 0; i < numberOfPeople; ++i) {
        QBrush brush(agentColor);

        if (environment->getAgentState(i) == Agent::PotentialBuyer) {
            scene->addEllipse(i*10 % 300, (i/30) * 10, 10, 10, QPen(), brush);
            potentialBuyers++;
        } else if(environment->getAgentState(i) == Agent::ProductUser) {
            brush.setColor(productUserColor);
            scene->addEllipse(i*10 % 300, (i/30) * 10, 10, 10, QPen(), brush);
            productUsers++;
        }
    }

    if (day < 30) {
        if (day <= currentDay) {
            currentDay = day;
            potentialBuyersSet->remove(0, potentialBuyersSet->count());
            productUsersSet->remove(0, productUsersSet->count());
            for(int i = 0; i <= currentDay; ++i){
                potentialBuyers = environment->getBase()[i].first;
                productUsers = environment->getBase()[i].second;
                potentialBuyersSet->append(potentialBuyers);
                productUsersSet->append(productUsers);
            }
        } else if (day > currentDay + 1){
            for(int i = currentDay + 1; i <= day; ++i){
                potentialBuyers = environment->getBase()[i].first;
                productUsers = environment->getBase()[i].second;
                potentialBuyersSet->append(potentialBuyers);
                productUsersSet->append(productUsers);
            }
        } else {
            potentialBuyersSet->append(potentialBuyers);
            productUsersSet->append(productUsers);
        }
    }
}

void MainWindow::on_createPopulation_clicked()
{
    int numberOfPeople = ui->numberOfPeople->value();
    int consumerPercentage = ui->consumerPercentage->value();
    int shelfLife = ui->shelfLife->value();
    environment = std::make_unique<Environment>(numberOfPeople, consumerPercentage, shelfLife);

    if (potentialBuyersSet) {
        potentialBuyersSet->remove(0, potentialBuyersSet->count());
    } else {
        potentialBuyersSet = new QBarSet("Потенциальные покупатели");
    }

    if (productUsersSet) {
        productUsersSet->remove(0, productUsersSet->count());
    } else {
        productUsersSet = new QBarSet("Покупатели");
    }

}

void MainWindow::on_startNewDay_clicked()
{
    if (!environment) {
        QMessageBox::warning(this, "Ошибка", "Сначала создайте популяцию.");
        return;
    }

    updateScene(environment->getNumberOfPeople());
}

