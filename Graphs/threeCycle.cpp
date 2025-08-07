#include<iostream>
#include"graph.h"

using namespace std;

int threeCycle(class Graph& g, int v){
    queue<int> children;
    for(int i = 0; i<g.vertices;++i){
        if(g.edges[v][i] == true)
            children.push(i);
    }
    vector<bool> visited(g.vertices,false);
    visited[v] = true;
    int count = 0;
    while(!children.empty()){
        int top = children.front();
        visited[top] = true;
        children.pop();
        for(int i = 0; i<g.vertices;++i){
            if(visited[i] == false && g.edges[top][i] == true && g.edges[i][v] == true)
                ++count;
        }
    }
    return count;
}

/*int threeCycle(class Graph& g){
    int count = 0;
    vector<bool> visitedVertices(g.vertices,false);
    for(int i = 0; i<g.vertices;++i)
        count += threeCycle(g,i);
    return count/3; // divide by 3, because each cycle is counted thrice on each of the vertices

}*/
// the above code is also correct, we follow same approach, just that the below solution is done iteratively
int threeCycle(class Graph& g){
    int count = 0;
    for(int i = 0; i<g.vertices;++i){
        for(int j = 0; j<g.vertices;++j){
            if(j==i)
                continue;
            if(g.edges[i][j] == 1){
                for(int k = 0; k<g.vertices; ++k){
                    if(k==i || k == j)
                        continue;
                    if(g.edges[j][k] && g.edges[i][k] == 1)
                        count++;
                }
            }
        }
    }
    return count/6;
}

int main(){
    class Graph g;
    g.input();
    cout << threeCycle(g) << endl;
    return 0;
}
