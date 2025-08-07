#include<vector>
#include"graph.h"
using namespace std;
//input:
//4 4 0 1 1 2 2 3 0 3
// 5 7 0 1 4 0 2 8 1 2 2 1 3 6 2 3 3 2 4 9 3 4 5
int main(){
    class Graph g;
    g.weightedInput();
    //g.KruskalsMST();
    //g.PrimsMST();
    g.dijkstra();
    //g.component_DFS();
    //g.BFS();
    //g.DFS();
    /*int a,b;
    cout << "Enter start and end for path" << endl;
    cin >> a >> b;
    cout << g.hasPath(a,b) << endl;
    g.getDFSPath(a,b);
    cout << g.isConnected() << endl;
    */
    /*vector<vector<int>> soln = g.components();
    for(int i = 0; i<soln.size();++i){
        for(int j = 0; j<soln[i].size();++j)
            cout << soln[i][j] << ' ';
        cout << endl;
    }*/
    return 0;
}
