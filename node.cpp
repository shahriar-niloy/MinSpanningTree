#include "node.h"
#include "scene.h"

Node::Node(double X, double Y, QGraphicsItem *parent, double wid, double heig) : QGraphicsEllipseItem(X-wid/2, -Y-heig/2, wid, heig, parent)
{
    x = X;
    y = -Y;
    name = QString::number(num);
    num++;
    //this->setTransformOriginPoint(-wid/2,-heig/2);
    pen.setColor(Qt::black);
    pen.setWidth(3);
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    label = new QGraphicsTextItem(name, this);
    label->setPos(x-wid/3,y-heig/3);
    label->setDefaultTextColor(Qt::black);
    //label->setScale(.60);
    label->setTextWidth(5);
    this->setPen(pen);
    this->setBrush(brush);
}

void Node::addEdge(double x, double y)
{
    qDebug() << "In addEdge" << endl;
    QPointF p1 = QPointF(this->x, this->y); //P1->PressNodePoint();
    QPointF p2 = QPointF(x,y);//p2->ReleaseNodePoint();
    edge *ed = new edge(p1.rx(), -p1.ry(), p2.rx(), -p2.ry());
    ed->setZValue(-1);
    scenePointer->addItem(ed);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF p = event->scenePos();
    qDebug() << "You clicked " << this->name << " " << p.rx() << " " << p.ry();
    event->accept();
    //QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //update();
    this->releasePoint = event->scenePos();
    qDebug() << "You released " << this->name << "  " << releasePoint.rx() << " " << releasePoint.ry();

    QList<QGraphicsItem *> list;
    if(scenePointer->itemAt(this->releasePoint, QTransform()) != 0){
        list = scenePointer->items(releasePoint, Qt::IntersectsItemShape, Qt::AscendingOrder, QTransform());
        //List is not empty, meaning that there is something! Next condition checks wheather this node is there at the list
        if(list.isEmpty() == 0 && list.indexOf(this) == -1){
            QGraphicsItem *temp = (scenePointer->itemAt(this->releasePoint, QTransform()));
            if(temp != NULL){
                qDebug() << "kaj hoise";
                //this->addEdge(temp->x, temp->y);
            }
            qDebug() << "Made this far " << releasePoint.rx() << "  " << releasePoint.ry();
        }
        list.clear();
        event->ignore();
        //QGraphicsItem::mouseReleaseEvent(event);
    }
    else{
        event->ignore();
        //QGraphicsItem::mouseReleaseEvent(event);
    }
}

void Node::setScenePointer(QGraphicsScene *s)
{
    scenePointer = s;
}
