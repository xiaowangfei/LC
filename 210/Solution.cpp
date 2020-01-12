//BFS
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    for(auto adj : prerequisites){
        graph[adj[1]].push_back(adj[0]);
        indegree[adj[0]]++;
    }
    queue<int> bfs_q;
    vector<int> result;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
            bfs_q.push(i);
        }
    }
    while(!bfs_q.empty()){
        int front = bfs_q.front();
        bfs_q.pop();
        result.push_back(front);
        for(int neighbor : graph[front]){
            if(--indegree[neighbor] == 0){
                bfs_q.push(neighbor);
            }
        }
    }
    if(result.size() == numCourses){
        return result;
    }
    else{
        return vector<int>();
    }
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
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    for(auto edge : prerequisites){
        graph[edge[1]].push_back(edge[0]);
    }
    unordered_set<int> visited;
    unordered_set<int> discover;
    stack<int> ans_stack;
    for(int i = 0; i < numCourses; i++){
        if(!dfs(i, graph, discover, visited, ans_stack)){
            return vector<int>();
        }
    }
    vector<int> result;
    while(!ans_stack.empty()){
        result.push_back(ans_stack.top());
        ans_stack.pop();
    }
    return result;
}
bool dfs(int node, vector<vector<int>>& graph, unordered_set<int>& discover, unordered_set<int>& visited, stack<int>& ans_stack){
    if(visited.find(node) != visited.end()) return true;
    if(discover.find(node) != discover.end()) return false;
    discover.insert(node);
    for(int neighbor : graph[node]){
        if(!dfs(neighbor, graph, discover, visited, ans_stack)){
            return false;
        }
    }
    visited.insert(node);
    ans_stack.push(node);
    return true;
}
