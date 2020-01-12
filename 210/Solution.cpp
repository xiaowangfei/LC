//DFS
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
