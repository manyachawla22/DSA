#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

class Edge{
    public:
    int source;
    int destination;
    int weight;


    Edge() : source(-1), destination(-1), weight(-1) {}

    Edge(int s, int d, int w) : source(s), destination(d), weight(w) {}

    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
    
    void print()const{
        cout << source << ' ' << destination << ' ' << weight << endl;
    }

    friend class Graph;
};

// class can be updated by moving some public functions to pvt(the helper functions for prims, dijkstra kruskals etc)
class Graph{
    int vertices;
    int** edges;

    void printDFS(vector<bool>& visited, int v){
        cout << v << ' ';
        visited[v] = true;
        for(int i =0; i<vertices;++i ){
            if(visited[i] == false && edges[v][i] == true)
                printDFS(visited,i);
        }
    }
    vector<int> Traversal_DFS(vector<bool>& visited, int v){
        vector<int> ans;
        Traversal_DFS(visited,v,ans);
        return ans;
    }
    void Traversal_DFS(vector<bool>& visited, int v,vector<int> &ans){
        ans.push_back(v);
        visited[v] = true;
        for(int i =0; i<vertices;++i ){
            if(visited[i] == false && edges[v][i] == true)
                Traversal_DFS(visited,i,ans);
        }
    }
    void printBFS(vector<bool>& visited, queue<int> &node){
        while(!node.empty()){
            int top = node.front();
            cout << top << ' ';
            node.pop();
            for(int i = 0; i<vertices;++i){
                if(visited[i] == false && edges[top][i] == true){
                    node.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    bool hasPath(vector<bool>& visited, queue<int> &node, int end){
        while(!node.empty()){
            int top = node.front();
            if(top == end)
                return true;
            //cout << top << ' ';
            node.pop();
            for(int i = 0; i<vertices;++i){
                if(visited[i] == false && edges[top][i] == true){
                    node.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;
    }
    void getDFSPathHelper(int start, int end, vector<bool>& visited, vector<int>& path){
        //cout << v << ' ';
        if(start == end){
            path.push_back(end);
            return;
        }
        visited[start] = true;
        for(int i =0; i<vertices;++i ){
            if(visited[i] == false && edges[start][i] == true){
                getDFSPathHelper(i,end,visited,path);
                if(path.size() != 0){
                    path.push_back(start);
                    return;
                }
            }
        }
    }

    bool getBFSPathHelper(int start, int end,vector<bool>& visited,int* parent, queue<int> &node){
        while(!node.empty()){
            int top = node.front();
            if(top == end){
                return true;
            }
            //cout << top << ' ';
            node.pop();
            for(int i = 0; i<vertices;++i){
                if(visited[i] == false && edges[top][i] == true){
                    node.push(i);
                    visited[i] = true;
                    parent[i] = top;
                }
            }
        }
        return false;
    }

    public:
    Graph(){}
    ~Graph(){
        for(int i =0; i<vertices;++i)
            delete[] edges[i];
        delete[] edges;
    }

    friend int threeCycle(Graph& g);
    friend int threeCycle(Graph& g, int v);
    
    void weightedInput(){
        int n, e;
        cout << "Enter no of vertices and edges" << endl;
        cin >> n >> e;
        vertices = n;
        

        int** edge = new int*[n];
        for(int i = 0; i<n;++i){
            edge[i] = new int[n];
        }
        for(int i =0; i<n;++i){
            for(int j = 0; j<n; ++j)
                edge[i][j] = 0;
        }

        for(int i = 0; i<e;++i){
            cout << "Enter the edge and weight" << endl;
            int a,b,c;
            cin >> a >> b >> c;
            edge[a][b] = edge[b][a] = c;
        }
        edges = edge;
        return;
    }
    void input(){
        int n, e;
        cout << "Enter no of vertices and edges" << endl;
        cin >> n >> e;
        vertices = n;
        

        int** edge = new int*[n];
        for(int i = 0; i<n;++i){
            edge[i] = new int[n];
        }
        for(int i =0; i<n;++i){
            for(int j = 0; j<n; ++j)
                edge[i][j] = 0;
        }

        for(int i = 0; i<e;++i){
            cout << "Enter the edge" << endl;
            int a,b;
            cin >> a >> b;
            edge[a][b] = edge[b][a] = 1;
        }
        edges = edge;
        return;
    }

    void DFS(){
        if(vertices == 0)
            return;
        vector<bool> visited(vertices,false);
        printDFS(visited,0);
        for(int i =0; i<vertices;++i){
            if(visited[i] == false)
                printDFS(visited,i);
        }
        cout << endl;
    }
    void BFS(){
        if(vertices == 0)
            return;
        queue<int> node;
        vector<bool> visited(vertices,false);
        node.push(0);
        visited[0] = true;
        printBFS(visited,node);
        for(int i =0; i<vertices;++i){
            if(visited[i] == false){
                node.push(i);
                visited[i] = true;
                printBFS(visited,node);
            }
        }
        cout << endl;
    }
    bool hasPath(int start, int end){
        if(start == end)
            return true;
        queue<int> node;
        vector<bool> visited(vertices,false);
        node.push(start);
        visited[start] = true;
        return hasPath(visited,node,end);
    }

    vector<int> getDFSPath(int start,int end){
        vector<int> path;
        if(vertices == 0 || start == end)
            return path;
        vector<bool> visited(vertices,false);
        getDFSPathHelper(start,end,visited,path);
        for(int i = path.size()-1; i>=0;--i)
            cout << path[i] << ' ';
        cout << endl;
        return path;
    }
    vector<int> getBFSPath(int start, int end){
        vector<int> path;
        if(vertices == 0 || start == end)
            return path;
        vector<bool> visited(vertices,false);
        int* parent = new int[vertices];
        queue<int> node;
        node.push(start);
        visited[start] = true;
        bool ans = getBFSPathHelper(start,end,visited,parent,node);
        if(ans == false)
            return path;
        parent[start] = -1;
        for(int i = end; i != -1;){
            path.push_back(i);
            i = parent[i];
        }
        for(int i = path.size()-1; i>=0;--i)
            cout << path[i] << ' ';
        cout << endl;
        delete[] parent;
        return path;
    }
    bool isConnected(){
        if(vertices == 0)
            return true;
        vector<bool> visited(vertices,false);
        Traversal_DFS(visited,0);
        for(int i =0; i<vertices;++i){
            if(visited[i] == false)
                return false;
        }
        return true;
    }
    vector<vector<int>> components(){
        vector<vector<int>> ans;
        if(vertices == 0)
            return ans;
        vector<bool> visited(vertices,false);
        for(int i =0; i<vertices;++i){
            if(visited[i] == false){
                vector<int> temp  = Traversal_DFS(visited,i);
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }
        return ans;
    }
    void printGraph()const{
        cout << "Adjacency Matrix of Graph:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << edges[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool detectCycle(const Edge& e, vector<int>& parent){// also updates the parent vector
        int ps, pd;
        ps = parent[e.source];
        pd = parent[e.destination];
        while(parent[ps] != ps){
            ps = parent[ps];
        }
        while(parent[pd] != pd){
            pd = parent[pd];
        }
        if(ps == pd)
            return false;
        parent[ps] = pd;
        return true;
    }

    void KruskalsMST(){ // prints the edges that exists in the MST
        vector<Edge> input;
        vector<Edge> output;
        for(int i = 0; i<vertices; ++i){// only add edges once- so add edge if i>j
            for(int j = i+1; j<vertices;++j){
                if(edges[i][j] > 0){
                    Edge temp(i,j,edges[i][j]);
                    input.push_back(temp);
                }
            }
        }
        vector<int> parent(vertices);
        for(int i = 0; i<vertices; ++i)
            parent[i] = i;
        sort(input.begin(),input.end());
        int count, i;
        count = i = 0;
        while(count<vertices-1){
            if(detectCycle(input[i], parent)){
                output.push_back(input[i]);
                ++count;
            }
            ++i;
        }
        cout << "The following edges exist in the MST acc to Kruskals:" << endl;
        for(int i = 0; i<vertices-1;++i)
            output[i].print();
    }

    int minWeight(const vector<int>& unvisited,const vector<pair<int,int>>& e)const{
        int min = 0;
        for(int i = 1; i<unvisited.size();++i){
            if(e[unvisited[i]].second < e[unvisited[min]].second )
                min = i;
        }
        return min;
    }
    void PrimsMST()const{
        vector<bool> visited(vertices,false);
        vector<int> unvisited;
        for(int i = 0; i<vertices; ++i)
            unvisited.push_back(i);

        vector<pair<int,int>> e(vertices);
        for(int i = 0; i<vertices;++i){
            e[i].first = -1;
            e[i].second = INT_MAX;
        }
        e[0].second = 0;

        while(!unvisited.empty()){ // pick least weight vortex
            int index = minWeight(unvisited,e);
            int v = unvisited[index];
            visited[v] = true;
            for(int i = 0; i<vertices;++i){
                if(visited[i] == false && edges[v][i] && edges[v][i] < e[i].second){
                    e[i].second = edges[v][i];
                    e[i].first = v;
                }
            }
            swap(unvisited[index],unvisited[unvisited.size()-1]);
            unvisited.pop_back();
        }
        cout << "The following edges exist in MST acc to Prims:" << endl;
        for(int i = 1; i<vertices;++i)
            cout << e[i].first << ' ' << i << ' ' << e[i].second << endl;
    }

    int minVortex(const vector<bool>& visited, const vector<int>& dist)const{
        int min = -1;
        for(int i = 0; i<visited.size();++i){
            if(!visited[i] && (min == - 1 || dist[i] < dist[min]))
                min = i;
        }
        return min;
    }

    void dijkstra(int source = 0){
        vector<bool> visited(vertices,false);
        vector<int> distance(vertices,INT_MAX);
        distance[source] = 0;

        for(int i = 0; i<vertices; ++i){
            int v = minVortex(visited,distance);
            visited[v] = true;
            for(int i = 0; i<vertices;++i){
                if(!visited[i] && edges[v][i] && distance[i] > (distance[v] + edges[v][i]))
                    distance[i] = distance[v] + edges[v][i];
            }
        }

        for(int i = 0; i<vertices;++i)
            cout << i << ' ' << distance[i] << endl;
    }
};
