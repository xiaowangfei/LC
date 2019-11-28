bool validPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            return helper(l+1, r, s) || helper(l, r - 1, s);
        }
        
    }
    return true;        
}
bool helper(int l, int r, string s){
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

//Shorter
bool validPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l++] != s[r--]){
            return helper(l - 1, r, s) || helper(l, r + 1, s);
        }            
    }
    return true;        
}
bool helper(int l, int r, string s){
    while(l < r){
        if(s[l++] != s[r--]){
            return false;
        }
    }
    return true;
}

//Write helper function
