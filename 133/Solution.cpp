Node* cloneGraph(Node* node) {
    if(node == NULL) return NULL;
    map<Node*, Node*> M;//map is used both as discovered set and mapping from old graph to new graph
    M[node] = new Node(node -> val, vector<Node*>());
    queue<Node*> bfs_q;
    bfs_q.push(node);
    while(!bfs_q.empty()){
        Node* curr = bfs_q.front();
        bfs_q.pop();
        //Here is the place where each edge is checked
        for(int i = 0; i < curr -> neighbors.size(); i++){
            if(M.find(curr -> neighbors[i]) == M.end()){
                bfs_q.push(curr -> neighbors[i]);
                M[curr -> neighbors[i]] = new Node(curr -> neighbors[i] -> val, vector<Node*>());
            }
            M[curr] -> neighbors.push_back(M[curr -> neighbors[i]]);
        }
    }
    return M[node];        
}

//Traverse new graphc nodes
Node* cloneGraph(Node* node) {
    if(node == NULL) return NULL;
    map<Node*, Node*> M;
    M[node] = new Node(node -> val, vector<Node*>(node -> neighbors));
    queue<Node*> bfs_q;
    bfs_q.push(M[node]);
    while(!bfs_q.empty()){
        Node* curr = bfs_q.front();
        vector<Node*> prev(curr -> neighbors);
        curr -> neighbors.clear();
        bfs_q.pop();
        for(int i = 0; i < prev.size(); i++){
            if(M.find(prev[i]) == M.end()){
                M[prev[i]] = new Node(prev[i] -> val, vector<Node*>(prev[i] -> neighbors));
                bfs_q.push(M[prev[i]]);
            }
            curr -> neighbors.push_back(M[prev[i]]);
        }
    }
    return M[node];        
}
//Notes:
//BFS are just to vist nodes, foreach populate all the edges. BF tree is only directed from parent to child, without cycles, compared to graph
//Need to add node to set once discovered, not visited. Otherwise, time complexibity would be large

//DFS
Node* cloneGraph(Node* node) {
    if(node == NULL) return node;
    map<Node*, Node*> HashMap;
    HashMap[node] = new Node(node -> val, vector<Node*>());
    dfs(node, HashMap);
    return HashMap[node];
}
void dfs(Node* node, map<Node*, Node*>& HashMap){
    for(Node* nb : node -> neighbors){
        if(HashMap.find(nb) == HashMap.end()){
            HashMap[nb] = new Node(nb -> val, vector<Node*>());
            dfs(nb, HashMap);
        }
        HashMap[node] -> neighbors.push_back(HashMap[nb]);
    }
}
