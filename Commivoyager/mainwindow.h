#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cityitem.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     int n=5;

signals:
     void sendData (int n);
private slots:
    void on_Create_clicked();

    void on_Answer_clicked();
    void on_Visual_clicked();
    void on_Accept_clicked();

    void on_Accept_2_clicked();

private:
    Ui::MainWindow *ui;
    float ans;
    cityitem *graph;
};
#endif // MAINWINDOW_H
