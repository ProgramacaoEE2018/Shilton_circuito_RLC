/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineA;
    QLineEdit *lineB;
    QLabel *label_2;
    QLineEdit *lineC;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineW;
    QLabel *label_7;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QCustomPlot *graph_fonte;
    QCustomPlot *graph_capacitor;
    QCustomPlot *graph_resistor;
    QCustomPlot *graph_indutor;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_8;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_13;
    QLabel *label_9;
    QLineEdit *lineA_2;
    QLabel *label_10;
    QLineEdit *lineB_2;
    QLabel *label_11;
    QLineEdit *lineC_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1197, 580);
        MainWindow->setMaximumSize(QSize(1197, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 220, 171, 231));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineA = new QLineEdit(formLayoutWidget);
        lineA->setObjectName(QStringLiteral("lineA"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineA);

        lineB = new QLineEdit(formLayoutWidget);
        lineB->setObjectName(QStringLiteral("lineB"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineB);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineC = new QLineEdit(formLayoutWidget);
        lineC->setObjectName(QStringLiteral("lineC"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineC);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        lineW = new QLineEdit(formLayoutWidget);
        lineW->setObjectName(QStringLiteral("lineW"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineW);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_7);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(514, 166, 651, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graph_fonte = new QCustomPlot(widget);
        graph_fonte->setObjectName(QStringLiteral("graph_fonte"));

        gridLayout_2->addWidget(graph_fonte, 0, 0, 1, 1);

        graph_capacitor = new QCustomPlot(widget);
        graph_capacitor->setObjectName(QStringLiteral("graph_capacitor"));

        gridLayout_2->addWidget(graph_capacitor, 0, 1, 1, 1);

        graph_resistor = new QCustomPlot(widget);
        graph_resistor->setObjectName(QStringLiteral("graph_resistor"));

        gridLayout_2->addWidget(graph_resistor, 1, 0, 1, 1);

        graph_indutor = new QCustomPlot(widget);
        graph_indutor->setObjectName(QStringLiteral("graph_indutor"));

        gridLayout_2->addWidget(graph_indutor, 1, 1, 1, 1);


        gridLayout->addWidget(widget, 2, 0, 1, 2);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(610, 40, 451, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 470, 93, 28));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 10, 401, 196));
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(260, 220, 171, 231));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, label_13);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        lineA_2 = new QLineEdit(formLayoutWidget_2);
        lineA_2->setObjectName(QStringLiteral("lineA_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineA_2);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_10);

        lineB_2 = new QLineEdit(formLayoutWidget_2);
        lineB_2->setObjectName(QStringLiteral("lineB_2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineB_2);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_11);

        lineC_2 = new QLineEdit(formLayoutWidget_2);
        lineC_2->setObjectName(QStringLiteral("lineC_2"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineC_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1197, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "A", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "B", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "C", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "W", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Par\303\242metros da Fonte:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Sinal de Entrada:</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">e(t) = </span><span style=\" font-size:14pt; text-decoration: underline;\">A</span><span style=\" font-size:14pt;\">*exp(</span><span style=\" font-size:14pt; text-decoration: underline;\">B</span><span style=\" font-size:14pt;\">*t)cos(</span><span style=\" font-size:14pt; text-decoration: underline;\">W</span><span style=\" font-size:14pt;\">*t+</span><span style=\" font-size:14pt; text-decoration: underline;\">C</span><span style=\" font-size:14pt;\">)</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Rodar", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/img/img/400px-RLC_serie.PNG\"/></p></body></html>", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Par\303\242metros do Circuito:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "R(\342\204\246)", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "C(F)", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "L(H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
