#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include <QPainter>

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

void MainWindow::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);
//    Rect rect(5, 5, 100, 200);
//    rect.draw(&painter);
    QPainter painter(this);
    for (int i = 0; i < 6; i++){
        for(Rect r: rects[i])
            r.draw(&painter, i);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->modifiers()&Qt::ControlModifier){
        cnt++;
        if(cnt % 2 == 1)
            p = event->pos();
        else
            rects[0].append(Rect(p.x(), p.y(), event->x(), event->y()));
    }
    else {
        //for (int i = 0; i < rect.size(); i++) это прямолинейный способ
        QVector <Rect> hits;
        for(Rect r:rects[0]){
            if (r.contains(event->x(), event->y()))
                hits.append(r);
        }
        if (hits.size() > 1){
            Rect rx = hits[0];
            for (int i = 1; i < hits.size(); i++)
                rx = rx.InterSection(hits[i]);
            int n = hits.size();
            rects[n - 1].append(rx);
        }
    }

    repaint();
}
