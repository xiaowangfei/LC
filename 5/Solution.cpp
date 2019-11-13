class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2){
            return s;
        }
        string result;
        int s_len = s.length();
        bool **dp_mem = new bool*[s_len];
        for(int i = 0; i < s_len; i++){
            dp_mem[i] = new bool[s_len];
            dp_mem[i][i] = true;
        }
        result = s.substr(0,1);
        for(int len = 2; len <= s_len; len++){
            for(int start = 0; start + len <= s_len; start++){
                if(s[start]==s[start + len -1] && (len == 2 || dp_mem[start + 1][start + len -2] == true)){
                    dp_mem[start][start + len -1] = true;
                    result=s.substr(start, len);
                }
                else{
                    dp_mem[start][start + len -1] = false;
                }
            }
        }

        return result;
    }
};
// use pair with map
    string longestPalindrome(string s) {
        if(s.length() < 2){
            return s;
        }
        string result;
        map<pair<int, int>, bool> dp_mem;
        for(int i = 0; i < s.length(); i++) {
            dp_mem[make_pair(i, i)] = true;
        }
        result = s.substr(0,1);
        for(int len = 2; len <= s.length(); len++){
            for(int start = 0; start + len <= s.length(); start++){
                if(s[start]==s[start + len -1] && (len == 2 || dp_mem[make_pair(start + 1, start + len -2)] == true)){
                    dp_mem[make_pair(start, start + len -1)] = true;
                    result=s.substr(start, len);
                }
                else{
                    dp_mem[make_pair(start, start + len -1)] = false;
                }
            }
        }

        return result;
    }
