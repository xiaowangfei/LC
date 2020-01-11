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
