//BFS
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> InDegree(numCourses, 0);    
    for(auto adj : prerequisites){
        graph[adj[1]].push_back(adj[0]);
        InDegree[adj[0]]++;
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
        result++;
        for(int neighbor : graph[front]){
            if(--InDegree[neighbor] == 0){
                bfs_q.push(neighbor);
            }
        }            
    }    
    return result == numCourses;
}

//DFS
//All nodes in the paths stemming from the node A would have A as an ancestor in DFS tree.
//All nodes that have A as an ancestor in DFS tree would stemming from the node A.
//ig. all the courses that have A as a prerequisites would be in the paths stemming from the course A.
//When A is added to the stack, all courses that has A as a prerequisite would have already been added to the stack.
//Need to use post-order & stack(finish time) not pre-order(discover time), because DFS may start any order in the graph.
//eg: 1 -> 2 -> 3 -> 4 -> 5, the DFS may search start with root of 5,4,3,2,1 preorder would yield incorrect answer. 
//Or any other order, eg: 5,2,4,3,1(post-order still give 1,2,3,4,5 vs preorder 5,2,3,4,1)
//(If start from 1, then both pre&post order would provide correct answer. But no guarantee)

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    for(auto adj : prerequisites){
        graph[adj[1]].push_back(adj[0]);
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
