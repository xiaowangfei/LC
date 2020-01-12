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
    if(visited.find(node) != visited.end()) return true;
    //If DFS result has back edge(color gray, indicating the next node is already discovered(parent node) but not visited), it means a cycle.
    //Or you can keep track of only currently discovered but not visited node, by adding disc.erase(node) at the end.
    if(disc.find(node) != disc.end()) return false;
    disc.insert(node);
    for(int neighbor : graph[node]){
        if(!acyclic(neighbor, graph, disc,visited)) return false;            
    }
    visited.insert(node);
    return true;
}
