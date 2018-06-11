#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<complex>
#include<vector>
#include"Classes_cirkt.h"
#include<ctgmath>
#include<QMessageBox>


//upgrade: sincronizar selecao legenda e grafico;
//         criar arrasto da legenda;


//variaveis
int esc, i,cont=0;
char comp;
float A, B, C, W, valor,periodo,R,Cap,L;
double t = 0, saida,mod, angle;
float real, img;
complex<double> E1,s,I,fasor;
QVector<double> x_pts_E1,y_pts_E1,x_pts_Ec,y_pts_Ec,x_pts_Er,y_pts_Er,x_pts_Ei,y_pts_Ei ;
double pi = 3.14159265359;

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

    //APAGAR DADOS USADOS NA PLOTAGEM PARA REALIMENTACAO
    x_pts_E1.clear();
    x_pts_Er.clear();
    x_pts_Ec.clear();
    x_pts_Ei.clear();
    y_pts_E1.clear();
    y_pts_Er.clear();
    y_pts_Ec.clear();
    y_pts_Ei.clear();
    ui->customPlot->clearPlottables();




    //LER VALORES DAS LINHAS DE EDIÇAO
    A = ui->lineA->text().toFloat();
    B = ui->lineB->text().toFloat();
    C = (ui->lineC->text().toFloat())*pi/180;//variavel C em rad, entrada em graus
    W = ui->lineW->text().toFloat();
    R = ui->lineRes->text().toFloat();
    Cap = ui->lineCap->text().toFloat();
    L= ui->lineL->text().toFloat();
    periodo = ui->lineTempo->text().toFloat();
    s = complex<double>(B, W); //variavel da funcao cirkt
    E1 = complex<double>(A*cos(C),A*sin(C));//fasor da fonte


    //ALERTA ERRO NA ENTRADA
     QMessageBox msgAlerta;
    if(ui->lineA->text().isEmpty() == false && A == 0){
        msgAlerta.setText("Fasor de Modulo Nulo.\nFavor inserir outro valor.");
        msgAlerta.exec();

    }
    if(W == 0 && A!=0){
        msgAlerta.setText("Desculpe!\nFormato de sinal nao suportado.\n Aguarde a proxima versao!");
        msgAlerta.exec();
    }
    if(ui->lineA->text().isEmpty() || ui->lineW->text().isEmpty() || ui->lineRes->text().isEmpty()|| ui->lineCap->text().isEmpty()|| ui->lineL->text().isEmpty()|| ui->lineTempo->text().isEmpty()){
        msgAlerta.setText("Campos obrigatorios: A, W, R, C, I, Tempo");
        msgAlerta.exec();
    }


    //IMPRIMIR SINAL
    QString messageSignal = QString("%1 * exp(%2*t)*cos(%3*t + %4)").arg(A).arg(B).arg(W).arg(C);
    ui->label_15->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->label_15->setTextFormat(Qt::RichText);
    ui->label_15->setText(messageSignal);
    ui->label_15->setAlignment(Qt::AlignBottom | Qt::AlignCenter);

    //CRIAÇAO DE OBJETOS
    Resistor R1(R);
    R1.set_imp();

    Indutor L1(Cap);
    L1.set_imp(s);

    Capacitor C1(L);
    C1.set_imp(s);

    I = E1 / (R1.get_imp() + C1.get_imp() + L1.get_imp());//funçao do circuito
    Tensao Er(I, R1.get_imp());
    Tensao Ec(I, C1.get_imp());
    Tensao Ei(I, L1.get_imp());

    //ITERAÇAO COLETA DE DADOS
    for (t = 0; t <= periodo; t=t+((2*pi)/(W*100))) {//sao calculadas 100 amostras no período do sinal
        saida = A * exp(B*t)*cos(W*t + C);
        x_pts_E1.push_back(t);
        y_pts_E1.push_back(saida);
    }
    for (t = 0; t <= periodo; t = t + ((2 * pi) / (W * 100))) {
        fasor = Er.get_valor();
        saida = abs(fasor) * exp(B*t)*cos(W*t + arg(fasor));
        x_pts_Er.push_back(t);
        y_pts_Er.push_back(saida);
    }
    for (t = 0; t <= periodo; t = t + ((2 * pi) / (W * 100))) {
        fasor = Ec.get_valor();
        saida = abs(fasor) * exp(B*t)*cos(W*t + arg(fasor));
        x_pts_Ec.push_back(t);
        y_pts_Ec.push_back(saida);
    }
    for (t = 0; t <= periodo; t = t + ((2 * pi) / (W * 100))) {
        fasor = Ei.get_valor();
        saida = abs(fasor) * exp(B*t)*cos(W*t + arg(fasor));
        x_pts_Ei.push_back(t);
        y_pts_Ei.push_back(saida);
    }

    MainWindow::makePlot();

}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("1 - Insira valores desejados nos campos indicados;\n"
                   "2 - Utilize o Mouse Whell para ampliar ou diminuir o grafico;\n"
                   "3 - Arraste os eixos para ampliar ou diminir apenas uma dimensao;\n"
                   "4 - Clique com Botão Direito sobre o grafico, curvas ou legenda para opcoes;\n"
                   "5 - Insira novos valores e clique em Rodar para plotar novos sinais."
                   );
    msgBox.exec();
}
void MainWindow::makePlot(){


    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x_pts_E1,y_pts_E1);
    ui->customPlot->graph(0)->setPen(QPen(Qt::magenta));

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

    //legend
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica", 9));
    ui->customPlot->graph(0)->setName("E(t)");
    ui->customPlot->graph(1)->setName("Vr(t)");
    ui->customPlot->graph(2)->setName("Vc(t)");
    ui->customPlot->graph(3)->setName("Vi(t)");

    ui->customPlot->replot();

    //interacao com usuario
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);

    // connect slots that takes care that when an axis is selected, only that direction can be dragged and zoomed:
    connect(ui->customPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(ui->customPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

    // make bottom and left axes transfer their ranges to top and right axes:
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // connect some interaction slots:
    connect(ui->customPlot, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));

    // connect slot that shows a message in the status bar when a graph is clicked:
    connect(ui->customPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));

    // setup policy and connect slot for context menu popup:
    ui->customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));

}
void MainWindow::moveLegend()
{
  if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
  {
    bool ok;
    int dataInt = contextAction->data().toInt(&ok);
    if (ok)
    {
      ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
      ui->customPlot->replot();
    }
  }
}
void MainWindow::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
  // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
  // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
  double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
  double dataKey = plottable->interface1D()->dataMainKey(dataIndex);
  QString message = QString("Grafico '%1' : (%2s ; %3V)").arg(plottable->name()).arg(dataKey).arg(dataValue);
  ui->label_14->setText(message);
}
void MainWindow::contextMenuRequest(QPoint pos)
{
  QMenu *menu = new QMenu(this);
  menu->setAttribute(Qt::WA_DeleteOnClose);

  if (ui->customPlot->legend->selectTest(pos, false) >= 0) // context menu on legend requested
  {
    menu->addAction("Move to top left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
    menu->addAction("Move to top center", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
    menu->addAction("Move to top right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
    menu->addAction("Move to bottom right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
    menu->addAction("Move to bottom left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
  } else  // general context menu on graphs requested
  {

    if (ui->customPlot->selectedGraphs().size() > 0)
      menu->addAction("Remove selected graph", this, SLOT(removeSelectedGraph()));
    if (ui->customPlot->graphCount() > 0)
      menu->addAction("Remove all graphs", this, SLOT(removeAllGraphs()));
  }

  menu->popup(ui->customPlot->mapToGlobal(pos));
}
void MainWindow::removeSelectedGraph()
{
  if (ui->customPlot->selectedGraphs().size() > 0)
  {
    ui->customPlot->removeGraph(ui->customPlot->selectedGraphs().first());
    ui->customPlot->replot();
  }
}
void MainWindow::removeAllGraphs()
{
  ui->customPlot->clearGraphs();
  ui->customPlot->replot();
}
void MainWindow::mouseWheel()
{
  // if an axis is selected, only allow the direction of that axis to be zoomed
  // if no axis is selected, both directions may be zoomed

  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->xAxis->orientation());
  else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeZoom(ui->customPlot->yAxis->orientation());
  else
    ui->customPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}
void MainWindow::mousePress()
{
  // if an axis is selected, only allow the direction of that axis to be dragged
  // if no axis is selected, both directions may be dragged

  if (ui->customPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->xAxis->orientation());
  else if (ui->customPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    ui->customPlot->axisRect()->setRangeDrag(ui->customPlot->yAxis->orientation());
  else
    ui->customPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}
void MainWindow::selectionChanged()
{
  // synchronize selection of graphs with selection of corresponding legend items:
  for (int i=0; i<ui->customPlot->graphCount(); ++i)
  {
    QCPGraph *graph = ui->customPlot->graph(i);
    QCPPlottableLegendItem *item = ui->customPlot->legend->itemWithPlottable(graph);
    if (item->selected() || graph->selected())
    {
      item->setSelected(true);
      graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
    }
  }
}





