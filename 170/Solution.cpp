/** Initialize your data structure here. */
vector<int> V;
TwoSum() {
}
    
/** Add the number to an internal data structure.. */
void add(int number) {
    V.push_back(number);
}
   
/** Find if there exists any pair of numbers which sum is equal to the value. */
bool find(int value) {
    set<int> S;
    for(int i = 0; i < V.size(); i++){
        if(S.find(V[i]) != S.end()){
            return true;
        }
        S.insert(value - V[i]);
    }
    return false;
}
