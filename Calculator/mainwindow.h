#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int hours;
    int adhours;
    int min;
    int admin;
    int sec;
    int adsec;
    QString choice;
private slots:

    void on_Button_0_clicked();
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_Button_dots_clicked();
    void on_Button_del_clicked();
    void on_Button_ToHours_clicked();
    void on_Button_ToMin_clicked();
    void on_Button_ToSec_clicked();
    void on_Button_TimeInterval_clicked();
    void on_Button_history_clicked();
    void on_Button_add_clicked();
    void on_Button_sub_clicked();
    void on_Button_make_clicked();
};
#endif // MAINWINDOW_H
