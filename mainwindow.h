#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPointF>
#include <QCursor>
#include <QDebug>
#include <QPainter>
#include "scene.h"
#include "node.h"
//#include "edge.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;
    QGraphicsView *canvas;
    QHBoxLayout *hbox;
    QVBoxLayout *vbox;
    QPushButton *mst;
    QPushButton *clear;
};

#endif // MAINWINDOW_H
