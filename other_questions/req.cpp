void dfs(int rt, int* visited, vector<int>ths, vector<int>adj[]) {
    if(ths[rt]==1) {
        return;
    }
    else if(visited[rt]) {
        return;
    }
    visited[rt] = 1;
    for(int i=0;i<adj[rt].size();i++) {
        if(visited[adj[rt][i]]==0) {
            dfs(adj[rt][i], visited, ths, adj);
        }
    }
    return;
}

int sol(vector<int>thieves, vector<vector<int>>edges){
    vector<int>ths;
    int maxi = -1;
    int n = edges.size()+1;
    int visited[n];
    for(int i=0;i<n;i++) {
        visited[i] = 0;
        ths.push_back(0);
    }
    vector<int>adj[n];
    for(int i=0;i<edges.size();i++) {
        adj[edges[i][0]-1].push_back(edges[i][1]-1);
        adj[edges[i][1]-1].push_back(edges[i][0]-1);

    }
    for(int i=0;i<thieves.size();i++) {
        ths[thieves[i]-1]=1;
    }
    dfs(0, visited,ths,adj);
    int cnt = -1;
    for(int i=0;i<n;i++) {
        if(visited[i]==1) cnt++;
        // cout<<visited[i]<<" ";
    }
    // cout<<endl;
    // cout<<cnt<<endl;
    return cnt;
}