int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
    int level = 1;
    queue<string> bfs_q;
    unordered_set<string> HashSet;
    unordered_set<string> dict;
    for(string word : wordList){
        dict.insert(word);
    }
    bfs_q.push(beginWord);
    HashSet.insert(beginWord);
    while(!bfs_q.empty()){
        int level_size = bfs_q.size();
        for(int i = 0; i < level_size; i++){
            string front = bfs_q.front();
            if(front == endWord){
                return level;
            }
            for(string word : findAdj(front, dict)){
                if(HashSet.find(word) == HashSet.end()){
                    HashSet.insert(word);
                    bfs_q.push(word);
                }
            }
            bfs_q.pop();
        }
        level++;
    }
    return 0;        
}
vector<string> findAdj(string word, unordered_set<string>& dict){
    vector<string> AdjWords;
    string temp = word;
    for(int i = 0; i < word.size(); i++){
        for(char j = 'a'; j <= 'z'; j++){
            temp[i] = j;
            if(temp[i] != word[i] && dict.find(temp) != dict.end()){
                AdjWords.push_back(temp);
            }
        }
        temp = word;
    }
    return AdjWords;
}
