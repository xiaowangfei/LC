int strStr(string haystack, string needle) {
    if(needle.empty()){
        return 0;
    }
    for(int i = 0; i < haystack.size(); i++){
        for(int j = 0; j < needle.size(); j++){
            if(i + j == haystack.size() || haystack[i + j] != needle[j]){
                break;
            }
            if(j == needle.size() - 1) {
                return i;
            }
        }
    }
    return -1;
 
}
