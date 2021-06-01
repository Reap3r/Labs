#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <algorithm>
#include <cmath>

int maxi=20;
float inf = 1e10;
QVector<int> path;
QVector<QVector<float> >d((1 << maxi), QVector<float>(maxi));
void findway(QVector<QVector<float> > g,int n)
{
    int k = 0;
    int mask = (1 << n) - 1;
    path.push_back(0);
    while (mask != 0)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[k][j])
                if ((mask & (1 << j)))
                    if (d[mask][k] == g[k][j] + d[mask ^ (1 << j)][j])
                    {
                        path.push_back(j);
                        k = j;
                        mask = mask ^ (1 << j);
                    }
        }
    }
}

float findcheapest(int i, int mask, QVector<QVector<float> > g, int n)
{
    if (d[mask][i] != inf)
    {
        return d[mask][i];
    }
    for (int j = 0; j < n; j++)
    {
        if (g[i][j])
            if ((mask & (1 << j)))
            {

                d[mask][i] = qMin(d[mask][i], findcheapest(j, mask - (1<<j), g,n) + g[i][j]);
            }
    }
    return d[mask][i];
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graph = new cityitem();
    connect(graph, &cityitem::firstwindow, this, &MainWindow::show);
    connect(this, SIGNAL(sendData(int)), graph, SLOT(recievData(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Create_clicked()
{
    ui->Check->hide();
    int size= ui->City->text().toInt();
    ui->LinksTable->setRowCount(size);
    ui->LinksTable->setColumnCount(size);
    QString temp = "";
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            ui->LinksTable->setItem(i,j,new QTableWidgetItem(temp));
        }
    }
    temp = "0";
    for(int i=0; i<size;i++){
        ui->LinksTable->setColumnWidth(i,1);
        ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
    }

    n=size;
    ui->Display->setText("Fill the table and press answer or visualising");
}

void MainWindow::on_Answer_clicked()
{
    bool check1 = true, check2 = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(ui->LinksTable->item(i,j)->text() == ""){
                check1 = false;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(ui->LinksTable->item(i,i)->text() != "0"){
            check2 = false;
        }
    }
    if(check1 && check2){
    QVector<QVector<float> > g(n, QVector<float>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            g[i][j] = ui->LinksTable->item(i,j)->text().toFloat();
        }
    }
    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            d[mask][i] = inf;
        }
    }
    d[0][0] = 0;
    ans = findcheapest(0, (1<<n) - 1, g,n);
    findway(g,n);

    for (int i = 0; i < n; i++){
        path[i]+=1;
    }
    QString answer;
    for (int i = 0; i < n; i++){

        answer = answer + QString::number(path[i]) + " -> ";
    }
    answer+='1';
    answer = answer + "   length = " + QString::number(ans);
    ui->Display->setText(answer);
    }else{
        if(!check1){
            ui->Display->setText("Don't leave empty cells");
        }else{
            ui->Display->setText("Don't make road between the same city");
        }

    }
}




void MainWindow::on_Visual_clicked()
{
   graph->show();
   graph->receiveData(n);
}


void MainWindow::on_Accept_clicked()
{
    n+=1;
    ui->LinksTable->setRowCount(n);
    ui->LinksTable->setColumnCount(n);
    QString temp = "0";
    for(int i=0; i<n;i++){
        ui->LinksTable->setColumnWidth(i,1);
        ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
    }
    ui->City->setText(QString::number(n));
}


void MainWindow::on_Accept_2_clicked()
{
    n-=1;
    ui->LinksTable->setRowCount(n);
    ui->LinksTable->setColumnCount(n);
    QString temp = "0";
    for(int i=0; i<n;i++){
        ui->LinksTable->setColumnWidth(i,1);
        ui->LinksTable->setItem(i,i,new QTableWidgetItem(temp));
    }
    ui->City->setText(QString::number(n));
}

