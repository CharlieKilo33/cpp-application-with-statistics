/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *createPopulation;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QSpinBox *numberOfIterations;
    QPushButton *startNewDay;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpinBox *shelfLife;
    QLabel *label_5;
    QComboBox *newProductUserColor;
    QLabel *label_2;
    QSpinBox *numberOfPeople;
    QLabel *label_6;
    QComboBox *newAgentColor;
    QLabel *label_7;
    QSpinBox *consumerPercentage;
    QChartView *chartView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1462, 733);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 671, 491));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(verticalLayoutWidget_2);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        createPopulation = new QPushButton(verticalLayoutWidget_2);
        createPopulation->setObjectName("createPopulation");

        verticalLayout->addWidget(createPopulation);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        numberOfIterations = new QSpinBox(verticalLayoutWidget_2);
        numberOfIterations->setObjectName("numberOfIterations");
        numberOfIterations->setMaximum(20);

        horizontalLayout_2->addWidget(numberOfIterations);


        verticalLayout->addLayout(horizontalLayout_2);

        startNewDay = new QPushButton(verticalLayoutWidget_2);
        startNewDay->setObjectName("startNewDay");

        verticalLayout->addWidget(startNewDay);


        verticalLayout_2->addLayout(verticalLayout);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(680, 10, 781, 701));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 10, 1, 1, 1);

        shelfLife = new QSpinBox(verticalLayoutWidget_3);
        shelfLife->setObjectName("shelfLife");
        shelfLife->setMaximum(30);

        gridLayout->addWidget(shelfLife, 12, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        newProductUserColor = new QComboBox(verticalLayoutWidget_3);
        newProductUserColor->setObjectName("newProductUserColor");

        gridLayout->addWidget(newProductUserColor, 14, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 12, 1, 1, 1);

        numberOfPeople = new QSpinBox(verticalLayoutWidget_3);
        numberOfPeople->setObjectName("numberOfPeople");
        numberOfPeople->setMaximum(500);

        gridLayout->addWidget(numberOfPeople, 5, 0, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 13, 1, 1, 1);

        newAgentColor = new QComboBox(verticalLayoutWidget_3);
        newAgentColor->setObjectName("newAgentColor");
        newAgentColor->setEditable(false);

        gridLayout->addWidget(newAgentColor, 13, 0, 1, 1);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 14, 1, 1, 1);

        consumerPercentage = new QSpinBox(verticalLayoutWidget_3);
        consumerPercentage->setObjectName("consumerPercentage");
        consumerPercentage->setMaximum(100);

        gridLayout->addWidget(consumerPercentage, 10, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        chartView = new QChartView(verticalLayoutWidget_3);
        chartView->setObjectName("chartView");

        verticalLayout_3->addWidget(chartView);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\260 \320\276\320\261\320\270\321\202\320\260\320\275\320\270\321\217", nullptr));
        createPopulation->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\320\276\320\277\321\203\320\273\321\217\321\206\320\270\321\216", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\275\321\214 \320\264\320\273\321\217 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260 \320\263\321\200\320\260\321\204\320\270\320\272\320\276\320\262: ", nullptr));
        startNewDay->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272\320\270 \320\267\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\277\320\276\321\202\321\200\320\265\320\261\320\270\321\202\320\265\320\273\320\265\320\271 \320\262 \320\264\320\265\320\275\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \320\273\321\216\320\264\320\265\320\271 \320\262 \320\277\320\276\320\277\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272 \321\201\320\276\321\205\321\200\320\260\320\275\320\275\320\276\321\201\321\202\320\270 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260 \320\262 \320\264\320\275\321\217\321\205", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\262\320\275\320\276\320\262\321\214 \321\201\320\276\320\267\320\264\320\260\320\275\320\275\320\276\320\271 \320\276\321\201\320\276\320\261\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\277\320\276\321\202\321\200\320\265\320\261\320\270\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
