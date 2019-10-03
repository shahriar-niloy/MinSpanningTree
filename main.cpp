#include "mainwindow.h"
#include <QApplication>
#include <vector>
using namespace std;

//Declaring Global Variables
extern int num;
int num = 0;
extern vector<Node*> NodeList; //Stores nodes
vector<Node*> NodeList;
//extern vector<edge*> edgeList; //Stores Edges
//vector<edge*> edgeList;
//End

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
