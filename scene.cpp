#include "scene.h"
scene::scene(QObject *parent) : QGraphicsScene(parent)
{

}

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF p = event->scenePos();
    QList<QGraphicsItem *> list;
    //qDebug() << p.rx() << "Works" << p.ry();
    lastPressPoint.setX(p.rx());
    lastPressPoint.setY(p.ry());
    //0 Means there is nothing in that particular position of canvas
    if(this->itemAt(p, QTransform()) == 0){
        list = this->items(p.rx()-nodeRadius/2,p.ry()-nodeRadius/2,nodeRadius,nodeRadius, Qt::IntersectsItemShape, Qt::AscendingOrder, QTransform());
        if(list.isEmpty()){
            event->accept();
            this->drawNode(p);
            return;
        }
        else{
            event->ignore();
            //QGraphicsScene::mousePressEvent(event);
        }
    }
    else{
        event->ignore();
        //QGraphicsScene::mousePressEvent(event);
    }
}

void scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF p = event->scenePos();
    lastReleasePoint.setX(p.rx());
    lastReleasePoint.setY(p.ry());
    //qDebug() << "Scene Recived Release Event" <<p.rx()<< p.ry();

    //QList<QGraphicsItem *> list;
    //if there is something
    if(itemAt(lastReleasePoint, QTransform()) != 0)
    {
        //qDebug() << "Condition Met!";
        if(itemAt(lastPressPoint, QTransform()) != 0){
            //qDebug() << "Second COnd";
            QGraphicsItem *p1 = (this->itemAt(this->lastReleasePoint, QTransform()));
            QGraphicsItem *p2 = (this->itemAt(this->lastPressPoint, QTransform()));
            //qDebug() << "     " << p2;
            if(p1 != NULL && p2 != NULL && p1 != p2)
            {
                //qDebug() << "Third COnd";
                //this->drawEdge(QPointF(p1->x,p1->y), QPointF(p2->x,p2->y));
                Node *nd1 = searchNode(lastPressPoint);
                Node *nd2 = searchNode(lastReleasePoint);
                edge * ed = this->drawEdge(QPointF(nd1->x,-nd1->y), QPointF(nd2->x,-nd2->y));
                ed->setOpacity(.35);
                ed->node1 = nd1->name.toInt();
                ed->node2 = nd2->name.toInt();
                //table[ed->node1][ed->node2] = 1;
                //table[ed->node2][ed->node1] = 1;
                weightTable.insert(std::make_pair(ed->weight, ed));
            }

        }
        //event->ignore();
        //QGraphicsItem::mouseReleaseEvent(event);
        //event->ignore();
        //QGraphicsScene::mousePressEvent(event);
    }
}

Node* scene::searchNode(QPointF pos)
{
    for(int i=0; i < NodeList.size(); ++i){
        if(NodeList[i]->x >= pos.rx()-nodeRadius/2 && NodeList[i]->x <= pos.rx()+nodeRadius/2){
            if(NodeList[i]->y >= pos.ry()-nodeRadius/2 && NodeList[i]->y <= pos.ry()+nodeRadius/2){
                return NodeList[i];
            }
        }
    }
}

Node* scene::drawNode(QPointF pos)
{
    Node *nd = new Node(pos.rx(), -pos.ry());
    nd->setScenePointer(this);
    this->addItem(nd);
    NodeList.push_back(nd);
    //qDebug() << nd->name << " " << nd << "   " << dynamic_cast<QGraphicsItem*> (nd);
    return nd;
}

edge *scene::drawEdge(QPointF pos1, QPointF pos2)
{
    edge *ed = new edge(pos1.rx(), pos1.ry(), pos2.rx(), pos2.ry());
    ed->setZValue(-1);
    this->addItem(ed);
    //edgeList.push_back(ed);
    return ed;
}

QPointF scene::getLastPressPoint()
{
    return QPointF(lastPressPoint.rx(), lastPressPoint.ry());
}

QPointF scene::getLastRealesePoint()
{
    return QPointF(lastReleasePoint.rx(), lastReleasePoint.ry());
}

void scene::MST()
{
    for(int i = 0; i < weightTable.size(); ++i)
            table[i][i] = 1;
    mapOfEdge::iterator it;
    for(it = weightTable.begin(); it != weightTable.end(); ++it){
        qDebug() << it->first << "  " << it->second->node1 << "  " << it->second->node2;
        if(edgeTable.empty()){
            edgeTable.push_back(it->second);
            table[it->second->node1][it->second->node2] = 1;
            table[it->second->node2][it->second->node1] = 1;
            continue;
        }
        //visited must be reset before every call of isCycle
        visited_reset(weightTable.size(), visited);
        if(isCycle(it->second->node1, it->second->node2, weightTable.size()) == 0){
            table[it->second->node1][it->second->node2] = 1;
            table[it->second->node2][it->second->node1] = 1;
            edgeTable.push_back(it->second);
            qDebug() << "Added!";
        }
        else
            qDebug() << "Skipped!";
    }
    this->MST_Show();
}

void scene::MST_Show()
{
    vectorOfEdge::iterator it1;
    for(it1 = edgeTable.begin(); it1 != edgeTable.end(); ++it1){
        edge *ed = *it1;
        ed->setOpacity(1);
        this->update();
    }
}

void scene::clear()
{
    num = 0;
    weightTable.clear();
    edgeTable.clear();
    for(int i = 0; i < MAXNODES; ++i)
        for(int j = 0; j < MAXNODES; ++j)
            table[i][j] = 0;
    visited_reset(MAXNODES,visited);
    NodeList.clear();
    //this->clear();
    QList<QGraphicsItem*> all = items();
    for (int i = 0; i < all.size(); i++)
    {
        QGraphicsItem *gi = all[i];
        if(gi->parentItem()==NULL) {
            delete gi;
        }
    }
    v->update();
}

void scene::setViewPointer(QGraphicsView *view)
{
    v = view;
}
