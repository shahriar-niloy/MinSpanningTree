#include "edge.h"
#include <cmath>

edge::edge(double X1,double Y1, double X2,double Y2 ) : QGraphicsLineItem(X1,-Y1,X2,-Y2,0)
{
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
    weight = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    pen=new QPen;
    pen->setWidth(3);
  //pen->setColor();
    this->setPen(*pen);
}

