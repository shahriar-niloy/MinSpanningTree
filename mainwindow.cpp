#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Window Settings
    this->setWindowTitle("Cable TV");
    this->resize(800, 600);
    //Button
    mst = new QPushButton("Solve it!");
    clear = new QPushButton("Clear");
    //Testing Scene Class
    scene *sc = new scene(this);
    //Layout
    vbox = new QVBoxLayout;
    hbox = new QHBoxLayout;
    //QGraphics
    //Scene = new QGraphicsScene(this);
    canvas = new QGraphicsView(this);
    canvas->setSceneRect(-300,-250,600,500);
    canvas->centerOn(0,0);
    canvas->setScene(sc);
    canvas->setRenderHints(QPainter::Antialiasing);
    sc->setViewPointer(canvas);
    //connect(sc, scene::mousePressEvent, sc, sc->draw);
    QObject::connect(MainWindow::mst, QPushButton::clicked, sc, sc->MST);
    QObject::connect(MainWindow::clear, QPushButton::clicked, sc, sc->clear);
    //Adding Widget
    hbox->addWidget(canvas);
    vbox->addWidget(mst);
    vbox->addWidget(clear);
    vbox->addStretch(10);
    hbox->addLayout(vbox);
    /*//Testing QPoint
    QPoint origin = canvas->mapFromGlobal(QCursor::pos());
    QPointF relative = canvas->mapToScene(origin);
    qDebug() << relative.rx() << " " << relative.ry() << endl;*/
    //Setting Layout
    this->setLayout(hbox);
}

MainWindow::~MainWindow()
{
    delete ui;
}
