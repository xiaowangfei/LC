//BFS
string alienOrder(vector<string>& words) {
    unordered_map<char, int> indegree;
    unordered_map<char, vector<char>> graph;
    string ans = "";
    for(string word : words){
        for(char c : word){
            indegree[c] = 0;
            graph[c] = vector<char>();
        }
    }
    for(int i = 0; i < words.size() - 1; i++){
        pair<char, char> edge;
        if(firstDiff(words[i], words[i + 1], edge)){
            graph[edge.first].push_back(edge.second);
            indegree[edge.second]++;
        }
    }
    queue<char> bfs_q;
    for(char c = 'a'; c <= 'z'; c++){
        if(indegree.find(c) != indegree.end() && indegree[c] == 0){
            bfs_q.push(c);
        }
    }
    while(!bfs_q.empty()){
        char front =bfs_q.front();
        bfs_q.pop();
        ans += front;
        for(char neib : graph[front]){
            if(--indegree[neib] == 0){
                bfs_q.push(neib);
            }
        }
    }
    if(ans.size() == indegree.size()) return ans;
    return "";
}
bool firstDiff(string a, string b, pair<char, char>& edge){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            edge = make_pair(a[i], b[i]);
            return true;
        }
    }
    return false;
}

//DFS
string alienOrder(vector<string>& words) {
    unordered_map<char, vector<char>> graph;
    for(string word : words){
        for(char c : word){
            graph[c] = vector<char>();
        }
    }
    for(int i = 0; i < words.size() - 1; i++){
        pair<char, char> edge;
        if(firstDiff(words[i], words[i + 1], edge)){
            graph[edge.first].push_back(edge.second);
        }
    }
    
    unordered_set<char> discover;
    unordered_set<char> visited;
    stack<char> sans;
    for(char c = 'a'; c <= 'z'; c++){
        if(!dfs(c, graph, discover, visited, sans)){
            return "";
        }
    }
    string ans = "";
    while(!sans.empty()){
        ans += sans.top();
        sans.pop();
    }
    return ans;
}
bool dfs(char c, unordered_map<char, vector<char>>& graph, unordered_set<char>& discover, unordered_set<char>& visited, stack<char>& sans){
    if(graph.find(c) == graph.end()) return true;
    if(visited.find(c) != visited.end()) return true;
    if(discover.find(c) != discover.end()) return false;
    discover.insert(c);
    for(char neib : graph[c]){
        if(!dfs(neib, graph, discover, visited, sans)){
            return false;
        }
    }
    sans.push(c);
    visited.insert(c);
    return true;   
}

bool firstDiff(string a, string b, pair<char, char>& edge){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            edge = make_pair(a[i], b[i]);
            return true;
        }
    }
    return false;
}
