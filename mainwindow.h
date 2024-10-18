#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "environment.h"
#include "qbarset.h"
#include <memory>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateScene(int numberOfPeople);


    void on_createPopulation_clicked();

    void on_startNewDay_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    std::unique_ptr<Environment> environment;
    QBarSet *potentialBuyersSet;
    QBarSet *productUsersSet;
    QLineSeries *series;
    int current_day = 0;
};
#endif // MAINWINDOW_H
