#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define sz(A) (int)A.size()

void make_zero(int *arr, int N){
    for(int i = 0; i < N; i++){
        arr[i] = 0;
    }
    return;
}

void dfs(int idx, int *vis, vector <int> *graph){
    if(vis[idx]) return;
    vis[idx] = 1;
    cout << idx << endl;
    for(int i = 0; i < sz(graph[idx]); i++){
        int next = graph[idx][i];
        if(!vis[next]) dfs(next, vis, graph);
    }
    return;
}

void bfs(int curr, int *vis, vector <int> *graph){
    int next;
    queue <int> req; req.push(curr); 
    vis[curr] = 1;
    while(!req.empty()){
        curr = req.front(); req.pop();
        cout << curr << " ";
        for(int i = 0; i < sz(graph[curr]); i++){
            next = graph[curr][i];
            if(vis[next]) continue;
            req.push(next); vis[next] = 1;
        }
    }
    cout << endl;
    return;
}

int main(){
    int V, E, x, y;
    cin >> V >> E;
    vector <int> graph[V];
    queue <int> req;
    int visited[V];



    for(int i = 0; i < E; i++){
       cin >> x >> y;
       graph[x].push_back(y); 
       graph[y].push_back(x); 
    }

    x = 0;
    

    make_zero(visited, V);
    dfs(x, visited, graph);

    make_zero(visited, V);
    bfs(0, visited, graph);


    return 0;
}
