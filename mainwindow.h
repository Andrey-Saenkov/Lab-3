#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <rect.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     void  paintEvent(QPaintEvent *event);
     void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QVector<Rect> rects[6];
    int cnt = 0;
    QPoint p;
};
#endif // MAINWINDOW_H
