#ifndef EDGE_H
#define EDGE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QPen>

class edge : public QGraphicsLineItem
{
private:
    double x1,y1,x2,y2;
    QPen *pen;
public:
    double weight;
    int node1;
    int node2;
    edge(double X1,double Y1, double X2,double Y2);
};

#endif // EDGE_H
