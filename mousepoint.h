#ifndef MOUSEPOINT_H
#define MOUSEPOINT_H
#include <QPointF>

class mousePoint
{
public:
    QPointF lastPressPoint;
    QPointF lastReleasePoint;
    mousePoint();
};

#endif // MOUSEPOINT_H
