#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_0_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "0";
    ui->Diplay->setText(label);
}


void MainWindow::on_Button_1_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "1";
    ui->Diplay->setText(label);
}


void MainWindow::on_Button_2_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "2";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_3_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "3";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_4_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "4";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_5_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "5";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_6_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "6";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_7_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "7";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_8_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "8";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_9_clicked()
{
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    QString label = ui->Diplay->text() + "9";
    ui->Diplay->setText(label);
}

void MainWindow::on_Button_dots_clicked()
{
    int counter=0;
    if(ui->Diplay->text() == "h : m : s"){
        ui->Diplay->setText("");
    }
    if(ui->Diplay->text() == ""){
        ui->Diplay->setText("00 : ");
    }
    QString check = ui->Diplay->text();
    for(int i=0;i<check.size(); i++){
        if(check[i]==':'){
            counter++;
        }
    }
    if(counter < 2){
        QString label = ui->Diplay->text() + " : ";
        ui->Diplay->setText(label);
        counter++;
    }
}


void MainWindow::on_Button_del_clicked()
{
    if(ui->Diplay->text()!=""){
        QString label = ui->Diplay->text();
        QString newlabel;
        for(int i=0; i<label.size()-1;i++){
            newlabel+=label[i];
        }
        ui->Diplay->setText(newlabel);
    }
}




void MainWindow::on_Button_ToHours_clicked()
{
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double hours = temp.toDouble();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double min = temp.toDouble();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double sec = temp.toDouble();
    temp="";
    hours=hours+min/60+sec/3600;
    label = QString::number(hours,'f',2) + " hours";
    ui->Diplay->setText(label);
}


void MainWindow::on_Button_ToMin_clicked()
{
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double hours = temp.toDouble();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double min = temp.toDouble();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double sec = temp.toDouble();
    temp="";
    min=hours*60+min+sec/60;
    label = QString::number(min,'f',2) + " minutes";
    ui->Diplay->setText(label);
}


void MainWindow::on_Button_ToSec_clicked()
{
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double hours = temp.toDouble();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double min = temp.toDouble();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    double sec = temp.toDouble();
    temp="";
    sec=hours*3600+min*60+sec;
    label = QString::number(sec,'f',0) + " seconds";
    ui->Diplay->setText(label);
}


void MainWindow::on_Button_TimeInterval_clicked()
{
    this->choice = "TimeInterval";
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->hours = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->min = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->sec = temp.toInt();
    temp="";
    if(this->hours>24 || this->min>59 || this->sec>59){
        if(this->hours>24){
            ui->Diplay->setText("Invalid data hours > 24");
        }
        if(this->min>59){
            ui->Diplay->setText("Invalid data minutes > 59");
        }
        if(this->sec>59){
            ui->Diplay->setText("Invalid data seconds > 59");
        }
    }else{
        ui->Diplay->setText("");
    }
}


void MainWindow::on_Button_history_clicked()
{
    ui->Diplay->setText("h : m : s");
}


void MainWindow::on_Button_add_clicked()
{
    this->choice = "Addition";
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->hours = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->min = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->sec = temp.toInt();
    temp="";
    ui->Diplay->setText("");
}


void MainWindow::on_Button_sub_clicked()
{
    this->choice = "Subtraction";
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->hours = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->min = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->sec = temp.toInt();
    temp="";
    ui->Diplay->setText("");
}


void MainWindow::on_Button_make_clicked()
{
    QString temp;
    QString label = ui->Diplay->text();
    int i=0;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->adhours = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->admin = temp.toInt();
    temp="";
    i+=3;
    while(label[i] >= 48 && label[i] <=57){
        temp=temp+label[i];
        i++;
    }
    this->adsec = temp.toInt();
    temp="";
    if(choice == "TimeInterval"){
        int ch=0,cm=0,cs=0;
        while(hours != adhours){
            if(hours==24){
                hours = 0;
            }
            hours++;
            ch++;
        }
        if(min>=admin){
            cm=min-admin;
        }else{
            cm=min+60-admin;
            ch--;
        }
        if(sec>=adsec){
            cs=sec-adsec;
        }else{
            cs=sec+60-adsec;
            cm--;
        }
        QString answer = QString::number(ch) + "h " + QString::number(cm) + "m " + QString::number(cs) + "s";
        ui->Diplay->setText(answer);
    }
    if(choice == "Addition"){
        hours = hours + adhours;
        min = min + admin;
        sec = sec + adsec;
        if(sec>59){
            min+= sec/60;
            sec=sec%60;
        }
        if(min>59){
            hours+= min/60;
            min=min%60;
        }
        QString answer = QString::number(hours) + "h " + QString::number(min) + "m " + QString::number(sec) + "s";
        ui->Diplay->setText(answer);
    }
    if(choice == "Subtraction"){
           if(hours > adhours){
               hours = hours - adhours;
               min = min - admin;
               sec = sec - adsec;
               if(min<0){
                   min+= 60;
                   hours--;
               }
               if(sec<0){
                   sec+=60;
                   min--;
               }
               QString answer = QString::number(hours) + "h " + QString::number(min) + "m " + QString::number(sec) + "s";
               ui->Diplay->setText(answer);
           }else{
               if((hours == adhours) && (min > admin)){
                   hours = 0;
                   min = min - admin;
                   sec = sec - adsec;
                   if(sec<0){
                       sec+=60;
                       min--;
                   }
                   QString answer = QString::number(hours) + "h " + QString::number(min) + "m " + QString::number(sec) + "s";
                   ui->Diplay->setText(answer);
               }else{
                   if((hours == adhours) && (min == admin) && (sec >= adsec)){
                       hours = 0;
                       min = 0;
                       sec = sec - adsec;
                       QString answer = QString::number(hours) + "h " + QString::number(min) + "m " + QString::number(sec) + "s";
                       ui->Diplay->setText(answer);
                   }else{
                       ui->Diplay->setText("Invalid data first data < second data");
                   }
               }
           }
    }
}

