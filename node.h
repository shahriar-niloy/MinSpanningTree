#ifndef NODE_H
#define NODE_H
#include <QGraphicsEllipseItem>
#include <QString>
#include <QPen>
#include <QBrush>
#include <QDebug>
#include "edge.h"
#define nodeRadius 35

extern int num;

class Node : public QGraphicsEllipseItem{
private:
    QBrush brush;
    QPen pen;
    QPointF releasePoint;
public:
    double x;
    double y;
    QGraphicsScene * scenePointer;
    QString name;
    QGraphicsTextItem *label;
    Node(double X, double Y, QGraphicsItem *parent = 0, double wid = nodeRadius, double heig = nodeRadius);
    void addEdge(double x, double y);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setScenePointer(QGraphicsScene * s);
};

#endif // NODE_H
