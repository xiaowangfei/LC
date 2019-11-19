class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        string result;
        int longest = 0;
        int start = 0;
        for(int mid = 0; mid < s.length(); mid++) {
            if(len(s, mid, mid) > longest){
                longest = len(s, mid, mid);
                start = mid - longest/2;
            }
            if(len(s, mid, mid+1) > longest){
                longest = len(s, mid, mid + 1);
                start = mid - longest/2 + 1; 
            }
        }

        return s.substr(start, longest);
    }
    int len(string& s, int left, int right){
        int longest = 0;
        while(left >= 0 && right < s.length()){
            if(s[left] == s[right]){
                longest = right - left + 1;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        return longest;
    }



};
// use DP
string longestPalindrome(string s) {
        if(s.length() < 2){
            return s;
        }
        string result;
        int s_len = s.length();
        vector<vector<bool>> dp_mem(s_len, vector<bool>(s_len, true));
        result = s.substr(0,1);
        int longest = 1;
//        for(int end = 0; end < s_len; end++){                  Move end right
//            for(int start = end; start >= 0; start--){
        for(int start = s_len - 1; start >= 0; start--){       //Move start left
            for(int end = start; end < s_len; end++){
                if(s[start]==s[end] && (end == start || end - start == 1 || dp_mem[start + 1][end - 1] == true)){
                    dp_mem[start][end] = true;
                    if(end - start + 1 > longest){
                        longest = end - start + 1;
                        result=s.substr(start, longest);
                    }
                }
                else{
                    dp_mem[start][end] = false;
                }
            }
        }

        return result;
    }


// use vector/array with map
    string longestPalindrome(string s) {
        if(s.length() < 2){
            return s;
        }
        string result;
        int s_len = s.length();
        // or vector<vector<bool>> dp_mem(s_len, vector<bool>(s_len, true))
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
 
