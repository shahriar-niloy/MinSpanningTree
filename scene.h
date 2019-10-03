#ifndef SCENE_H
#define SCENE_H
#include <QEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <utility>
#include "node.h"
#include "mst.h"

extern std::vector<Node*> NodeList;
//extern std::vector<edge*> edgeList;

class scene : public QGraphicsScene
{
private:
    QPointF lastPressPoint;
    QPointF lastReleasePoint;
    QGraphicsView *v;
public:
    scene(QObject *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    Node *searchNode(QPointF pos);
public slots:
    Node *drawNode(QPointF pos);
    edge *drawEdge(QPointF pos1, QPointF pos2);
    QPointF getLastPressPoint();
    QPointF getLastRealesePoint();
    void MST();
    void MST_Show();
    void clear();
    void setViewPointer(QGraphicsView *view);
};

#endif // SCENE_H
