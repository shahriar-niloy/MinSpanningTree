#ifndef MST_H
#define MST_H
#include <map>
#include <vector>
#include "edge.h"
#define MAXNODES 50
//using namespace std;

extern bool table[MAXNODES][MAXNODES];
extern bool visited[MAXNODES];

//Typedeffing
typedef std::multimap<double, edge*> mapOfEdge;
typedef std::vector<edge*> vectorOfEdge;
//Storage for weight for corresponding edges
extern mapOfEdge weightTable;
//Storage for MST edges
extern vectorOfEdge edgeTable;

//Custom Function Def
bool isCycle(int nd1, int nd2, int nodeCount);
void visited_reset(int n, bool visited[]);

#endif // MST_H
