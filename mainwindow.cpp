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

void MainWindow::moveEvent(QMoveEvent * event)
{
    QPoint difPos = event->pos() - event->oldPos();
    int dx= difPos.x(),dy = difPos.y();
    QString textX = "NONE",textY = "NONE";

    if(dx>0 ) textX = "RIGHT";
    else if (dx < 0) textX = "LEFT";

    if(dy>0 ) textY = "UP";
    else if (dy < 0) textY = "DOWN";

    ui->label->setText(textX+"-"+textY);
    QMainWindow::moveEvent(event);
}
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    int keyCode = event->key();
    QRect position = this->geometry();
    switch(keyCode)
    {
    case Qt::Key_Up:
        position.translate(0,-10); break;
    case Qt::Key_Down:
        position.translate(0,10); break;
    case Qt::Key_Right:
        position.translate(10,0); break;
    case Qt::Key_Left:
        position.translate(-10,0); break;
    }
    this->setGeometry(position);
}
