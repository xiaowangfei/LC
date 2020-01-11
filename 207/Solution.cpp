//BFS
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> InDegree(numCourses, 0);    
    for(auto adj : prerequisites){
        graph[adj[0]].push_back(adj[1]);
    }
    for(auto adj : prerequisites){
        InDegree[adj[1]]++;
    }  
    int result = 0;
    queue<int> bfs_q;
    for(int i = 0; i < numCourses; i++){
        if(InDegree[i] == 0){
            bfs_q.push(i);
        }
    }
    while(!bfs_q.empty()){
        int front = bfs_q.front();
        bfs_q.pop();
        for(int neighbor : graph[front]){
            if(--InDegree[neighbor] == 0){
                bfs_q.push(neighbor);
            }
        }            
        result++;
    }    
    return result == numCourses;
}

//DFS
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    for(auto adj : prerequisites){
        graph[adj[0]].push_back(adj[1]);
    }
    set<int> visited;
    set<int> disc;
    for(int i = 0; i < numCourses; i++){
        if(!acyclic(i, graph, disc, visited)) return false;
    }
    return true;
}
bool acyclic(int node, vector<vector<int>>& graph, set<int>& disc, set<int>& visited){
    if(disc.find(node) != disc.end() && visited.find(node) == visited.end()) return false;
    disc.insert(node);
    if(visited.find(node) != visited.end()) return true;
    for(int neighbor : graph[node]){
        if(!acyclic(neighbor, graph, disc,visited)) return false;            
    }
    visited.insert(node);
    return true;
}
