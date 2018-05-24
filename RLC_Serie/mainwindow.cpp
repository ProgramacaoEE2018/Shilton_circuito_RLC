#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//ideia: se o usuario nao inserir algum parametra o programa deve retornar alerta
MainWindow::~MainWindow()
{
    delete ui;
}
