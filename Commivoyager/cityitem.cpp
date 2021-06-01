#include "cityitem.h"
#include "ui_cityitem.h"
#include <QtMath>

cityitem::cityitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cityitem)
{
    ui->setupUi(this);


}


cityitem::~cityitem()
{
    delete ui;
}

void cityitem::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

        int x=-200,y;
        int r = 200;
        int len=400/(n/2);
        int **citycords = new int*[n];
        for(int i=0;i<n;i++){
            citycords[i] = new int[2];
        }
        int k=0;
        for(int i=0; i<n/2;i++){
            y=qSqrt(r*r-x*x);
            citycords[k][0] = 275-x;
            citycords[k][1] = 300-y;
            k++;
            x+=len;
        }
        x=200;
        if(n%2==0){
            for(int i=0; i<n/2;i++){
                y=qSqrt(r*r-x*x)*-1;
                citycords[k][0] = 275-x;
                citycords[k][1] = 300-y;
                k++;
                x-=len;
            }
        }else{
            len=400/(n/2+1);
            for(int i=0; i<n/2+1;i++){
                y=qSqrt(r*r-x*x)*-1;
                citycords[k][0] = 275-x;
                citycords[k][1] = 300-y;
                k++;
                x-=len;
            }
        }
        for(int i=0; i<n;i++){
           for(int j=0; j<n;j++){
               if(j!=i){
                   QPen pen(Qt::black, 2, Qt::SolidLine);
                   painter.setPen(pen);
                   painter.drawLine(citycords[i][0]+25, citycords[i][1]+25, citycords[j][0]+25, citycords[j][1]+25);
               }
           }
        }
        for(int i=0; i<n;i++){
            QPen pen1(Qt::black, 1, Qt::SolidLine);
            painter.setPen(pen1);
            painter.setBrush(QBrush(QColor(159,186,199,255), Qt::SolidPattern));
            painter.drawEllipse(citycords[i][0], citycords[i][1], 50, 50);
            painter.setFont(QFont(QString::number(i+1),14));
            QPen pen2(QColor(138,69,153,255), 2, Qt::SolidLine);
            painter.setPen(pen2);
            painter.drawText(citycords[i][0]+15, citycords[i][1]+30, QString::number(i+1));
        }
}


void cityitem::receiveData(int x){
    n=x;
}

void cityitem::on_back_clicked()
{
    this->close();
    emit firstwindow();
}
