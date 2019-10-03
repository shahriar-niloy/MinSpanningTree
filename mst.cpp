#include "mst.h"

bool visited[MAXNODES] = {0};
bool table[MAXNODES][MAXNODES] = {0};
mapOfEdge weightTable;
vectorOfEdge edgeTable;

void visited_reset(int n, bool visited[]){
    for(int i = 0; i < n; ++i)
        visited[i] = 0;
}

bool isCycle(int nd1, int nd2, int nodeCount){
    static bool leave = 0;
    static int level = 0;
    bool last = 0;
    visited[nd1] = 1;
    //cout << "One Step Down!" << endl;

    for(int j = 0; j < nodeCount; ++j){
        if(leave){
            if(level == 0)
                leave = 0;
            return last;
        }
        if(table[nd1][nd2] && j == nd2){
            //cout << "Time to go!" << endl;
            leave = 1;
            return 1;
        }
        //cout << "table[i][j] = " << table[nd1][j] << " visited[j] =" << visited[j] << endl;
        if(table[nd1][j] && visited[j] == 0){
            //cout << "Recursive Step!\n";
            level++;
            last = isCycle(j, nd2, nodeCount);
            level--;
            //cout << "Backtracking!" << endl;
        }
    }
    return last;
}
