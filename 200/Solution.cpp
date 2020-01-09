//DFS
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int ans = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(dfs(i, j, grid, visited)){
                ans++;
            }
        }
    }
    return ans;
}
bool dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited){
    if(x < 0 || x >= grid.size()) return false;
    if(y < 0 || y >= grid[0].size()) return false;
    if(grid[x][y] == '0') return false;
    if(visited[x][y]) return false;
    visited[x][y] = true;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    for(int i = 0; i < 4; i++){
        dfs(x + dx[i], y + dy[i], grid, visited);
    }
    return true;
}
//BFS
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int ans = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(valid(i, j, grid, visited) && bfs(i, j, grid, visited)){
                ans++;
            }
        }
    }
    return ans;
}
bool bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited){
    visited[row][col] = true;
    queue<pair<int, int>> bfs_q;
    bfs_q.push(make_pair(row, col));
    while(!bfs_q.empty()){
        pair<int, int> front = bfs_q.front();
        int x = front.first;
        int y = front.second;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for(int i = 0; i < 4; i++){
            if(valid(x + dx[i], y + dy[i], grid, visited)){
                bfs_q.push(make_pair(x + dx[i], y + dy[i]));
                visited[x + dx[i]][y + dy[i]] = true;
            }
        }
        bfs_q.pop();
    }

    return true;
}
bool valid(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited){
    if(x < 0 || x >= grid.size()) return false;
    if(y < 0 || y >= grid[0].size()) return false;
    if(visited[x][y]) return false;
    if(grid[x][y] == '0') return false;
    return true;        
}
//Note how to access pair elements
//int x = front.first;
//int y = front.second;
