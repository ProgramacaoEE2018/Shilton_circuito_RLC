#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<complex>
#include<vector>
#include"Classes_cirkt.h"
#include<ctgmath>

//verificar se o fasor de entrada está sendo lido de forma correta
//caso contrario a corrente é calculada errada e dps as tensoes tambem




//variaveis
int esc, i,cont=0;
char comp;
float A, B, C, W, valor,periodo;
double t = 0, saida,max_val_x,max_val_y,min_val_x,min_val_y,mod, angle;
float real, img;
complex<double> E1,s,I,fasor;
QVector<double> x_pts_E1,y_pts_E1,x_pts_Ec,y_pts_Ec,x_pts_Er,y_pts_Er,x_pts_Ei,y_pts_Ei ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    //APAGAR DADOS USADOS NA PLOTAGEM
    x_pts_E1.clear();
    x_pts_Er.clear();
    x_pts_Ec.clear();
    x_pts_Ei.clear();
    y_pts_E1.clear();
    y_pts_Er.clear();
    y_pts_Ec.clear();
    y_pts_Ei.clear();
    max_val_x=max_val_y=min_val_x=min_val_y=0;

    //LER VALORES DAS LINHAS DE EDIÇAO
    A = ui->lineA->text().toFloat();
    B = ui->lineB->text().toFloat();
    C = ui->lineC->text().toFloat();
    W = ui->lineW->text().toFloat();
    periodo = ui->lineTempo->text().toFloat();
    s = complex<double>(B, W); //variavel da funcao cirkt
    E1 = complex<double>(A, C);//fasor da fonte

    //CRIAÇAO DE OBJETOS
    Resistor R1(valor);
    R1.set_imp();

    Indutor L1(valor);
    L1.set_imp(s);

    Capacitor C1(valor);
    C1.set_imp(s);

    I = E1 / (R1.get_imp() + C1.get_imp() + L1.get_imp());//funçao do circuito
    Tensao Er(I, R1.get_imp());
    Tensao Ec(I, C1.get_imp());
    Tensao Ei(I, L1.get_imp());

    //ITERAÇAO COLETA DE DADOS
    for (t = 0; t <= periodo; t=t+((2*3.14)/(W*100))) {//sao calculadas 100 amostras no período do sinal
        saida = A * exp(B*t)*cos(W*t + C);
        if(max_val_x>t){max_val_x = t;}
        if(min_val_x<t){min_val_x = t;}
        if(max_val_y>saida){max_val_y = saida;}
        if(min_val_y<saida){min_val_y = saida;}
        x_pts_E1.push_back(t);
        y_pts_E1.push_back(saida);

    }
    for (t = 0; t <= periodo; t = t + ((2 * 3.14) / (W * 100))) {
        fasor = Er.get_valor();
        saida = abs(fasor) * exp(B*t)*cos(W*t + arg(fasor));//verificar formula
        if(max_val_x>t){max_val_x = t;}
        if(min_val_x<t){min_val_x = t;}
        if(max_val_y>saida){max_val_y = saida;}
        if(min_val_y<saida){min_val_y = saida;}
        x_pts_Er.push_back(t);
        y_pts_Er.push_back(saida);
    }
    for (t = 0; t <= periodo; t = t + ((2 * 3.14) / (W * 100))) {
        fasor = Ec.get_valor();
        saida = abs(fasor) * exp(B*t)*cos(W*t + arg(fasor));//verificar formula
        if(max_val_x>t){max_val_x = t;}
        if(min_val_x<t){min_val_x = t;}
        if(max_val_y>saida){max_val_y = saida;}
        if(min_val_y<saida){min_val_y = saida;}
        x_pts_Ec.push_back(t);
        y_pts_Ec.push_back(saida);
    }
    for (t = 0; t <= periodo; t = t + ((2 * 3.14) / (W * 100))) {
        fasor = Ei.get_valor();
        saida = abs(fasor) * exp(B*t)*cos(W*t + arg(fasor));//verificar formula
        if(max_val_x>t){max_val_x = t;}
        if(min_val_x<t){min_val_x = t;}
        if(max_val_y>saida){max_val_y = saida;}
        if(min_val_y<saida){min_val_y = saida;}
        x_pts_Ei.push_back(t);
        y_pts_Ei.push_back(saida);
    }

    MainWindow::makePlot();
}

void MainWindow::makePlot(){
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x_pts_E1,y_pts_E1);

    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(x_pts_Er,y_pts_Er);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));

    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setData(x_pts_Ec,y_pts_Ec);
    ui->customPlot->graph(2)->setPen(QPen(Qt::green));

    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setData(x_pts_Ei,y_pts_Ei);
    ui->customPlot->graph(3)->setPen(QPen(Qt::yellow));

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("Tempo");
    ui->customPlot->yAxis->setLabel("Tensao");

    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->customPlot->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    ui->customPlot->graph(1)->rescaleAxes(true);
    ui->customPlot->graph(2)->rescaleAxes(true);
    ui->customPlot->graph(3)->rescaleAxes(true);
    ui->customPlot->replot();
}


