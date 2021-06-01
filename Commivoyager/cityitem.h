#ifndef CITYITEM_H
#define CITYITEM_H

#include <QWidget>
#include <QPainter>



namespace Ui {
class cityitem;
}

class cityitem : public QWidget
{
    Q_OBJECT

public:
    explicit cityitem(QWidget *parent = 0);
    ~cityitem();

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void receiveData (int x);

signals:
    void firstwindow();
private slots:
    void on_back_clicked();
private:
    int n=1;
    Ui::cityitem *ui;
};

#endif // CITYITEM_H
