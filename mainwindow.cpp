#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

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

    series = new QLineSeries();
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Рост потребителей");
    chart->createDefaultAxes();
    ui->chartView->setChart(chart);

    // Инициализация графика для столбцов
    potentialBuyersSet = new QBarSet("Потенциальные покупатели");
    productUsersSet = new QBarSet("Покупатели");

    // Создаем столбчатый график и добавляем наборы данных
    QBarSeries *barSeries = new QBarSeries();
    barSeries->append(potentialBuyersSet);
    barSeries->append(productUsersSet);

    // Настраиваем график
    QChart *barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Рост потребителей");
    barChart->setAnimationOptions(QChart::SeriesAnimations);

    // Ось X - дни
    QStringList categories;
    for (int i = 0; i < 30; ++i) {
        categories << QString::number(i);
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    // Ось Y - количество пользователей
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 500); // Максимум 1000 потребителей
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
    environment->updateEnvironment(day);

    // Очищаем сцену и заново рисуем агентов
    scene->clear();
    int productUsers = 0;
    int potentialBuyers = 0;

    // Получаем цвет для новых агентов и пользователей продукта из комбобоксов
    QString agentColorName = ui->newAgentColor->currentText();
    QString productUserColorName = ui->newProductUserColor->currentText();

    // Конвертируем строки в цвета
    QColor agentColor(agentColorName);
    QColor productUserColor(productUserColorName);

    for (int i = 0; i < numberOfPeople; ++i) {
        QBrush brush(agentColor); // По умолчанию цвет для новых агентов

        if (environment->getAgentState(i) == Agent::PotentialBuyer) {
            scene->addEllipse(i*10 % 300, (i/30) * 10, 10, 10, QPen(), brush);
            potentialBuyers++;
        } else if(environment->getAgentState(i) == Agent::ProductUser) {
            brush.setColor(productUserColor);  // Цвет для пользователей продукта
            scene->addEllipse(i*10 % 300, (i/30) * 10, 10, 10, QPen(), brush);
            productUsers++;
        }
    }

    // Обновляем график количества пользователей продукта
    series->append(ui->numberOfIterations->value(), productUsers);

    // Обновляем график столбцов
    if (day < 30) { // Максимум 30 дней
        if (day <= current_day) {
            // Изменяем старые значения
            potentialBuyersSet->remove(day, current_day - day + 1);
            productUsersSet->remove(day, current_day - day + 1);
            potentialBuyersSet->append(potentialBuyers);
            productUsersSet->append(productUsers);
        } else if (day > current_day + 1){
            // Добавляем новые значения
            potentialBuyersSet->insert(day, potentialBuyers);
            productUsersSet->insert(day, productUsers);

        } else {
            potentialBuyersSet->append(potentialBuyers);
            productUsersSet->append(productUsers);
        }
    }
    current_day = day;

}

void MainWindow::on_createPopulation_clicked()
{
    int numberOfPeople = ui->numberOfPeople->value();
    int consumerPercentage = ui->consumerPercentage->value();
    int shelfLife = ui->shelfLife->value();
    environment = std::make_unique<Environment>(numberOfPeople, consumerPercentage, shelfLife);

    // Обнуляем данные для графиков, если они были инициализированы
    if (potentialBuyersSet) {
        potentialBuyersSet->remove(0, potentialBuyersSet->count()); // Удалить все значения
    } else {
        potentialBuyersSet = new QBarSet("Потенциальные покупатели");
    }

    if (productUsersSet) {
        productUsersSet->remove(0, productUsersSet->count()); // Удалить все значения
    } else {
        productUsersSet = new QBarSet("Покупатели");
    }
}

void MainWindow::on_startNewDay_clicked()
{
    updateScene(environment->getNumberOfPeople());
}


